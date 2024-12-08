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

// 定义缓冲区大小，用于存储生成的随机表达式
static char buf[65536] = {};        // 存储生成的随机表达式
static char code_buf[65536 + 128] = {}; // 用于存储完整的 C 程序代码
static char *code_format =          // 用于构造 C 程序代码的模板
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static char *pbuf; // 指向 buf 中当前写入位置的指针

// 将格式化字符串写入缓冲区，并更新指针 pbuf
#define format_buf(fmt, ...) pbuf += sprintf(pbuf, fmt, ##__VA_ARGS__)

// 生成范围在 [0, max) 的随机数
static inline uint32_t choose(uint32_t max) {
  return rand() % max;
}

// 生成随机操作符并追加到缓冲区
static inline void gen_rand_op() {
  char op_list[] = {'+', '-', '*', '/', '+', '-', '*'}; // 定义操作符集合
  format_buf("%c", op_list[choose(7)]);                // 随机选择一个操作符追加到缓冲区
}

// 生成随机数字并追加到缓冲区
static inline void gen_num() {
  format_buf("%uu", rand()); // 使用 rand() 生成随机数字
}

// 随机插入空格到缓冲区
static inline void gen_space() {
  char *space_list[3] = {
    "",
    " ",
    "  ",
  };
  format_buf("%s", space_list[choose(3)]); // 随机插入 0~2 个空格
}

static int nr_op = 0; // 操作符计数，用于限制递归深度

// 核心函数：递归生成随机表达式
static inline void gen_rand_expr() {
  gen_space(); // 随机插入空格
  switch (choose(3)) {
    default: // 递归生成表达式或数字
      if (nr_op == 0) gen_rand_expr(); // 如果没有操作符，则递归生成表达式
      else gen_num();                  // 否则直接生成数字
      break;
    case 1: // 生成带括号的子表达式
      format_buf("(");         // 插入左括号
      gen_rand_expr();         // 递归生成子表达式
      format_buf(")");         // 插入右括号
      break;
    case 0: // 生成操作符和操作数
      nr_op++;                 // 增加操作符计数
      if (pbuf - buf >= sizeof(buf) / 2) { // 如果缓冲区使用超过一半，生成数字避免溢出
        gen_num();
        break;
      }
      gen_rand_expr();         // 生成左操作数
      gen_space();
      gen_rand_op();           // 插入随机操作符
      gen_space();
      gen_rand_expr();         // 生成右操作数
      nr_op--;                 // 减少操作符计数
      break;
  }
  gen_space(); // 随机插入空格
}

// 移除表达式中的所有 'u' 后缀
void remove_u(char *p) {
  char *q = p;
  while ((q = strchr(q, 'u')) != NULL) { // 查找 'u' 并移除
    strcpy(q, q + 1); // 删除 'u' 并向左移动字符串
  }
}

int main(int argc, char *argv[]) {
  // 设置随机种子，确保每次运行生成不同的随机表达式
  int seed = time(0);
  srand(seed);

  // 解析命令行参数，设置循环次数
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop); // 如果提供参数，则更新循环次数
  }

  for (int i = 0; i < loop; i++) {
    nr_op = 0;       // 重置操作符计数
    pbuf = buf;      // 重置缓冲区指针
    gen_rand_expr(); // 生成随机表达式

    // 使用模板生成完整的 C 程序代码
    sprintf(code_buf, code_format, buf);

    // 将生成的代码写入临时文件
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL); // 确保文件打开成功
    fputs(code_buf, fp);
    fclose(fp);

    // 使用系统调用编译生成的 C 程序
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue; // 如果编译失败，跳过本次循环

    // 运行生成的可执行文件并读取输出
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL); // 确保命令执行成功

    int result;
    if (fscanf(fp, "%d", &result) != 1) { // 检查是否正确读取结果
        printf("Error: Failed to read result from file.\n");
        pclose(fp); // 确保关闭文件句柄
        return 1;   // 返回非零值表示错误
    }
    ret = pclose(fp);
    if (ret != 0) continue; // 如果执行失败，跳过本次循环

    remove_u(buf); // 移除表达式中的所有 'u' 后缀

    // 输出计算结果和对应的表达式
    printf("%u %s\n", result, buf);
  }

  return 0; // 程序结束
}