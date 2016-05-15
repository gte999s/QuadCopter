/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorFusionTask.h
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

#ifndef RTW_HEADER_sensorFusionTask_h_
#define RTW_HEADER_sensorFusionTask_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef sensorFusionTask_COMMON_INCLUDES_
# define sensorFusionTask_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "HostLib_Network.h"
#endif                                 /* sensorFusionTask_COMMON_INCLUDES_ */

#include "sensorFusionTask_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
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
  real32_T UDPReceive_o1[31];          /* '<Root>/UDP Receive' */
  real32_T Gain[3];                    /* '<Root>/Gain' */
  real32_T Init;                       /* '<S5>/Init' */
  real32_T Xnew;                       /* '<S5>/Reset' */
  real32_T MatrixConcatenate[6];       /* '<S9>/Matrix Concatenate' */
  real32_T OutportBufferForZYX[3];     /* '<S3>/MATLAB Function' */
  real32_T OutportBufferForq[4];       /* '<S3>/runMahonyUpdate' */
  real32_T q[4];                       /* '<S3>/runMahonyUpdate' */
  real32_T cal[12];                    /* '<S7>/calibrate1' */
  real32_T cal_p[12];                  /* '<S7>/calibrate' */
  uint16_T UDPReceive_o2;              /* '<Root>/UDP Receive' */
  boolean_T Compare;                   /* '<S1>/Compare' */
} B_sensorFusionTask_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPReceive_NetworkLib[137];   /* '<Root>/UDP Receive' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_p;                     /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S3>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S3>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S3>/To Workspace2' */

  real32_T FixPtUnitDelay1_DSTATE;     /* '<S5>/FixPt Unit Delay1' */
  real32_T qLocal[4];                  /* '<S3>/runMahonyUpdate' */
  real32_T bias[3];                    /* '<S7>/calibrate1' */
  real32_T bias_c[3];                  /* '<S7>/calibrate' */
  uint32_T count;                      /* '<S7>/calibrate1' */
  uint32_T count_m;                    /* '<S7>/calibrate' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S5>/FixPt Unit Delay2' */
  int8_T runSensorFusion_SubsysRanBC;  /* '<Root>/runSensorFusion' */
} DW_sensorFusionTask_T;

/* Parameters (auto storage) */
struct P_sensorFusionTask_T_ {
  real32_T UnitDelayResettable_vinit;  /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S5>/Initial Condition'
                                        *   '<S5>/FixPt Unit Delay1'
                                        */
  real32_T q_Y0;                       /* Computed Parameter: q_Y0
                                        * Referenced by: '<S3>/q'
                                        */
  real32_T ZYX_Y0;                     /* Computed Parameter: ZYX_Y0
                                        * Referenced by: '<S3>/ZYX'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S5>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S5>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sensorFusionTask_T {
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
extern P_sensorFusionTask_T sensorFusionTask_P;

/* Block signals (auto storage) */
extern B_sensorFusionTask_T sensorFusionTask_B;

/* Block states (auto storage) */
extern DW_sensorFusionTask_T sensorFusionTask_DW;

/* Model entry point functions */
extern void sensorFusionTask_initialize(void);
extern void sensorFusionTask_output(void);
extern void sensorFusionTask_update(void);
extern void sensorFusionTask_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sensorFusionTask_T *const sensorFusionTask_M;

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
 * '<Root>' : 'sensorFusionTask'
 * '<S1>'   : 'sensorFusionTask/Compare To Zero'
 * '<S2>'   : 'sensorFusionTask/executionInfo'
 * '<S3>'   : 'sensorFusionTask/runSensorFusion'
 * '<S4>'   : 'sensorFusionTask/runSensorFusionMahony'
 * '<S5>'   : 'sensorFusionTask/executionInfo/Unit Delay Resettable'
 * '<S6>'   : 'sensorFusionTask/runSensorFusion/MATLAB Function'
 * '<S7>'   : 'sensorFusionTask/runSensorFusion/calibrateSensorData'
 * '<S8>'   : 'sensorFusionTask/runSensorFusion/runMahonyUpdate'
 * '<S9>'   : 'sensorFusionTask/runSensorFusion/unpackData'
 * '<S10>'  : 'sensorFusionTask/runSensorFusion/calibrateSensorData/calibrate'
 * '<S11>'  : 'sensorFusionTask/runSensorFusion/calibrateSensorData/calibrate1'
 * '<S12>'  : 'sensorFusionTask/runSensorFusionMahony/For Iterator Subsystem'
 * '<S13>'  : 'sensorFusionTask/runSensorFusionMahony/For Iterator Subsystem1'
 * '<S14>'  : 'sensorFusionTask/runSensorFusionMahony/runMahonyUpdate'
 * '<S15>'  : 'sensorFusionTask/runSensorFusionMahony/For Iterator Subsystem/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_sensorFusionTask_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
