/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPU6050_Gyro_Accel.c
 *
 * Code generated for Simulink model 'MPU6050_Gyro_Accel'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Mon Mar 28 20:21:06 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "MPU6050_Gyro_Accel.h"
#include "MPU6050_Gyro_Accel_private.h"
#include "MPU6050_Gyro_Accel_dt.h"

/* Block signals (auto storage) */
B_MPU6050_Gyro_Accel_T MPU6050_Gyro_Accel_B;

/* Block states (auto storage) */
DW_MPU6050_Gyro_Accel_T MPU6050_Gyro_Accel_DW;

/* Real-time model */
RT_MODEL_MPU6050_Gyro_Accel_T MPU6050_Gyro_Accel_M_;
RT_MODEL_MPU6050_Gyro_Accel_T *const MPU6050_Gyro_Accel_M =
  &MPU6050_Gyro_Accel_M_;

/* Model output function */
void MPU6050_Gyro_Accel_output(void)
{
  /* S-Function (sf_MPU6050): '<Root>/mpu6050 gyro x-axis' */
  sf_MPU6050_Outputs_wrapper( &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o1,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o2,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o3,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o4,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o5,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o6,
    &MPU6050_Gyro_Accel_DW.mpu6050gyroxaxis_DSTATE);
}

/* Model update function */
void MPU6050_Gyro_Accel_update(void)
{
  /* S-Function "sf_MPU6050_wrapper" Block: <Root>/mpu6050 gyro x-axis */
  sf_MPU6050_Update_wrapper( &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o1,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o2,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o3,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o4,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o5,
    &MPU6050_Gyro_Accel_B.mpu6050gyroxaxis_o6,
    &MPU6050_Gyro_Accel_DW.mpu6050gyroxaxis_DSTATE);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(MPU6050_Gyro_Accel_M)!=-1) &&
        !((rtmGetTFinal(MPU6050_Gyro_Accel_M)-
           MPU6050_Gyro_Accel_M->Timing.taskTime0) >
          MPU6050_Gyro_Accel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MPU6050_Gyro_Accel_M, "Simulation finished");
    }

    if (rtmGetStopRequested(MPU6050_Gyro_Accel_M)) {
      rtmSetErrorStatus(MPU6050_Gyro_Accel_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MPU6050_Gyro_Accel_M->Timing.taskTime0 =
    (++MPU6050_Gyro_Accel_M->Timing.clockTick0) *
    MPU6050_Gyro_Accel_M->Timing.stepSize0;
}

/* Model initialize function */
void MPU6050_Gyro_Accel_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MPU6050_Gyro_Accel_M, 0,
                sizeof(RT_MODEL_MPU6050_Gyro_Accel_T));
  rtmSetTFinal(MPU6050_Gyro_Accel_M, -1);
  MPU6050_Gyro_Accel_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  MPU6050_Gyro_Accel_M->Sizes.checksums[0] = (3152529765U);
  MPU6050_Gyro_Accel_M->Sizes.checksums[1] = (1363378506U);
  MPU6050_Gyro_Accel_M->Sizes.checksums[2] = (793124032U);
  MPU6050_Gyro_Accel_M->Sizes.checksums[3] = (3509033679U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    MPU6050_Gyro_Accel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MPU6050_Gyro_Accel_M->extModeInfo,
      &MPU6050_Gyro_Accel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MPU6050_Gyro_Accel_M->extModeInfo,
                        MPU6050_Gyro_Accel_M->Sizes.checksums);
    rteiSetTPtr(MPU6050_Gyro_Accel_M->extModeInfo, rtmGetTPtr
                (MPU6050_Gyro_Accel_M));
  }

  /* block I/O */
  (void) memset(((void *) &MPU6050_Gyro_Accel_B), 0,
                sizeof(B_MPU6050_Gyro_Accel_T));

  /* states (dwork) */
  (void) memset((void *)&MPU6050_Gyro_Accel_DW, 0,
                sizeof(DW_MPU6050_Gyro_Accel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MPU6050_Gyro_Accel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;
  }

  /* S-Function Block: <Root>/mpu6050 gyro x-axis */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        MPU6050_Gyro_Accel_DW.mpu6050gyroxaxis_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void MPU6050_Gyro_Accel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
