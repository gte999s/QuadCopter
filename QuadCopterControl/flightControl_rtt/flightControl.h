/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControl.h
 *
 * Code generated for Simulink model 'flightControl'.
 *
 * Model version                  : 1.178
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sat Jul 30 16:23:18 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControl_h_
#define RTW_HEADER_flightControl_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef flightControl_COMMON_INCLUDES_
# define flightControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "HostLib_Network.h"
#endif                                 /* flightControl_COMMON_INCLUDES_ */

#include "flightControl_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
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
  real32_T UDPReceive_o1[31];          /* '<Root>/UDP Receive' */
  real32_T Selector[3];                /* '<S2>/Selector' */
  real32_T Product[3];                 /* '<S2>/Product' */
  real32_T Selector1[3];               /* '<S2>/Selector1' */
  real32_T Selector2[3];               /* '<S2>/Selector2' */
  real32_T OutportBufferForq[4];       /* '<S2>/runMahonyUpdate' */
  real32_T q[4];                       /* '<S2>/runMahonyUpdate' */
  uint16_T UDPReceive_o2;              /* '<Root>/UDP Receive' */
} B_flightControl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPReceive_NetworkLib[137];   /* '<Root>/UDP Receive' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK_b;                     /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S2>/To Workspace3' */

  real32_T qLocal[4];                  /* '<S2>/runMahonyUpdate' */
  real32_T bias[3];                    /* '<S4>/calibrate1' */
  real32_T bias_c[3];                  /* '<S4>/calibrate' */
  uint32_T count;                      /* '<S4>/calibrate1' */
  uint32_T count_m;                    /* '<S4>/calibrate' */
  int8_T runSensorFusion_SubsysRanBC;  /* '<Root>/runSensorFusion' */
  boolean_T runSensorFusion_MODE;      /* '<Root>/runSensorFusion' */
} DW_flightControl_T;

/* Parameters (auto storage) */
struct P_flightControl_T_ {
  real32_T q_Y0;                       /* Computed Parameter: q_Y0
                                        * Referenced by: '<S2>/q'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S2>/Constant2'
                                        */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControl_T {
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
extern P_flightControl_T flightControl_P;

/* Block signals (auto storage) */
extern B_flightControl_T flightControl_B;

/* Block states (auto storage) */
extern DW_flightControl_T flightControl_DW;

/* Model entry point functions */
extern void flightControl_initialize(void);
extern void flightControl_output(void);
extern void flightControl_update(void);
extern void flightControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControl_T *const flightControl_M;

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
 * '<Root>' : 'flightControl'
 * '<S1>'   : 'flightControl/Compare To Zero'
 * '<S2>'   : 'flightControl/runSensorFusion'
 * '<S3>'   : 'flightControl/runSensorFusionMahony'
 * '<S4>'   : 'flightControl/runSensorFusion/calibrateSensorData'
 * '<S5>'   : 'flightControl/runSensorFusion/q2cFcn'
 * '<S6>'   : 'flightControl/runSensorFusion/qinvFcn'
 * '<S7>'   : 'flightControl/runSensorFusion/runMahonyUpdate'
 * '<S8>'   : 'flightControl/runSensorFusion/unpackData'
 * '<S9>'   : 'flightControl/runSensorFusion/calibrateSensorData/calibrate'
 * '<S10>'  : 'flightControl/runSensorFusion/calibrateSensorData/calibrate1'
 * '<S11>'  : 'flightControl/runSensorFusionMahony/For Iterator Subsystem'
 * '<S12>'  : 'flightControl/runSensorFusionMahony/For Iterator Subsystem1'
 * '<S13>'  : 'flightControl/runSensorFusionMahony/runMahonyUpdate'
 * '<S14>'  : 'flightControl/runSensorFusionMahony/For Iterator Subsystem/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_flightControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
