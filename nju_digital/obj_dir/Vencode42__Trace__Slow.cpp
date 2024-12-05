// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode42__Syms.h"


void Vencode42___024root__traceInitSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencode42___024root__traceInitTop(Vencode42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencode42___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vencode42___024root__traceInitSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"x", false,-1, 3,0);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBus(c+3,"y", false,-1, 1,0);
        tracep->declBus(c+1,"encode42 x", false,-1, 3,0);
        tracep->declBit(c+2,"encode42 en", false,-1);
        tracep->declBus(c+3,"encode42 y", false,-1, 1,0);
    }
}

void Vencode42___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vencode42___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vencode42___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vencode42___024root__traceRegister(Vencode42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vencode42___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vencode42___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vencode42___024root__traceCleanup, vlSelf);
    }
}

void Vencode42___024root__traceFullSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vencode42___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vencode42___024root* const __restrict vlSelf = static_cast<Vencode42___024root*>(voidSelf);
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vencode42___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vencode42___024root__traceFullSub0(Vencode42___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlSelf->x),4);
        tracep->fullBit(oldp+2,(vlSelf->en));
        tracep->fullCData(oldp+3,(vlSelf->y),2);
    }
}
