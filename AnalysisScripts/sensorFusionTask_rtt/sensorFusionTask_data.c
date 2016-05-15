/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorFusionTask_data.c
 *
 * Code generated for Simulink model 'sensorFusionTask'.
 *
 * Model version                  : 1.162
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun May 15 18:11:44 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sensorFusionTask.h"
#include "sensorFusionTask_private.h"

/* Block parameters (auto storage) */
P_sensorFusionTask_T sensorFusionTask_P = {
  0.0F,                                /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S5>/Initial Condition'
                                        *   '<S5>/FixPt Unit Delay1'
                                        */
  0.0F,                                /* Computed Parameter: q_Y0
                                        * Referenced by: '<S3>/q'
                                        */
  0.0F,                                /* Computed Parameter: ZYX_Y0
                                        * Referenced by: '<S3>/ZYX'
                                        */
  800.0F,                              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S7>/Constant'
                                        */
  1.0F,                                /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S3>/Constant2'
                                        */
  57.2957802F,                         /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S1>/Constant'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                        * Referenced by: '<S5>/FixPt Unit Delay2'
                                        */
  0U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S5>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
