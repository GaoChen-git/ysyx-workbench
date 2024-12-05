// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode42__Syms.h"


void Vencode42___024root__traceChgSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep);

void Vencode42___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencode42___024root* const __restrict vlSelf = static_cast<Vencode42___024root*>(voidSelf);
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vencode42___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencode42___024root__traceChgSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlSelf->x),4);
        tracep->chgBit(oldp+1,(vlSelf->en));
        tracep->chgCData(oldp+2,(vlSelf->y),2);
    }
}

void Vencode42___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vencode42___024root* const __restrict vlSelf = static_cast<Vencode42___024root*>(voidSelf);
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
