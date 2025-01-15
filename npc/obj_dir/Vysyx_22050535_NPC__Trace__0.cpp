// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_22050535_NPC__Syms.h"


void Vysyx_22050535_NPC___024root__trace_chg_sub_0(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_22050535_NPC___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_22050535_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_22050535_NPC___024root*>(voidSelf);
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_22050535_NPC___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_22050535_NPC___024root__trace_chg_sub_0(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[15]),32);
    }
    bufp->chgBit(oldp+16,(vlSelf->clk));
    bufp->chgBit(oldp+17,(vlSelf->rst));
    bufp->chgIData(oldp+18,(vlSelf->mem_inst),32);
    bufp->chgIData(oldp+19,(vlSelf->pc),32);
    bufp->chgIData(oldp+20,(vlSelf->ysyx_22050535_NPC__DOT__src1),32);
    bufp->chgIData(oldp+21,(vlSelf->ysyx_22050535_NPC__DOT__src2),32);
    bufp->chgIData(oldp+22,(vlSelf->ysyx_22050535_NPC__DOT__result),32);
    bufp->chgIData(oldp+23,(vlSelf->ysyx_22050535_NPC__DOT__imm),32);
    bufp->chgCData(oldp+24,((0x1fU & (vlSelf->mem_inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+25,((0x1fU & (vlSelf->mem_inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+26,((0x1fU & (vlSelf->mem_inst 
                                      >> 7U))),5);
    bufp->chgBit(oldp+27,(vlSelf->ysyx_22050535_NPC__DOT__branch_taken));
    bufp->chgCData(oldp+28,((0x7fU & vlSelf->mem_inst)),7);
    bufp->chgCData(oldp+29,((7U & (vlSelf->mem_inst 
                                   >> 0xcU))),3);
    bufp->chgCData(oldp+30,((vlSelf->mem_inst >> 0x19U)),7);
    bufp->chgIData(oldp+31,((0x1fU & (vlSelf->mem_inst 
                                      >> 7U))),32);
    bufp->chgIData(oldp+32,((0x1fU & (vlSelf->mem_inst 
                                      >> 0xfU))),32);
    bufp->chgIData(oldp+33,((0x1fU & (vlSelf->mem_inst 
                                      >> 0x14U))),32);
}

void Vysyx_22050535_NPC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_cleanup\n"); );
    // Init
    Vysyx_22050535_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_22050535_NPC___024root*>(voidSelf);
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
