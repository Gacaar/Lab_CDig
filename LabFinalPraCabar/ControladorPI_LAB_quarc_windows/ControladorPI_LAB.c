/*
 * ControladorPI_LAB.c
 *
 * Real-Time Workshop code generation for Simulink model "ControladorPI_LAB.mdl".
 *
 * Model Version              : 1.17
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Nov 21 08:53:16 2019
 */

#include "ControladorPI_LAB.h"
#include "ControladorPI_LAB_private.h"
#include <stdio.h>
#include "ControladorPI_LAB_dt.h"

/* Block signals (auto storage) */
BlockIO_ControladorPI_LAB ControladorPI_LAB_B;

/* Block states (auto storage) */
D_Work_ControladorPI_LAB ControladorPI_LAB_DWork;

/* Real-time model */
RT_MODEL_ControladorPI_LAB ControladorPI_LAB_M_;
RT_MODEL_ControladorPI_LAB *ControladorPI_LAB_M = &ControladorPI_LAB_M_;

/* Model output function */
void ControladorPI_LAB_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput0CartPositionEn;
  real_T rtb_SquareWave;
  real_T rtb_Sum9;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_b;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControladorPI_LAB_DWork.CartPositionWatchdog_SubsysRanB);

  {
    real_T currentTime;

    /* S-Function Block: ControladorPI_LAB/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (ControladorPI_LAB_DWork.EncoderInput0CartPositionEnco_m, 1,
         &ControladorPI_LAB_DWork.EncoderInput0CartPositionEncode[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      } else {
        rtb_EncoderInput0CartPositionEn =
          ControladorPI_LAB_DWork.EncoderInput0CartPositionEncode[0];
        rtb_Sum9 = ControladorPI_LAB_DWork.EncoderInput0CartPositionEncode[1];
      }
    }

    /* Gain: '<S1>/Conversion to m' */
    ControladorPI_LAB_B.Conversiontom = ControladorPI_LAB_P.Conversiontom_Gain *
      rtb_EncoderInput0CartPositionEn;

    /* Outputs for enable SubSystem: '<S1>/Cart Position Watchdog' incorporates:
     *  Constant: '<S1>/Constant'
     *  EnablePort: '<S3>/Enable'
     */
    if (ControladorPI_LAB_P.Constant_Value > 0.0) {
      if (ControladorPI_LAB_DWork.CartPositionWatchdog_MODE == SUBSYS_DISABLED)
      {
        ControladorPI_LAB_DWork.CartPositionWatchdog_MODE = SUBSYS_ENABLED;
      }
    } else {
      if (ControladorPI_LAB_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
        ControladorPI_LAB_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;
      }
    }

    if (ControladorPI_LAB_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
      /* RelationalOperator: '<S3>/Check Maximum Allowed Position' incorporates:
       *  Constant: '<S3>/X MAX'
       */
      ControladorPI_LAB_B.CheckMaximumAllowedPosition =
        (ControladorPI_LAB_P.XMAX_Value < ControladorPI_LAB_B.Conversiontom);

      /* RelationalOperator: '<S7>/Compare' */
      rtb_Compare = (ControladorPI_LAB_B.CheckMaximumAllowedPosition != FALSE);

      /* Stop: '<S5>/Stop Simulation' */
      if (rtb_Compare) {
        rtmSetStopRequested(ControladorPI_LAB_M, 1);
      }

      /* RelationalOperator: '<S3>/Check Minimum Allowed Position' incorporates:
       *  Constant: '<S3>/X IN'
       */
      ControladorPI_LAB_B.CheckMinimumAllowedPosition =
        (ControladorPI_LAB_B.Conversiontom < ControladorPI_LAB_P.XIN_Value);

      /* RelationalOperator: '<S8>/Compare' */
      rtb_Compare_b = (ControladorPI_LAB_B.CheckMinimumAllowedPosition != FALSE);

      /* Stop: '<S6>/Stop Simulation' */
      if (rtb_Compare_b) {
        rtmSetStopRequested(ControladorPI_LAB_M, 1);
      }

      srUpdateBC(ControladorPI_LAB_DWork.CartPositionWatchdog_SubsysRanB);
    }

    /* end of Outputs for SubSystem: '<S1>/Cart Position Watchdog' */

    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<S1>/Conversion to rd'
     */
    ControladorPI_LAB_B.Gain = ControladorPI_LAB_P.Conversiontord_Gain *
      rtb_Sum9 * ControladorPI_LAB_P.Gain_Gain;

    /* Gain: '<S1>/m to mm' */
    ControladorPI_LAB_B.mtomm = ControladorPI_LAB_P.mtomm_Gain *
      ControladorPI_LAB_B.Conversiontom;

    /* Step: '<Root>/Step1' */
    currentTime = ControladorPI_LAB_M->Timing.t[0];
    if (currentTime < ControladorPI_LAB_P.Step1_Time) {
      currentTime = ControladorPI_LAB_P.Step1_Y0;
    } else {
      currentTime = ControladorPI_LAB_P.Step1_YFinal;
    }

    /* SignalGenerator: '<Root>/Square Wave' */
    {
      real_T phase = ControladorPI_LAB_P.SquareWave_Frequency*
        ControladorPI_LAB_M->Timing.t[0];
      phase = phase-floor(phase);
      rtb_SquareWave = ( phase >= 0.5 ) ?
        ControladorPI_LAB_P.SquareWave_Amplitude :
        -ControladorPI_LAB_P.SquareWave_Amplitude;
    }

    /* Switch: '<S2>/SwitchControl' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (!(ControladorPI_LAB_P.Constant_Value_l >
          ControladorPI_LAB_P.SwitchControl_Threshold)) {
      currentTime = rtb_SquareWave;
    }

    /* Sum: '<Root>/Sum8' incorporates:
     *  Gain: '<Root>/Gain6'
     *  Gain: '<Root>/mm to m'
     */
    currentTime = ControladorPI_LAB_P.mmtom_Gain * currentTime *
      ControladorPI_LAB_P.Gain6_Gain - ControladorPI_LAB_B.Conversiontom;

    /* S-Function (sfix_udelay): '<Root>/Delay2'
     *
     * Regarding '<Root>/Delay2':
     * Integer/Tapped Delay Block: '<Root>/Delay2'
     */
    ControladorPI_LAB_B.Delay2 = ControladorPI_LAB_DWork.Delay2_X;

    /* Sum: '<Root>/Sum5' */
    ControladorPI_LAB_B.Sum5 = currentTime + ControladorPI_LAB_B.Delay2;

    /* Gain: '<Root>/Gain3' */
    currentTime = ControladorPI_LAB_P.Gain3_Gain * ControladorPI_LAB_B.Sum5;

    /* S-Function (sfix_udelay): '<Root>/Delay3'
     *
     * Regarding '<Root>/Delay3':
     * Integer/Tapped Delay Block: '<Root>/Delay3'
     */
    ControladorPI_LAB_B.xk[0] = ControladorPI_LAB_DWork.Delay3_X[0];
    ControladorPI_LAB_B.xk[1] = ControladorPI_LAB_DWork.Delay3_X[1];

    /* Gain: '<Root>/Gain2' */
    ControladorPI_LAB_B.Gain2 = ControladorPI_LAB_P.Gain2_Gain[0] *
      ControladorPI_LAB_B.xk[0] + ControladorPI_LAB_P.Gain2_Gain[1] *
      ControladorPI_LAB_B.xk[1];

    /* Sum: '<Root>/Sum6' */
    ControladorPI_LAB_B.U = currentTime - ControladorPI_LAB_B.Gain2;

    /* Saturate: '<Root>/Amplifier Voltage Limit' */
    ControladorPI_LAB_B.AmplifierVoltageLimit = rt_SATURATE
      (ControladorPI_LAB_B.U, ControladorPI_LAB_P.AmplifierVoltageLimit_LowerSat,
       ControladorPI_LAB_P.AmplifierVoltageLimit_UpperSat);

    /* Gain: '<S1>/Cable Gain Pre-Compensation' */
    rtb_Sum9 = ControladorPI_LAB_P.CableGainPreCompensation_Gain *
      ControladorPI_LAB_B.AmplifierVoltageLimit;

    /* Saturate: '<S1>/DAC Limit' */
    rtb_Sum9 = rt_SATURATE(rtb_Sum9, ControladorPI_LAB_P.DACLimit_LowerSat,
      ControladorPI_LAB_P.DACLimit_UpperSat);

    /* S-Function Block: ControladorPI_LAB/IP02/Analog Output #0: To Amplifier Driving the Motor (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.AnalogOutput0ToAmplifierDriving, 1, &rtb_Sum9);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      }
    }

    /* Gain: '<S1>/Cable Gain' */
    ControladorPI_LAB_B.CableGain = ControladorPI_LAB_P.CableGain_Gain *
      rtb_Sum9;

    /* Gain: '<Root>/m to mm  1' */
    ControladorPI_LAB_B.mtomm1 = ControladorPI_LAB_P.mtomm1_Gain *
      ControladorPI_LAB_B.Conversiontom;

    /* Gain: '<Root>/Gain13' */
    ControladorPI_LAB_B.Gain13 = ControladorPI_LAB_P.Gain13_Gain[0] *
      ControladorPI_LAB_B.xk[0] + ControladorPI_LAB_P.Gain13_Gain[1] *
      ControladorPI_LAB_B.xk[1];

    /* Sum: '<Root>/Sum9' */
    rtb_Sum9 = ControladorPI_LAB_B.Conversiontom - ControladorPI_LAB_B.Gain13;

    /* Sum: '<Root>/Sum7' incorporates:
     *  Gain: '<Root>/Gain10'
     *  Gain: '<Root>/Gain11'
     *  Gain: '<Root>/Gain12'
     */
    ControladorPI_LAB_B.xk1[0] = (ControladorPI_LAB_P.Gain10_Gain[0] * rtb_Sum9
      + ControladorPI_LAB_P.Gain12_Gain[0] *
      ControladorPI_LAB_B.AmplifierVoltageLimit) +
      (ControladorPI_LAB_P.Gain11_Gain[0] * ControladorPI_LAB_B.xk[0] +
       ControladorPI_LAB_P.Gain11_Gain[2] * ControladorPI_LAB_B.xk[1]);
    ControladorPI_LAB_B.xk1[1] = (ControladorPI_LAB_P.Gain10_Gain[1] * rtb_Sum9
      + ControladorPI_LAB_P.Gain12_Gain[1] *
      ControladorPI_LAB_B.AmplifierVoltageLimit) +
      (ControladorPI_LAB_P.Gain11_Gain[1] * ControladorPI_LAB_B.xk[0] +
       ControladorPI_LAB_P.Gain11_Gain[3] * ControladorPI_LAB_B.xk[1]);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void ControladorPI_LAB_update(int_T tid)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay2'
   */
  ControladorPI_LAB_DWork.Delay2_X = ControladorPI_LAB_B.Sum5;

  /* Integer/Tapped Delay Block: '<Root>/Delay3'
   */
  (void) memcpy(&ControladorPI_LAB_DWork.Delay3_X[0],ControladorPI_LAB_B.xk1,
                2*sizeof(real_T));

  /* Update absolute time for base rate */
  if (!(++ControladorPI_LAB_M->Timing.clockTick0))
    ++ControladorPI_LAB_M->Timing.clockTickH0;
  ControladorPI_LAB_M->Timing.t[0] = ControladorPI_LAB_M->Timing.clockTick0 *
    ControladorPI_LAB_M->Timing.stepSize0 +
    ControladorPI_LAB_M->Timing.clockTickH0 *
    ControladorPI_LAB_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.3000000000000001E-002s, 0.0s] */
    if (!(++ControladorPI_LAB_M->Timing.clockTick1))
      ++ControladorPI_LAB_M->Timing.clockTickH1;
    ControladorPI_LAB_M->Timing.t[1] = ControladorPI_LAB_M->Timing.clockTick1 *
      ControladorPI_LAB_M->Timing.stepSize1 +
      ControladorPI_LAB_M->Timing.clockTickH1 *
      ControladorPI_LAB_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void ControladorPI_LAB_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ControladorPI_LAB_M,0,
                sizeof(RT_MODEL_ControladorPI_LAB));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControladorPI_LAB_M->solverInfo,
                          &ControladorPI_LAB_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControladorPI_LAB_M->solverInfo, &rtmGetTPtr
                (ControladorPI_LAB_M));
    rtsiSetStepSizePtr(&ControladorPI_LAB_M->solverInfo,
                       &ControladorPI_LAB_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ControladorPI_LAB_M->solverInfo, (&rtmGetErrorStatus
      (ControladorPI_LAB_M)));
    rtsiSetRTModelPtr(&ControladorPI_LAB_M->solverInfo, ControladorPI_LAB_M);
  }

  rtsiSetSimTimeStep(&ControladorPI_LAB_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ControladorPI_LAB_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ControladorPI_LAB_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ControladorPI_LAB_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ControladorPI_LAB_M->Timing.sampleTimes =
      (&ControladorPI_LAB_M->Timing.sampleTimesArray[0]);
    ControladorPI_LAB_M->Timing.offsetTimes =
      (&ControladorPI_LAB_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControladorPI_LAB_M->Timing.sampleTimes[0] = (0.0);
    ControladorPI_LAB_M->Timing.sampleTimes[1] = (1.3000000000000001E-002);

    /* task offsets */
    ControladorPI_LAB_M->Timing.offsetTimes[0] = (0.0);
    ControladorPI_LAB_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ControladorPI_LAB_M, &ControladorPI_LAB_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ControladorPI_LAB_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ControladorPI_LAB_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControladorPI_LAB_M, 4.9920000000000009E+000);
  ControladorPI_LAB_M->Timing.stepSize0 = 1.3000000000000001E-002;
  ControladorPI_LAB_M->Timing.stepSize1 = 1.3000000000000001E-002;

  /* external mode info */
  ControladorPI_LAB_M->Sizes.checksums[0] = (3996521114U);
  ControladorPI_LAB_M->Sizes.checksums[1] = (2325476511U);
  ControladorPI_LAB_M->Sizes.checksums[2] = (2834264086U);
  ControladorPI_LAB_M->Sizes.checksums[3] = (245202598U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ControladorPI_LAB_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &ControladorPI_LAB_DWork.CartPositionWatchdog_SubsysRanB;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &ControladorPI_LAB_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, ControladorPI_LAB_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(ControladorPI_LAB_M));
  }

  ControladorPI_LAB_M->solverInfoPtr = (&ControladorPI_LAB_M->solverInfo);
  ControladorPI_LAB_M->Timing.stepSize = (1.3000000000000001E-002);
  rtsiSetFixedStepSize(&ControladorPI_LAB_M->solverInfo, 1.3000000000000001E-002);
  rtsiSetSolverMode(&ControladorPI_LAB_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ControladorPI_LAB_M->ModelData.blockIO = ((void *) &ControladorPI_LAB_B);
  (void) memset(((void *) &ControladorPI_LAB_B),0,
                sizeof(BlockIO_ControladorPI_LAB));

  /* parameters */
  ControladorPI_LAB_M->ModelData.defaultParam = ((real_T *) &ControladorPI_LAB_P);

  /* states (dwork) */
  ControladorPI_LAB_M->Work.dwork = ((void *) &ControladorPI_LAB_DWork);
  (void) memset((void *)&ControladorPI_LAB_DWork, 0,
                sizeof(D_Work_ControladorPI_LAB));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    ControladorPI_LAB_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void ControladorPI_LAB_terminate(void)
{
  /* S-Function Block: ControladorPI_LAB/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(ControladorPI_LAB_DWork.HILInitialize_Card);
    hil_task_delete_all(ControladorPI_LAB_DWork.HILInitialize_Card);
    hil_monitor_stop_all(ControladorPI_LAB_DWork.HILInitialize_Card);
    hil_monitor_delete_all(ControladorPI_LAB_DWork.HILInitialize_Card);
    is_switching = false;
    if ((ControladorPI_LAB_P.HILInitialize_AOTerminate && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControladorPI_LAB_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_AOChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_DOTerminate && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &ControladorPI_LAB_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = ControladorPI_LAB_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &ControladorPI_LAB_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_POTerminate && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &ControladorPI_LAB_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControladorPI_LAB_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      }
    }

    hil_close(ControladorPI_LAB_DWork.HILInitialize_Card);
    ControladorPI_LAB_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ControladorPI_LAB_output(tid);
}

void MdlUpdate(int_T tid)
{
  ControladorPI_LAB_update(tid);
}

void MdlInitializeSizes(void)
{
  ControladorPI_LAB_M->Sizes.numContStates = (0);/* Number of continuous states */
  ControladorPI_LAB_M->Sizes.numY = (0);/* Number of model outputs */
  ControladorPI_LAB_M->Sizes.numU = (0);/* Number of model inputs */
  ControladorPI_LAB_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ControladorPI_LAB_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ControladorPI_LAB_M->Sizes.numBlocks = (49);/* Number of blocks */
  ControladorPI_LAB_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  ControladorPI_LAB_M->Sizes.numBlockPrms = (147);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Integer/Tapped Delay Block: '<Root>/Delay2'
   * Initialize State
   * Initial Condition parameter uses the same data type and scaling as Output0
   */
  ControladorPI_LAB_DWork.Delay2_X = ControladorPI_LAB_P.Delay2_InitialCondition;

  /* Integer/Tapped Delay Block: '<Root>/Delay3'
   * Initialize State
   * Initial Condition parameter uses the same data type and scaling as Output0
   */
  ControladorPI_LAB_DWork.Delay3_X[0] =
    ControladorPI_LAB_P.Delay3_InitialCondition;
  ControladorPI_LAB_DWork.Delay3_X[1] =
    ControladorPI_LAB_P.Delay3_InitialCondition;
}

void MdlStart(void)
{
  /* S-Function Block: ControladorPI_LAB/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &ControladorPI_LAB_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (ControladorPI_LAB_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ControladorPI_LAB_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      return;
    }

    if ((ControladorPI_LAB_P.HILInitialize_AIPStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &ControladorPI_LAB_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = ControladorPI_LAB_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &ControladorPI_LAB_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = ControladorPI_LAB_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_AIChannels[0], 8U,
         &ControladorPI_LAB_DWork.HILInitialize_AIMinimums[0],
         &ControladorPI_LAB_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_AOPStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &ControladorPI_LAB_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = ControladorPI_LAB_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &ControladorPI_LAB_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = ControladorPI_LAB_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_AOChannels[0], 8U,
         &ControladorPI_LAB_DWork.HILInitialize_AOMinimums[0],
         &ControladorPI_LAB_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_AOStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControladorPI_LAB_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_AOChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if (ControladorPI_LAB_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = ControladorPI_LAB_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_AOChannels[0], 8U,
         &ControladorPI_LAB_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (ControladorPI_LAB_DWork.HILInitialize_Card, NULL, 0U,
       &ControladorPI_LAB_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
      return;
    }

    if ((ControladorPI_LAB_P.HILInitialize_DOStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &ControladorPI_LAB_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = ControladorPI_LAB_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &ControladorPI_LAB_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if (ControladorPI_LAB_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &ControladorPI_LAB_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = ControladorPI_LAB_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &ControladorPI_LAB_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_EIPStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &ControladorPI_LAB_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            ControladorPI_LAB_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &ControladorPI_LAB_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_EIStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &ControladorPI_LAB_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = ControladorPI_LAB_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_EIChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_POPStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &ControladorPI_LAB_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = ControladorPI_LAB_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &ControladorPI_LAB_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &ControladorPI_LAB_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &ControladorPI_LAB_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            ControladorPI_LAB_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = ControladorPI_LAB_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            ControladorPI_LAB_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              ControladorPI_LAB_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (ControladorPI_LAB_DWork.HILInitialize_Card,
           &ControladorPI_LAB_DWork.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (ControladorPI_LAB_DWork.HILInitialize_Card,
           &ControladorPI_LAB_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &ControladorPI_LAB_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            ControladorPI_LAB_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &ControladorPI_LAB_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = ControladorPI_LAB_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &ControladorPI_LAB_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = ControladorPI_LAB_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &ControladorPI_LAB_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &ControladorPI_LAB_DWork.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &ControladorPI_LAB_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = ControladorPI_LAB_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &ControladorPI_LAB_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControladorPI_LAB_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs[0],
        &ControladorPI_LAB_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if ((ControladorPI_LAB_P.HILInitialize_POStart && !is_switching) ||
        (ControladorPI_LAB_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &ControladorPI_LAB_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControladorPI_LAB_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(ControladorPI_LAB_DWork.HILInitialize_Card,
        &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U,
        &ControladorPI_LAB_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }

    if (ControladorPI_LAB_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &ControladorPI_LAB_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = ControladorPI_LAB_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (ControladorPI_LAB_DWork.HILInitialize_Card,
         &ControladorPI_LAB_P.HILInitialize_POChannels[0], 8U,
         &ControladorPI_LAB_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: ControladorPI_LAB/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (ControladorPI_LAB_DWork.HILInitialize_Card,
       ControladorPI_LAB_P.EncoderInput0CartPositionEnco_l,
       ControladorPI_LAB_P.EncoderInput0CartPositionEnco_m, 2,
       &ControladorPI_LAB_DWork.EncoderInput0CartPositionEnco_m);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ControladorPI_LAB_M, _rt_error_message);
    }
  }

  /* Start for enable SubSystem: '<S1>/Cart Position Watchdog' */
  ControladorPI_LAB_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S1>/Cart Position Watchdog' */
  MdlInitialize();
}

RT_MODEL_ControladorPI_LAB *ControladorPI_LAB(void)
{
  ControladorPI_LAB_initialize(1);
  return ControladorPI_LAB_M;
}

void MdlTerminate(void)
{
  ControladorPI_LAB_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
