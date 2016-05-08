/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: readRegisterTest_private.h
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

#ifndef RTW_HEADER_readRegisterTest_private_h_
#define RTW_HEADER_readRegisterTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void readAccelGryoMag_Outputs_wrapper(real32_T *AccelX,
  real32_T *AccelY,
  real32_T *AccelZ,
  real32_T *GyroX,
  real32_T *GyroY,
  real32_T *GyroZ,
  real32_T *MagX,
  real32_T *MagY,
  real32_T *MagZ,
  uint32_T *DataSamples,
  const real_T *xD);
extern void readAccelGryoMag_Update_wrapper(const real32_T *AccelX,
  const real32_T *AccelY,
  const real32_T *AccelZ,
  const real32_T *GyroX,
  const real32_T *GyroY,
  const real32_T *GyroZ,
  const real32_T *MagX,
  const real32_T *MagY,
  const real32_T *MagZ,
  const uint32_T *DataSamples,
  real_T *xD);

#endif                                 /* RTW_HEADER_readRegisterTest_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
