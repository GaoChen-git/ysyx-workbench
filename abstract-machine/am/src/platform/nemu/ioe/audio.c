#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)

// 初始化声卡
void __am_audio_init() {
    // 声卡初始化时无操作
}

// 配置声卡信息
void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;// 声卡存在
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);// 从寄存器读取缓冲区大小
}

// 配置声卡控制参数
void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
    outl(AUDIO_FREQ_ADDR, ctrl->freq);          // 设置采样频率
    outl(AUDIO_CHANNELS_ADDR, ctrl->channels);  // 设置通道数
    outl(AUDIO_SAMPLES_ADDR, ctrl->samples);    // 设置每次处理的采样数
    outl(AUDIO_INIT_ADDR, 1);                   // 初始化音频设备
}

// 读取声卡状态
void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);  // 从寄存器读取当前缓冲区已用大小
}

// 播放音频数据
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
    uint8_t *buf = (uint8_t *)ctl->buf.start;   // 获取音频数据起始地址
  int len = ctl->buf.end - ctl->buf.start;    // 计算音频数据长度

  while (len > 0) {
    int available_space = inl(AUDIO_SBUF_SIZE_ADDR) - inl(AUDIO_COUNT_ADDR);  // 计算剩余空间
    if (available_space == 0) {
      continue;  // 等待缓冲区空闲
    }

    int write_len = (len < available_space) ? len : available_space;  // 决定写入长度

    // 将音频数据写入缓冲区
    for (int i = 0; i < write_len; i++) {
      outb(AUDIO_SBUF_ADDR + (inl(AUDIO_COUNT_ADDR) % inl(AUDIO_SBUF_SIZE_ADDR)), buf[i]);
    }

    len -= write_len;  // 更新剩余长度
    buf += write_len;  // 更新数据指针
  }
}
