/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: readRegisterTest.c
 *
 * Code generated for Simulink model 'readRegisterTest'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Apr 30 14:34:34 2016
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
  /* S-Function (readAccelGryoMag): '<S1>/readAccelGyroMagSfun' */
  readAccelGryoMag_Outputs_wrapper( &readRegisterTest_B.readAccelGyroMagSfun_o1
    [0], &readRegisterTest_B.readAccelGyroMagSfun_o2[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o3[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o4[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o5[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o6[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o7,
    &readRegisterTest_B.readAccelGyroMagSfun_o8,
    &readRegisterTest_B.readAccelGyroMagSfun_o9,
    &readRegisterTest_B.readAccelGyroMagSfun_o10,
    &readRegisterTest_DW.readAccelGyroMagSfun_DSTATE);

  /* SignalConversion: '<Root>/TmpSignal ConversionAtUDP SendInport1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[0],
         &readRegisterTest_B.readAccelGyroMagSfun_o1[0], 50U * sizeof(real32_T));
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[50],
         &readRegisterTest_B.readAccelGyroMagSfun_o2[0], 50U * sizeof(real32_T));
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[100],
         &readRegisterTest_B.readAccelGyroMagSfun_o3[0], 50U * sizeof(real32_T));
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[150],
         &readRegisterTest_B.readAccelGyroMagSfun_o4[0], 50U * sizeof(real32_T));
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[200],
         &readRegisterTest_B.readAccelGyroMagSfun_o5[0], 50U * sizeof(real32_T));
  memcpy(&readRegisterTest_B.TmpSignalConversionAtUDPSendInp[250],
         &readRegisterTest_B.readAccelGyroMagSfun_o6[0], 50U * sizeof(real32_T));
  readRegisterTest_B.TmpSignalConversionAtUDPSendInp[300] =
    readRegisterTest_B.readAccelGyroMagSfun_o7;
  readRegisterTest_B.TmpSignalConversionAtUDPSendInp[301] =
    readRegisterTest_B.readAccelGyroMagSfun_o8;
  readRegisterTest_B.TmpSignalConversionAtUDPSendInp[302] =
    readRegisterTest_B.readAccelGyroMagSfun_o9;
  readRegisterTest_B.TmpSignalConversionAtUDPSendInp[303] = (real32_T)
    readRegisterTest_B.readAccelGyroMagSfun_o10;
}

/* Model update function */
void readRegisterTest_update(void)
{
  char_T *sErr;

  /* S-Function "readAccelGryoMag_wrapper" Block: <S1>/readAccelGyroMagSfun */
  readAccelGryoMag_Update_wrapper( &readRegisterTest_B.readAccelGyroMagSfun_o1[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o2[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o3[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o4[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o5[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o6[0],
    &readRegisterTest_B.readAccelGyroMagSfun_o7,
    &readRegisterTest_B.readAccelGyroMagSfun_o8,
    &readRegisterTest_B.readAccelGyroMagSfun_o9,
    &readRegisterTest_B.readAccelGyroMagSfun_o10,
    &readRegisterTest_DW.readAccelGyroMagSfun_DSTATE);

  /* Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&readRegisterTest_DW.UDPSend_NetworkLib[0U],
                    &readRegisterTest_B.TmpSignalConversionAtUDPSendInp[0U], 304);
  if (*sErr != 0) {
    rtmSetErrorStatus(readRegisterTest_M, sErr);
    rtmSetStopRequested(readRegisterTest_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */

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
  readRegisterTest_M->Sizes.checksums[0] = (4218181954U);
  readRegisterTest_M->Sizes.checksums[1] = (3160224958U);
  readRegisterTest_M->Sizes.checksums[2] = (507651711U);
  readRegisterTest_M->Sizes.checksums[3] = (1981394724U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    readRegisterTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
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

  {
    char_T *sErr;

    /* Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */
    sErr = GetErrorBuffer(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&readRegisterTest_DW.UDPSend_NetworkLib[0U], 1,
                        "255.255.255.255", -1, "127.0.0.1", 25000, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(readRegisterTest_M, sErr);
        rtmSetStopRequested(readRegisterTest_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */

    /* S-Function Block: <S1>/readAccelGyroMagSfun */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          readRegisterTest_DW.readAccelGyroMagSfun_DSTATE = initVector[0];
        }
      }
    }
  }
}

/* Model terminate function */
void readRegisterTest_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(readRegisterTest_M, sErr);
    rtmSetStopRequested(readRegisterTest_M, 1);
  }

  LibDestroy(&readRegisterTest_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&readRegisterTest_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
