// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42___024root.h"
#include "Vencode42__Syms.h"

//==========


void Vencode42___024root___ctor_var_reset(Vencode42___024root* vlSelf);

Vencode42___024root::Vencode42___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vencode42___024root___ctor_var_reset(this);
}

void Vencode42___024root::__Vconfigure(Vencode42__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vencode42___024root::~Vencode42___024root() {
}

void Vencode42___024root___eval_initial(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_initial\n"); );
}

void Vencode42___024root___combo__TOP__1(Vencode42___024root* vlSelf);

void Vencode42___024root___eval_settle(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_settle\n"); );
    // Body
    Vencode42___024root___combo__TOP__1(vlSelf);
}

void Vencode42___024root___final(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___final\n"); );
}

void Vencode42___024root___ctor_var_reset(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = VL_RAND_RESET_I(4);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->y = VL_RAND_RESET_I(2);
}
