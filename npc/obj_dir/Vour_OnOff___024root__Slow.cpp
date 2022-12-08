// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vour_OnOff.h for the primary calling header

#include "Vour_OnOff___024root.h"
#include "Vour_OnOff__Syms.h"

//==========


void Vour_OnOff___024root___ctor_var_reset(Vour_OnOff___024root* vlSelf);

Vour_OnOff___024root::Vour_OnOff___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vour_OnOff___024root___ctor_var_reset(this);
}

void Vour_OnOff___024root::__Vconfigure(Vour_OnOff__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vour_OnOff___024root::~Vour_OnOff___024root() {
}

void Vour_OnOff___024root___eval_initial(Vour_OnOff___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour_OnOff__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour_OnOff___024root___eval_initial\n"); );
}

void Vour_OnOff___024root___combo__TOP__1(Vour_OnOff___024root* vlSelf);

void Vour_OnOff___024root___eval_settle(Vour_OnOff___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour_OnOff__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour_OnOff___024root___eval_settle\n"); );
    // Body
    Vour_OnOff___024root___combo__TOP__1(vlSelf);
}

void Vour_OnOff___024root___final(Vour_OnOff___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour_OnOff__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour_OnOff___024root___final\n"); );
}

void Vour_OnOff___024root___ctor_var_reset(Vour_OnOff___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour_OnOff__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour_OnOff___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->f = VL_RAND_RESET_I(1);
}
