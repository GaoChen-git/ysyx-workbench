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


// 工具函数：生成随机数，范围为 [0, n)
static uint32_t choose(uint32_t n) {
    return rand() % n;
}

// 工具函数：向缓冲区 `buf` 中追加字符
static void gen(char c) {
    int len = strlen(buf);
    if (len < sizeof(buf) - 1) {
        buf[len] = c;
        buf[len + 1] = '\0';
    }
}

// 工具函数：生成随机数字符串并追加到缓冲区
static void gen_num() {
    char num[12]; // 最大支持 32 位无符号整数，10 位 + 终止符
    sprintf(num, "%u", choose(10000)); // 限制随机数字大小为 0~9999
    strcat(buf, num);
}

// 工具函数：生成随机操作符并追加到缓冲区
static void gen_rand_op() {
    switch (choose(4)) {
        case 0: gen('+'); break;
        case 1: gen('-'); break;
        case 2: gen('*'); break;
        case 3: gen('/'); break;
    }
}

// 工具函数：随机插入空格
static void gen_space() {
    for (int i = 0; i < choose(3); i++) { // 随机插入 0~2 个空格
        gen(' ');
    }
}

// 核心函数：生成随机表达式
static void gen_rand_expr() {
    if (strlen(buf) > 60000) { // 防止表达式过长导致溢出
        gen_num(); // 达到最大长度后，只生成数字
        return;
    }
    switch (choose(3)) {
        case 0: // 生成数字
            gen_space();
            gen_num();
            gen_space();
            break;
        case 1: // 生成带括号的子表达式
            gen_space();
            gen('(');
            gen_rand_expr();
            gen(')');
            gen_space();
            break;
        default: // 生成操作符和递归表达式
            gen_rand_expr();
            gen_space();
            gen_rand_op();
            gen_space();
            gen_rand_expr();
            break;
    }
}


int main(int argc, char *argv[]) {
  // 设置随机种子
  int seed = time(0);
  srand(seed);

  // 解析循环次数
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

    // 编译生成的代码
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue; // 编译失败，跳过

    // 运行生成的可执行文件
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    // 获取运行结果
    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}