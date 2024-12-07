/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NEQ, TK_AND, TK_OR, TK_NOT,
  TK_HEX, TK_DEC, TK_REG,
  // 运算符的 ASCII 值如 '+', '-', '*' 等直接作为 token_type
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},        // 空格 (跳过不处理)
  {"\\+", '+'},             // 加号
  {"-", '-'},               // 减号
  {"\\*", '*'},             // 乘号
  {"/", '/'},               // 除号
  {"\\(", '('},             // 左括号
  {"\\)", ')'},             // 右括号
  {"0x[0-9a-fA-F]+", TK_HEX}, // 十六进制整数
  {"[0-9]+", TK_DEC},       // 十进制整数
  {"==", TK_EQ},            // 等于
  {"!=", TK_NEQ},           // 不等于
  {"&&", TK_AND},           // 逻辑与
  {"\\|\\|", TK_OR},        // 逻辑或
  {"!", TK_NOT},            // 逻辑非
  {"\\$[a-zA-Z][a-zA-Z0-9]*", TK_REG}, // 寄存器 (例如 $eax)
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
            case TK_NOTYPE:
                // 跳过空格串
                break;
            case TK_DEC:
            case TK_HEX:
            case TK_REG:
                if (substr_len >= sizeof(tokens[nr_token].str)) {
                    printf("Token string too long, buffer overflow prevented.\n");
                    return false;
                }
                tokens[nr_token].type = rules[i].token_type;
                strncpy(tokens[nr_token].str, substr_start, substr_len);
                tokens[nr_token].str[substr_len] = '\0'; // Null-terminate the string
                nr_token++;
                break;
            default:
                // 对于运算符或括号，直接记录类型
                tokens[nr_token].type = rules[i].token_type;
                nr_token++;
                break;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static bool check_parentheses(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') return false;

  int balance = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') balance++;
    if (tokens[i].type == ')') balance--;
    if (balance < 0) return false; // 不匹配
  }
  return balance == 0;
}

static int find_main_operator(int p, int q) {
  int op = -1, min_precedence = 10; // 假设最低优先级为 10
  int balance = 0;

  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') balance++;
    if (tokens[i].type == ')') balance--;

    if (balance == 0) {
      int precedence = 0;
      switch (tokens[i].type) {
        case TK_AND:
        case TK_OR: precedence = 1; break; // 最低优先级
        case '+':
        case '-': precedence = 2; break;
        case '*':
        case '/': precedence = 3; break;
      }

      if (precedence <= min_precedence) {
        min_precedence = precedence;
        op = i;
      }
    }
  }
  return op;
}

word_t eval(int p, int q, bool *success) {
  if (p > q) {
    *success = false;
    return 0;
  }
  else if (p == q) {
    // 处理单个 token
    uint32_t value = 0;
    if (tokens[p].type == TK_DEC) {
      sscanf(tokens[p].str, "%d", &value);
    } else if (tokens[p].type == TK_HEX) {
      sscanf(tokens[p].str, "%x", &value);
    } else if (tokens[p].type == TK_REG) {
      value = isa_reg_str2val(tokens[p].str + 1, success); // 寄存器
      if (!*success) return 0;
    } else {
      *success = false;
      return 0;
    }
    return value;
  }
  else if (check_parentheses(p, q)) {
    return eval(p + 1, q - 1, success);
  }
  else {
    int op = find_main_operator(p, q);
    if (op == -1) {
      *success = false;
      return 0;
    }

    word_t val1 = eval(p, op - 1, success);
    if (!*success) return 0;
    word_t val2 = eval(op + 1, q, success);
    if (!*success) return 0;

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/':
        if (val2 == 0) {
          printf("Division by zero error\n");
          *success = false;
          return 0;
        }
        return val1 / val2;
      default: assert(0);
    }
  }
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  *success = true;
  return eval(0, nr_token - 1, success);
}
