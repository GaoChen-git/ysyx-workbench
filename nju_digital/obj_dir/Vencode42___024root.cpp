// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42___024root.h"
#include "Vencode42__Syms.h"

//==========

extern const VlUnpacked<CData/*1:0*/, 32> Vencode42__ConstPool__TABLE_d8639f1c_0;

VL_INLINE_OPT void Vencode42___024root___combo__TOP__1(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___combo__TOP__1\n"); );
    // Variables
    CData/*4:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->x) << 1U) | (IData)(vlSelf->en));
    vlSelf->y = Vencode42__ConstPool__TABLE_d8639f1c_0
        [__Vtableidx1];
}

void Vencode42___024root___eval(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval\n"); );
    // Body
    Vencode42___024root___combo__TOP__1(vlSelf);
}

QData Vencode42___024root___change_request_1(Vencode42___024root* vlSelf);

VL_INLINE_OPT QData Vencode42___024root___change_request(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___change_request\n"); );
    // Body
    return (Vencode42___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vencode42___024root___change_request_1(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vencode42___024root___eval_debug_assertions(Vencode42___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
