/*
 * so_observador.c
 *
 * Real-Time Workshop code generation for Simulink model "so_observador.mdl".
 *
 * Model Version              : 1.8
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Nov 14 08:56:31 2019
 */

#include "so_observador.h"
#include "so_observador_private.h"
#include <stdio.h>
#include "so_observador_dt.h"

/* Block signals (auto storage) */
BlockIO_so_observador so_observador_B;

/* Block states (auto storage) */
D_Work_so_observador so_observador_DWork;

/* Real-time model */
RT_MODEL_so_observador so_observador_M_;
RT_MODEL_so_observador *so_observador_M = &so_observador_M_;

/* Model output function */
void so_observador_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput0CartPositionEn;
  real_T rtb_Sum4;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g;

  /* Reset subsysRan breadcrumbs */
  srClearBC(so_observador_DWork.CartPositionWatchdog_SubsysRanB);

  {
    real_T rtb_Conversiontom;
    real_T currentTime;

    /* S-Function Block: so_observador/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (so_observador_DWork.EncoderInput0CartPositionEnco_o, 1,
         &so_observador_DWork.EncoderInput0CartPositionEncode[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
      } else {
        rtb_EncoderInput0CartPositionEn =
          so_observador_DWork.EncoderInput0CartPositionEncode[0];
        rtb_Sum4 = so_observador_DWork.EncoderInput0CartPositionEncode[1];
      }
    }

    /* Gain: '<S1>/Conversion to m' */
    rtb_Conversiontom = so_observador_P.Conversiontom_Gain *
      rtb_EncoderInput0CartPositionEn;

    /* Outputs for enable SubSystem: '<S1>/Cart Position Watchdog' incorporates:
     *  Constant: '<S1>/Constant'
     *  EnablePort: '<S2>/Enable'
     */
    if (so_observador_P.Constant_Value > 0.0) {
      if (so_observador_DWork.CartPositionWatchdog_MODE == SUBSYS_DISABLED) {
        so_observador_DWork.CartPositionWatchdog_MODE = SUBSYS_ENABLED;
      }
    } else {
      if (so_observador_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
        so_observador_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;
      }
    }

    if (so_observador_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
      /* RelationalOperator: '<S2>/Check Maximum Allowed Position' incorporates:
       *  Constant: '<S2>/X MAX'
       */
      so_observador_B.CheckMaximumAllowedPosition = (so_observador_P.XMAX_Value <
        rtb_Conversiontom);

      /* RelationalOperator: '<S6>/Compare' */
      rtb_Compare = (so_observador_B.CheckMaximumAllowedPosition != FALSE);

      /* Stop: '<S4>/Stop Simulation' */
      if (rtb_Compare) {
        rtmSetStopRequested(so_observador_M, 1);
      }

      /* RelationalOperator: '<S2>/Check Minimum Allowed Position' incorporates:
       *  Constant: '<S2>/X IN'
       */
      so_observador_B.CheckMinimumAllowedPosition = (rtb_Conversiontom <
        so_observador_P.XIN_Value);

      /* RelationalOperator: '<S7>/Compare' */
      rtb_Compare_g = (so_observador_B.CheckMinimumAllowedPosition != FALSE);

      /* Stop: '<S5>/Stop Simulation' */
      if (rtb_Compare_g) {
        rtmSetStopRequested(so_observador_M, 1);
      }

      srUpdateBC(so_observador_DWork.CartPositionWatchdog_SubsysRanB);
    }

    /* end of Outputs for SubSystem: '<S1>/Cart Position Watchdog' */

    /* Gain: '<S3>/Gain' incorporates:
     *  Gain: '<S1>/Conversion to rd'
     */
    so_observador_B.Gain = so_observador_P.Conversiontord_Gain * rtb_Sum4 *
      so_observador_P.Gain_Gain;

    /* Gain: '<S1>/m to mm' */
    so_observador_B.mtomm = so_observador_P.mtomm_Gain * rtb_Conversiontom;

    /* Step: '<Root>/Step' */
    currentTime = so_observador_M->Timing.t[0];
    if (currentTime < so_observador_P.Step_Time) {
      so_observador_B.R = so_observador_P.Step_Y0;
    } else {
      so_observador_B.R = so_observador_P.Step_YFinal;
    }

    /* Sum: '<Root>/Sum1' incorporates:
     *  Gain: '<Root>/mm to m'
     */
    rtb_Sum4 = so_observador_P.mmtom_Gain * so_observador_B.R -
      rtb_Conversiontom;

    /* Saturate: '<Root>/Amplifier Voltage Limit' */
    so_observador_B.AmplifierVoltageLimit = rt_SATURATE(rtb_Sum4,
      so_observador_P.AmplifierVoltageLimit_LowerSat,
      so_observador_P.AmplifierVoltageLimit_UpperSat);

    /* Gain: '<S1>/Cable Gain Pre-Compensation' */
    rtb_Sum4 = so_observador_P.CableGainPreCompensation_Gain *
      so_observador_B.AmplifierVoltageLimit;

    /* Saturate: '<S1>/DAC Limit' */
    rtb_Sum4 = rt_SATURATE(rtb_Sum4, so_observador_P.DACLimit_LowerSat,
      so_observador_P.DACLimit_UpperSat);

    /* S-Function Block: so_observador/IP02/Analog Output #0: To Amplifier Driving the Motor (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.AnalogOutput0ToAmplifierDriving, 1, &rtb_Sum4);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
      }
    }

    /* Gain: '<S1>/Cable Gain' */
    so_observador_B.CableGain = so_observador_P.CableGain_Gain * rtb_Sum4;

    /* S-Function (sfix_udelay): '<Root>/Delay1'
     *
     * Regarding '<Root>/Delay1':
     * Integer/Tapped Delay Block: '<Root>/Delay1'
     */
    so_observador_B.xk[0] = so_observador_DWork.Delay1_X[0];
    so_observador_B.xk[1] = so_observador_DWork.Delay1_X[1];

    /* Gain: '<Root>/m to mm' */
    so_observador_B.mtomm_n = so_observador_P.mtomm_Gain_b * rtb_Conversiontom;

    /* Gain: '<Root>/Gain9' */
    so_observador_B.Gain9 = so_observador_P.Gain9_Gain[0] * so_observador_B.xk[0]
      + so_observador_P.Gain9_Gain[1] * so_observador_B.xk[1];

    /* Sum: '<Root>/Sum4' */
    rtb_Sum4 = so_observador_B.mtomm_n - so_observador_B.Gain9;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Gain: '<Root>/Gain5'
     *  Gain: '<Root>/Gain7'
     *  Gain: '<Root>/Gain8'
     */
    so_observador_B.xk1[0] = (so_observador_P.Gain5_Gain[0] * rtb_Sum4 +
      so_observador_P.Gain8_Gain[0] * so_observador_B.AmplifierVoltageLimit) +
      (so_observador_P.Gain7_Gain[0] * so_observador_B.xk[0] +
       so_observador_P.Gain7_Gain[2] * so_observador_B.xk[1]);
    so_observador_B.xk1[1] = (so_observador_P.Gain5_Gain[1] * rtb_Sum4 +
      so_observador_P.Gain8_Gain[1] * so_observador_B.AmplifierVoltageLimit) +
      (so_observador_P.Gain7_Gain[1] * so_observador_B.xk[0] +
       so_observador_P.Gain7_Gain[3] * so_observador_B.xk[1]);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void so_observador_update(int_T tid)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay1'
   */
  (void) memcpy(&so_observador_DWork.Delay1_X[0],so_observador_B.xk1,
                2*sizeof(real_T));

  /* Update absolute time for base rate */
  if (!(++so_observador_M->Timing.clockTick0))
    ++so_observador_M->Timing.clockTickH0;
  so_observador_M->Timing.t[0] = so_observador_M->Timing.clockTick0 *
    so_observador_M->Timing.stepSize0 + so_observador_M->Timing.clockTickH0 *
    so_observador_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    if (!(++so_observador_M->Timing.clockTick1))
      ++so_observador_M->Timing.clockTickH1;
    so_observador_M->Timing.t[1] = so_observador_M->Timing.clockTick1 *
      so_observador_M->Timing.stepSize1 + so_observador_M->Timing.clockTickH1 *
      so_observador_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void so_observador_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)so_observador_M,0,
                sizeof(RT_MODEL_so_observador));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&so_observador_M->solverInfo,
                          &so_observador_M->Timing.simTimeStep);
    rtsiSetTPtr(&so_observador_M->solverInfo, &rtmGetTPtr(so_observador_M));
    rtsiSetStepSizePtr(&so_observador_M->solverInfo,
                       &so_observador_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&so_observador_M->solverInfo, (&rtmGetErrorStatus
      (so_observador_M)));
    rtsiSetRTModelPtr(&so_observador_M->solverInfo, so_observador_M);
  }

  rtsiSetSimTimeStep(&so_observador_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&so_observador_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = so_observador_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    so_observador_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    so_observador_M->Timing.sampleTimes =
      (&so_observador_M->Timing.sampleTimesArray[0]);
    so_observador_M->Timing.offsetTimes =
      (&so_observador_M->Timing.offsetTimesArray[0]);

    /* task periods */
    so_observador_M->Timing.sampleTimes[0] = (0.0);
    so_observador_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    so_observador_M->Timing.offsetTimes[0] = (0.0);
    so_observador_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(so_observador_M, &so_observador_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = so_observador_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    so_observador_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(so_observador_M, 10.0);
  so_observador_M->Timing.stepSize0 = 0.01;
  so_observador_M->Timing.stepSize1 = 0.01;

  /* external mode info */
  so_observador_M->Sizes.checksums[0] = (2348297455U);
  so_observador_M->Sizes.checksums[1] = (1882864790U);
  so_observador_M->Sizes.checksums[2] = (545359229U);
  so_observador_M->Sizes.checksums[3] = (2377596519U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    so_observador_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &so_observador_DWork.CartPositionWatchdog_SubsysRanB;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &so_observador_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, so_observador_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(so_observador_M));
  }

  so_observador_M->solverInfoPtr = (&so_observador_M->solverInfo);
  so_observador_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&so_observador_M->solverInfo, 0.01);
  rtsiSetSolverMode(&so_observador_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  so_observador_M->ModelData.blockIO = ((void *) &so_observador_B);
  (void) memset(((void *) &so_observador_B),0,
                sizeof(BlockIO_so_observador));

  /* parameters */
  so_observador_M->ModelData.defaultParam = ((real_T *) &so_observador_P);

  /* states (dwork) */
  so_observador_M->Work.dwork = ((void *) &so_observador_DWork);
  (void) memset((void *)&so_observador_DWork, 0,
                sizeof(D_Work_so_observador));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    so_observador_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void so_observador_terminate(void)
{
  /* S-Function Block: so_observador/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(so_observador_DWork.HILInitialize_Card);
    hil_task_delete_all(so_observador_DWork.HILInitialize_Card);
    hil_monitor_stop_all(so_observador_DWork.HILInitialize_Card);
    hil_monitor_delete_all(so_observador_DWork.HILInitialize_Card);
    is_switching = false;
    if ((so_observador_P.HILInitialize_AOTerminate && !is_switching) ||
        (so_observador_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &so_observador_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = so_observador_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_AOChannels[0], 8U,
        &so_observador_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
      }
    }

    if ((so_observador_P.HILInitialize_DOTerminate && !is_switching) ||
        (so_observador_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &so_observador_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = so_observador_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &so_observador_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
      }
    }

    if ((so_observador_P.HILInitialize_POTerminate && !is_switching) ||
        (so_observador_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &so_observador_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = so_observador_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_POChannels[0], 8U,
        &so_observador_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
      }
    }

    hil_close(so_observador_DWork.HILInitialize_Card);
    so_observador_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  so_observador_output(tid);
}

void MdlUpdate(int_T tid)
{
  so_observador_update(tid);
}

void MdlInitializeSizes(void)
{
  so_observador_M->Sizes.numContStates = (0);/* Number of continuous states */
  so_observador_M->Sizes.numY = (0);   /* Number of model outputs */
  so_observador_M->Sizes.numU = (0);   /* Number of model inputs */
  so_observador_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  so_observador_M->Sizes.numSampTimes = (2);/* Number of sample times */
  so_observador_M->Sizes.numBlocks = (43);/* Number of blocks */
  so_observador_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  so_observador_M->Sizes.numBlockPrms = (138);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay1'
   * Initialize State
   * Initial Condition parameter uses the same data type and scaling as Output0
   */
  so_observador_DWork.Delay1_X[0] = so_observador_P.Delay1_InitialCondition;
  so_observador_DWork.Delay1_X[1] = so_observador_P.Delay1_InitialCondition;
}

void MdlStart(void)
{
  /* S-Function Block: so_observador/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &so_observador_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(so_observador_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (so_observador_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(so_observador_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(so_observador_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(so_observador_M, _rt_error_message);
      return;
    }

    if ((so_observador_P.HILInitialize_AIPStart && !is_switching) ||
        (so_observador_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &so_observador_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = so_observador_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &so_observador_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = so_observador_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_AIChannels[0], 8U,
         &so_observador_DWork.HILInitialize_AIMinimums[0],
         &so_observador_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_AOPStart && !is_switching) ||
        (so_observador_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &so_observador_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = so_observador_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &so_observador_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = so_observador_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_AOChannels[0], 8U,
         &so_observador_DWork.HILInitialize_AOMinimums[0],
         &so_observador_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_AOStart && !is_switching) ||
        (so_observador_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &so_observador_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = so_observador_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_AOChannels[0], 8U,
        &so_observador_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if (so_observador_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &so_observador_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = so_observador_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_AOChannels[0], 8U,
         &so_observador_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(so_observador_DWork.HILInitialize_Card,
      NULL, 0U, &so_observador_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(so_observador_M, _rt_error_message);
      return;
    }

    if ((so_observador_P.HILInitialize_DOStart && !is_switching) ||
        (so_observador_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &so_observador_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = so_observador_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &so_observador_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if (so_observador_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &so_observador_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = so_observador_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &so_observador_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_EIPStart && !is_switching) ||
        (so_observador_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &so_observador_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = so_observador_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &so_observador_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_EIStart && !is_switching) ||
        (so_observador_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &so_observador_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = so_observador_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_EIChannels[0], 8U,
        &so_observador_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_POPStart && !is_switching) ||
        (so_observador_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &so_observador_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = so_observador_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &so_observador_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &so_observador_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &so_observador_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            so_observador_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            so_observador_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = so_observador_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            so_observador_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            so_observador_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = so_observador_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(so_observador_DWork.HILInitialize_Card,
          &so_observador_DWork.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &so_observador_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(so_observador_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(so_observador_DWork.HILInitialize_Card,
          &so_observador_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &so_observador_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(so_observador_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &so_observador_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = so_observador_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &so_observador_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = so_observador_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &so_observador_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = so_observador_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_POChannels[0], 8U,
        (t_pwm_configuration *) &so_observador_DWork.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &so_observador_DWork.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &so_observador_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &so_observador_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = so_observador_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &so_observador_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = so_observador_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_POChannels[0], 8U,
        &so_observador_DWork.HILInitialize_POSortedFreqs[0],
        &so_observador_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if ((so_observador_P.HILInitialize_POStart && !is_switching) ||
        (so_observador_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &so_observador_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = so_observador_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(so_observador_DWork.HILInitialize_Card,
        &so_observador_P.HILInitialize_POChannels[0], 8U,
        &so_observador_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }

    if (so_observador_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &so_observador_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = so_observador_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (so_observador_DWork.HILInitialize_Card,
         &so_observador_P.HILInitialize_POChannels[0], 8U,
         &so_observador_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(so_observador_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: so_observador/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (so_observador_DWork.HILInitialize_Card,
       so_observador_P.EncoderInput0CartPositionEnco_n,
       so_observador_P.EncoderInput0CartPositionEnco_h, 2,
       &so_observador_DWork.EncoderInput0CartPositionEnco_o);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(so_observador_M, _rt_error_message);
    }
  }

  /* Start for enable SubSystem: '<S1>/Cart Position Watchdog' */
  so_observador_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S1>/Cart Position Watchdog' */
  MdlInitialize();
}

RT_MODEL_so_observador *so_observador(void)
{
  so_observador_initialize(1);
  return so_observador_M;
}

void MdlTerminate(void)
{
  so_observador_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
