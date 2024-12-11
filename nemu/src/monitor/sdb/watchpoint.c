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

#include "sdb.h"
#include <string.h>
#include <assert.h>

#define EXPR_LEN 256  // 表达式长度限制
#define NR_WP 32

typedef struct watchpoint {
    int NO;                     // 监视点编号
    struct watchpoint *next;    // 链表指针

    /* TODO: Add more members if necessary */
    char expr[EXPR_LEN];        // 存储的表达式
    uint32_t value;             // 表达式的当前值
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;      // 初始化所有监视点到空闲链表
}

/* TODO: Implement the functionality of watchpoint */
// 分配一个新的监视点
WP* new_wp() {
  if (free_ == NULL) {
    assert(0);  // 没有空闲监视点，程序终止
  }
  WP *wp = free_;       // 从空闲链表头部分配
  free_ = free_->next;  // 更新空闲链表

  wp->next = head;  // 将监视点加入使用链表
  head = wp;

  return wp;
}

// 释放监视点
void free_wp(WP *wp) {
  assert(wp != NULL);

  // 从使用链表中移除
  if (head == wp) {
    head = head->next;
  } else {
    WP *prev = head;
    while (prev->next != wp) {
      prev = prev->next;
      assert(prev != NULL);  // 保证找到目标监视点
    }
    prev->next = wp->next;
  }

  // 归还到空闲链表
  wp->next = free_;
  free_ = wp;
}

// 打印使用中的监视点信息
void print_watchpoints() {
  printf("Num\tExpr\t\tValue\n");
  for (WP *wp = head; wp != NULL; wp = wp->next) {
    printf("%d\t%s\t\t%u\n", wp->NO, wp->expr, wp->value);
  }
}

// 添加一个监视点
void add_watchpoint(char *expression) {
  WP *wp = new_wp();
  strncpy(wp->expr, expression, EXPR_LEN - 1);  // 保存表达式
  wp->expr[EXPR_LEN - 1] = '\0';

  bool success = true;
  wp->value = expr(wp->expr, &success);  // 初次求值
  if (!success) {
    printf("Failed to evaluate expression: %s\n", expression);
    free_wp(wp);  // 求值失败，释放监视点
  }
}

// 删除指定编号的监视点
void delete_watchpoint(int no) {
  WP *wp = head;
  while (wp != NULL && wp->NO != no) {
    wp = wp->next;
  }
  if (wp == NULL) {
    printf("No watchpoint with number %d\n", no);
    return;
  }
  free_wp(wp);  // 释放监视点
}
