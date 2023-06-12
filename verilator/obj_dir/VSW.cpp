// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSW.h"
#include "VSW__Syms.h"

//============================================================
// Constructors

VSW::VSW(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSW__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_q_0_b{vlSymsp->TOP.io_q_0_b}
    , io_q_1_b{vlSymsp->TOP.io_q_1_b}
    , io_q_2_b{vlSymsp->TOP.io_q_2_b}
    , io_q_3_b{vlSymsp->TOP.io_q_3_b}
    , io_q_4_b{vlSymsp->TOP.io_q_4_b}
    , io_q_5_b{vlSymsp->TOP.io_q_5_b}
    , io_q_6_b{vlSymsp->TOP.io_q_6_b}
    , io_q_7_b{vlSymsp->TOP.io_q_7_b}
    , io_q_8_b{vlSymsp->TOP.io_q_8_b}
    , io_q_9_b{vlSymsp->TOP.io_q_9_b}
    , io_r_0_b{vlSymsp->TOP.io_r_0_b}
    , io_r_1_b{vlSymsp->TOP.io_r_1_b}
    , io_r_2_b{vlSymsp->TOP.io_r_2_b}
    , io_r_3_b{vlSymsp->TOP.io_r_3_b}
    , io_r_4_b{vlSymsp->TOP.io_r_4_b}
    , io_r_5_b{vlSymsp->TOP.io_r_5_b}
    , io_r_6_b{vlSymsp->TOP.io_r_6_b}
    , io_r_7_b{vlSymsp->TOP.io_r_7_b}
    , io_r_8_b{vlSymsp->TOP.io_r_8_b}
    , io_r_9_b{vlSymsp->TOP.io_r_9_b}
    , io_r_10_b{vlSymsp->TOP.io_r_10_b}
    , io_r_11_b{vlSymsp->TOP.io_r_11_b}
    , io_r_12_b{vlSymsp->TOP.io_r_12_b}
    , io_r_13_b{vlSymsp->TOP.io_r_13_b}
    , io_r_14_b{vlSymsp->TOP.io_r_14_b}
    , io_r_15_b{vlSymsp->TOP.io_r_15_b}
    , io_r_16_b{vlSymsp->TOP.io_r_16_b}
    , io_start{vlSymsp->TOP.io_start}
    , io_done{vlSymsp->TOP.io_done}
    , io_result{vlSymsp->TOP.io_result}
    , io_v1_out_0{vlSymsp->TOP.io_v1_out_0}
    , io_v1_out_1{vlSymsp->TOP.io_v1_out_1}
    , io_v1_out_2{vlSymsp->TOP.io_v1_out_2}
    , io_v1_out_3{vlSymsp->TOP.io_v1_out_3}
    , io_v1_out_4{vlSymsp->TOP.io_v1_out_4}
    , io_v1_out_5{vlSymsp->TOP.io_v1_out_5}
    , io_v1_out_6{vlSymsp->TOP.io_v1_out_6}
    , io_v1_out_7{vlSymsp->TOP.io_v1_out_7}
    , io_v1_out_8{vlSymsp->TOP.io_v1_out_8}
    , io_v1_out_9{vlSymsp->TOP.io_v1_out_9}
    , io_v1_out_10{vlSymsp->TOP.io_v1_out_10}
    , io_v2_out_0{vlSymsp->TOP.io_v2_out_0}
    , io_v2_out_1{vlSymsp->TOP.io_v2_out_1}
    , io_v2_out_2{vlSymsp->TOP.io_v2_out_2}
    , io_v2_out_3{vlSymsp->TOP.io_v2_out_3}
    , io_v2_out_4{vlSymsp->TOP.io_v2_out_4}
    , io_v2_out_5{vlSymsp->TOP.io_v2_out_5}
    , io_v2_out_6{vlSymsp->TOP.io_v2_out_6}
    , io_v2_out_7{vlSymsp->TOP.io_v2_out_7}
    , io_v2_out_8{vlSymsp->TOP.io_v2_out_8}
    , io_v2_out_9{vlSymsp->TOP.io_v2_out_9}
    , io_v2_out_10{vlSymsp->TOP.io_v2_out_10}
    , io_e_out_0{vlSymsp->TOP.io_e_out_0}
    , io_e_out_1{vlSymsp->TOP.io_e_out_1}
    , io_e_out_2{vlSymsp->TOP.io_e_out_2}
    , io_e_out_3{vlSymsp->TOP.io_e_out_3}
    , io_e_out_4{vlSymsp->TOP.io_e_out_4}
    , io_e_out_5{vlSymsp->TOP.io_e_out_5}
    , io_e_out_6{vlSymsp->TOP.io_e_out_6}
    , io_e_out_7{vlSymsp->TOP.io_e_out_7}
    , io_e_out_8{vlSymsp->TOP.io_e_out_8}
    , io_e_out_9{vlSymsp->TOP.io_e_out_9}
    , io_f_out_0{vlSymsp->TOP.io_f_out_0}
    , io_f_out_1{vlSymsp->TOP.io_f_out_1}
    , io_f_out_2{vlSymsp->TOP.io_f_out_2}
    , io_f_out_3{vlSymsp->TOP.io_f_out_3}
    , io_f_out_4{vlSymsp->TOP.io_f_out_4}
    , io_f_out_5{vlSymsp->TOP.io_f_out_5}
    , io_f_out_6{vlSymsp->TOP.io_f_out_6}
    , io_f_out_7{vlSymsp->TOP.io_f_out_7}
    , io_f_out_8{vlSymsp->TOP.io_f_out_8}
    , io_f_out_9{vlSymsp->TOP.io_f_out_9}
    , io_f_out_10{vlSymsp->TOP.io_f_out_10}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VSW::VSW(const char* _vcname__)
    : VSW(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSW::~VSW() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSW___024root___eval_debug_assertions(VSW___024root* vlSelf);
#endif  // VL_DEBUG
void VSW___024root___eval_static(VSW___024root* vlSelf);
void VSW___024root___eval_initial(VSW___024root* vlSelf);
void VSW___024root___eval_settle(VSW___024root* vlSelf);
void VSW___024root___eval(VSW___024root* vlSelf);

void VSW::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSW::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSW___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSW___024root___eval_static(&(vlSymsp->TOP));
        VSW___024root___eval_initial(&(vlSymsp->TOP));
        VSW___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSW___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSW::eventsPending() { return false; }

uint64_t VSW::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSW::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSW___024root___eval_final(VSW___024root* vlSelf);

VL_ATTR_COLD void VSW::final() {
    VSW___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSW::hierName() const { return vlSymsp->name(); }
const char* VSW::modelName() const { return "VSW"; }
unsigned VSW::threads() const { return 1; }
