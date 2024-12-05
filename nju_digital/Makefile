all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --exe --build --trace ./csrc/encode42_main.cpp ./vsrc/encode42.v
clean:
	rm -rf obj_dir *.vcd

include ../Makefile
