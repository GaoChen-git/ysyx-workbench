// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vour_OnOff.h"
#include "Vour_OnOff__Syms.h"

//============================================================
// Constructors

Vour_OnOff::Vour_OnOff(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vour_OnOff__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
}

Vour_OnOff::Vour_OnOff(const char* _vcname__)
    : Vour_OnOff(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vour_OnOff::~Vour_OnOff() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vour_OnOff___024root___eval_initial(Vour_OnOff___024root* vlSelf);
void Vour_OnOff___024root___eval_settle(Vour_OnOff___024root* vlSelf);
void Vour_OnOff___024root___eval(Vour_OnOff___024root* vlSelf);
QData Vour_OnOff___024root___change_request(Vour_OnOff___024root* vlSelf);
#ifdef VL_DEBUG
void Vour_OnOff___024root___eval_debug_assertions(Vour_OnOff___024root* vlSelf);
#endif  // VL_DEBUG
void Vour_OnOff___024root___final(Vour_OnOff___024root* vlSelf);

static void _eval_initial_loop(Vour_OnOff__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vour_OnOff___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vour_OnOff___024root___eval_settle(&(vlSymsp->TOP));
        Vour_OnOff___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vour_OnOff___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/our_OnOff.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vour_OnOff___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vour_OnOff::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vour_OnOff::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vour_OnOff___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vour_OnOff___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vour_OnOff___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/our_OnOff.v", 2, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vour_OnOff___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vour_OnOff::final() {
    Vour_OnOff___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vour_OnOff::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vour_OnOff::name() const {
    return vlSymsp->name();
}
