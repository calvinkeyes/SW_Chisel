// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSW.h for the primary calling header

#include "verilated.h"

#include "VSW___024root.h"

void VSW___024root___nba_sequent__TOP__0(VSW___024root* vlSelf);

void VSW___024root___eval_nba(VSW___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSW__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSW___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VSW___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VSW___024root___eval_triggers__ico(VSW___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSW___024root___dump_triggers__ico(VSW___024root* vlSelf);
#endif  // VL_DEBUG
void VSW___024root___eval_ico(VSW___024root* vlSelf);
void VSW___024root___eval_triggers__act(VSW___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSW___024root___dump_triggers__act(VSW___024root* vlSelf);
#endif  // VL_DEBUG
void VSW___024root___eval_act(VSW___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSW___024root___dump_triggers__nba(VSW___024root* vlSelf);
#endif  // VL_DEBUG

void VSW___024root___eval(VSW___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSW__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSW___024root___eval\n"); );
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
        VSW___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VSW___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("SW.v", 3, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VSW___024root___eval_ico(vlSelf);
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
            VSW___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VSW___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("SW.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VSW___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VSW___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("SW.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VSW___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VSW___024root___eval_debug_assertions(VSW___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSW__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSW___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_q_0_b & 0xfcU))) {
        Verilated::overWidthError("io_q_0_b");}
    if (VL_UNLIKELY((vlSelf->io_q_1_b & 0xfcU))) {
        Verilated::overWidthError("io_q_1_b");}
    if (VL_UNLIKELY((vlSelf->io_q_2_b & 0xfcU))) {
        Verilated::overWidthError("io_q_2_b");}
    if (VL_UNLIKELY((vlSelf->io_q_3_b & 0xfcU))) {
        Verilated::overWidthError("io_q_3_b");}
    if (VL_UNLIKELY((vlSelf->io_q_4_b & 0xfcU))) {
        Verilated::overWidthError("io_q_4_b");}
    if (VL_UNLIKELY((vlSelf->io_q_5_b & 0xfcU))) {
        Verilated::overWidthError("io_q_5_b");}
    if (VL_UNLIKELY((vlSelf->io_q_6_b & 0xfcU))) {
        Verilated::overWidthError("io_q_6_b");}
    if (VL_UNLIKELY((vlSelf->io_q_7_b & 0xfcU))) {
        Verilated::overWidthError("io_q_7_b");}
    if (VL_UNLIKELY((vlSelf->io_q_8_b & 0xfcU))) {
        Verilated::overWidthError("io_q_8_b");}
    if (VL_UNLIKELY((vlSelf->io_q_9_b & 0xfcU))) {
        Verilated::overWidthError("io_q_9_b");}
    if (VL_UNLIKELY((vlSelf->io_q_10_b & 0xfcU))) {
        Verilated::overWidthError("io_q_10_b");}
    if (VL_UNLIKELY((vlSelf->io_q_11_b & 0xfcU))) {
        Verilated::overWidthError("io_q_11_b");}
    if (VL_UNLIKELY((vlSelf->io_q_12_b & 0xfcU))) {
        Verilated::overWidthError("io_q_12_b");}
    if (VL_UNLIKELY((vlSelf->io_q_13_b & 0xfcU))) {
        Verilated::overWidthError("io_q_13_b");}
    if (VL_UNLIKELY((vlSelf->io_q_14_b & 0xfcU))) {
        Verilated::overWidthError("io_q_14_b");}
    if (VL_UNLIKELY((vlSelf->io_q_15_b & 0xfcU))) {
        Verilated::overWidthError("io_q_15_b");}
    if (VL_UNLIKELY((vlSelf->io_r_0_b & 0xfcU))) {
        Verilated::overWidthError("io_r_0_b");}
    if (VL_UNLIKELY((vlSelf->io_r_1_b & 0xfcU))) {
        Verilated::overWidthError("io_r_1_b");}
    if (VL_UNLIKELY((vlSelf->io_r_2_b & 0xfcU))) {
        Verilated::overWidthError("io_r_2_b");}
    if (VL_UNLIKELY((vlSelf->io_r_3_b & 0xfcU))) {
        Verilated::overWidthError("io_r_3_b");}
    if (VL_UNLIKELY((vlSelf->io_r_4_b & 0xfcU))) {
        Verilated::overWidthError("io_r_4_b");}
    if (VL_UNLIKELY((vlSelf->io_r_5_b & 0xfcU))) {
        Verilated::overWidthError("io_r_5_b");}
    if (VL_UNLIKELY((vlSelf->io_r_6_b & 0xfcU))) {
        Verilated::overWidthError("io_r_6_b");}
    if (VL_UNLIKELY((vlSelf->io_r_7_b & 0xfcU))) {
        Verilated::overWidthError("io_r_7_b");}
    if (VL_UNLIKELY((vlSelf->io_r_8_b & 0xfcU))) {
        Verilated::overWidthError("io_r_8_b");}
    if (VL_UNLIKELY((vlSelf->io_r_9_b & 0xfcU))) {
        Verilated::overWidthError("io_r_9_b");}
    if (VL_UNLIKELY((vlSelf->io_r_10_b & 0xfcU))) {
        Verilated::overWidthError("io_r_10_b");}
    if (VL_UNLIKELY((vlSelf->io_r_11_b & 0xfcU))) {
        Verilated::overWidthError("io_r_11_b");}
    if (VL_UNLIKELY((vlSelf->io_r_12_b & 0xfcU))) {
        Verilated::overWidthError("io_r_12_b");}
    if (VL_UNLIKELY((vlSelf->io_r_13_b & 0xfcU))) {
        Verilated::overWidthError("io_r_13_b");}
    if (VL_UNLIKELY((vlSelf->io_r_14_b & 0xfcU))) {
        Verilated::overWidthError("io_r_14_b");}
    if (VL_UNLIKELY((vlSelf->io_r_15_b & 0xfcU))) {
        Verilated::overWidthError("io_r_15_b");}
    if (VL_UNLIKELY((vlSelf->io_r_16_b & 0xfcU))) {
        Verilated::overWidthError("io_r_16_b");}
    if (VL_UNLIKELY((vlSelf->io_r_17_b & 0xfcU))) {
        Verilated::overWidthError("io_r_17_b");}
    if (VL_UNLIKELY((vlSelf->io_r_18_b & 0xfcU))) {
        Verilated::overWidthError("io_r_18_b");}
    if (VL_UNLIKELY((vlSelf->io_r_19_b & 0xfcU))) {
        Verilated::overWidthError("io_r_19_b");}
    if (VL_UNLIKELY((vlSelf->io_r_20_b & 0xfcU))) {
        Verilated::overWidthError("io_r_20_b");}
    if (VL_UNLIKELY((vlSelf->io_r_21_b & 0xfcU))) {
        Verilated::overWidthError("io_r_21_b");}
    if (VL_UNLIKELY((vlSelf->io_r_22_b & 0xfcU))) {
        Verilated::overWidthError("io_r_22_b");}
    if (VL_UNLIKELY((vlSelf->io_r_23_b & 0xfcU))) {
        Verilated::overWidthError("io_r_23_b");}
    if (VL_UNLIKELY((vlSelf->io_r_24_b & 0xfcU))) {
        Verilated::overWidthError("io_r_24_b");}
    if (VL_UNLIKELY((vlSelf->io_r_25_b & 0xfcU))) {
        Verilated::overWidthError("io_r_25_b");}
    if (VL_UNLIKELY((vlSelf->io_r_26_b & 0xfcU))) {
        Verilated::overWidthError("io_r_26_b");}
    if (VL_UNLIKELY((vlSelf->io_r_27_b & 0xfcU))) {
        Verilated::overWidthError("io_r_27_b");}
    if (VL_UNLIKELY((vlSelf->io_r_28_b & 0xfcU))) {
        Verilated::overWidthError("io_r_28_b");}
    if (VL_UNLIKELY((vlSelf->io_r_29_b & 0xfcU))) {
        Verilated::overWidthError("io_r_29_b");}
    if (VL_UNLIKELY((vlSelf->io_r_30_b & 0xfcU))) {
        Verilated::overWidthError("io_r_30_b");}
    if (VL_UNLIKELY((vlSelf->io_r_31_b & 0xfcU))) {
        Verilated::overWidthError("io_r_31_b");}
    if (VL_UNLIKELY((vlSelf->io_r_32_b & 0xfcU))) {
        Verilated::overWidthError("io_r_32_b");}
    if (VL_UNLIKELY((vlSelf->io_r_33_b & 0xfcU))) {
        Verilated::overWidthError("io_r_33_b");}
    if (VL_UNLIKELY((vlSelf->io_r_34_b & 0xfcU))) {
        Verilated::overWidthError("io_r_34_b");}
    if (VL_UNLIKELY((vlSelf->io_r_35_b & 0xfcU))) {
        Verilated::overWidthError("io_r_35_b");}
    if (VL_UNLIKELY((vlSelf->io_r_36_b & 0xfcU))) {
        Verilated::overWidthError("io_r_36_b");}
    if (VL_UNLIKELY((vlSelf->io_r_37_b & 0xfcU))) {
        Verilated::overWidthError("io_r_37_b");}
    if (VL_UNLIKELY((vlSelf->io_r_38_b & 0xfcU))) {
        Verilated::overWidthError("io_r_38_b");}
    if (VL_UNLIKELY((vlSelf->io_r_39_b & 0xfcU))) {
        Verilated::overWidthError("io_r_39_b");}
    if (VL_UNLIKELY((vlSelf->io_r_40_b & 0xfcU))) {
        Verilated::overWidthError("io_r_40_b");}
    if (VL_UNLIKELY((vlSelf->io_r_41_b & 0xfcU))) {
        Verilated::overWidthError("io_r_41_b");}
    if (VL_UNLIKELY((vlSelf->io_r_42_b & 0xfcU))) {
        Verilated::overWidthError("io_r_42_b");}
    if (VL_UNLIKELY((vlSelf->io_r_43_b & 0xfcU))) {
        Verilated::overWidthError("io_r_43_b");}
    if (VL_UNLIKELY((vlSelf->io_r_44_b & 0xfcU))) {
        Verilated::overWidthError("io_r_44_b");}
    if (VL_UNLIKELY((vlSelf->io_r_45_b & 0xfcU))) {
        Verilated::overWidthError("io_r_45_b");}
    if (VL_UNLIKELY((vlSelf->io_r_46_b & 0xfcU))) {
        Verilated::overWidthError("io_r_46_b");}
    if (VL_UNLIKELY((vlSelf->io_r_47_b & 0xfcU))) {
        Verilated::overWidthError("io_r_47_b");}
    if (VL_UNLIKELY((vlSelf->io_r_48_b & 0xfcU))) {
        Verilated::overWidthError("io_r_48_b");}
    if (VL_UNLIKELY((vlSelf->io_r_49_b & 0xfcU))) {
        Verilated::overWidthError("io_r_49_b");}
    if (VL_UNLIKELY((vlSelf->io_r_50_b & 0xfcU))) {
        Verilated::overWidthError("io_r_50_b");}
    if (VL_UNLIKELY((vlSelf->io_r_51_b & 0xfcU))) {
        Verilated::overWidthError("io_r_51_b");}
    if (VL_UNLIKELY((vlSelf->io_r_52_b & 0xfcU))) {
        Verilated::overWidthError("io_r_52_b");}
    if (VL_UNLIKELY((vlSelf->io_r_53_b & 0xfcU))) {
        Verilated::overWidthError("io_r_53_b");}
    if (VL_UNLIKELY((vlSelf->io_r_54_b & 0xfcU))) {
        Verilated::overWidthError("io_r_54_b");}
    if (VL_UNLIKELY((vlSelf->io_r_55_b & 0xfcU))) {
        Verilated::overWidthError("io_r_55_b");}
    if (VL_UNLIKELY((vlSelf->io_r_56_b & 0xfcU))) {
        Verilated::overWidthError("io_r_56_b");}
    if (VL_UNLIKELY((vlSelf->io_r_57_b & 0xfcU))) {
        Verilated::overWidthError("io_r_57_b");}
    if (VL_UNLIKELY((vlSelf->io_r_58_b & 0xfcU))) {
        Verilated::overWidthError("io_r_58_b");}
    if (VL_UNLIKELY((vlSelf->io_r_59_b & 0xfcU))) {
        Verilated::overWidthError("io_r_59_b");}
    if (VL_UNLIKELY((vlSelf->io_r_60_b & 0xfcU))) {
        Verilated::overWidthError("io_r_60_b");}
    if (VL_UNLIKELY((vlSelf->io_r_61_b & 0xfcU))) {
        Verilated::overWidthError("io_r_61_b");}
    if (VL_UNLIKELY((vlSelf->io_r_62_b & 0xfcU))) {
        Verilated::overWidthError("io_r_62_b");}
    if (VL_UNLIKELY((vlSelf->io_r_63_b & 0xfcU))) {
        Verilated::overWidthError("io_r_63_b");}
    if (VL_UNLIKELY((vlSelf->io_r_64_b & 0xfcU))) {
        Verilated::overWidthError("io_r_64_b");}
    if (VL_UNLIKELY((vlSelf->io_r_65_b & 0xfcU))) {
        Verilated::overWidthError("io_r_65_b");}
    if (VL_UNLIKELY((vlSelf->io_r_66_b & 0xfcU))) {
        Verilated::overWidthError("io_r_66_b");}
    if (VL_UNLIKELY((vlSelf->io_r_67_b & 0xfcU))) {
        Verilated::overWidthError("io_r_67_b");}
    if (VL_UNLIKELY((vlSelf->io_r_68_b & 0xfcU))) {
        Verilated::overWidthError("io_r_68_b");}
    if (VL_UNLIKELY((vlSelf->io_r_69_b & 0xfcU))) {
        Verilated::overWidthError("io_r_69_b");}
    if (VL_UNLIKELY((vlSelf->io_r_70_b & 0xfcU))) {
        Verilated::overWidthError("io_r_70_b");}
    if (VL_UNLIKELY((vlSelf->io_r_71_b & 0xfcU))) {
        Verilated::overWidthError("io_r_71_b");}
    if (VL_UNLIKELY((vlSelf->io_r_72_b & 0xfcU))) {
        Verilated::overWidthError("io_r_72_b");}
    if (VL_UNLIKELY((vlSelf->io_r_73_b & 0xfcU))) {
        Verilated::overWidthError("io_r_73_b");}
    if (VL_UNLIKELY((vlSelf->io_r_74_b & 0xfcU))) {
        Verilated::overWidthError("io_r_74_b");}
    if (VL_UNLIKELY((vlSelf->io_r_75_b & 0xfcU))) {
        Verilated::overWidthError("io_r_75_b");}
    if (VL_UNLIKELY((vlSelf->io_r_76_b & 0xfcU))) {
        Verilated::overWidthError("io_r_76_b");}
    if (VL_UNLIKELY((vlSelf->io_r_77_b & 0xfcU))) {
        Verilated::overWidthError("io_r_77_b");}
    if (VL_UNLIKELY((vlSelf->io_r_78_b & 0xfcU))) {
        Verilated::overWidthError("io_r_78_b");}
    if (VL_UNLIKELY((vlSelf->io_r_79_b & 0xfcU))) {
        Verilated::overWidthError("io_r_79_b");}
    if (VL_UNLIKELY((vlSelf->io_r_80_b & 0xfcU))) {
        Verilated::overWidthError("io_r_80_b");}
    if (VL_UNLIKELY((vlSelf->io_r_81_b & 0xfcU))) {
        Verilated::overWidthError("io_r_81_b");}
    if (VL_UNLIKELY((vlSelf->io_r_82_b & 0xfcU))) {
        Verilated::overWidthError("io_r_82_b");}
    if (VL_UNLIKELY((vlSelf->io_r_83_b & 0xfcU))) {
        Verilated::overWidthError("io_r_83_b");}
    if (VL_UNLIKELY((vlSelf->io_r_84_b & 0xfcU))) {
        Verilated::overWidthError("io_r_84_b");}
    if (VL_UNLIKELY((vlSelf->io_r_85_b & 0xfcU))) {
        Verilated::overWidthError("io_r_85_b");}
    if (VL_UNLIKELY((vlSelf->io_r_86_b & 0xfcU))) {
        Verilated::overWidthError("io_r_86_b");}
    if (VL_UNLIKELY((vlSelf->io_r_87_b & 0xfcU))) {
        Verilated::overWidthError("io_r_87_b");}
    if (VL_UNLIKELY((vlSelf->io_r_88_b & 0xfcU))) {
        Verilated::overWidthError("io_r_88_b");}
    if (VL_UNLIKELY((vlSelf->io_r_89_b & 0xfcU))) {
        Verilated::overWidthError("io_r_89_b");}
    if (VL_UNLIKELY((vlSelf->io_r_90_b & 0xfcU))) {
        Verilated::overWidthError("io_r_90_b");}
    if (VL_UNLIKELY((vlSelf->io_r_91_b & 0xfcU))) {
        Verilated::overWidthError("io_r_91_b");}
    if (VL_UNLIKELY((vlSelf->io_r_92_b & 0xfcU))) {
        Verilated::overWidthError("io_r_92_b");}
    if (VL_UNLIKELY((vlSelf->io_r_93_b & 0xfcU))) {
        Verilated::overWidthError("io_r_93_b");}
    if (VL_UNLIKELY((vlSelf->io_r_94_b & 0xfcU))) {
        Verilated::overWidthError("io_r_94_b");}
    if (VL_UNLIKELY((vlSelf->io_r_95_b & 0xfcU))) {
        Verilated::overWidthError("io_r_95_b");}
    if (VL_UNLIKELY((vlSelf->io_r_96_b & 0xfcU))) {
        Verilated::overWidthError("io_r_96_b");}
    if (VL_UNLIKELY((vlSelf->io_r_97_b & 0xfcU))) {
        Verilated::overWidthError("io_r_97_b");}
    if (VL_UNLIKELY((vlSelf->io_r_98_b & 0xfcU))) {
        Verilated::overWidthError("io_r_98_b");}
    if (VL_UNLIKELY((vlSelf->io_r_99_b & 0xfcU))) {
        Verilated::overWidthError("io_r_99_b");}
    if (VL_UNLIKELY((vlSelf->io_r_100_b & 0xfcU))) {
        Verilated::overWidthError("io_r_100_b");}
    if (VL_UNLIKELY((vlSelf->io_r_101_b & 0xfcU))) {
        Verilated::overWidthError("io_r_101_b");}
    if (VL_UNLIKELY((vlSelf->io_r_102_b & 0xfcU))) {
        Verilated::overWidthError("io_r_102_b");}
    if (VL_UNLIKELY((vlSelf->io_r_103_b & 0xfcU))) {
        Verilated::overWidthError("io_r_103_b");}
    if (VL_UNLIKELY((vlSelf->io_r_104_b & 0xfcU))) {
        Verilated::overWidthError("io_r_104_b");}
    if (VL_UNLIKELY((vlSelf->io_r_105_b & 0xfcU))) {
        Verilated::overWidthError("io_r_105_b");}
    if (VL_UNLIKELY((vlSelf->io_start & 0xfeU))) {
        Verilated::overWidthError("io_start");}
}
#endif  // VL_DEBUG
