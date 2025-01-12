#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "Vysyx_22050535_NPC.h"  // Verilator 自动生成的顶层模块头文件

// 定义内存空间（模拟存储器）
uint32_t pmem[256];  // 模拟256个字的存储空间

// 模拟存储器的读取函数
extern "C" int pmem_read(int raddr) {
    uint32_t addr = static_cast<uint32_t>(raddr & ~0x3u);  // 地址对齐到4字节
    if (addr < 0x80000000 || addr >= 0x80000000 + 4 * (sizeof(pmem) / sizeof(uint32_t))) {
        std::cerr << "Error: Memory access out of bounds at address: 0x"
                  << std::hex << addr << std::endl;
        exit(EXIT_FAILURE);
    }
    return pmem[(addr - 0x80000000) / 4];
}

// 模拟存储器的写入函数
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t addr = static_cast<uint32_t>(waddr & ~0x3u);  // 地址对齐到4字节
    if (addr < 0x80000000 || addr >= 0x80000000 + 4 * (sizeof(pmem) / sizeof(uint32_t))) {
        std::cerr << "Error: Memory access out of bounds at address: 0x"
                  << std::hex << addr << std::endl;
        exit(EXIT_FAILURE);
    }

    uint32_t index = (addr - 0x80000000) / 4;
    uint32_t mask = static_cast<uint32_t>(wmask);
    for (int i = 0; i < 4; i++) {  // 每个字节掩码
        if (mask & (1 << i)) {
            uint8_t byte = static_cast<uint8_t>((wdata >> (i * 8)) & 0xFF);
            reinterpret_cast<uint8_t *>(&pmem[index])[i] = byte;
        }
    }
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

    // 初始化程序内存，测试指令为RV32E指令集的典型示例
    pmem[0] = 0x00100093; // addi x1, x0, 1  (x1 = 1)
    pmem[1] = 0x00208113; // addi x2, x1, 2  (x2 = x1 + 2)
    pmem[2] = 0x002082B3; // add x5, x1, x2  (x5 = x1 + x2)
    pmem[3] = 0x4040A293; // sub x5, x1, x2  (x5 = x1 - x2)
    pmem[4] = 0x00A0A313; // andi x6, x1, 10 (x6 = x1 & 10)
    pmem[5] = 0x00A0B393; // ori x7, x1, 10  (x7 = x1 | 10)
    pmem[6] = 0x00100073; // ebreak          (结束仿真)

    // 仿真时钟和复位信号
    top->clk = 0;
    top->rst = 1;

    uint64_t time = 0;  // 仿真时钟周期计数器
    const uint64_t MAX_TIME = 100;  // 最大仿真周期限制

    while (!Verilated::gotFinish() && time < MAX_TIME) {
        top->clk = !top->clk;   // 产生时钟信号

        if (time > 10) {  // 假设第10个时间周期后开始仿真
            if (top->clk) {  // 上升沿触发
                if (time == 12) {
                    top->rst = 0;  // 复位信号停止复位
                }
                if (time >= 12) {
                    // 每个周期从存储器读取指令
                    top->mem_inst = pmem_read(top->pc);
                    std::cout << "Time: " << time
                              << ", PC: 0x" << std::hex << top->pc
                              << ", Instruction: 0x" << pmem_read(top->pc) << std::endl;
                }
            }
        }

        top->eval();  // 评估模型
        tfp->dump(time);  // 写入波形

        time++;  // 仿真时间步进
    }

    // 检查是否达到最大时间限制
    if (time >= MAX_TIME) {
        std::cerr << "Simulation ended due to reaching maximum time steps. PC: 0x"
                  << std::hex << top->pc << std::endl;
    }

    // 清理资源
    tfp->close();
    delete tfp;
    delete top;
    return 0;
}
