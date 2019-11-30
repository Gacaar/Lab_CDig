/*
 * ControlSemCanalslx.c
 *
 * Real-Time Workshop code generation for Simulink model "ControlSemCanalslx.mdl".
 *
 * Model Version              : 1.24
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Nov 21 08:52:55 2019
 */

#include "ControlSemCanalslx.h"
#include "ControlSemCanalslx_private.h"
#include <stdio.h>
#include "ControlSemCanalslx_dt.h"

/* Block signals (auto storage) */
BlockIO_ControlSemCanalslx ControlSemCanalslx_B;

/* Block states (auto storage) */
D_Work_ControlSemCanalslx ControlSemCanalslx_DWork;

/* Real-time model */
RT_MODEL_ControlSemCanalslx ControlSemCanalslx_M_;
RT_MODEL_ControlSemCanalslx *ControlSemCanalslx_M = &ControlSemCanalslx_M_;

/* Model output function */
void ControlSemCanalslx_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput0CartPositionEn;
  real_T rtb_SquareWaveGenerator1;
  real_T rtb_Sum9;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_l;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControlSemCanalslx_DWork.CartPositionWatchdog_SubsysRanB);

  {
    real_T rtb_Conversiontom;
    real_T currentTime;

    /* S-Function Block: ControlSemCanalslx/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (ControlSemCanalslx_DWork.EncoderInput0CartPositionEnco_b, 1,
         &ControlSemCanalslx_DWork.EncoderInput0CartPositionEncode[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      } else {
        rtb_EncoderInput0CartPositionEn =
          ControlSemCanalslx_DWork.EncoderInput0CartPositionEncode[0];
        rtb_Sum9 = ControlSemCanalslx_DWork.EncoderInput0CartPositionEncode[1];
      }
    }

    /* Gain: '<S1>/Conversion to m' */
    rtb_Conversiontom = ControlSemCanalslx_P.Conversiontom_Gain *
      rtb_EncoderInput0CartPositionEn;

    /* Outputs for enable SubSystem: '<S1>/Cart Position Watchdog' incorporates:
     *  Constant: '<S1>/Constant'
     *  EnablePort: '<S3>/Enable'
     */
    if (ControlSemCanalslx_P.Constant_Value > 0.0) {
      if (ControlSemCanalslx_DWork.CartPositionWatchdog_MODE == SUBSYS_DISABLED)
      {
        ControlSemCanalslx_DWork.CartPositionWatchdog_MODE = SUBSYS_ENABLED;
      }
    } else {
      if (ControlSemCanalslx_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED)
      {
        ControlSemCanalslx_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;
      }
    }

    if (ControlSemCanalslx_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
      /* RelationalOperator: '<S3>/Check Maximum Allowed Position' incorporates:
       *  Constant: '<S3>/X MAX'
       */
      ControlSemCanalslx_B.CheckMaximumAllowedPosition =
        (ControlSemCanalslx_P.XMAX_Value < rtb_Conversiontom);

      /* RelationalOperator: '<S7>/Compare' */
      rtb_Compare = (ControlSemCanalslx_B.CheckMaximumAllowedPosition != FALSE);

      /* Stop: '<S5>/Stop Simulation' */
      if (rtb_Compare) {
        rtmSetStopRequested(ControlSemCanalslx_M, 1);
      }

      /* RelationalOperator: '<S3>/Check Minimum Allowed Position' incorporates:
       *  Constant: '<S3>/X IN'
       */
      ControlSemCanalslx_B.CheckMinimumAllowedPosition = (rtb_Conversiontom <
        ControlSemCanalslx_P.XIN_Value);

      /* RelationalOperator: '<S8>/Compare' */
      rtb_Compare_l = (ControlSemCanalslx_B.CheckMinimumAllowedPosition != FALSE);

      /* Stop: '<S6>/Stop Simulation' */
      if (rtb_Compare_l) {
        rtmSetStopRequested(ControlSemCanalslx_M, 1);
      }

      srUpdateBC(ControlSemCanalslx_DWork.CartPositionWatchdog_SubsysRanB);
    }

    /* end of Outputs for SubSystem: '<S1>/Cart Position Watchdog' */

    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<S1>/Conversion to rd'
     */
    ControlSemCanalslx_B.Gain = ControlSemCanalslx_P.Conversiontord_Gain *
      rtb_Sum9 * ControlSemCanalslx_P.Gain_Gain;

    /* Gain: '<S1>/m to mm' */
    ControlSemCanalslx_B.mtomm = ControlSemCanalslx_P.mtomm_Gain *
      rtb_Conversiontom;

    /* Step: '<Root>/Step1' */
    currentTime = ControlSemCanalslx_M->Timing.t[0];
    if (currentTime < ControlSemCanalslx_P.Step1_Time) {
      currentTime = ControlSemCanalslx_P.Step1_Y0;
    } else {
      currentTime = ControlSemCanalslx_P.Step1_YFinal;
    }

    /* SignalGenerator: '<Root>/Square Wave Generator1' */
    {
      real_T phase = ControlSemCanalslx_P.SquareWaveGenerator1_Frequency*
        ControlSemCanalslx_M->Timing.t[0];
      phase = phase-floor(phase);
      rtb_SquareWaveGenerator1 = ( phase >= 0.5 ) ?
        ControlSemCanalslx_P.SquareWaveGenerator1_Amplitude :
        -ControlSemCanalslx_P.SquareWaveGenerator1_Amplitude;
    }

    /* Switch: '<S2>/SwitchControl' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (!(ControlSemCanalslx_P.Constant_Value_i >
          ControlSemCanalslx_P.SwitchControl_Threshold)) {
      currentTime = rtb_SquareWaveGenerator1;
    }

    /* Gain: '<Root>/Gain6' incorporates:
     *  Gain: '<Root>/mm to m'
     */
    currentTime = ControlSemCanalslx_P.mmtom_Gain * currentTime *
      ControlSemCanalslx_P.Gain6_Gain;

    /* S-Function (sfix_udelay): '<Root>/Delay3'
     *
     * Regarding '<Root>/Delay3':
     * Integer/Tapped Delay Block: '<Root>/Delay3'
     */
    ControlSemCanalslx_B.xk[0] = ControlSemCanalslx_DWork.Delay3_X[0];
    ControlSemCanalslx_B.xk[1] = ControlSemCanalslx_DWork.Delay3_X[1];

    /* Gain: '<Root>/Gain2' */
    ControlSemCanalslx_B.Gain2 = ControlSemCanalslx_P.Gain2_Gain[0] *
      ControlSemCanalslx_B.xk[0] + ControlSemCanalslx_P.Gain2_Gain[1] *
      ControlSemCanalslx_B.xk[1];

    /* Sum: '<Root>/Sum6' */
    ControlSemCanalslx_B.U = currentTime - ControlSemCanalslx_B.Gain2;

    /* Saturate: '<Root>/Amplifier Voltage Limit' */
    ControlSemCanalslx_B.U_d = rt_SATURATE(ControlSemCanalslx_B.U,
      ControlSemCanalslx_P.AmplifierVoltageLimit_LowerSat,
      ControlSemCanalslx_P.AmplifierVoltageLimit_UpperSat);

    /* Gain: '<S1>/Cable Gain Pre-Compensation' */
    rtb_Sum9 = ControlSemCanalslx_P.CableGainPreCompensation_Gain *
      ControlSemCanalslx_B.U_d;

    /* Saturate: '<S1>/DAC Limit' */
    rtb_Sum9 = rt_SATURATE(rtb_Sum9, ControlSemCanalslx_P.DACLimit_LowerSat,
      ControlSemCanalslx_P.DACLimit_UpperSat);

    /* S-Function Block: ControlSemCanalslx/IP02/Analog Output #0: To Amplifier Driving the Motor (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.AnalogOutput0ToAmplifierDriving, 1, &rtb_Sum9);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      }
    }

    /* Gain: '<S1>/Cable Gain' */
    ControlSemCanalslx_B.CableGain = ControlSemCanalslx_P.CableGain_Gain *
      rtb_Sum9;

    /* Gain: '<Root>/Gain13' */
    rtb_Sum9 = ControlSemCanalslx_P.Gain13_Gain[0] * ControlSemCanalslx_B.xk[0]
      + ControlSemCanalslx_P.Gain13_Gain[1] * ControlSemCanalslx_B.xk[1];

    /* Gain: '<Root>/m to mm  1' */
    ControlSemCanalslx_B.mtomm1[0] = ControlSemCanalslx_P.mtomm1_Gain *
      rtb_Conversiontom;
    ControlSemCanalslx_B.mtomm1[1] = ControlSemCanalslx_P.mtomm1_Gain * rtb_Sum9;

    /* Sum: '<Root>/Sum9' */
    rtb_Sum9 = rtb_Conversiontom - rtb_Sum9;

    /* Sum: '<Root>/Sum7' incorporates:
     *  Gain: '<Root>/Gain10'
     *  Gain: '<Root>/Gain11'
     *  Gain: '<Root>/Gain12'
     */
    ControlSemCanalslx_B.xk1[0] = (ControlSemCanalslx_P.Gain10_Gain[0] *
      rtb_Sum9 + ControlSemCanalslx_P.Gain12_Gain[0] * ControlSemCanalslx_B.U_d)
      + (ControlSemCanalslx_P.Gain11_Gain[0] * ControlSemCanalslx_B.xk[0] +
         ControlSemCanalslx_P.Gain11_Gain[2] * ControlSemCanalslx_B.xk[1]);
    ControlSemCanalslx_B.xk1[1] = (ControlSemCanalslx_P.Gain10_Gain[1] *
      rtb_Sum9 + ControlSemCanalslx_P.Gain12_Gain[1] * ControlSemCanalslx_B.U_d)
      + (ControlSemCanalslx_P.Gain11_Gain[1] * ControlSemCanalslx_B.xk[0] +
         ControlSemCanalslx_P.Gain11_Gain[3] * ControlSemCanalslx_B.xk[1]);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void ControlSemCanalslx_update(int_T tid)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay3'
   */
  (void) memcpy(&ControlSemCanalslx_DWork.Delay3_X[0],ControlSemCanalslx_B.xk1,
                2*sizeof(real_T));

  /* Update absolute time for base rate */
  if (!(++ControlSemCanalslx_M->Timing.clockTick0))
    ++ControlSemCanalslx_M->Timing.clockTickH0;
  ControlSemCanalslx_M->Timing.t[0] = ControlSemCanalslx_M->Timing.clockTick0 *
    ControlSemCanalslx_M->Timing.stepSize0 +
    ControlSemCanalslx_M->Timing.clockTickH0 *
    ControlSemCanalslx_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.3000000000000001E-002s, 0.0s] */
    if (!(++ControlSemCanalslx_M->Timing.clockTick1))
      ++ControlSemCanalslx_M->Timing.clockTickH1;
    ControlSemCanalslx_M->Timing.t[1] = ControlSemCanalslx_M->Timing.clockTick1 *
      ControlSemCanalslx_M->Timing.stepSize1 +
      ControlSemCanalslx_M->Timing.clockTickH1 *
      ControlSemCanalslx_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void ControlSemCanalslx_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ControlSemCanalslx_M,0,
                sizeof(RT_MODEL_ControlSemCanalslx));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlSemCanalslx_M->solverInfo,
                          &ControlSemCanalslx_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlSemCanalslx_M->solverInfo, &rtmGetTPtr
                (ControlSemCanalslx_M));
    rtsiSetStepSizePtr(&ControlSemCanalslx_M->solverInfo,
                       &ControlSemCanalslx_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ControlSemCanalslx_M->solverInfo, (&rtmGetErrorStatus
                           (ControlSemCanalslx_M)));
    rtsiSetRTModelPtr(&ControlSemCanalslx_M->solverInfo, ControlSemCanalslx_M);
  }

  rtsiSetSimTimeStep(&ControlSemCanalslx_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ControlSemCanalslx_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ControlSemCanalslx_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ControlSemCanalslx_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ControlSemCanalslx_M->Timing.sampleTimes =
      (&ControlSemCanalslx_M->Timing.sampleTimesArray[0]);
    ControlSemCanalslx_M->Timing.offsetTimes =
      (&ControlSemCanalslx_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControlSemCanalslx_M->Timing.sampleTimes[0] = (0.0);
    ControlSemCanalslx_M->Timing.sampleTimes[1] = (1.3000000000000001E-002);

    /* task offsets */
    ControlSemCanalslx_M->Timing.offsetTimes[0] = (0.0);
    ControlSemCanalslx_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ControlSemCanalslx_M, &ControlSemCanalslx_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ControlSemCanalslx_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ControlSemCanalslx_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControlSemCanalslx_M, 5.993);
  ControlSemCanalslx_M->Timing.stepSize0 = 1.3000000000000001E-002;
  ControlSemCanalslx_M->Timing.stepSize1 = 1.3000000000000001E-002;

  /* external mode info */
  ControlSemCanalslx_M->Sizes.checksums[0] = (2977635087U);
  ControlSemCanalslx_M->Sizes.checksums[1] = (3757637251U);
  ControlSemCanalslx_M->Sizes.checksums[2] = (173849326U);
  ControlSemCanalslx_M->Sizes.checksums[3] = (3204673066U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ControlSemCanalslx_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &ControlSemCanalslx_DWork.CartPositionWatchdog_SubsysRanB;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &ControlSemCanalslx_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, ControlSemCanalslx_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(ControlSemCanalslx_M));
  }

  ControlSemCanalslx_M->solverInfoPtr = (&ControlSemCanalslx_M->solverInfo);
  ControlSemCanalslx_M->Timing.stepSize = (1.3000000000000001E-002);
  rtsiSetFixedStepSize(&ControlSemCanalslx_M->solverInfo,
                       1.3000000000000001E-002);
  rtsiSetSolverMode(&ControlSemCanalslx_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ControlSemCanalslx_M->ModelData.blockIO = ((void *) &ControlSemCanalslx_B);
  (void) memset(((void *) &ControlSemCanalslx_B),0,
                sizeof(BlockIO_ControlSemCanalslx));

  /* parameters */
  ControlSemCanalslx_M->ModelData.defaultParam = ((real_T *)
    &ControlSemCanalslx_P);

  /* states (dwork) */
  ControlSemCanalslx_M->Work.dwork = ((void *) &ControlSemCanalslx_DWork);
  (void) memset((void *)&ControlSemCanalslx_DWork, 0,
                sizeof(D_Work_ControlSemCanalslx));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    ControlSemCanalslx_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void ControlSemCanalslx_terminate(void)
{
  /* S-Function Block: ControlSemCanalslx/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(ControlSemCanalslx_DWork.HILInitialize_Card);
    hil_task_delete_all(ControlSemCanalslx_DWork.HILInitialize_Card);
    hil_monitor_stop_all(ControlSemCanalslx_DWork.HILInitialize_Card);
    hil_monitor_delete_all(ControlSemCanalslx_DWork.HILInitialize_Card);
    is_switching = false;
    if ((ControlSemCanalslx_P.HILInitialize_AOTerminate && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControlSemCanalslx_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_AOChannels[0], 8U,
        &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_DOTerminate && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &ControlSemCanalslx_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = ControlSemCanalslx_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &ControlSemCanalslx_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_POTerminate && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &ControlSemCanalslx_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControlSemCanalslx_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U,
        &ControlSemCanalslx_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      }
    }

    hil_close(ControlSemCanalslx_DWork.HILInitialize_Card);
    ControlSemCanalslx_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ControlSemCanalslx_output(tid);
}

void MdlUpdate(int_T tid)
{
  ControlSemCanalslx_update(tid);
}

void MdlInitializeSizes(void)
{
  ControlSemCanalslx_M->Sizes.numContStates = (0);/* Number of continuous states */
  ControlSemCanalslx_M->Sizes.numY = (0);/* Number of model outputs */
  ControlSemCanalslx_M->Sizes.numU = (0);/* Number of model inputs */
  ControlSemCanalslx_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ControlSemCanalslx_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ControlSemCanalslx_M->Sizes.numBlocks = (48);/* Number of blocks */
  ControlSemCanalslx_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  ControlSemCanalslx_M->Sizes.numBlockPrms = (145);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay3'
   * Initialize State
   * Initial Condition parameter uses the same data type and scaling as Output0
   */
  ControlSemCanalslx_DWork.Delay3_X[0] =
    ControlSemCanalslx_P.Delay3_InitialCondition;
  ControlSemCanalslx_DWork.Delay3_X[1] =
    ControlSemCanalslx_P.Delay3_InitialCondition;
}

void MdlStart(void)
{
  /* S-Function Block: ControlSemCanalslx/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &ControlSemCanalslx_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (ControlSemCanalslx_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ControlSemCanalslx_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      return;
    }

    if ((ControlSemCanalslx_P.HILInitialize_AIPStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &ControlSemCanalslx_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = ControlSemCanalslx_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &ControlSemCanalslx_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = ControlSemCanalslx_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_AIChannels[0], 8U,
         &ControlSemCanalslx_DWork.HILInitialize_AIMinimums[0],
         &ControlSemCanalslx_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_AOPStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &ControlSemCanalslx_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = ControlSemCanalslx_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &ControlSemCanalslx_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = ControlSemCanalslx_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_AOChannels[0], 8U,
         &ControlSemCanalslx_DWork.HILInitialize_AOMinimums[0],
         &ControlSemCanalslx_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_AOStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControlSemCanalslx_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_AOChannels[0], 8U,
        &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if (ControlSemCanalslx_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControlSemCanalslx_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_AOChannels[0], 8U,
         &ControlSemCanalslx_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (ControlSemCanalslx_DWork.HILInitialize_Card, NULL, 0U,
       &ControlSemCanalslx_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
      return;
    }

    if ((ControlSemCanalslx_P.HILInitialize_DOStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &ControlSemCanalslx_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = ControlSemCanalslx_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &ControlSemCanalslx_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if (ControlSemCanalslx_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &ControlSemCanalslx_DWork.HILInitialize_DOStates
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = ControlSemCanalslx_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &ControlSemCanalslx_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_EIPStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &ControlSemCanalslx_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            ControlSemCanalslx_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &ControlSemCanalslx_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_EIStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &ControlSemCanalslx_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = ControlSemCanalslx_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_EIChannels[0], 8U,
         &ControlSemCanalslx_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_POPStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &ControlSemCanalslx_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = ControlSemCanalslx_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &ControlSemCanalslx_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &ControlSemCanalslx_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &ControlSemCanalslx_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            ControlSemCanalslx_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = ControlSemCanalslx_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            ControlSemCanalslx_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              ControlSemCanalslx_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (ControlSemCanalslx_DWork.HILInitialize_Card,
           &ControlSemCanalslx_DWork.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (ControlSemCanalslx_DWork.HILInitialize_Card,
           &ControlSemCanalslx_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &ControlSemCanalslx_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            ControlSemCanalslx_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &ControlSemCanalslx_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = ControlSemCanalslx_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &ControlSemCanalslx_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = ControlSemCanalslx_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &ControlSemCanalslx_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &ControlSemCanalslx_DWork.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &ControlSemCanalslx_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = ControlSemCanalslx_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &ControlSemCanalslx_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControlSemCanalslx_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U,
        &ControlSemCanalslx_DWork.HILInitialize_POSortedFreqs[0],
        &ControlSemCanalslx_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if ((ControlSemCanalslx_P.HILInitialize_POStart && !is_switching) ||
        (ControlSemCanalslx_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &ControlSemCanalslx_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControlSemCanalslx_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(ControlSemCanalslx_DWork.HILInitialize_Card,
        &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U,
        &ControlSemCanalslx_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }

    if (ControlSemCanalslx_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &ControlSemCanalslx_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControlSemCanalslx_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (ControlSemCanalslx_DWork.HILInitialize_Card,
         &ControlSemCanalslx_P.HILInitialize_POChannels[0], 8U,
         &ControlSemCanalslx_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: ControlSemCanalslx/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (ControlSemCanalslx_DWork.HILInitialize_Card,
       ControlSemCanalslx_P.EncoderInput0CartPositionEnco_e,
       ControlSemCanalslx_P.EncoderInput0CartPositionEnco_j, 2,
       &ControlSemCanalslx_DWork.EncoderInput0CartPositionEnco_b);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControlSemCanalslx_M, _rt_error_message);
    }
  }

  /* Start for enable SubSystem: '<S1>/Cart Position Watchdog' */
  ControlSemCanalslx_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S1>/Cart Position Watchdog' */
  MdlInitialize();
}

RT_MODEL_ControlSemCanalslx *ControlSemCanalslx(void)
{
  ControlSemCanalslx_initialize(1);
  return ControlSemCanalslx_M;
}

void MdlTerminate(void)
{
  ControlSemCanalslx_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
