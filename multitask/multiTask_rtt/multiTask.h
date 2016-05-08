/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: multiTask.h
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

#ifndef RTW_HEADER_multiTask_h_
#define RTW_HEADER_multiTask_h_
#include <string.h>
#include <stddef.h>
#ifndef multiTask_COMMON_INCLUDES_
# define multiTask_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_led_lct.h"
#endif                                 /* multiTask_COMMON_INCLUDES_ */

#include "multiTask_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
} DW_multiTask_T;

/* Parameters (auto storage) */
struct P_multiTask_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  uint8_T LED_p1[5];                   /* Expression: deviceFile
                                        * Referenced by: '<S2>/LED'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_multiTask_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_multiTask_T multiTask_P;

/* Block states (auto storage) */
extern DW_multiTask_T multiTask_DW;

/* Model entry point functions */
extern void multiTask_initialize(void);
extern void multiTask_output0(void);
extern void multiTask_update0(void);
extern void multiTask_output1(void);
extern void multiTask_update1(void);
extern void multiTask_terminate(void);

/* Real-time Model object */
extern RT_MODEL_multiTask_T *const multiTask_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'multiTask'
 * '<S1>'   : 'multiTask/counter'
 * '<S2>'   : 'multiTask/ledBlink'
 * '<S3>'   : 'multiTask/counter/Counter Free-Running'
 * '<S4>'   : 'multiTask/counter/Counter Free-Running/Increment Real World'
 * '<S5>'   : 'multiTask/counter/Counter Free-Running/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_multiTask_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
