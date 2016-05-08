/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: udpRead_data.c
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

/* Block parameters (auto storage) */
P_udpRead_T udpRead_P = {
  0.0F,                                /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S2>/Tapped Delay'
                                        */
  0.0F,                                /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S3>/Initial Condition'
                                        *   '<S3>/FixPt Unit Delay1'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S5>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                        * Referenced by: '<S3>/FixPt Unit Delay2'
                                        */
  0U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
