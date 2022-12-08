all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --exe --build ./csrc/main.cpp ./vsrc/our_OnOff.v
clean:
	rm -rf obj_dir
include ../Makefile
