/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: readRegisterTest.c
 *
 * Code generated for Simulink model 'readRegisterTest'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Apr 02 13:23:52 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "readRegisterTest.h"
#include "readRegisterTest_private.h"
#include "readRegisterTest_dt.h"

/* Block signals (auto storage) */
B_readRegisterTest_T readRegisterTest_B;

/* Block states (auto storage) */
DW_readRegisterTest_T readRegisterTest_DW;

/* Real-time model */
RT_MODEL_readRegisterTest_T readRegisterTest_M_;
RT_MODEL_readRegisterTest_T *const readRegisterTest_M = &readRegisterTest_M_;

/* Model output function */
void readRegisterTest_output(void)
{
  int32_T s1_iter;
  real32_T tmp[150];
  real32_T tmp_0;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(readRegisterTest_DW.ForIteratorSubsystem_SubsysRanB);

  /* S-Function (readAccelGryo): '<Root>/S-Function Builder' */
  readAccelGryo_Outputs_wrapper( &readRegisterTest_B.SFunctionBuilder_o1[0],
    &readRegisterTest_B.SFunctionBuilder_o2[0],
    &readRegisterTest_B.SFunctionBuilder_o3[0],
    &readRegisterTest_B.SFunctionBuilder_o4[0],
    &readRegisterTest_B.SFunctionBuilder_o5[0],
    &readRegisterTest_B.SFunctionBuilder_o6[0],
    &readRegisterTest_B.SFunctionBuilder_o7,
    &readRegisterTest_DW.SFunctionBuilder_DSTATE);

  /* Outputs for Iterator SubSystem: '<Root>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S1>/For Iterator'
   */
  /* Selector: '<S1>/Selector1' incorporates:
   *  Selector: '<S1>/Selector'
   */
  s1_iter = 0;
  do {
    exitg1 = 0;
    if (readRegisterTest_B.SFunctionBuilder_o7 < 0.0F) {
      tmp_0 = (real32_T)ceil(readRegisterTest_B.SFunctionBuilder_o7);
    } else {
      tmp_0 = (real32_T)floor(readRegisterTest_B.SFunctionBuilder_o7);
    }

    if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
      tmp_0 = 0.0F;
    } else {
      tmp_0 = (real32_T)fmod(tmp_0, 4.2949673E+9F);
    }

    if (s1_iter + 1 <= (tmp_0 < 0.0F ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)
                        (uint32_T)tmp_0)) {
      memcpy(&tmp[0], &readRegisterTest_B.SFunctionBuilder_o1[0], 50U * sizeof
             (real32_T));
      memcpy(&tmp[50], &readRegisterTest_B.SFunctionBuilder_o2[0], 50U * sizeof
             (real32_T));
      memcpy(&tmp[100], &readRegisterTest_B.SFunctionBuilder_o3[0], 50U * sizeof
             (real32_T));
      readRegisterTest_B.Selector[0] = tmp[150 * s1_iter];
      readRegisterTest_B.Selector[1] = tmp[150 * s1_iter + 1];
      readRegisterTest_B.Selector[2] = tmp[150 * s1_iter + 2];
      memcpy(&tmp[0], &readRegisterTest_B.SFunctionBuilder_o4[0], 50U * sizeof
             (real32_T));
      memcpy(&tmp[50], &readRegisterTest_B.SFunctionBuilder_o5[0], 50U * sizeof
             (real32_T));
      memcpy(&tmp[100], &readRegisterTest_B.SFunctionBuilder_o6[0], 50U * sizeof
             (real32_T));
      readRegisterTest_B.Selector1[0] = tmp[150 * s1_iter];
      readRegisterTest_B.Selector1[1] = tmp[150 * s1_iter + 1];
      readRegisterTest_B.Selector1[2] = tmp[150 * s1_iter + 2];
      srUpdateBC(readRegisterTest_DW.ForIteratorSubsystem_SubsysRanB);
      s1_iter++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<Root>/For Iterator Subsystem' */
}

/* Model update function */
void readRegisterTest_update(void)
{
  /* S-Function "readAccelGryo_wrapper" Block: <Root>/S-Function Builder */
  readAccelGryo_Update_wrapper( &readRegisterTest_B.SFunctionBuilder_o1[0],
    &readRegisterTest_B.SFunctionBuilder_o2[0],
    &readRegisterTest_B.SFunctionBuilder_o3[0],
    &readRegisterTest_B.SFunctionBuilder_o4[0],
    &readRegisterTest_B.SFunctionBuilder_o5[0],
    &readRegisterTest_B.SFunctionBuilder_o6[0],
    &readRegisterTest_B.SFunctionBuilder_o7,
    &readRegisterTest_DW.SFunctionBuilder_DSTATE);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(readRegisterTest_M)!=-1) &&
        !((rtmGetTFinal(readRegisterTest_M)-readRegisterTest_M->Timing.t[0]) >
          readRegisterTest_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(readRegisterTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(readRegisterTest_M)) {
      rtmSetErrorStatus(readRegisterTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  readRegisterTest_M->Timing.t[0] =
    (++readRegisterTest_M->Timing.clockTick0) *
    readRegisterTest_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    readRegisterTest_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void readRegisterTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)readRegisterTest_M, 0,
                sizeof(RT_MODEL_readRegisterTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&readRegisterTest_M->solverInfo,
                          &readRegisterTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&readRegisterTest_M->solverInfo, &rtmGetTPtr(readRegisterTest_M));
    rtsiSetStepSizePtr(&readRegisterTest_M->solverInfo,
                       &readRegisterTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&readRegisterTest_M->solverInfo, (&rtmGetErrorStatus
      (readRegisterTest_M)));
    rtsiSetRTModelPtr(&readRegisterTest_M->solverInfo, readRegisterTest_M);
  }

  rtsiSetSimTimeStep(&readRegisterTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&readRegisterTest_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(readRegisterTest_M, &readRegisterTest_M->Timing.tArray[0]);
  rtmSetTFinal(readRegisterTest_M, -1);
  readRegisterTest_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  readRegisterTest_M->Sizes.checksums[0] = (3996646705U);
  readRegisterTest_M->Sizes.checksums[1] = (2933237790U);
  readRegisterTest_M->Sizes.checksums[2] = (2684094241U);
  readRegisterTest_M->Sizes.checksums[3] = (2350533359U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    readRegisterTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &readRegisterTest_DW.ForIteratorSubsystem_SubsysRanB;
    rteiSetModelMappingInfoPtr(readRegisterTest_M->extModeInfo,
      &readRegisterTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(readRegisterTest_M->extModeInfo,
                        readRegisterTest_M->Sizes.checksums);
    rteiSetTPtr(readRegisterTest_M->extModeInfo, rtmGetTPtr(readRegisterTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &readRegisterTest_B), 0,
                sizeof(B_readRegisterTest_T));

  /* states (dwork) */
  (void) memset((void *)&readRegisterTest_DW, 0,
                sizeof(DW_readRegisterTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    readRegisterTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;
  }

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        readRegisterTest_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void readRegisterTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
