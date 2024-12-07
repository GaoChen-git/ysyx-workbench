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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

word_t expr(char *e, bool *success);

void run_tests(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Cannot open file %s\n", filename);
    return;
  }

  char line[65535];
  int total = 0, pass = 0;

  while (fgets(line, sizeof(line), fp)) {
    uint32_t expected;
    char expr_buf[65535];
    // 从文件读取 "结果 表达式" 格式
    if (sscanf(line, "%u %[^\n]", &expected, expr_buf) != 2) {
      printf("Error: Invalid format in input file.\n");
      continue;
    }

    // 调用 expr() 计算结果
    bool success = true;
    uint32_t result = expr(expr_buf, &success);

    if (success && result == expected) {
      pass++;
    } else {
      printf("Mismatch: expected %u, got %u, expr = %s\n", expected, result, expr_buf);
    }

    total++;
  }

  fclose(fp);
  printf("Test Results: Passed %d/%d tests.\n", pass, total);
}

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

    /* 如果提供了输入文件参数，运行测试 */
    if (argc > 1) {
        printf("Running tests from input file: %s\n", argv[1]);
        run_tests(argv[1]);
    }

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
