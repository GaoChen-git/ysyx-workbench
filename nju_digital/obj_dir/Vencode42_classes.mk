# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vencode42.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff_classes.mk
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
=======
VM_TRACE = 1
>>>>>>> PA0:nju_digital/obj_dir/Vencode42_classes.mk
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff_classes.mk
	Vour_OnOff \
	Vour_OnOff___024root__DepSet_he4849518__0 \
	Vour_OnOff___024root__DepSet_hd6714a0a__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vour_OnOff___024root__Slow \
	Vour_OnOff___024root__DepSet_he4849518__0__Slow \
	Vour_OnOff___024root__DepSet_hd6714a0a__0__Slow \
=======
	Vencode42 \
	Vencode42___024root \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vencode42__ConstPool_0 \
	Vencode42___024root__Slow \
>>>>>>> PA0:nju_digital/obj_dir/Vencode42_classes.mk

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vencode42__Trace \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vencode42__Syms \
	Vencode42__Trace__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff_classes.mk
	verilated_threads \
=======
	verilated_vcd_c \
>>>>>>> PA0:nju_digital/obj_dir/Vencode42_classes.mk

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
