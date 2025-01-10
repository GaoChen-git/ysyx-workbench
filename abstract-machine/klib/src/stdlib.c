#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
static char *curr = NULL; // 用于指示当前可分配内存的起始位置
#endif
void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
    // 使用 NEMU 提供的 heap 区域进行分配
    if (curr == NULL) {
    curr = (char *)heap.start; // 初始化 curr 为堆区起始位置
    }

    // 对齐分配地址，假定对齐到8字节（具体请根据需要RTFM）
    uintptr_t aligned = ROUNDUP((uintptr_t)curr, 8);

    // 检查是否有足够空间分配（在测试代码中一般不需要严密检查）
    // 简单实现，不做越界检查
    char *ret = (char *)aligned;
    curr = (char *)(aligned + size); // 移动当前指针
    return ret;
#endif
    return NULL;
}

void free(void *ptr) {
    // 简单版本，不释放内存
}

#endif
