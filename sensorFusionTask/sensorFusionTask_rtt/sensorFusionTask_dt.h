/*
 * sensorFusionTask_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sensorFusionTask".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sun May 15 17:57:20 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&sensorFusionTask_B.UDPReceive_o1[0]), 1, 0, 53 },

  { (char_T *)(&sensorFusionTask_B.UDPReceive_o2), 5, 0, 1 },

  { (char_T *)(&sensorFusionTask_B.sf_calibrate1.cal[0]), 1, 0, 15 },

  { (char_T *)(&sensorFusionTask_B.sf_calibrate.cal[0]), 1, 0, 15 }
  ,

  { (char_T *)(&sensorFusionTask_DW.UDPReceive_NetworkLib[0]), 0, 0, 137 },

  { (char_T *)(&sensorFusionTask_DW.Scope_PWORK.LoggedData), 11, 0, 12 },

  { (char_T *)(&sensorFusionTask_DW.FixPtUnitDelay1_DSTATE), 1, 0, 5 },

  { (char_T *)(&sensorFusionTask_DW.FixPtUnitDelay2_DSTATE), 3, 0, 1 },

  { (char_T *)(&sensorFusionTask_DW.runSensorFusion_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&sensorFusionTask_DW.runSensorFusion_MODE), 8, 0, 1 },

  { (char_T *)(&sensorFusionTask_DW.sf_calibrate1.bias[0]), 1, 0, 3 },

  { (char_T *)(&sensorFusionTask_DW.sf_calibrate1.count), 7, 0, 1 },

  { (char_T *)(&sensorFusionTask_DW.sf_calibrate.bias[0]), 1, 0, 3 },

  { (char_T *)(&sensorFusionTask_DW.sf_calibrate.count), 7, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&sensorFusionTask_P.UnitDelayResettable_vinit), 1, 0, 6 },

  { (char_T *)(&sensorFusionTask_P.Constant_Value_p), 5, 0, 1 },

  { (char_T *)(&sensorFusionTask_P.FixPtUnitDelay2_InitialConditio), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] sensorFusionTask_dt.h */
