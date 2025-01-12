// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_22050535_NPC.h for the primary calling header

#ifndef VERILATED_VYSYX_22050535_NPC___024ROOT_H_
#define VERILATED_VYSYX_22050535_NPC___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_22050535_NPC__Syms;
class Vysyx_22050535_NPC___024unit;


class Vysyx_22050535_NPC___024root final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_22050535_NPC___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_22050535_NPC__DOT__branch_taken;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(mem_inst,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ ysyx_22050535_NPC__DOT__src1;
    IData/*31:0*/ ysyx_22050535_NPC__DOT__src2;
    IData/*31:0*/ ysyx_22050535_NPC__DOT__result;
    IData/*31:0*/ ysyx_22050535_NPC__DOT__imm;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 16> ysyx_22050535_NPC__DOT__regs_inst__DOT__regs;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_22050535_NPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_22050535_NPC___024root(Vysyx_22050535_NPC__Syms* symsp, const char* v__name);
    ~Vysyx_22050535_NPC___024root();
    VL_UNCOPYABLE(Vysyx_22050535_NPC___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
