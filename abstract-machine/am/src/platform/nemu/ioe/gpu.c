#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)     // 同步寄存器地址

void __am_gpu_init() {
    // // 从 VGACTL_ADDR 获取屏幕宽高信息
    // uint32_t screen_info = inl(VGACTL_ADDR);
    // int w = (screen_info >> 16) & 0xFFFF;    // 高16位存储宽度
    // int h = screen_info & 0xFFFF; // 低16位存储高度

    // // 初始化帧缓冲区
    // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    // for (int i = 0; i < w * h; i++) {
    //     fb[i] = 0xFCA311; // 填充测试颜色数据
    // }

    // // 同步帧缓冲区到屏幕
    // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
//   *cfg = (AM_GPU_CONFIG_T) {
//     .present = true, .has_accel = false,
//     .width = 0, .height = 0,
//     .vmemsz = 0
//   };
    // 从 VGACTL_ADDR 读取屏幕信息
    uint32_t screen_info = inl(VGACTL_ADDR);
    int w = (screen_info >> 16) & 0xFFFF;
    int h = screen_info & 0xFFFF;

    *cfg = (AM_GPU_CONFIG_T) {
        .present = true,
        .has_accel = false,
        .width = w,
        .height = h,
        .vmemsz = w * h * sizeof(uint32_t), // 帧缓冲区大小
    };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
    // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    // int screen_w = inl(VGACTL_ADDR) >> 16;
    // int screen_h = inl(VGACTL_ADDR) & 0xFFFF;

    // for (int y = 0; y < ctl->h; y++) {
    //     for (int x = 0; x < ctl->w; x++) {
    //         int screen_pos = (ctl->y + y) * screen_w + (ctl->x + x);
    //         int buf_pos = y * ctl->w + x;

    //         // 检查坐标是否在屏幕范围内
    //         if ((ctl->x + x) < screen_w && (ctl->y + y) < screen_h) {
    //             fb[screen_pos] = ((uint32_t *)ctl->pixels)[buf_pos];
    //         }
    //     }
    // }

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
    // GPU 始终准备就绪
    status->ready = true;
}
