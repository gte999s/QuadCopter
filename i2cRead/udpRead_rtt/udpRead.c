/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: udpRead.c
 *
 * Code generated for Simulink model 'udpRead'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Apr 30 15:26:09 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "udpRead.h"
#include "udpRead_private.h"
#include "udpRead_dt.h"

/* Block signals (auto storage) */
B_udpRead_T udpRead_B;

/* Block states (auto storage) */
DW_udpRead_T udpRead_DW;

/* Real-time model */
RT_MODEL_udpRead_T udpRead_M_;
RT_MODEL_udpRead_T *const udpRead_M = &udpRead_M_;

/* Model output function */
void udpRead_output(void)
{
  char_T *sErr;
  int32_T samplesRead;
  int32_T s4_iter;
  real32_T u;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(udpRead_DW.ForIteratorSubsystem_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(udpRead_DW.EnabledSubsystem_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&udpRead_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 64;
  LibOutputs_Network(&udpRead_DW.UDPReceive_NetworkLib[0U],
                     &udpRead_B.UDPReceive_o1[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(udpRead_M, sErr);
    rtmSetStopRequested(udpRead_M, 1);
  }

  udpRead_B.UDPReceive_o2 = (uint16_T)samplesRead;

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  udpRead_B.Compare = (udpRead_B.UDPReceive_o2 > udpRead_P.Constant_Value);

  /* Switch: '<S3>/Init' incorporates:
   *  Constant: '<S3>/Initial Condition'
   *  Logic: '<S3>/FixPt Logical Operator'
   *  UnitDelay: '<S3>/FixPt Unit Delay1'
   *  UnitDelay: '<S3>/FixPt Unit Delay2'
   */
  if (udpRead_B.Compare || (udpRead_DW.FixPtUnitDelay2_DSTATE != 0)) {
    udpRead_B.Init = udpRead_P.UnitDelayResettable_vinit;
  } else {
    udpRead_B.Init = udpRead_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S3>/Init' */

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (udpRead_B.Compare) {
    if (!udpRead_DW.EnabledSubsystem_MODE) {
      udpRead_DW.EnabledSubsystem_MODE = true;
    }

    /* Logic: '<S2>/Logical Operator' incorporates:
     *  RelationalOperator: '<S2>/Relational Operator'
     *  S-Function (sfix_udelay): '<S2>/Tapped Delay'
     */
    udpRead_B.LogicalOperator = ((udpRead_DW.TappedDelay_X[0] ==
      udpRead_DW.TappedDelay_X[2]) && (udpRead_DW.TappedDelay_X[1] ==
      udpRead_DW.TappedDelay_X[3]));

    /* Outputs for Iterator SubSystem: '<S2>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S4>/For Iterator'
     */
    s4_iter = 1;
    do {
      exitg1 = 0;
      u = udpRead_B.UDPReceive_o1[63];
      if (u < 0.0F) {
        u = (real32_T)ceil(u);
      } else {
        u = (real32_T)floor(u);
      }

      if (rtIsNaNF(u) || rtIsInfF(u)) {
        u = 0.0F;
      } else {
        u = (real32_T)fmod(u, 4.2949673E+9F);
      }

      if (s4_iter <= (u < 0.0F ? -(int32_T)(uint32_T)-u : (int32_T)(uint32_T)u))
      {
        udpRead_B.Selector = udpRead_B.UDPReceive_o1[s4_iter - 1];
        udpRead_B.Selector1 = udpRead_B.UDPReceive_o1[s4_iter + 9];
        udpRead_B.Selector2 = udpRead_B.UDPReceive_o1[s4_iter + 19];
        udpRead_B.Compare_p = (s4_iter == udpRead_P.CompareToConstant_const);
        udpRead_B.Selector3 = udpRead_B.UDPReceive_o1[s4_iter + 29];
        udpRead_B.Selector4 = udpRead_B.UDPReceive_o1[s4_iter + 39];
        udpRead_B.Selector5 = udpRead_B.UDPReceive_o1[s4_iter + 49];
        srUpdateBC(udpRead_DW.ForIteratorSubsystem_SubsysRanB);
        s4_iter++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    /* End of Outputs for SubSystem: '<S2>/For Iterator Subsystem' */
    srUpdateBC(udpRead_DW.EnabledSubsystem_SubsysRanBC);
  } else {
    if (udpRead_DW.EnabledSubsystem_MODE) {
      udpRead_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Switch: '<S3>/Reset' incorporates:
   *  Constant: '<S3>/Initial Condition'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Logic: '<Root>/Logical Operator'
   *  Sum: '<Root>/Sum'
   */
  if (udpRead_B.Compare) {
    udpRead_B.Xnew = udpRead_P.UnitDelayResettable_vinit;
  } else {
    udpRead_B.Xnew = (real32_T)!udpRead_B.Compare + udpRead_B.Init;
  }

  /* End of Switch: '<S3>/Reset' */
}

/* Model update function */
void udpRead_update(void)
{
  /* Update for UnitDelay: '<S3>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   */
  udpRead_DW.FixPtUnitDelay2_DSTATE = udpRead_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S3>/FixPt Unit Delay1' */
  udpRead_DW.FixPtUnitDelay1_DSTATE = udpRead_B.Xnew;

  /* Update for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  Update for EnablePort: '<S2>/Enable'
   */
  if (udpRead_DW.EnabledSubsystem_MODE) {
    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    udpRead_DW.TappedDelay_X[0] = udpRead_DW.TappedDelay_X[1];
    udpRead_DW.TappedDelay_X[1] = udpRead_DW.TappedDelay_X[2];
    udpRead_DW.TappedDelay_X[2] = udpRead_DW.TappedDelay_X[3];
    udpRead_DW.TappedDelay_X[3] = udpRead_B.UDPReceive_o1[60];
  }

  /* End of Update for SubSystem: '<Root>/Enabled Subsystem' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(udpRead_M)!=-1) &&
        !((rtmGetTFinal(udpRead_M)-udpRead_M->Timing.taskTime0) >
          udpRead_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(udpRead_M, "Simulation finished");
    }

    if (rtmGetStopRequested(udpRead_M)) {
      rtmSetErrorStatus(udpRead_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  udpRead_M->Timing.taskTime0 =
    (++udpRead_M->Timing.clockTick0) * udpRead_M->Timing.stepSize0;
}

/* Model initialize function */
void udpRead_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)udpRead_M, 0,
                sizeof(RT_MODEL_udpRead_T));
  rtmSetTFinal(udpRead_M, -1);
  udpRead_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  udpRead_M->Sizes.checksums[0] = (1278964958U);
  udpRead_M->Sizes.checksums[1] = (3600619979U);
  udpRead_M->Sizes.checksums[2] = (2378837995U);
  udpRead_M->Sizes.checksums[3] = (818122248U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    udpRead_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&udpRead_DW.ForIteratorSubsystem_SubsysRanB;
    systemRan[2] = (sysRanDType *)&udpRead_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(udpRead_M->extModeInfo,
      &udpRead_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(udpRead_M->extModeInfo, udpRead_M->Sizes.checksums);
    rteiSetTPtr(udpRead_M->extModeInfo, rtmGetTPtr(udpRead_M));
  }

  /* block I/O */
  (void) memset(((void *) &udpRead_B), 0,
                sizeof(B_udpRead_T));

  /* states (dwork) */
  (void) memset((void *)&udpRead_DW, 0,
                sizeof(DW_udpRead_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    udpRead_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
    sErr = GetErrorBuffer(&udpRead_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&udpRead_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&udpRead_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        25000, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&udpRead_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&udpRead_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(udpRead_M, sErr);
        rtmSetStopRequested(udpRead_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/Enabled Subsystem' */
    /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    udpRead_DW.TappedDelay_X[0] = udpRead_P.TappedDelay_vinit;
    udpRead_DW.TappedDelay_X[1] = udpRead_P.TappedDelay_vinit;
    udpRead_DW.TappedDelay_X[2] = udpRead_P.TappedDelay_vinit;
    udpRead_DW.TappedDelay_X[3] = udpRead_P.TappedDelay_vinit;

    /* End of InitializeConditions for SubSystem: '<Root>/Enabled Subsystem' */

    /* InitializeConditions for UnitDelay: '<S3>/FixPt Unit Delay2' */
    udpRead_DW.FixPtUnitDelay2_DSTATE =
      udpRead_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S3>/FixPt Unit Delay1' */
    udpRead_DW.FixPtUnitDelay1_DSTATE = udpRead_P.UnitDelayResettable_vinit;
  }
}

/* Model terminate function */
void udpRead_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&udpRead_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&udpRead_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(udpRead_M, sErr);
    rtmSetStopRequested(udpRead_M, 1);
  }

  LibDestroy(&udpRead_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&udpRead_DW.UDPReceive_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
