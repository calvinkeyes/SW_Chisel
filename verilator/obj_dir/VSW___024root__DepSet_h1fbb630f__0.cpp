// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSW.h for the primary calling header

#include "verilated.h"

#include "VSW__Syms.h"
#include "VSW___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSW___024root___dump_triggers__ico(VSW___024root* vlSelf);
#endif  // VL_DEBUG

void VSW___024root___eval_triggers__ico(VSW___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSW__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSW___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSW___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSW___024root___dump_triggers__act(VSW___024root* vlSelf);
#endif  // VL_DEBUG

void VSW___024root___eval_triggers__act(VSW___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSW__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSW___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSW___024root___dump_triggers__act(vlSelf);
    }
#endif
}
