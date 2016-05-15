/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorFusionTask_private.h
 *
 * Code generated for Simulink model 'sensorFusionTask'.
 *
 * Model version                  : 1.160
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun May 15 17:57:20 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sensorFusionTask_private_h_
#define RTW_HEADER_sensorFusionTask_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void sensorFusionTask_calibrate_Init(DW_calibrate_sensorFusionTask_T
  *localDW);
extern void sensorFusionTask_calibrate(const real32_T rtu_raw[12], real32_T
  rtu_sampleSize, B_calibrate_sensorFusionTask_T *localB,
  DW_calibrate_sensorFusionTask_T *localDW);

#endif                                 /* RTW_HEADER_sensorFusionTask_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
