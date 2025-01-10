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
#include <device/map.h>
#include <SDL2/SDL.h>

// 定义音频寄存器枚举
enum {
  reg_freq,         // 频率寄存器
  reg_channels,     // 声道数寄存器
  reg_samples,      // 样本数寄存器
  reg_sbuf_size,    // 缓冲区大小寄存器
  reg_init,         // 初始化寄存器
  reg_count,        // 缓冲区计数寄存器
  nr_reg            // 寄存器总数
};


static uint8_t *sbuf = NULL;        // 音频流缓冲区
static uint32_t *audio_base = NULL; // 寄存器基地址
static int tail = 0;                // 缓冲区读取指针

// 音频播放回调函数
static inline void audio_play(void *userdata, uint8_t *stream, int len) {
  int nread = len;                              // 请求读取的字节数
  int count = audio_base[reg_count];            // 缓冲区中现有数据量
  if (count < len) nread = count;               // 实际读取量取决于现有数据

  if (nread + tail < CONFIG_SB_SIZE) {          // 数据不会跨越缓冲区末尾
    memcpy(stream, sbuf + tail, nread);         // 从缓冲区拷贝到 SDL 流
    tail += nread;                              // 更新读取指针
  } else {                                      // 数据跨越缓冲区末尾
    int first_cpy_len = CONFIG_SB_SIZE - tail;  // 剩余部分长度
    memcpy(stream, sbuf + tail, first_cpy_len); // 拷贝缓冲区尾部数据
    memcpy(stream + first_cpy_len, sbuf, nread - first_cpy_len); // 拷贝缓冲区开头数据
    tail = nread - first_cpy_len;               // 更新读取指针
  }
  audio_base[reg_count] -= nread;               // 更新缓冲区计数
  if (len > nread) memset(stream + nread, 0, len - nread); // 填充剩余部分为 0 避免噪声
}

// 音频寄存器 I/O 处理函数
static void audio_io_handler(uint32_t offset, int len, bool is_write) {
    if (offset == reg_init * sizeof(uint32_t) && len == 4 && is_write) {
        // 初始化音频设备
        SDL_AudioSpec s = {};                       // SDL 音频规格结构体
        s.freq = audio_base[reg_freq];              // 设置频率
        s.format = AUDIO_S16SYS;                    // 使用 16 位有符号数格式
        s.channels = audio_base[reg_channels];      // 设置声道数
        s.samples = audio_base[reg_samples];        // 设置样本数
        s.callback = audio_play;                    // 设置回调函数
        s.userdata = NULL;                          // 不使用用户数据

        tail = 0;                                   // 重置缓冲区读取指针
        audio_base[reg_count] = 0;                  // 初始化缓冲区计数
        SDL_InitSubSystem(SDL_INIT_AUDIO);          // 初始化 SDL 音频子系统
        SDL_OpenAudio(&s, NULL);                    // 打开音频设备
        SDL_PauseAudio(0);                          // 开始播放
  }
}

// 初始化音频设备
void init_audio() {
    uint32_t space_size = sizeof(uint32_t) * nr_reg; // 计算寄存器空间大小
    audio_base = (uint32_t *)new_space(space_size);  // 分配寄存器空间
#ifdef CONFIG_HAS_PORT_IO
    add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);// 添加 PIO 映射
#else
    add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);// 添加 MMIO 映射
#endif

    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;     // 设置缓冲区大小寄存器

    sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);    // 分配流缓冲区空间
    add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL); // 添加缓冲区 MMIO 映射
}

