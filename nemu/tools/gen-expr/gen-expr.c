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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 生成一个随机数字
static void gen_num() {
  char num[12];
  sprintf(num, "%u", rand() % 100); // 随机生成 0-99 的数字

  // 检查缓冲区最后一个字符是否是数字或右括号
  // 如果是，则需要插入一个运算符，防止非法表达式
  if (strlen(buf) > 0 && (isdigit(buf[strlen(buf) - 1]) || buf[strlen(buf) - 1] == ')')) {
    strcat(buf, "+"); // 默认插入加号，确保语法合法
  }
  strcat(buf, num); // 将生成的数字追加到缓冲区
}

// 生成一个随机运算符
static void gen_rand_op() {
  // 检查缓冲区最后一个字符是否是运算符或左括号
  // 如果是，则需要插入一个数字，防止连续运算符
  if (strlen(buf) == 0 || buf[strlen(buf) - 1] == '(' ||
      buf[strlen(buf) - 1] == '+' || buf[strlen(buf) - 1] == '-' ||
      buf[strlen(buf) - 1] == '*' || buf[strlen(buf) - 1] == '/') {
    gen_num(); // 如果位置不合法，插入一个数字
  }

  char op = "+-*/"[rand() % 4]; // 随机选择一个运算符
  size_t len = strlen(buf);
  buf[len] = op; // 将运算符追加到缓冲区
  buf[len + 1] = '\0'; // 添加字符串结束符
}

// 生成一个随机表达式
static void gen_rand_expr() {
  // 防止缓冲区溢出
  if (strlen(buf) > 65535 - 50) return;

  switch (rand() % 3) { // 随机选择表达式类型
    case 0: // 生成一个数字
      gen_num();    break;
    case 1: // 生成一个括号表达式
      if (strlen(buf) > 0 && (isdigit(buf[strlen(buf) - 1]) || buf[strlen(buf) - 1] == ')')) {
        gen_rand_op(); // 如果前面是数字或右括号，插入运算符
      }
      strcat(buf, "(");  // 插入左括号
      gen_rand_expr();   // 递归生成括号内的表达式
      strcat(buf, ")");  // 插入右括号
      break;
    default: // 生成二元表达式
      gen_rand_expr();   // 生成左子表达式
      gen_rand_op();     // 插入运算符
      gen_rand_expr();   // 生成右子表达式
      break;
  }
}


// static void gen_rand_expr() {
//   buf[0] = '\0';
// }

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
