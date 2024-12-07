# 默认 Verilog 文件路径
VFILE_PATH = ./vsrc/

# 默认文件名
VFILE = $(VFILE_PATH)our_OnOff.v

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Building Verilator simulation with file: $(VFILE)..."
	verilator -Wall --cc --exe --build ./csrc/main.cpp $(VFILE)
	@echo "Compiling simulation..."
	make -C obj_dir -f V$(basename $(notdir $(VFILE))).mk V$(basename $(notdir $(VFILE)))
	@echo "Running simulation..."
	./obj_dir/V$(basename $(notdir $(VFILE)))

clean:
	rm -rf obj_dir
	@echo "Cleaned up build files."

# 如果传入参数覆盖默认值
VFILE_OVERRIDE = $(word 2, $(MAKECMDGOALS))

# 如果传入文件名，修改 VFILE 为指定的文件路径
ifneq ($(VFILE_OVERRIDE),)
	VFILE = $(VFILE_PATH)$(VFILE_OVERRIDE)
endif

include ../Makefile
