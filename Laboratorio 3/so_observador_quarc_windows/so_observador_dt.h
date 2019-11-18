/*
 * so_observador_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "so_observador.mdl".
 *
 * Model Version              : 1.8
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Nov 14 08:56:31 2019
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_task),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_task",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&so_observador_B.Gain), 0, 0, 11 },

  { (char_T *)(&so_observador_B.CheckMaximumAllowedPosition), 8, 0, 2 }
  ,

  { (char_T *)(&so_observador_DWork.Delay1_X[0]), 0, 0, 66 },

  { (char_T *)(&so_observador_DWork.AnalogOutput0ToAmplifierDriving), 11, 0, 8 },

  { (char_T *)(&so_observador_DWork.HILInitialize_ClockModes[0]), 6, 0, 53 },

  { (char_T *)(&so_observador_DWork.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&so_observador_DWork.EncoderInput0CartPositionEnco_o), 14, 0, 1 },

  { (char_T *)(&so_observador_DWork.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&so_observador_DWork.CartPositionWatchdog_MODE), 10, 0, 1 },

  { (char_T *)(&so_observador_DWork.CartPositionWatchdog_SubsysRanB), 2, 0, 1 },

  { (char_T *)(&so_observador_DWork.HILInitialize_DOBits[0]), 8, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&so_observador_P.HILInitialize_OOStart), 0, 0, 46 },

  { (char_T *)(&so_observador_P.HILInitialize_CKChannels[0]), 6, 0, 10 },

  { (char_T *)(&so_observador_P.HILInitialize_AIChannels[0]), 7, 0, 45 },

  { (char_T *)(&so_observador_P.ShowMessageonHost_MsgIcon), 2, 0, 2 },

  { (char_T *)(&so_observador_P.HILInitialize_Active), 8, 0, 35 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] so_observador_dt.h */
