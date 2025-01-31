// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VENCODE42_H_
#define VERILATED_VENCODE42_H_  // guard

#include "verilated.h"

class Vencode42__Syms;
class Vencode42___024root;
class VerilatedVcdC;
class Vencode42_VerilatedVcd;


// This class is the main interface to the Verilated model
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff.h
class Vour_OnOff VL_NOT_FINAL : public VerilatedModel {
=======
class Vencode42 VL_NOT_FINAL {
>>>>>>> PA0:nju_digital/obj_dir/Vencode42.h
  private:
    // Symbol table holding complete model state (owned by this class)
    Vencode42__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&x,3,0);
    VL_IN8(&en,0,0);
    VL_OUT8(&y,1,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vencode42___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vencode42(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vencode42(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vencode42();
  private:
    VL_UNCOPYABLE(Vencode42);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
<<<<<<< HEAD:npc/obj_dir/Vour_OnOff.h
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
=======
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp() const;
>>>>>>> PA0:nju_digital/obj_dir/Vencode42.h
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
