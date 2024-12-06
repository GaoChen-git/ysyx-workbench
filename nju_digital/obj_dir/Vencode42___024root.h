// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode42.h for the primary calling header

#ifndef VERILATED_VENCODE42___024ROOT_H_
#define VERILATED_VENCODE42___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vencode42__Syms;
class Vencode42_VerilatedVcd;


//----------

VL_MODULE(Vencode42___024root) {
  public:

    // PORTS
    VL_IN8(x,3,0);
    VL_IN8(en,0,0);
    VL_OUT8(y,1,0);

    // INTERNAL VARIABLES
    Vencode42__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vencode42___024root);  ///< Copying not allowed
  public:
    Vencode42___024root(const char* name);
    ~Vencode42___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vencode42__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
