/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: udpRead.h
 *
 * Code generated for Simulink model 'udpRead'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun May 01 16:54:21 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_udpRead_h_
#define RTW_HEADER_udpRead_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef udpRead_COMMON_INCLUDES_
# define udpRead_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "HostLib_Network.h"
#endif                                 /* udpRead_COMMON_INCLUDES_ */

#include "udpRead_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T UDPReceive_o1[30];          /* '<Root>/UDP Receive' */
  real32_T Init;                       /* '<S3>/Init' */
  real32_T Xnew;                       /* '<S3>/Reset' */
  real32_T Selector;                   /* '<S5>/Selector' */
  real32_T Selector1;                  /* '<S5>/Selector1' */
  real32_T Selector2;                  /* '<S5>/Selector2' */
  real32_T Selector_d;                 /* '<S4>/Selector' */
  real32_T Selector1_f;                /* '<S4>/Selector1' */
  real32_T Selector2_f;                /* '<S4>/Selector2' */
  real32_T Selector3;                  /* '<S4>/Selector3' */
  real32_T Selector4;                  /* '<S4>/Selector4' */
  real32_T Selector5;                  /* '<S4>/Selector5' */
  uint16_T UDPReceive_o2;              /* '<Root>/UDP Receive' */
  boolean_T Compare;                   /* '<S6>/Compare' */
} B_udpRead_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPReceive_NetworkLib[137];   /* '<Root>/UDP Receive' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_c;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_i;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S4>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK;                      /* '<S4>/Scope2' */

  real32_T FixPtUnitDelay1_DSTATE;     /* '<S3>/FixPt Unit Delay1' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S3>/FixPt Unit Delay2' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<Root>/Enabled Subsystem' */
  int8_T ForIteratorSubsystem1_SubsysRan;/* '<S2>/For Iterator Subsystem1' */
  int8_T ForIteratorSubsystem_SubsysRanB;/* '<S2>/For Iterator Subsystem' */
  boolean_T EnabledSubsystem_MODE;     /* '<Root>/Enabled Subsystem' */
} DW_udpRead_T;

/* Parameters (auto storage) */
struct P_udpRead_T_ {
  real32_T UnitDelayResettable_vinit;  /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S3>/Initial Condition'
                                        *   '<S3>/FixPt Unit Delay1'
                                        */
  int32_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 4
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S3>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_udpRead_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_udpRead_T udpRead_P;

/* Block signals (auto storage) */
extern B_udpRead_T udpRead_B;

/* Block states (auto storage) */
extern DW_udpRead_T udpRead_DW;

/* Model entry point functions */
extern void udpRead_initialize(void);
extern void udpRead_output(void);
extern void udpRead_update(void);
extern void udpRead_terminate(void);

/* Real-time Model object */
extern RT_MODEL_udpRead_T *const udpRead_M;

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
 * '<Root>' : 'udpRead'
 * '<S1>'   : 'udpRead/Compare To Zero'
 * '<S2>'   : 'udpRead/Enabled Subsystem'
 * '<S3>'   : 'udpRead/Unit Delay Resettable'
 * '<S4>'   : 'udpRead/Enabled Subsystem/For Iterator Subsystem'
 * '<S5>'   : 'udpRead/Enabled Subsystem/For Iterator Subsystem1'
 * '<S6>'   : 'udpRead/Enabled Subsystem/For Iterator Subsystem/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_udpRead_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
