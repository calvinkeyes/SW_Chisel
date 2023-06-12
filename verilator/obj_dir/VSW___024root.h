// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSW.h for the primary calling header

#ifndef VERILATED_VSW___024ROOT_H_
#define VERILATED_VSW___024ROOT_H_  // guard

#include "verilated.h"

class VSW__Syms;

class VSW___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_q_0_b,1,0);
        VL_IN8(io_q_1_b,1,0);
        VL_IN8(io_q_2_b,1,0);
        VL_IN8(io_q_3_b,1,0);
        VL_IN8(io_q_4_b,1,0);
        VL_IN8(io_q_5_b,1,0);
        VL_IN8(io_q_6_b,1,0);
        VL_IN8(io_q_7_b,1,0);
        VL_IN8(io_q_8_b,1,0);
        VL_IN8(io_q_9_b,1,0);
        VL_IN8(io_r_0_b,1,0);
        VL_IN8(io_r_1_b,1,0);
        VL_IN8(io_r_2_b,1,0);
        VL_IN8(io_r_3_b,1,0);
        VL_IN8(io_r_4_b,1,0);
        VL_IN8(io_r_5_b,1,0);
        VL_IN8(io_r_6_b,1,0);
        VL_IN8(io_r_7_b,1,0);
        VL_IN8(io_r_8_b,1,0);
        VL_IN8(io_r_9_b,1,0);
        VL_IN8(io_r_10_b,1,0);
        VL_IN8(io_r_11_b,1,0);
        VL_IN8(io_r_12_b,1,0);
        VL_IN8(io_r_13_b,1,0);
        VL_IN8(io_r_14_b,1,0);
        VL_IN8(io_r_15_b,1,0);
        VL_IN8(io_r_16_b,1,0);
        VL_IN8(io_start,0,0);
        VL_OUT8(io_done,0,0);
        CData/*4:0*/ SW__DOT__r_count_0_io_out;
        CData/*4:0*/ SW__DOT__r_count_1_io_out;
        CData/*4:0*/ SW__DOT__r_count_2_io_out;
        CData/*4:0*/ SW__DOT__r_count_3_io_out;
        CData/*4:0*/ SW__DOT__r_count_4_io_out;
        CData/*4:0*/ SW__DOT__r_count_5_io_out;
        CData/*4:0*/ SW__DOT__r_count_6_io_out;
        CData/*4:0*/ SW__DOT__r_count_7_io_out;
        CData/*4:0*/ SW__DOT__r_count_8_io_out;
        CData/*4:0*/ SW__DOT__r_count_9_io_out;
        CData/*0:0*/ SW__DOT__start_reg_0;
        CData/*0:0*/ SW__DOT__start_reg_1;
        CData/*0:0*/ SW__DOT__start_reg_2;
        CData/*0:0*/ SW__DOT__start_reg_3;
        CData/*0:0*/ SW__DOT__start_reg_4;
        CData/*0:0*/ SW__DOT__start_reg_5;
        CData/*0:0*/ SW__DOT__start_reg_6;
        CData/*0:0*/ SW__DOT__start_reg_7;
        CData/*0:0*/ SW__DOT__start_reg_8;
        CData/*0:0*/ SW__DOT__start_reg_9;
        CData/*4:0*/ SW__DOT__r_count_0__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_0__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_1__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_1__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_2__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_2__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_3__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_3__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_4__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_4__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_5__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_5__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_6__DOT___io_out_T_2;
    };
    struct {
        CData/*4:0*/ SW__DOT__r_count_6__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_7__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_7__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_8__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_8__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__r_count_9__DOT___io_out_T_2;
        CData/*4:0*/ SW__DOT__r_count_9__DOT__io_out_r;
        CData/*4:0*/ SW__DOT__max__DOT__counter;
        CData/*4:0*/ SW__DOT__max__DOT___counter_T_1;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(io_result,15,0);
        VL_OUT16(io_v1_out_0,15,0);
        VL_OUT16(io_v1_out_1,15,0);
        VL_OUT16(io_v1_out_2,15,0);
        VL_OUT16(io_v1_out_3,15,0);
        VL_OUT16(io_v1_out_4,15,0);
        VL_OUT16(io_v1_out_5,15,0);
        VL_OUT16(io_v1_out_6,15,0);
        VL_OUT16(io_v1_out_7,15,0);
        VL_OUT16(io_v1_out_8,15,0);
        VL_OUT16(io_v1_out_9,15,0);
        VL_OUT16(io_v1_out_10,15,0);
        VL_OUT16(io_v2_out_0,15,0);
        VL_OUT16(io_v2_out_1,15,0);
        VL_OUT16(io_v2_out_2,15,0);
        VL_OUT16(io_v2_out_3,15,0);
        VL_OUT16(io_v2_out_4,15,0);
        VL_OUT16(io_v2_out_5,15,0);
        VL_OUT16(io_v2_out_6,15,0);
        VL_OUT16(io_v2_out_7,15,0);
        VL_OUT16(io_v2_out_8,15,0);
        VL_OUT16(io_v2_out_9,15,0);
        VL_OUT16(io_v2_out_10,15,0);
        VL_OUT16(io_e_out_0,15,0);
        VL_OUT16(io_e_out_1,15,0);
        VL_OUT16(io_e_out_2,15,0);
        VL_OUT16(io_e_out_3,15,0);
        VL_OUT16(io_e_out_4,15,0);
        VL_OUT16(io_e_out_5,15,0);
        VL_OUT16(io_e_out_6,15,0);
        VL_OUT16(io_e_out_7,15,0);
        VL_OUT16(io_e_out_8,15,0);
        VL_OUT16(io_e_out_9,15,0);
        VL_OUT16(io_f_out_0,15,0);
        VL_OUT16(io_f_out_1,15,0);
        VL_OUT16(io_f_out_2,15,0);
        VL_OUT16(io_f_out_3,15,0);
        VL_OUT16(io_f_out_4,15,0);
        VL_OUT16(io_f_out_5,15,0);
        VL_OUT16(io_f_out_6,15,0);
        VL_OUT16(io_f_out_7,15,0);
        VL_OUT16(io_f_out_8,15,0);
        VL_OUT16(io_f_out_9,15,0);
        VL_OUT16(io_f_out_10,15,0);
        SData/*15:0*/ SW__DOT__array_0_io_e_o;
        SData/*15:0*/ SW__DOT__array_1_io_e_o;
        SData/*15:0*/ SW__DOT__array_1_io_f_o;
        SData/*15:0*/ SW__DOT__array_2_io_e_o;
        SData/*15:0*/ SW__DOT__array_2_io_f_o;
        SData/*15:0*/ SW__DOT__array_3_io_e_o;
        SData/*15:0*/ SW__DOT__array_3_io_f_o;
        SData/*15:0*/ SW__DOT__array_4_io_e_o;
        SData/*15:0*/ SW__DOT__array_4_io_f_o;
    };
    struct {
        SData/*15:0*/ SW__DOT__array_5_io_e_o;
        SData/*15:0*/ SW__DOT__array_5_io_f_o;
        SData/*15:0*/ SW__DOT__array_6_io_e_o;
        SData/*15:0*/ SW__DOT__array_6_io_f_o;
        SData/*15:0*/ SW__DOT__array_7_io_e_o;
        SData/*15:0*/ SW__DOT__array_7_io_f_o;
        SData/*15:0*/ SW__DOT__array_8_io_e_o;
        SData/*15:0*/ SW__DOT__array_8_io_f_o;
        SData/*15:0*/ SW__DOT__array_9_io_e_o;
        SData/*15:0*/ SW__DOT__array_9_io_f_o;
        SData/*15:0*/ SW__DOT__E_0;
        SData/*15:0*/ SW__DOT__E_1;
        SData/*15:0*/ SW__DOT__E_2;
        SData/*15:0*/ SW__DOT__E_3;
        SData/*15:0*/ SW__DOT__E_4;
        SData/*15:0*/ SW__DOT__E_5;
        SData/*15:0*/ SW__DOT__E_6;
        SData/*15:0*/ SW__DOT__E_7;
        SData/*15:0*/ SW__DOT__E_8;
        SData/*15:0*/ SW__DOT__E_9;
        SData/*15:0*/ SW__DOT__F_1;
        SData/*15:0*/ SW__DOT__F_2;
        SData/*15:0*/ SW__DOT__F_3;
        SData/*15:0*/ SW__DOT__F_4;
        SData/*15:0*/ SW__DOT__F_5;
        SData/*15:0*/ SW__DOT__F_6;
        SData/*15:0*/ SW__DOT__F_7;
        SData/*15:0*/ SW__DOT__F_8;
        SData/*15:0*/ SW__DOT__F_9;
        SData/*15:0*/ SW__DOT__F_10;
        SData/*15:0*/ SW__DOT__V1_1;
        SData/*15:0*/ SW__DOT__V1_2;
        SData/*15:0*/ SW__DOT__V1_3;
        SData/*15:0*/ SW__DOT__V1_4;
        SData/*15:0*/ SW__DOT__V1_5;
        SData/*15:0*/ SW__DOT__V1_6;
        SData/*15:0*/ SW__DOT__V1_7;
        SData/*15:0*/ SW__DOT__V1_8;
        SData/*15:0*/ SW__DOT__V1_9;
        SData/*15:0*/ SW__DOT__V1_10;
        SData/*15:0*/ SW__DOT__V2_1;
        SData/*15:0*/ SW__DOT__V2_2;
        SData/*15:0*/ SW__DOT__V2_3;
        SData/*15:0*/ SW__DOT__V2_4;
        SData/*15:0*/ SW__DOT__V2_5;
        SData/*15:0*/ SW__DOT__V2_6;
        SData/*15:0*/ SW__DOT__V2_7;
        SData/*15:0*/ SW__DOT__V2_8;
        SData/*15:0*/ SW__DOT__V2_9;
        SData/*15:0*/ SW__DOT__V2_10;
        SData/*15:0*/ SW__DOT__array_0__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_0__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_1__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_1__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_2__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_2__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_3__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_3__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_4__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_4__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_5__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_5__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_6__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_6__DOT__v_temp;
    };
    struct {
        SData/*15:0*/ SW__DOT__array_7__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_7__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_8__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_8__DOT__v_temp;
        SData/*15:0*/ SW__DOT__array_9__DOT__ef_temp;
        SData/*15:0*/ SW__DOT__array_9__DOT__v_temp;
        SData/*15:0*/ SW__DOT__max__DOT__max;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSW__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSW___024root(VSW__Syms* symsp, const char* v__name);
    ~VSW___024root();
    VL_UNCOPYABLE(VSW___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
