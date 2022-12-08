// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vour_OnOff.h for the primary calling header

#ifndef VERILATED_VOUR_ONOFF___024ROOT_H_
#define VERILATED_VOUR_ONOFF___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vour_OnOff__Syms;

//----------

VL_MODULE(Vour_OnOff___024root) {
  public:

    // PORTS
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(f,0,0);

    // INTERNAL VARIABLES
    Vour_OnOff__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vour_OnOff___024root);  ///< Copying not allowed
  public:
    Vour_OnOff___024root(const char* name);
    ~Vour_OnOff___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vour_OnOff__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
