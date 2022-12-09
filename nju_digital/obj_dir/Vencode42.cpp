// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vencode42.h"
#include "Vencode42__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vencode42::Vencode42(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vencode42__Syms(_vcontextp__, _vcname__, this)}
    , x{vlSymsp->TOP.x}
    , en{vlSymsp->TOP.en}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vencode42::Vencode42(const char* _vcname__)
    : Vencode42(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vencode42::~Vencode42() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vencode42___024root___eval_initial(Vencode42___024root* vlSelf);
void Vencode42___024root___eval_settle(Vencode42___024root* vlSelf);
void Vencode42___024root___eval(Vencode42___024root* vlSelf);
QData Vencode42___024root___change_request(Vencode42___024root* vlSelf);
#ifdef VL_DEBUG
void Vencode42___024root___eval_debug_assertions(Vencode42___024root* vlSelf);
#endif  // VL_DEBUG
void Vencode42___024root___final(Vencode42___024root* vlSelf);

static void _eval_initial_loop(Vencode42__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vencode42___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vencode42___024root___eval_settle(&(vlSymsp->TOP));
        Vencode42___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vencode42___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/encode42.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vencode42___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vencode42::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vencode42::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vencode42___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vencode42___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vencode42___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vsrc/encode42.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vencode42___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vencode42::final() {
    Vencode42___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vencode42::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vencode42::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vencode42___024root__traceInitTop(Vencode42___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vencode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode42___024root*>(voidSelf);
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vencode42___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vencode42___024root__traceRegister(Vencode42___024root* vlSelf, VerilatedVcd* tracep);

void Vencode42::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vencode42___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
