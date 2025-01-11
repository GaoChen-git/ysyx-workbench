// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_22050535_Adder__Syms.h"


VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_init_sub__TOP__0(Vysyx_22050535_Adder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+35,"mem_inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_22050535_NPC ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+35,"mem_inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+37,"src1", false,-1, 31,0);
    tracep->declBus(c+38,"result", false,-1, 31,0);
    tracep->declBus(c+39,"rs1", false,-1, 4,0);
    tracep->declBus(c+40,"rd", false,-1, 4,0);
    tracep->declBus(c+41,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("ebreak_inst ");
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu_inst ");
    tracep->declBus(c+37,"src1", false,-1, 31,0);
    tracep->declBus(c+41,"imm", false,-1, 31,0);
    tracep->declBus(c+38,"result", false,-1, 31,0);
    tracep->pushNamePrefix("adder ");
    tracep->declBus(c+37,"op1", false,-1, 31,0);
    tracep->declBus(c+41,"op2", false,-1, 31,0);
    tracep->declBus(c+38,"result", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu_inst ");
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+39,"rs1", false,-1, 4,0);
    tracep->declBus(c+40,"rd", false,-1, 4,0);
    tracep->declBus(c+41,"imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu_inst ");
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+35,"mem_inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_inst ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBit(c+34,"rst", false,-1);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf_inst ");
    tracep->declBit(c+33,"clk", false,-1);
    tracep->declBus(c+38,"wdata", false,-1, 31,0);
    tracep->declBus(c+42,"waddr", false,-1, 31,0);
    tracep->declBus(c+43,"raddr1", false,-1, 31,0);
    tracep->declBus(c+44,"raddr2", false,-1, 31,0);
    tracep->declBit(c+45,"wen", false,-1);
    tracep->declBus(c+37,"rdata1", false,-1, 31,0);
    tracep->declBus(c+44,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_init_top(Vysyx_22050535_Adder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root__trace_init_top\n"); );
    // Body
    Vysyx_22050535_Adder___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_22050535_Adder___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_22050535_Adder___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_register(Vysyx_22050535_Adder___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_22050535_Adder___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_22050535_Adder___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_22050535_Adder___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_full_sub_0(Vysyx_22050535_Adder___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_22050535_Adder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_22050535_Adder___024root*>(voidSelf);
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_22050535_Adder___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_22050535_Adder___024root__trace_full_sub_0(Vysyx_22050535_Adder___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_Adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_Adder___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf[31]),32);
    bufp->fullBit(oldp+33,(vlSelf->clk));
    bufp->fullBit(oldp+34,(vlSelf->rst));
    bufp->fullIData(oldp+35,(vlSelf->mem_inst),32);
    bufp->fullIData(oldp+36,(vlSelf->pc),32);
    bufp->fullIData(oldp+37,(((0U == (0x1fU & (vlSelf->mem_inst 
                                               >> 0xfU)))
                               ? 0U : vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf
                              [(0x1fU & (vlSelf->mem_inst 
                                         >> 0xfU))])),32);
    bufp->fullIData(oldp+38,((((0U == (0x1fU & (vlSelf->mem_inst 
                                                >> 0xfU)))
                                ? 0U : vlSelf->ysyx_22050535_NPC__DOT__rf_inst__DOT__rf
                               [(0x1fU & (vlSelf->mem_inst 
                                          >> 0xfU))]) 
                              + (((- (IData)((vlSelf->mem_inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | (vlSelf->mem_inst 
                                              >> 0x14U)))),32);
    bufp->fullCData(oldp+39,((0x1fU & (vlSelf->mem_inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+40,((0x1fU & (vlSelf->mem_inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+41,((((- (IData)((vlSelf->mem_inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->mem_inst 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+42,((0x1fU & (vlSelf->mem_inst 
                                       >> 7U))),32);
    bufp->fullIData(oldp+43,((0x1fU & (vlSelf->mem_inst 
                                       >> 0xfU))),32);
    bufp->fullIData(oldp+44,(0U),32);
    bufp->fullBit(oldp+45,(1U));
}
