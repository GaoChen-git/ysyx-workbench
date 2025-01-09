#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000 // 高位用于标识按下状态

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
    uint32_t key_data = inl(KBD_ADDR); // 从键盘数据寄存器读取按键信息

    if (key_data == AM_KEY_NONE) { // 无按键输入
        kbd->keydown = false;
        kbd->keycode = AM_KEY_NONE;
    } else {
        kbd->keydown = (key_data & KEYDOWN_MASK) != 0; // 高位判断是否按下
        kbd->keycode = key_data & ~KEYDOWN_MASK;       // 低位保存键码
    }
}
