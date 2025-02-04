// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VENCODE42__SYMS_H_
#define VERILATED_VENCODE42__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vencode42.h"

// INCLUDE MODULE CLASSES
#include "Vencode42___024root.h"

// SYMS CLASS (contains all model state)
class Vencode42__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff__Syms.h
    Vour_OnOff* const __Vm_modelp;
    VlDeleter __Vm_deleter;
=======
    Vencode42* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
>>>>>>> PA0:nju_digital/obj_dir/Vencode42__Syms.h
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vencode42___024root            TOP;

    // CONSTRUCTORS
    Vencode42__Syms(VerilatedContext* contextp, const char* namep, Vencode42* modelp);
    ~Vencode42__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
