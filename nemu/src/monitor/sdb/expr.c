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
  char str[65536];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
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
                // 检查 token 的字符串长度，防止缓冲区溢出
                if (substr_len >= sizeof(tokens[nr_token].str)) {
                    printf("Token string too long, buffer overflow prevented.\n");
                    return false;
                }
                // 记录 token 类型和内容
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
    // 检查子表达式是否被一对括号包围
    if (tokens[p].type != '(' || tokens[q].type != ')') return false;

    int balance = 0;
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') balance++;   // 遇到左括号，增加计数
        if (tokens[i].type == ')') balance--;   // 遇到右括号，减少计数
        if (balance < 0) return false;  // 括号不匹配
    }
    // 只有括号完全匹配时才返回 true
    return balance == 0;
}

static int find_main_operator(int p, int q) {
    int op = -1, min_precedence = 10; // 设最低优先级为10
    int balance = 0;    // 括号平衡计数器

    for (int i = p; i <= q; i++) {
        // 跳过括号内部的内容
        if (tokens[i].type == '(') balance++;
        if (tokens[i].type == ')') balance--;

        // 当前 token 不在括号中
        if (balance == 0) {
            int precedence = 0;
            switch (tokens[i].type) {
            case TK_AND:
            case TK_OR: precedence = 1; break;  // 最低优先级
            case '+':
            case '-': precedence = 2; break;    // 中等优先级
            case '*':
            case '/': precedence = 3; break;    // 高优先级
            default: continue; // 跳过非运算符 token
            }
            // 更新主运算符,选择优先级最低的运算符作为主运算符
            if (precedence <= min_precedence) {
                min_precedence = precedence;
                op = i;
            }
        }
    }
    printf("Main operator at %d: %c\n", op, op != -1 ? tokens[op].type : ' ');//debug printf
    return op;  // 返回主运算符的位置
}

word_t eval(int p, int q, bool *success) {
    if (p > q) {
        /* Bad expression */
        *success = false;
        return 0;
    }
    else if (p == q) {
        /* Single token.
         * For now this token should be a number.
         * Return the value of the number.
         */
        // 处理单个 token，单个token，必须是一个数字或寄存器
        uint32_t value = 0;
        if (tokens[p].type == TK_DEC) {
            // 解析十进制整数
            sscanf(tokens[p].str, "%d", &value);
            printf("Parsed decimal %s -> %u\n", tokens[p].str, value);//debug printf
        }
        else if (tokens[p].type == TK_HEX) {
            // 解析十六进制整数
            sscanf(tokens[p].str, "%x", &value);
            printf("Parsed hexadecimal %s -> %u\n", tokens[p].str, value);//debug printf
        }
        else if (tokens[p].type == TK_REG) {
            // 获取寄存器的值
            value = isa_reg_str2val(tokens[p].str + 1, success); // 寄存器
            printf("Parsed register %s -> %u\n", tokens[p].str, value);//debug printf
            if (!*success) return 0;    // 获取失败，返回错误
        }
        else {
            // 非法的单个 token
            *success = false;
            return 0;
        }
        return value;
    }
    else if (check_parentheses(p, q) == true) {
        /* The expression is surrounded by a matched pair of parentheses.
         * If that is the case, just throw away the parentheses.
         */
        return eval(p + 1, q - 1, success);
    }
    else {
        // 查找主运算符
        int op = find_main_operator(p, q);
        if (op == -1) {
            *success = false;   // 没有找到主运算符
            return 0;
        }
        // 递归求值左右子表达式
        word_t val1 = eval(p, op - 1, success);
        printf("Left operand: %u\n", val1);//debug printf
        if (!*success) return 0;
        word_t val2 = eval(op + 1, q, success);
        printf("Right operand: %u\n", val2);//debug printf
        if (!*success) return 0;
        // 根据主运算符的类型计算结果
        switch (tokens[op].type) {
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            case '/':
            if (val2 == 0) {
                printf("Division by zero error\n");
                *success = false;
                return 0;   // 除零错误
            }
            return val1 / val2;
            default: assert(0);     // 不支持的运算符
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
  printf("nr_token=%d\n",nr_token);
  printf("nr_token=%d\n",nr_token);
  // 调用 eval 函数计算表达式的值
  return eval(0, nr_token - 1, success);
}
