// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22050535_NPC.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_22050535_NPC___024root.h"

VL_INLINE_OPT void Vysyx_22050535_NPC___024root___ico_sequent__TOP__0(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->ysyx_22050535_NPC__DOT__imm = ((0x6fU == 
                                            (0x7fU 
                                             & vlSelf->mem_inst))
                                            ? ((0x7ff00000U 
                                                & ((- (IData)(
                                                              (vlSelf->mem_inst 
                                                               >> 0x1fU))) 
                                                   << 0x14U)) 
                                               | ((0xff000U 
                                                   & vlSelf->mem_inst) 
                                                  | ((0x800U 
                                                      & (vlSelf->mem_inst 
                                                         >> 9U)) 
                                                     | (0x7feU 
                                                        & (vlSelf->mem_inst 
                                                           >> 0x14U)))))
                                            : ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->mem_inst))
                                                ? (
                                                   (0x7ffff000U 
                                                    & ((- (IData)(
                                                                  (vlSelf->mem_inst 
                                                                   >> 0x1fU))) 
                                                       << 0xcU)) 
                                                   | ((0x800U 
                                                       & (vlSelf->mem_inst 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlSelf->mem_inst 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlSelf->mem_inst 
                                                               >> 7U)))))
                                                : (
                                                   ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->mem_inst)) 
                                                    | ((3U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelf->mem_inst)) 
                                                       | (0x67U 
                                                          == 
                                                          (0x7fU 
                                                           & vlSelf->mem_inst))))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->mem_inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelf->mem_inst 
                                                       >> 0x14U))
                                                    : 0U)));
    vlSelf->ysyx_22050535_NPC__DOT__src1 = ((0U == 
                                             (0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs
                                            [(0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU))]);
    vlSelf->ysyx_22050535_NPC__DOT__src2 = ((0U == 
                                             (0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0x14U)))
                                             ? 0U : 
                                            vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs
                                            [(0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0x14U))]);
    vlSelf->ysyx_22050535_NPC__DOT__branch_taken = 0U;
    if ((0x13U != (0x7fU & vlSelf->mem_inst))) {
        if ((0x33U != (0x7fU & vlSelf->mem_inst))) {
            if ((0x63U == (0x7fU & vlSelf->mem_inst))) {
                if ((0x4000U & vlSelf->mem_inst)) {
                    vlSelf->ysyx_22050535_NPC__DOT__branch_taken 
                        = ((0x2000U & vlSelf->mem_inst)
                            ? ((0x1000U & vlSelf->mem_inst)
                                ? (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                   >= vlSelf->ysyx_22050535_NPC__DOT__src2)
                                : (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                   < vlSelf->ysyx_22050535_NPC__DOT__src2))
                            : ((0x1000U & vlSelf->mem_inst)
                                ? VL_GTES_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)
                                : VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)));
                } else if ((1U & (~ (vlSelf->mem_inst 
                                     >> 0xdU)))) {
                    vlSelf->ysyx_22050535_NPC__DOT__branch_taken 
                        = ((0x1000U & vlSelf->mem_inst)
                            ? (vlSelf->ysyx_22050535_NPC__DOT__src1 
                               != vlSelf->ysyx_22050535_NPC__DOT__src2)
                            : (vlSelf->ysyx_22050535_NPC__DOT__src1 
                               == vlSelf->ysyx_22050535_NPC__DOT__src2));
                }
            }
        }
    }
    if ((0x13U == (0x7fU & vlSelf->mem_inst))) {
        vlSelf->ysyx_22050535_NPC__DOT__result = ((0x4000U 
                                                   & vlSelf->mem_inst)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     & vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     | vlSelf->ysyx_22050535_NPC__DOT__imm))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 0U
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     ^ vlSelf->ysyx_22050535_NPC__DOT__imm)))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      < vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 0U
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     + vlSelf->ysyx_22050535_NPC__DOT__imm))));
    } else if ((0x33U == (0x7fU & vlSelf->mem_inst))) {
        vlSelf->ysyx_22050535_NPC__DOT__result = ((0x4000U 
                                                   & vlSelf->mem_inst)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     & vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     | vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((0x40000000U 
                                                      & vlSelf->mem_inst)
                                                      ? 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                      : 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->ysyx_22050535_NPC__DOT__src2)))
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     ^ vlSelf->ysyx_22050535_NPC__DOT__src2)))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      < vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                     : 
                                                    ((0x40000000U 
                                                      & vlSelf->mem_inst)
                                                      ? 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      - vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      : 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      + vlSelf->ysyx_22050535_NPC__DOT__src2)))));
    } else if ((0x63U == (0x7fU & vlSelf->mem_inst))) {
        if ((1U & (~ (vlSelf->mem_inst >> 0xeU)))) {
            if ((0x2000U & vlSelf->mem_inst)) {
                vlSelf->ysyx_22050535_NPC__DOT__result = 0U;
            }
        }
    } else {
        vlSelf->ysyx_22050535_NPC__DOT__result = 0U;
    }
}

void Vysyx_22050535_NPC___024root___eval_ico(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vysyx_22050535_NPC___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vysyx_22050535_NPC___024root___eval_act(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vysyx_22050535_NPC___024root___nba_sequent__TOP__0(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdlyvdim0__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvdim0__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvval__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvset__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 = 0;
    // Body
    __Vdlyvset__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 = 0U;
    vlSelf->pc = ((IData)(vlSelf->rst) ? 0x80000000U
                   : ((IData)(4U) + vlSelf->pc));
    if ((0U != (0xfU & (vlSelf->mem_inst >> 7U)))) {
        __Vdlyvval__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 
            = vlSelf->ysyx_22050535_NPC__DOT__result;
        __Vdlyvset__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 = 1U;
        __Vdlyvdim0__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0 
            = (0xfU & (vlSelf->mem_inst >> 7U));
    }
    if (__Vdlyvset__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0) {
        vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[__Vdlyvdim0__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0] 
            = __Vdlyvval__ysyx_22050535_NPC__DOT__regs_inst__DOT__regs__v0;
    }
    vlSelf->ysyx_22050535_NPC__DOT__src1 = ((0U == 
                                             (0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs
                                            [(0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0xfU))]);
    vlSelf->ysyx_22050535_NPC__DOT__src2 = ((0U == 
                                             (0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0x14U)))
                                             ? 0U : 
                                            vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs
                                            [(0xfU 
                                              & (vlSelf->mem_inst 
                                                 >> 0x14U))]);
    vlSelf->ysyx_22050535_NPC__DOT__branch_taken = 0U;
    if ((0x13U != (0x7fU & vlSelf->mem_inst))) {
        if ((0x33U != (0x7fU & vlSelf->mem_inst))) {
            if ((0x63U == (0x7fU & vlSelf->mem_inst))) {
                if ((0x4000U & vlSelf->mem_inst)) {
                    vlSelf->ysyx_22050535_NPC__DOT__branch_taken 
                        = ((0x2000U & vlSelf->mem_inst)
                            ? ((0x1000U & vlSelf->mem_inst)
                                ? (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                   >= vlSelf->ysyx_22050535_NPC__DOT__src2)
                                : (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                   < vlSelf->ysyx_22050535_NPC__DOT__src2))
                            : ((0x1000U & vlSelf->mem_inst)
                                ? VL_GTES_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)
                                : VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)));
                } else if ((1U & (~ (vlSelf->mem_inst 
                                     >> 0xdU)))) {
                    vlSelf->ysyx_22050535_NPC__DOT__branch_taken 
                        = ((0x1000U & vlSelf->mem_inst)
                            ? (vlSelf->ysyx_22050535_NPC__DOT__src1 
                               != vlSelf->ysyx_22050535_NPC__DOT__src2)
                            : (vlSelf->ysyx_22050535_NPC__DOT__src1 
                               == vlSelf->ysyx_22050535_NPC__DOT__src2));
                }
            }
        }
    }
}

VL_INLINE_OPT void Vysyx_22050535_NPC___024root___nba_sequent__TOP__1(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___nba_sequent__TOP__1\n"); );
    // Body
    if ((0x13U == (0x7fU & vlSelf->mem_inst))) {
        vlSelf->ysyx_22050535_NPC__DOT__result = ((0x4000U 
                                                   & vlSelf->mem_inst)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     & vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     | vlSelf->ysyx_22050535_NPC__DOT__imm))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 0U
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     ^ vlSelf->ysyx_22050535_NPC__DOT__imm)))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      < vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__imm)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 0U
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     + vlSelf->ysyx_22050535_NPC__DOT__imm))));
    } else if ((0x33U == (0x7fU & vlSelf->mem_inst))) {
        vlSelf->ysyx_22050535_NPC__DOT__result = ((0x4000U 
                                                   & vlSelf->mem_inst)
                                                   ? 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     & vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     | vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((0x40000000U 
                                                      & vlSelf->mem_inst)
                                                      ? 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                      : 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelf->ysyx_22050535_NPC__DOT__src2)))
                                                     : 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     ^ vlSelf->ysyx_22050535_NPC__DOT__src2)))
                                                   : 
                                                  ((0x2000U 
                                                    & vlSelf->mem_inst)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    ((vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      < vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelf->ysyx_22050535_NPC__DOT__src1, vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      ? 1U
                                                      : 0U))
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->mem_inst)
                                                     ? 
                                                    (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelf->ysyx_22050535_NPC__DOT__src2))
                                                     : 
                                                    ((0x40000000U 
                                                      & vlSelf->mem_inst)
                                                      ? 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      - vlSelf->ysyx_22050535_NPC__DOT__src2)
                                                      : 
                                                     (vlSelf->ysyx_22050535_NPC__DOT__src1 
                                                      + vlSelf->ysyx_22050535_NPC__DOT__src2)))));
    } else if ((0x63U == (0x7fU & vlSelf->mem_inst))) {
        if ((1U & (~ (vlSelf->mem_inst >> 0xeU)))) {
            if ((0x2000U & vlSelf->mem_inst)) {
                vlSelf->ysyx_22050535_NPC__DOT__result = 0U;
            }
        }
    } else {
        vlSelf->ysyx_22050535_NPC__DOT__result = 0U;
    }
}

void Vysyx_22050535_NPC___024root___eval_nba(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_22050535_NPC___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        Vysyx_22050535_NPC___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vysyx_22050535_NPC___024root___eval_triggers__ico(Vysyx_22050535_NPC___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22050535_NPC___024root___dump_triggers__ico(Vysyx_22050535_NPC___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_22050535_NPC___024root___eval_triggers__act(Vysyx_22050535_NPC___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22050535_NPC___024root___dump_triggers__act(Vysyx_22050535_NPC___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22050535_NPC___024root___dump_triggers__nba(Vysyx_22050535_NPC___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_22050535_NPC___024root___eval(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vysyx_22050535_NPC___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vysyx_22050535_NPC___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_22050535_NPC.v", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vysyx_22050535_NPC___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_22050535_NPC___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_22050535_NPC___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/ysyx_22050535_NPC.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_22050535_NPC___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_22050535_NPC___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_22050535_NPC.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_22050535_NPC___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_22050535_NPC___024root___eval_debug_assertions(Vysyx_22050535_NPC___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
