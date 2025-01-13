#include <am.h>
#include <nemu.h>

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  // 从 64 位寄存器的两个 32 位部分读取当前系统时间
  uint32_t low = inl(RTC_ADDR);          // 读取低 32 位
  uint32_t high = inl(RTC_ADDR + 4);     // 读取高 32 位
  uint64_t time = ((uint64_t)high << 32) | low;  // 合成 64 位时间

  // 将时间填入 AM_TIMER_UPTIME_T 结构体
  uptime->us = time;  // 微秒
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
