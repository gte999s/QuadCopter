/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorControlTask.c
 *
 * Code generated for Simulink model 'motorControlTask'.
 *
 * Model version                  : 1.194
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun Jul 24 13:43:30 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorControlTask.h"
#include "motorControlTask_private.h"
#include "motorControlTask_dt.h"

/* Block signals (auto storage) */
B_motorControlTask_T motorControlTask_B;

/* Block states (auto storage) */
DW_motorControlTask_T motorControlTask_DW;

/* Real-time model */
RT_MODEL_motorControlTask_T motorControlTask_M_;
RT_MODEL_motorControlTask_T *const motorControlTask_M = &motorControlTask_M_;

/* Model output function */
void motorControlTask_output(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/MotorControl' */
  /* Bias: '<S1>/Bias' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Gain: '<S1>/Gain'
   */
  motorControlTask_B.Bias[0] = motorControlTask_P.Gain_Gain *
    motorControlTask_P.Constant1_Value + motorControlTask_P.Bias_Bias;
  motorControlTask_B.Bias[1] = motorControlTask_P.Gain_Gain *
    motorControlTask_P.Constant2_Value + motorControlTask_P.Bias_Bias;
  motorControlTask_B.Bias[2] = motorControlTask_P.Gain_Gain *
    motorControlTask_P.Constant3_Value + motorControlTask_P.Bias_Bias;
  motorControlTask_B.Bias[3] = motorControlTask_P.Gain_Gain *
    motorControlTask_P.Constant4_Value + motorControlTask_P.Bias_Bias;

  /* S-Function (motorControlFCN): '<S1>/motorControl' */
  motorControlFCN_Outputs_wrapper(&motorControlTask_B.Bias[0],
    &motorControlTask_DW.motorControl_DSTATE);

  /* End of Outputs for SubSystem: '<Root>/MotorControl' */
}

/* Model update function */
void motorControlTask_update(void)
{
  /* Update for Atomic SubSystem: '<Root>/MotorControl' */

  /* S-Function "motorControlFCN_wrapper" Block: <S1>/motorControl */
  motorControlFCN_Update_wrapper(&motorControlTask_B.Bias[0],
    &motorControlTask_DW.motorControl_DSTATE);

  /* End of Update for SubSystem: '<Root>/MotorControl' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(motorControlTask_M)!=-1) &&
        !((rtmGetTFinal(motorControlTask_M)-motorControlTask_M->Timing.t[0]) >
          motorControlTask_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(motorControlTask_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motorControlTask_M)) {
      rtmSetErrorStatus(motorControlTask_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motorControlTask_M->Timing.t[0] =
    (++motorControlTask_M->Timing.clockTick0) *
    motorControlTask_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    motorControlTask_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void motorControlTask_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motorControlTask_M, 0,
                sizeof(RT_MODEL_motorControlTask_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motorControlTask_M->solverInfo,
                          &motorControlTask_M->Timing.simTimeStep);
    rtsiSetTPtr(&motorControlTask_M->solverInfo, &rtmGetTPtr(motorControlTask_M));
    rtsiSetStepSizePtr(&motorControlTask_M->solverInfo,
                       &motorControlTask_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&motorControlTask_M->solverInfo, (&rtmGetErrorStatus
      (motorControlTask_M)));
    rtsiSetRTModelPtr(&motorControlTask_M->solverInfo, motorControlTask_M);
  }

  rtsiSetSimTimeStep(&motorControlTask_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&motorControlTask_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(motorControlTask_M, &motorControlTask_M->Timing.tArray[0]);
  rtmSetTFinal(motorControlTask_M, -1);
  motorControlTask_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  motorControlTask_M->Sizes.checksums[0] = (4276788412U);
  motorControlTask_M->Sizes.checksums[1] = (1764471682U);
  motorControlTask_M->Sizes.checksums[2] = (1375146313U);
  motorControlTask_M->Sizes.checksums[3] = (3666588002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    motorControlTask_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motorControlTask_M->extModeInfo,
      &motorControlTask_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motorControlTask_M->extModeInfo,
                        motorControlTask_M->Sizes.checksums);
    rteiSetTPtr(motorControlTask_M->extModeInfo, rtmGetTPtr(motorControlTask_M));
  }

  /* block I/O */
  (void) memset(((void *) &motorControlTask_B), 0,
                sizeof(B_motorControlTask_T));

  /* states (dwork) */
  (void) memset((void *)&motorControlTask_DW, 0,
                sizeof(DW_motorControlTask_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motorControlTask_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* InitializeConditions for Atomic SubSystem: '<Root>/MotorControl' */

  /* S-Function Block: <S1>/motorControl */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        motorControlTask_DW.motorControl_DSTATE = initVector[0];
      }
    }
  }

  /* End of InitializeConditions for SubSystem: '<Root>/MotorControl' */
}

/* Model terminate function */
void motorControlTask_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
