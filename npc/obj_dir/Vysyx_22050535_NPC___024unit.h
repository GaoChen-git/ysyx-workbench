// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_22050535_NPC.h for the primary calling header

#ifndef VERILATED_VYSYX_22050535_NPC___024UNIT_H_
#define VERILATED_VYSYX_22050535_NPC___024UNIT_H_  // guard

#include "verilated.h"

class Vysyx_22050535_NPC__Syms;

class Vysyx_22050535_NPC___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vysyx_22050535_NPC__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_22050535_NPC___024unit(Vysyx_22050535_NPC__Syms* symsp, const char* v__name);
    ~Vysyx_22050535_NPC___024unit();
    VL_UNCOPYABLE(Vysyx_22050535_NPC___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
