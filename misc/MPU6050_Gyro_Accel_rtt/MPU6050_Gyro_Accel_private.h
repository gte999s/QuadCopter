/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MPU6050_Gyro_Accel_private.h
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

#ifndef RTW_HEADER_MPU6050_Gyro_Accel_private_h_
#define RTW_HEADER_MPU6050_Gyro_Accel_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void sf_MPU6050_Outputs_wrapper(int16_T *gx,
  int16_T *gy,
  int16_T *gz,
  int16_T *ax,
  int16_T *ay,
  int16_T *az,
  const real_T *xD);
extern void sf_MPU6050_Update_wrapper(const int16_T *gx,
  const int16_T *gy,
  const int16_T *gz,
  const int16_T *ax,
  const int16_T *ay,
  const int16_T *az,
  real_T *xD);

#endif                                 /* RTW_HEADER_MPU6050_Gyro_Accel_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
