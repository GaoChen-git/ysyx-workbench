// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vencode42__Syms.h"
#include "Vencode42.h"
#include "Vencode42___024root.h"

// FUNCTIONS
Vencode42__Syms::~Vencode42__Syms()
{
}

<<<<<<< HEAD:npc/obj_dir/Vour_OnOff__Syms.cpp
Vour_OnOff__Syms::Vour_OnOff__Syms(VerilatedContext* contextp, const char* namep, Vour_OnOff* modelp)
=======
Vencode42__Syms::Vencode42__Syms(VerilatedContext* contextp, const char* namep,Vencode42* modelp)
>>>>>>> PA0:nju_digital/obj_dir/Vencode42__Syms.cpp
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
