/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: udpRead.c
 *
 * Code generated for Simulink model 'udpRead'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun May 01 16:54:21 2016
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
  boolean_T rtb_Compare;
  int32_T s5_iter;
  real_T tmp;
  int32_T exitg1;
  int32_T exitg2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(udpRead_DW.ForIteratorSubsystem_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(udpRead_DW.ForIteratorSubsystem1_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(udpRead_DW.EnabledSubsystem_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&udpRead_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 30;
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
  rtb_Compare = (udpRead_B.UDPReceive_o2 > udpRead_P.Constant_Value_p);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_Compare) {
    if (!udpRead_DW.EnabledSubsystem_MODE) {
      udpRead_DW.EnabledSubsystem_MODE = true;
    }

    /* Outputs for Iterator SubSystem: '<S2>/For Iterator Subsystem1' incorporates:
     *  ForIterator: '<S5>/For Iterator'
     */
    /* Selector: '<S5>/Selector' incorporates:
     *  Selector: '<S5>/Selector1'
     *  Selector: '<S5>/Selector2'
     */
    s5_iter = 24;
    do {
      exitg2 = 0;
      if (udpRead_P.Constant1_Value < 0.0) {
        tmp = ceil(udpRead_P.Constant1_Value);
      } else {
        tmp = floor(udpRead_P.Constant1_Value);
      }

      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      if (s5_iter - 23 <= (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
                           (uint32_T)tmp)) {
        udpRead_B.Selector = udpRead_B.UDPReceive_o1[s5_iter];
        udpRead_B.Selector1 = udpRead_B.UDPReceive_o1[s5_iter + 2];
        udpRead_B.Selector2 = udpRead_B.UDPReceive_o1[s5_iter + 4];
        srUpdateBC(udpRead_DW.ForIteratorSubsystem1_SubsysRan);
        s5_iter++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /* End of Outputs for SubSystem: '<S2>/For Iterator Subsystem1' */

    /* Outputs for Iterator SubSystem: '<S2>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S4>/For Iterator'
     */
    s5_iter = 1;
    do {
      exitg1 = 0;
      if (udpRead_P.Constant_Value < 0.0) {
        tmp = ceil(udpRead_P.Constant_Value);
      } else {
        tmp = floor(udpRead_P.Constant_Value);
      }

      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      if (s5_iter <= (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)
                      tmp)) {
        udpRead_B.Selector_d = udpRead_B.UDPReceive_o1[s5_iter - 1];
        udpRead_B.Selector1_f = udpRead_B.UDPReceive_o1[s5_iter + 3];
        udpRead_B.Selector2_f = udpRead_B.UDPReceive_o1[s5_iter + 7];
        udpRead_B.Compare = (s5_iter == udpRead_P.CompareToConstant_const);
        udpRead_B.Selector3 = udpRead_B.UDPReceive_o1[s5_iter + 11];
        udpRead_B.Selector4 = udpRead_B.UDPReceive_o1[s5_iter + 15];
        udpRead_B.Selector5 = udpRead_B.UDPReceive_o1[s5_iter + 19];
        srUpdateBC(udpRead_DW.ForIteratorSubsystem_SubsysRanB);
        s5_iter++;
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

  /* Switch: '<S3>/Init' incorporates:
   *  Constant: '<S3>/Initial Condition'
   *  Logic: '<S3>/FixPt Logical Operator'
   *  UnitDelay: '<S3>/FixPt Unit Delay1'
   *  UnitDelay: '<S3>/FixPt Unit Delay2'
   */
  if (rtb_Compare || (udpRead_DW.FixPtUnitDelay2_DSTATE != 0)) {
    udpRead_B.Init = udpRead_P.UnitDelayResettable_vinit;
  } else {
    udpRead_B.Init = udpRead_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S3>/Init' */

  /* Switch: '<S3>/Reset' incorporates:
   *  Constant: '<S3>/Initial Condition'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_Compare) {
    udpRead_B.Xnew = udpRead_P.UnitDelayResettable_vinit;
  } else {
    udpRead_B.Xnew = 1.0F + udpRead_B.Init;
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

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
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
  udpRead_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  udpRead_M->Sizes.checksums[0] = (1556687154U);
  udpRead_M->Sizes.checksums[1] = (1743337526U);
  udpRead_M->Sizes.checksums[2] = (3012980648U);
  udpRead_M->Sizes.checksums[3] = (1570491107U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    udpRead_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&udpRead_DW.ForIteratorSubsystem_SubsysRanB;
    systemRan[2] = (sysRanDType *)&udpRead_DW.ForIteratorSubsystem1_SubsysRan;
    systemRan[3] = (sysRanDType *)&udpRead_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
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
