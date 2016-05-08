/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: readRegisterTest.h
 *
 * Code generated for Simulink model 'readRegisterTest'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Apr 30 15:28:42 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_readRegisterTest_h_
#define RTW_HEADER_readRegisterTest_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef readRegisterTest_COMMON_INCLUDES_
# define readRegisterTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* readRegisterTest_COMMON_INCLUDES_ */

#include "readRegisterTest_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T readAccelGyroMagSfun_o1[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o2[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o3[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o4[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o5[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o6[50];/* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o7;    /* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o8;    /* '<S2>/readAccelGyroMagSfun' */
  real32_T readAccelGyroMagSfun_o9;    /* '<S2>/readAccelGyroMagSfun' */
  real32_T MatrixConcatenate[150];     /* '<Root>/Matrix Concatenate' */
  real32_T MatrixConcatenate1[150];    /* '<Root>/Matrix Concatenate1' */
  real32_T Selector[3];                /* '<S1>/Selector' */
  real32_T Selector1[3];               /* '<S1>/Selector1' */
  uint32_T readAccelGyroMagSfun_o10;   /* '<S2>/readAccelGyroMagSfun' */
} B_readRegisterTest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T readAccelGyroMagSfun_DSTATE;  /* '<S2>/readAccelGyroMagSfun' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_b;                    /* '<S1>/Scope2' */

  int8_T ForIteratorSubsystem_SubsysRanB;/* '<Root>/For Iterator Subsystem' */
} DW_readRegisterTest_T;

/* Real-time Model Data Structure */
struct tag_RTM_readRegisterTest_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (auto storage) */
extern B_readRegisterTest_T readRegisterTest_B;

/* Block states (auto storage) */
extern DW_readRegisterTest_T readRegisterTest_DW;

/* Model entry point functions */
extern void readRegisterTest_initialize(void);
extern void readRegisterTest_output(void);
extern void readRegisterTest_update(void);
extern void readRegisterTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_readRegisterTest_T *const readRegisterTest_M;

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
 * '<Root>' : 'readRegisterTest'
 * '<S1>'   : 'readRegisterTest/For Iterator Subsystem'
 * '<S2>'   : 'readRegisterTest/readSensors'
 */
#endif                                 /* RTW_HEADER_readRegisterTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
