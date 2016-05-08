/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: multiTask_data.c
 *
 * Code generated for Simulink model 'multiTask'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Apr 23 15:50:00 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "multiTask.h"
#include "multiTask_private.h"

/* Block parameters (auto storage) */
P_multiTask_T multiTask_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  20.0,                                /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  10.0,                                /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */

  /*  Expression: deviceFile
   * Referenced by: '<S2>/LED'
   */
  { 108U, 101U, 100U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
