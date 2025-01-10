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

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  nr_reg
};

static uint8_t *sbuf = NULL;// 流缓冲区
static uint32_t *audio_base = NULL;// 寄存器基地址
static int sbuf_read_pos = 0;     // 缓冲区读取位置
static int sbuf_size = 0;         // 缓冲区大小

static SDL_AudioSpec spec;

static void sdl_audio_callback(void *userdata, uint8_t *stream, int len) {
  // 从缓冲区读取音频数据
  int available = sbuf_size - sbuf_read_pos;
  if (available < len) {
    memcpy(stream, sbuf + sbuf_read_pos, available);
    memset(stream + available, 0, len - available); // 填零防止噪音
    sbuf_read_pos = 0;
  } else {
    memcpy(stream, sbuf + sbuf_read_pos, len);
    sbuf_read_pos += len;
  }
  audio_base[reg_count] = sbuf_size - sbuf_read_pos; // 更新缓冲区使用情况
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
    if (!is_write) return;

  switch (offset) {
    case reg_freq:
      spec.freq = audio_base[reg_freq];
      break;
    case reg_channels:
      spec.channels = audio_base[reg_channels];
      break;
    case reg_samples:
      spec.samples = audio_base[reg_samples];
      break;
    case reg_init:
      if (audio_base[reg_init]) {
        SDL_InitSubSystem(SDL_INIT_AUDIO);
        spec.format = AUDIO_S16SYS;
        spec.callback = sdl_audio_callback;
        spec.userdata = NULL;
        SDL_OpenAudio(&spec, NULL);
        SDL_PauseAudio(0);
      }
      break;
    default:
      break;
  }
}

void init_audio() {
    uint32_t space_size = sizeof(uint32_t) * nr_reg;
    audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
    add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
    add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

    sbuf_size = CONFIG_SB_SIZE;
    sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
    add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);

    memset(audio_base, 0, space_size);
}
