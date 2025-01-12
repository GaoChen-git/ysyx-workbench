// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_22050535_NPC__Syms.h"


VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_init_sub__TOP__0(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declBus(c+19,"mem_inst", false,-1, 31,0);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_22050535_NPC ");
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declBus(c+19,"mem_inst", false,-1, 31,0);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBus(c+21,"src1", false,-1, 31,0);
    tracep->declBus(c+22,"src2", false,-1, 31,0);
    tracep->declBus(c+23,"result", false,-1, 31,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+25,"rs1", false,-1, 3,0);
    tracep->declBus(c+26,"rs2", false,-1, 3,0);
    tracep->declBus(c+27,"rd", false,-1, 3,0);
    tracep->declBit(c+28,"branch_taken", false,-1);
    tracep->declBus(c+29,"opcode", false,-1, 6,0);
    tracep->declBus(c+30,"func3", false,-1, 2,0);
    tracep->declBus(c+31,"func7", false,-1, 6,0);
    tracep->pushNamePrefix("exu_inst ");
    tracep->declBus(c+21,"src1", false,-1, 31,0);
    tracep->declBus(c+22,"src2", false,-1, 31,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+29,"opcode", false,-1, 6,0);
    tracep->declBus(c+30,"func3", false,-1, 2,0);
    tracep->declBus(c+31,"func7", false,-1, 6,0);
    tracep->declBus(c+23,"result", false,-1, 31,0);
    tracep->declBit(c+28,"branch_taken", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu_inst ");
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBus(c+25,"rs1", false,-1, 3,0);
    tracep->declBus(c+26,"rs2", false,-1, 3,0);
    tracep->declBus(c+27,"rd", false,-1, 3,0);
    tracep->declBus(c+24,"imm", false,-1, 31,0);
    tracep->declBus(c+29,"opcode", false,-1, 6,0);
    tracep->declBus(c+30,"func3", false,-1, 2,0);
    tracep->declBus(c+31,"func7", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu_inst ");
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->declBus(c+19,"inst", false,-1, 31,0);
    tracep->declBus(c+19,"mem_inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_inst ");
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declBus(c+20,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regs_inst ");
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBus(c+23,"wdata", false,-1, 31,0);
    tracep->declBus(c+32,"waddr", false,-1, 31,0);
    tracep->declBus(c+33,"raddr1", false,-1, 31,0);
    tracep->declBus(c+34,"raddr2", false,-1, 31,0);
    tracep->declBit(c+35,"wen", false,-1);
    tracep->declBus(c+21,"rdata1", false,-1, 31,0);
    tracep->declBus(c+22,"rdata2", false,-1, 31,0);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+1+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_init_top(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_init_top\n"); );
    // Body
    Vysyx_22050535_NPC___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_22050535_NPC___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_22050535_NPC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_register(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_22050535_NPC___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_22050535_NPC___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_22050535_NPC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_full_sub_0(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_22050535_NPC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_22050535_NPC___024root*>(voidSelf);
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_22050535_NPC___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_22050535_NPC___024root__trace_full_sub_0(Vysyx_22050535_NPC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22050535_NPC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22050535_NPC___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_22050535_NPC__DOT__regs_inst__DOT__regs[15]),32);
    bufp->fullBit(oldp+17,(vlSelf->clk));
    bufp->fullBit(oldp+18,(vlSelf->rst));
    bufp->fullIData(oldp+19,(vlSelf->mem_inst),32);
    bufp->fullIData(oldp+20,(vlSelf->pc),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_22050535_NPC__DOT__src1),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_22050535_NPC__DOT__src2),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_22050535_NPC__DOT__result),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_22050535_NPC__DOT__imm),32);
    bufp->fullCData(oldp+25,((0xfU & (vlSelf->mem_inst 
                                      >> 0xfU))),4);
    bufp->fullCData(oldp+26,((0xfU & (vlSelf->mem_inst 
                                      >> 0x14U))),4);
    bufp->fullCData(oldp+27,((0xfU & (vlSelf->mem_inst 
                                      >> 7U))),4);
    bufp->fullBit(oldp+28,(vlSelf->ysyx_22050535_NPC__DOT__branch_taken));
    bufp->fullCData(oldp+29,((0x7fU & vlSelf->mem_inst)),7);
    bufp->fullCData(oldp+30,((7U & (vlSelf->mem_inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+31,((vlSelf->mem_inst >> 0x19U)),7);
    bufp->fullIData(oldp+32,((0xfU & (vlSelf->mem_inst 
                                      >> 7U))),32);
    bufp->fullIData(oldp+33,((0xfU & (vlSelf->mem_inst 
                                      >> 0xfU))),32);
    bufp->fullIData(oldp+34,((0xfU & (vlSelf->mem_inst 
                                      >> 0x14U))),32);
    bufp->fullBit(oldp+35,(1U));
}
