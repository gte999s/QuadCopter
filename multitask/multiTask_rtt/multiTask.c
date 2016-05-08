/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: multiTask.c
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

/* Block states (auto storage) */
DW_multiTask_T multiTask_DW;

/* Real-time model */
RT_MODEL_multiTask_T multiTask_M_;
RT_MODEL_multiTask_T *const multiTask_M = &multiTask_M_;
static void rate_monotonic_scheduler(void);

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (multiTask_M->Timing.TaskCounters.TID[1])++;
  if ((multiTask_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    multiTask_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void multiTask_output0(void)           /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_PulseGenerator;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/ledBlink' */
  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  rtb_PulseGenerator = (multiTask_DW.clockTickCounter <
                        multiTask_P.PulseGenerator_Duty) &&
    (multiTask_DW.clockTickCounter >= 0) ? multiTask_P.PulseGenerator_Amp : 0.0;
  if (multiTask_DW.clockTickCounter >= multiTask_P.PulseGenerator_Period - 1.0)
  {
    multiTask_DW.clockTickCounter = 0;
  } else {
    multiTask_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* S-Function (linuxLedWrite_sfcn): '<S2>/LED' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  MW_ledWrite(multiTask_P.LED_p1, rtb_PulseGenerator != 0.0);

  /* End of Outputs for SubSystem: '<Root>/ledBlink' */
}

/* Model update function for TID0 */
void multiTask_update0(void)           /* Sample time: [0.1s, 0.0s] */
{
  /* (no update code required) */
}

/* Model output function for TID1 */
void multiTask_output1(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID1 */
void multiTask_update1(void)           /* Sample time: [1.0s, 0.0s] */
{
  /* (no update code required) */
}

/* Model initialize function */
void multiTask_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)multiTask_M, 0,
                sizeof(RT_MODEL_multiTask_T));

  /* states (dwork) */
  (void) memset((void *)&multiTask_DW, 0,
                sizeof(DW_multiTask_T));

  /* Start for Atomic SubSystem: '<Root>/ledBlink' */
  /* Start for DiscretePulseGenerator: '<S2>/Pulse Generator' */
  multiTask_DW.clockTickCounter = 0;

  /* Start for S-Function (linuxLedWrite_sfcn): '<S2>/LED' */
  MW_ledInit(multiTask_P.LED_p1);

  /* End of Start for SubSystem: '<Root>/ledBlink' */
}

/* Model terminate function */
void multiTask_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/ledBlink' */
  /* Terminate for S-Function (linuxLedWrite_sfcn): '<S2>/LED' */
  MW_ledTerminate(multiTask_P.LED_p1);

  /* End of Terminate for SubSystem: '<Root>/ledBlink' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
