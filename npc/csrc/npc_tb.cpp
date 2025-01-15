#include <verilated.h>
#include <verilated_vcd_c.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdint>
#include "Vysyx_22050535_NPC.h"  // Verilator 自动生成的顶层模块头文件

// 定义内存空间（模拟存储器）
uint32_t pmem[0x8000000 / 4];  // 模拟128MB的存储空间（物理内存）
int ebreak_end = 0;

// 模拟存储器的读取函数
extern "C" int pmem_read(int raddr) {
    uint32_t addr = static_cast<uint32_t>(raddr & ~0x3u);  // 地址对齐到4字节
    if (addr < 0x80000000 || addr >= 0x80000000 + sizeof(pmem) * 4) {
        std::cerr << "Error: Memory access out of bounds at address: 0x"
                  << std::hex << addr << std::endl;
        exit(EXIT_FAILURE);
    }
    return pmem[(addr - 0x80000000) / 4];
}

// 模拟存储器的写入函数
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t addr = static_cast<uint32_t>(waddr & ~0x3u);  // 地址对齐到4字节
    if (addr < 0x80000000 || addr >= 0x80000000 + sizeof(pmem) * 4) {
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
    ebreak_end = 1;
}

// 加载镜像文件到模拟内存
void load_img(const char *img_file) {
    std::ifstream file(img_file, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open image file: " << img_file << std::endl;
        exit(EXIT_FAILURE);
    }

    std::streamsize size = file.tellg();  // 获取文件大小
    file.seekg(0, std::ios::beg);

    if (size > sizeof(pmem)) {
        std::cerr << "Error: Image size exceeds pmem capacity." << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!file.read(reinterpret_cast<char *>(pmem), size)) {  // 加载到 pmem
        std::cerr << "Error: Failed to read image file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Loaded image: " << img_file << ", size: " << size << " bytes." << std::endl;
}

// 主函数
int main(int argc, char **argv) {
    const char *default_img = "/home/gaochen/ysyx-workbench/am-kernels/tests/cpu-tests/build/add-riscv32e-nemu.bin";
    const char *img_file = nullptr;

    // 检查命令行参数
    if (argc < 2) {
        std::cout << "No image file provided. Using default image: " << default_img << std::endl;
        img_file = default_img;
    } else {
        img_file = argv[1];
    }

    // 加载镜像文件
    load_img(img_file);

    Verilated::commandArgs(argc, argv);  // 解析命令行参数

    // 实例化顶层模块
    Vysyx_22050535_NPC *top = new Vysyx_22050535_NPC;

    // 波形生成器设置
    Verilated::traceEverOn(true);  // 启用波形跟踪
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // 设置跟踪深度
    tfp->open("wave.vcd");  // 打开波形文件

    // 仿真时钟和复位信号
    top->clk = 0;
    top->rst = 1;

    uint64_t time = 0;  // 仿真时钟周期计数器
    const uint64_t MAX_TIME = 1000;  // 最大仿真周期限制

    while (!Verilated::gotFinish() && time < MAX_TIME && !ebreak_end) {
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
