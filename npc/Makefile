# Verilog 文件路径
VFILE_PATH = ./vsrc/

# 自动扫描 vsrc 目录下的所有 .v 文件
VFILES = $(wildcard $(VFILE_PATH)*.v)

# 仿真测试文件路径
CSRC = ./csrc/npc_tb.cpp

# 顶层模块名称
TOP_MODULE = Vysyx_22050535_NPC

all:
	@echo "Write this Makefile by your self."

# 仿真目标
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Building Verilator simulation with files from $(VFILE_PATH)..."
	verilator -Wall --cc --exe --build $(CSRC) $(VFILES) --trace
	@echo "Compiling simulation..."
	make -C obj_dir -f $(TOP_MODULE).mk $(TOP_MODULE)
	@echo "Running simulation..."
	./obj_dir/$(TOP_MODULE)

# 清理生成的文件
clean:
	rm -rf obj_dir wave.vcd
	@echo "Cleaned up build files."

include ../Makefile
