#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include <cstdlib>
#include "Vysyx_22050535_NPC.h"  // Verilator 自动生成的顶层模块头文件

// 定义内存空间（模拟存储器）
uint32_t pmem[256];

// 模拟存储器的读取函数
uint32_t pmem_read(uint32_t addr) {
    if (addr < 0x80000000 || addr >= 0x80000000 + 4 * (sizeof(pmem) / sizeof(uint32_t))) {
        std::cerr << "Error: Memory access out of bounds at address: 0x"
                  << std::hex << addr << std::endl;
        exit(EXIT_FAILURE);
    }
    return pmem[(addr - 0x80000000) / 4];
}

// DPI-C 回调函数：在 ebreak 指令时结束仿真
extern "C" void sim_end() {
    std::cout << "Simulation ended due to ebreak instruction." << std::endl;
    exit(0);
}

// 主函数
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);  // 解析命令行参数

    // 实例化顶层模块
    Vysyx_22050535_NPC *top = new Vysyx_22050535_NPC;

    // 波形生成器设置
    Verilated::traceEverOn(true);  // 启用波形跟踪
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // 设置跟踪深度
    tfp->open("wave.vcd");  // 打开波形文件

    // 初始化程序内存
    pmem[0] = 0x00100093; // addi x1, x0, 1
    pmem[1] = 0x00208113; // addi x2, x1, 2
    pmem[2] = 0x00100073; // ebreak

    // 仿真时钟和复位信号
    top->clk = 0;
    top->rst = 1;

    // 仿真过程
    uint64_t time = 0;  // 仿真时钟周期计数器
    const uint64_t MAX_TIME = 100;  // 最大仿真周期限制，防止死循环

    while (!Verilated::gotFinish() && time < MAX_TIME) {
        // 模拟时钟上升沿和下降沿
        if ((time % 2) == 0) {
            top->clk = !top->clk;  // 切换时钟信号
            if (top->clk) {  // 上升沿
                if (time == 2) {
                    top->rst = 0;  // 取消复位
                }
                // 每个周期从内存读取指令
                std::cout << "Time: " << time
                          << ", PC: 0x" << std::hex << top->pc
                          << ", Instruction: 0x" << pmem_read(top->pc) << std::endl;
                top->mem_inst = pmem_read(top->pc);
            }
        }

        top->eval();  // 评估模型
        tfp->dump(time);  // 写入波形

        time++;  // 仿真时间步进
    }

    // 检查是否达到最大时间限制
    if (time >= MAX_TIME) {
        std::cerr << "Simulation ended due to reaching maximum time steps."
                  << " PC: 0x" << std::hex << top->pc << std::endl;
    }

    // 清理资源
    tfp->close();
    delete tfp;
    delete top;
    return 0;
}
