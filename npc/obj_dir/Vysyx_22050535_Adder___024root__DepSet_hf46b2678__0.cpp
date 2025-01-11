// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22050535_Adder.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_22050535_Adder__Syms.h"
#include "Vysyx_22050535_Adder___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22050535_Adder___024root___dump_triggers__ico(Vysyx_22050535_Adder___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_22050535_Adder___024root___eval_triggers__ico(Vysyx_22050535_Adder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_22050535_Adder___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vysyx_22050535_Adder___024unit____Vdpiimwrap_sim_end_TOP____024unit();

VL_INLINE_OPT void Vysyx_22050535_Adder___024root___ico_sequent__TOP__0(Vysyx_22050535_Adder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0x100073U == vlSelf->mem_inst)) {
        Vysyx_22050535_Adder___024unit____Vdpiimwrap_sim_end_TOP____024unit();
    }
    vlSelf->ysyx_22050535_NPC__DOT__src1 = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU))]);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22050535_Adder___024root___dump_triggers__act(Vysyx_22050535_Adder___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_22050535_Adder___024root___eval_triggers__act(Vysyx_22050535_Adder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_22050535_Adder___024root___dump_triggers__act(vlSelf);
    }
#endif
}
