all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Building Verilator simulation..."
	verilator -Wall --cc --exe --build ./csrc/main.cpp ./vsrc/our_OnOff.v
	@echo "Compiling simulation..."
	make -C obj_dir -f Vour_OnOff.mk Vour_OnOff
	@echo "Running simulation..."
	./obj_dir/Vour_OnOff

clean:
	rm -rf obj_dir
	@echo "Cleaned up build files."

include ../Makefile
