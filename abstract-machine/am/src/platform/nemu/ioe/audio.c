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
    // cfg->present = false;                      // 声卡不存在
    cfg->present = true;                      // 声卡存在
    cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR); // 从寄存器读取缓冲区大小
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
  stat->count = inl(AUDIO_COUNT_ADDR);          // 从寄存器读取当前缓冲区已用大小
}

// 播放音频数据
void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
    uint8_t *buf = (uint8_t *)ctl->buf.start;   // 获取待播放音频数据的起始地址
    int len = ctl->buf.end - ctl->buf.start;    // 计算音频数据长度

    // 读出环形缓冲区总大小
    uint32_t sbuf_size = inl(AUDIO_SBUF_SIZE_ADDR);

    while (len > 0) {
        // 当前环形缓冲区已用大小
        uint32_t cur_count = inl(AUDIO_COUNT_ADDR);
        uint32_t free_space = sbuf_size - cur_count; // 剩余可用空间

        if (free_space == 0) {
            // 如果缓冲区已满，简单忙等 (可考虑用yield或sleep)
            continue;
        }

        // 本次实际可写入的字节数
        int write_len = (len < free_space ? len : free_space);

        // 按环形逻辑写入
        for (int i = 0; i < write_len; i++) {
            // 写位置：(cur_count + i) % sbuf_size
            outb(AUDIO_SBUF_ADDR + ((cur_count + i) % sbuf_size), buf[i]);
        }

        // **关键：写完后需要更新硬件 count 寄存器，告诉硬件我们又写了多少字节**
        outl(AUDIO_COUNT_ADDR, cur_count + write_len);

        // 更新本次写入后，剩余的未写音频数据
        buf += write_len;
        len -= write_len;
    }
}
