// 在宏定义的标识符前添加学号前缀ysyx_22050535_xx
// 如`define SIZE 5需要修改为`define ysyx_22050535_SIZE 5
// 全局宏定义文件

`define ysyx_22050535_RESET_VAL 32'h80000000    // PC复位值
`define ysyx_22050535_INST_WIDTH 32             // 指令宽度
`define ysyx_22050535_ADDR_WIDTH 32             // 地址宽度
`define ysyx_22050535_DATA_WIDTH 32             // 数据宽度
`define ysyx_22050535_REG_NUM 16                // RV32E 使用16个寄存器

// `define ysyx_22050535_REG_NUM 32                // RV32I寄存器数量
