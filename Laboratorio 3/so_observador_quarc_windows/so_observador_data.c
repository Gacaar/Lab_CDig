/*
 * so_observador_data.c
 *
 * Real-Time Workshop code generation for Simulink model "so_observador.mdl".
 *
 * Model Version              : 1.8
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Nov 14 08:56:31 2019
 */

#include "so_observador.h"
#include "so_observador_private.h"

/* Block parameters (auto storage) */
Parameters_so_observador so_observador_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S1>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S1>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AOHigh : '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AOLow : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOInitial : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOFinal : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S1>/HIL Initialize'
                                        */
  2.4305934065934067E+004,             /* HILInitialize_POFrequency : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POLeading : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POTrailing : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S1>/HIL Initialize'
                                        */
  2.2748544093178037E-005,             /* Conversiontom_Gain : '<S1>/Conversion to m'
                                        */
  1.0,                                 /* Constant_Value : '<S1>/Constant'
                                        */
  1.5339807878856412E-003,             /* Conversiontord_Gain : '<S1>/Conversion to rd'
                                        */
  5.7295779513082323E+001,             /* Gain_Gain : '<S3>/Gain'
                                        */
  1000.0,                              /* mtomm_Gain : '<S1>/m to mm'
                                        */
  0.0,                                 /* Step_Time : '<Root>/Step'
                                        */
  0.0,                                 /* Step_Y0 : '<Root>/Step'
                                        */
  15.0,                                /* Step_YFinal : '<Root>/Step'
                                        */
  0.001,                               /* mmtom_Gain : '<Root>/mm to m'
                                        */
  12.0,                                /* AmplifierVoltageLimit_UpperSat : '<Root>/Amplifier Voltage Limit'
                                        */
  -12.0,                               /* AmplifierVoltageLimit_LowerSat : '<Root>/Amplifier Voltage Limit'
                                        */
  1.0,                                 /* CableGainPreCompensation_Gain : '<S1>/Cable Gain Pre-Compensation'
                                        */
  10.0,                                /* DACLimit_UpperSat : '<S1>/DAC Limit'
                                        */
  -10.0,                               /* DACLimit_LowerSat : '<S1>/DAC Limit'
                                        */
  1.0,                                 /* CableGain_Gain : '<S1>/Cable Gain'
                                        */
  0.0,                                 /* Delay1_InitialCondition : '<Root>/Delay1'
                                        */
  1000.0,                              /* mtomm_Gain_b : '<Root>/m to mm'
                                        */

  /*  Gain9_Gain : '<Root>/Gain9'
   */
  { 1.0, 0.0 },

  /*  Gain5_Gain : '<Root>/Gain5'
   */
  { 1.8932911680210145E+000, 8.4383816704657164E+001 },

  /*  Gain7_Gain : '<Root>/Gain7'
   */
  { 1.0, 0.0, 9.4564235421732024E-003, 8.9329116802101449E-001 },

  /*  Gain8_Gain : '<Root>/Gain8'
   */
  { 5.7490686080016495E-005, 1.1285926520430404E-002 },
  0.3,                                 /* XMAX_Value : '<S2>/X MAX'
                                        */
  -0.3,                                /* XIN_Value : '<S2>/X IN'
                                        */

  /*  HILInitialize_CKChannels : '<S1>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* HILInitialize_DOWatchdog : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POModes : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POConfiguration : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POAlignment : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPolarity : '<S1>/HIL Initialize'
                                        */
  0,                                   /* EncoderInput0CartPositionEncode : '<S1>/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle'
                                        */

  /*  HILInitialize_AIChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_AOChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_DOChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_EIChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* HILInitialize_EIQuadrature : '<S1>/HIL Initialize'
                                        */

  /*  HILInitialize_POChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  EncoderInput0CartPositionEnco_h : '<S1>/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle'
   */
  { 0U, 1U },
  100U,                                /* EncoderInput0CartPositionEnco_n : '<S1>/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle'
                                        */
  0U,                                  /* AnalogOutput0ToAmplifierDriving : '<S1>/Analog Output #0: To Amplifier Driving the Motor'
                                        */
  1,                                   /* ShowMessageonHost_MsgIcon : '<S4>/Show Message on Host'
                                        */
  1,                                   /* ShowMessageonHost_MsgIcon_j : '<S5>/Show Message on Host'
                                        */
  0,                                   /* HILInitialize_Active : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AIPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOInitial : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOFinal : '<S1>/HIL Initialize'
                                        */
  1,                                   /* EncoderInput0CartPositionEnc_hf : '<S1>/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle'
                                        */
  1                                    /* AnalogOutput0ToAmplifierDrivi_b : '<S1>/Analog Output #0: To Amplifier Driving the Motor'
                                        */
};
