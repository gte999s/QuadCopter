/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorFusionTask.c
 *
 * Code generated for Simulink model 'sensorFusionTask'.
 *
 * Model version                  : 1.160
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * TLC version                    : 8.9 (Jul 31 2015)
 * C/C++ source code generated on : Sun May 15 17:57:20 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sensorFusionTask.h"
#include "sensorFusionTask_private.h"
#include "sensorFusionTask_dt.h"

/* Block signals (auto storage) */
B_sensorFusionTask_T sensorFusionTask_B;

/* Block states (auto storage) */
DW_sensorFusionTask_T sensorFusionTask_DW;

/* Real-time model */
RT_MODEL_sensorFusionTask_T sensorFusionTask_M_;
RT_MODEL_sensorFusionTask_T *const sensorFusionTask_M = &sensorFusionTask_M_;

/* Forward declaration for local functions */
static real32_T sensorFusionTask_norm(const real32_T x[3]);
static void sensorFusionTa_runMadwickUpdate(const real32_T qIn[4], real32_T
  Accelerometer[3], const real32_T Gyroscope[3], real32_T Magnetometer[3],
  real32_T Beta, real32_T q[4]);

/*
 * Initial conditions for atomic system:
 *    '<S7>/calibrate'
 *    '<S7>/calibrate1'
 */
void sensorFusionTask_calibrate_Init(DW_calibrate_sensorFusionTask_T *localDW)
{
  localDW->count = 1U;
  localDW->bias[0] = 0.0F;
  localDW->bias[1] = 0.0F;
  localDW->bias[2] = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S7>/calibrate'
 *    '<S7>/calibrate1'
 */
void sensorFusionTask_calibrate(const real32_T rtu_raw[12], real32_T
  rtu_sampleSize, B_calibrate_sensorFusionTask_T *localB,
  DW_calibrate_sensorFusionTask_T *localDW)
{
  real32_T y;
  int32_T i;
  uint32_T qY;

  /* MATLAB Function 'runSensorFusion/calibrateSensorData/calibrate': '<S10>:1' */
  if ((real_T)localDW->count >= rtu_sampleSize) {
    /* '<S10>:1:10' */
    /* '<S10>:1:11' */
    localB->cal[0] = rtu_raw[0] - localDW->bias[0];
    localB->cal[3] = rtu_raw[3] - localDW->bias[0];
    localB->cal[6] = rtu_raw[6] - localDW->bias[0];
    localB->cal[9] = rtu_raw[9] - localDW->bias[0];
    localB->cal[1] = rtu_raw[1] - localDW->bias[1];
    localB->cal[4] = rtu_raw[4] - localDW->bias[1];
    localB->cal[7] = rtu_raw[7] - localDW->bias[1];
    localB->cal[10] = rtu_raw[10] - localDW->bias[1];
    localB->cal[2] = rtu_raw[2] - localDW->bias[2];
    localB->cal[5] = rtu_raw[5] - localDW->bias[2];
    localB->cal[8] = rtu_raw[8] - localDW->bias[2];
    localB->cal[11] = rtu_raw[11] - localDW->bias[2];
  } else {
    /* '<S10>:1:13' */
    for (i = 0; i < 12; i++) {
      localB->cal[i] = 0.0F;
    }

    /* '<S10>:1:14' */
    for (i = 0; i < 4; i++) {
      /* '<S10>:1:14' */
      /* '<S10>:1:15' */
      y = 1.0F / rtu_sampleSize;
      localDW->bias[0] += rtu_raw[3 * i] * y;
      localDW->bias[1] += rtu_raw[3 * i + 1] * y;
      localDW->bias[2] += rtu_raw[3 * i + 2] * y;

      /* '<S10>:1:16' */
      qY = localDW->count + 1U;
      if (qY < localDW->count) {
        qY = MAX_uint32_T;
      }

      localDW->count = qY;

      /* '<S10>:1:14' */
    }
  }

  /* '<S10>:1:19' */
  localB->biasOut[0] = localDW->bias[0];
  localB->biasOut[1] = localDW->bias[1];
  localB->biasOut[2] = localDW->bias[2];
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = (real32_T)atan2((real32_T)u0_0, (real32_T)u1_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/runMahonyUpdate' */
static real32_T sensorFusionTask_norm(const real32_T x[3])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.17549435E-38F;
  absxk = (real32_T)fabs(x[0]);
  if (absxk > 1.17549435E-38F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.17549435E-38F;
    y = t * t;
  }

  absxk = (real32_T)fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = (real32_T)fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * (real32_T)sqrt(y);
}

/* Function for MATLAB Function: '<S3>/runMahonyUpdate' */
static void sensorFusionTa_runMadwickUpdate(const real32_T qIn[4], real32_T
  Accelerometer[3], const real32_T Gyroscope[3], real32_T Magnetometer[3],
  real32_T Beta, real32_T q[4])
{
  real32_T step[4];
  int32_T k;
  boolean_T b_y;
  boolean_T x[3];
  real32_T B;
  real_T d_y;
  real_T scale;
  real_T absxk;
  real_T t;
  real32_T b_scale;
  real32_T c_absxk;
  real32_T c_t;
  boolean_T exitg2;
  real32_T tmp[24];
  real32_T tmp_0[6];
  int32_T i;
  real_T b_idx_0;
  real_T b_idx_1;
  real_T b_idx_2;
  real_T b_idx_3;
  real_T h_idx_3;

  /*  Normalise accelerometer measurement */
  x[0] = ((real32_T)fabs(Accelerometer[0]) < 0.0001);
  x[1] = ((real32_T)fabs(Accelerometer[1]) < 0.0001);
  x[2] = ((real32_T)fabs(Accelerometer[2]) < 0.0001);
  b_y = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k < 3)) {
    if (!x[k]) {
      b_y = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (!b_y) {
    /* '<S8>:1:26' */
    /* '<S8>:1:27' */
    B = sensorFusionTask_norm(Accelerometer);
    Accelerometer[0] /= B;
    Accelerometer[1] /= B;
    Accelerometer[2] /= B;

    /*  normalise magnitude */
  }

  /*  Normalise magnetometer measurement */
  x[0] = ((real32_T)fabs(Magnetometer[0]) < 0.0001);
  x[1] = ((real32_T)fabs(Magnetometer[1]) < 0.0001);
  x[2] = ((real32_T)fabs(Magnetometer[2]) < 0.0001);
  b_y = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k < 3)) {
    if (!x[k]) {
      b_y = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (!b_y) {
    /* '<S8>:1:30' */
    /* '<S8>:1:31' */
    B = sensorFusionTask_norm(Magnetometer);
    Magnetometer[0] /= B;
    Magnetometer[1] /= B;
    Magnetometer[2] /= B;

    /*  normalise magnitude */
  }

  /*  Reference direction of Earth's magnetic feild */
  /* '<S8>:1:34' */
  /* QUATERN2ROTMAT Converts a quaternion to its conjugate */
  /*  */
  /*    qConj = quaternConj(q) */
  /*  */
  /*    Converts a quaternion to its conjugate. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* '<S8>:1:92' */
  /*  normalise quaternion */
  /* '<S8>:1:61' */
  /* QUATERNPROD Calculates the quaternion product */
  /*  */
  /*    ab = quaternProd(a, b) */
  /*  */
  /*    Calculates the quaternion product of quaternion a and b. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* '<S8>:1:74' */
  b_idx_0 = ((0.0F * qIn[0] - Magnetometer[0] * -qIn[1]) - Magnetometer[1] *
             -qIn[2]) - Magnetometer[2] * -qIn[3];

  /* '<S8>:1:75' */
  b_idx_1 = ((0.0F * -qIn[1] + Magnetometer[0] * qIn[0]) + Magnetometer[1] *
             -qIn[3]) - Magnetometer[2] * -qIn[2];

  /* '<S8>:1:76' */
  b_idx_2 = ((0.0F * -qIn[2] - Magnetometer[0] * -qIn[3]) + Magnetometer[1] *
             qIn[0]) + Magnetometer[2] * -qIn[1];

  /* '<S8>:1:77' */
  b_idx_3 = ((0.0F * -qIn[3] + Magnetometer[0] * -qIn[2]) - Magnetometer[1] *
             -qIn[1]) + Magnetometer[2] * qIn[0];

  /*  normalise quaternion */
  /* '<S8>:1:61' */
  /* QUATERNPROD Calculates the quaternion product */
  /*  */
  /*    ab = quaternProd(a, b) */
  /*  */
  /*    Calculates the quaternion product of quaternion a and b. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* '<S8>:1:74' */
  /* '<S8>:1:75' */
  /* '<S8>:1:76' */
  /* '<S8>:1:77' */
  h_idx_3 = ((qIn[0] * (real32_T)b_idx_3 + qIn[1] * (real32_T)b_idx_2) - qIn[2] *
             (real32_T)b_idx_1) + qIn[3] * (real32_T)b_idx_0;

  /* '<S8>:1:35' */
  scale = 2.2250738585072014E-308;
  absxk = fabs(((qIn[0] * (real32_T)b_idx_1 + qIn[1] * (real32_T)b_idx_0) + qIn
                [2] * (real32_T)b_idx_3) - qIn[3] * (real32_T)b_idx_2);
  if (absxk > 2.2250738585072014E-308) {
    d_y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    d_y = t * t;
  }

  absxk = fabs(((qIn[0] * (real32_T)b_idx_2 - qIn[1] * (real32_T)b_idx_3) + qIn
                [2] * (real32_T)b_idx_0) + qIn[3] * (real32_T)b_idx_1);
  if (absxk > scale) {
    t = scale / absxk;
    d_y = d_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    d_y += t * t;
  }

  d_y = scale * sqrt(d_y);

  /*  Gradient decent algorithm corrective step */
  /* '<S8>:1:37' */
  /* '<S8>:1:43' */
  /* '<S8>:1:49' */
  tmp[0] = -2.0F * qIn[2];
  tmp[1] = 2.0F * qIn[3];
  tmp[2] = -2.0F * qIn[0];
  tmp[3] = 2.0F * qIn[1];
  tmp[4] = 2.0F * qIn[1];
  tmp[5] = 2.0F * qIn[0];
  tmp[6] = 2.0F * qIn[3];
  tmp[7] = 2.0F * qIn[2];
  tmp[8] = 0.0F;
  tmp[9] = -4.0F * qIn[1];
  tmp[10] = -4.0F * qIn[2];
  tmp[11] = 0.0F;
  tmp[12] = (real32_T)(-2.0 * h_idx_3) * qIn[2];
  tmp[13] = (real32_T)(2.0 * h_idx_3) * qIn[3];
  tmp[14] = (real32_T)(-4.0 * d_y) * qIn[2] - (real32_T)(2.0 * h_idx_3) * qIn[0];
  tmp[15] = (real32_T)(-4.0 * d_y) * qIn[3] + (real32_T)(2.0 * h_idx_3) * qIn[1];
  tmp[16] = (real32_T)(-2.0 * d_y) * qIn[3] + (real32_T)(2.0 * h_idx_3) * qIn[1];
  tmp[17] = (real32_T)(2.0 * d_y) * qIn[2] + (real32_T)(2.0 * h_idx_3) * qIn[0];
  tmp[18] = (real32_T)(2.0 * d_y) * qIn[1] + (real32_T)(2.0 * h_idx_3) * qIn[3];
  tmp[19] = (real32_T)(-2.0 * d_y) * qIn[0] + (real32_T)(2.0 * h_idx_3) * qIn[2];
  tmp[20] = (real32_T)(2.0 * d_y) * qIn[2];
  tmp[21] = (real32_T)(2.0 * d_y) * qIn[3] - (real32_T)(4.0 * h_idx_3) * qIn[1];
  tmp[22] = (real32_T)(2.0 * d_y) * qIn[0] - (real32_T)(4.0 * h_idx_3) * qIn[2];
  tmp[23] = (real32_T)(2.0 * d_y) * qIn[1];
  tmp_0[0] = (qIn[1] * qIn[3] - qIn[0] * qIn[2]) * 2.0F - Accelerometer[0];
  tmp_0[1] = (qIn[0] * qIn[1] + qIn[2] * qIn[3]) * 2.0F - Accelerometer[1];
  tmp_0[2] = ((0.5F - qIn[1] * qIn[1]) - qIn[2] * qIn[2]) * 2.0F -
    Accelerometer[2];
  tmp_0[3] = (((0.5F - qIn[2] * qIn[2]) - qIn[3] * qIn[3]) * (real32_T)(2.0 *
    d_y) + (qIn[1] * qIn[3] - qIn[0] * qIn[2]) * (real32_T)(2.0 * h_idx_3)) -
    Magnetometer[0];
  tmp_0[4] = ((qIn[1] * qIn[2] - qIn[0] * qIn[3]) * (real32_T)(2.0 * d_y) +
              (qIn[0] * qIn[1] + qIn[2] * qIn[3]) * (real32_T)(2.0 * h_idx_3)) -
    Magnetometer[1];
  tmp_0[5] = (((0.5F - qIn[1] * qIn[1]) - qIn[2] * qIn[2]) * (real32_T)(2.0 *
    h_idx_3) + (qIn[0] * qIn[2] + qIn[1] * qIn[3]) * (real32_T)(2.0 * d_y)) -
    Magnetometer[2];

  /* '<S8>:1:50' */
  B = 0.0F;
  b_scale = 1.17549435E-38F;
  for (k = 0; k < 4; k++) {
    step[k] = 0.0F;
    for (i = 0; i < 6; i++) {
      step[k] += tmp[(i << 2) + k] * tmp_0[i];
    }

    c_absxk = (real32_T)fabs(step[k]);
    if (c_absxk > b_scale) {
      c_t = b_scale / c_absxk;
      B = B * c_t * c_t + 1.0F;
      b_scale = c_absxk;
    } else {
      c_t = c_absxk / b_scale;
      B += c_t * c_t;
    }
  }

  B = b_scale * (real32_T)sqrt(B);

  /*  normalise step magnitude */
  /*  Compute rate of change of quaternion */
  /* '<S8>:1:53' */
  /*  normalise quaternion */
  /* '<S8>:1:61' */
  /* QUATERNPROD Calculates the quaternion product */
  /*  */
  /*    ab = quaternProd(a, b) */
  /*  */
  /*    Calculates the quaternion product of quaternion a and b. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* '<S8>:1:74' */
  /* '<S8>:1:75' */
  /* '<S8>:1:76' */
  /* '<S8>:1:77' */
  /*  Integrate to yield quaternion */
  /* '<S8>:1:56' */
  q[0] = ((real32_T)((((qIn[0] * 0.0F - qIn[1] * Gyroscope[0]) - qIn[2] *
                       Gyroscope[1]) - qIn[3] * Gyroscope[2]) * 0.5) - step[0] /
          B * Beta) * 0.005F + qIn[0];
  q[1] = ((real32_T)((((qIn[0] * Gyroscope[0] + qIn[1] * 0.0F) + qIn[2] *
                       Gyroscope[2]) - qIn[3] * Gyroscope[1]) * 0.5) - step[1] /
          B * Beta) * 0.005F + qIn[1];
  q[2] = ((real32_T)((((qIn[0] * Gyroscope[1] - qIn[1] * Gyroscope[2]) + qIn[2] *
                       0.0F) + qIn[3] * Gyroscope[0]) * 0.5) - step[2] / B *
          Beta) * 0.005F + qIn[2];
  q[3] = ((real32_T)((((qIn[0] * Gyroscope[2] + qIn[1] * Gyroscope[1]) - qIn[2] *
                       Gyroscope[0]) + qIn[3] * 0.0F) * 0.5) - step[3] / B *
          Beta) * 0.005F + qIn[3];

  /* '<S8>:1:57' */
  b_scale = 1.17549435E-38F;
  c_absxk = (real32_T)fabs(q[0]);
  if (c_absxk > 1.17549435E-38F) {
    B = 1.0F;
    b_scale = c_absxk;
  } else {
    c_t = c_absxk / 1.17549435E-38F;
    B = c_t * c_t;
  }

  c_absxk = (real32_T)fabs(q[1]);
  if (c_absxk > b_scale) {
    c_t = b_scale / c_absxk;
    B = B * c_t * c_t + 1.0F;
    b_scale = c_absxk;
  } else {
    c_t = c_absxk / b_scale;
    B += c_t * c_t;
  }

  c_absxk = (real32_T)fabs(q[2]);
  if (c_absxk > b_scale) {
    c_t = b_scale / c_absxk;
    B = B * c_t * c_t + 1.0F;
    b_scale = c_absxk;
  } else {
    c_t = c_absxk / b_scale;
    B += c_t * c_t;
  }

  c_absxk = (real32_T)fabs(q[3]);
  if (c_absxk > b_scale) {
    c_t = b_scale / c_absxk;
    B = B * c_t * c_t + 1.0F;
    b_scale = c_absxk;
  } else {
    c_t = c_absxk / b_scale;
    B += c_t * c_t;
  }

  B = b_scale * (real32_T)sqrt(B);
  q[0] /= B;
  q[1] /= B;
  q[2] /= B;
  q[3] /= B;
}

/* Model output function */
void sensorFusionTask_output(void)
{
  char_T *sErr;
  int32_T samplesRead;
  real32_T magInterp[12];
  real32_T varargin_2[6];
  int32_T k;
  real_T r;
  boolean_T rtb_Compare;
  real32_T rtb_MatrixConcatenate1[12];
  real32_T tmp[3];
  real32_T magInterp_0[3];
  real32_T R_idx_2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(sensorFusionTask_DW.runSensorFusion_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 31;
  LibOutputs_Network(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U],
                     &sensorFusionTask_B.UDPReceive_o1[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(sensorFusionTask_M, sErr);
    rtmSetStopRequested(sensorFusionTask_M, 1);
  }

  sensorFusionTask_B.UDPReceive_o2 = (uint16_T)samplesRead;

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Compare = (sensorFusionTask_B.UDPReceive_o2 >
                 sensorFusionTask_P.Constant_Value_p);

  /* Outputs for Enabled SubSystem: '<Root>/runSensorFusion' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtb_Compare) {
    if (!sensorFusionTask_DW.runSensorFusion_MODE) {
      sensorFusionTask_DW.runSensorFusion_MODE = true;
    }

    /* Concatenate: '<S9>/Matrix Concatenate1' */
    rtb_MatrixConcatenate1[0] = sensorFusionTask_B.UDPReceive_o1[0];
    rtb_MatrixConcatenate1[3] = sensorFusionTask_B.UDPReceive_o1[1];
    rtb_MatrixConcatenate1[6] = sensorFusionTask_B.UDPReceive_o1[2];
    rtb_MatrixConcatenate1[9] = sensorFusionTask_B.UDPReceive_o1[3];
    rtb_MatrixConcatenate1[1] = sensorFusionTask_B.UDPReceive_o1[4];
    rtb_MatrixConcatenate1[4] = sensorFusionTask_B.UDPReceive_o1[5];
    rtb_MatrixConcatenate1[7] = sensorFusionTask_B.UDPReceive_o1[6];
    rtb_MatrixConcatenate1[10] = sensorFusionTask_B.UDPReceive_o1[7];
    rtb_MatrixConcatenate1[2] = sensorFusionTask_B.UDPReceive_o1[8];
    rtb_MatrixConcatenate1[5] = sensorFusionTask_B.UDPReceive_o1[9];
    rtb_MatrixConcatenate1[8] = sensorFusionTask_B.UDPReceive_o1[10];
    rtb_MatrixConcatenate1[11] = sensorFusionTask_B.UDPReceive_o1[11];

    /* MATLAB Function: '<S7>/calibrate' incorporates:
     *  Constant: '<S7>/Constant'
     */
    sensorFusionTask_calibrate(rtb_MatrixConcatenate1,
      sensorFusionTask_P.Constant_Value, &sensorFusionTask_B.sf_calibrate,
      &sensorFusionTask_DW.sf_calibrate);

    /* Concatenate: '<S9>/Matrix Concatenate2' */
    rtb_MatrixConcatenate1[0] = sensorFusionTask_B.UDPReceive_o1[12];
    rtb_MatrixConcatenate1[3] = sensorFusionTask_B.UDPReceive_o1[13];
    rtb_MatrixConcatenate1[6] = sensorFusionTask_B.UDPReceive_o1[14];
    rtb_MatrixConcatenate1[9] = sensorFusionTask_B.UDPReceive_o1[15];
    rtb_MatrixConcatenate1[1] = sensorFusionTask_B.UDPReceive_o1[16];
    rtb_MatrixConcatenate1[4] = sensorFusionTask_B.UDPReceive_o1[17];
    rtb_MatrixConcatenate1[7] = sensorFusionTask_B.UDPReceive_o1[18];
    rtb_MatrixConcatenate1[10] = sensorFusionTask_B.UDPReceive_o1[19];
    rtb_MatrixConcatenate1[2] = sensorFusionTask_B.UDPReceive_o1[20];
    rtb_MatrixConcatenate1[5] = sensorFusionTask_B.UDPReceive_o1[21];
    rtb_MatrixConcatenate1[8] = sensorFusionTask_B.UDPReceive_o1[22];
    rtb_MatrixConcatenate1[11] = sensorFusionTask_B.UDPReceive_o1[23];

    /* MATLAB Function: '<S7>/calibrate1' incorporates:
     *  Constant: '<S7>/Constant'
     */
    sensorFusionTask_calibrate(rtb_MatrixConcatenate1,
      sensorFusionTask_P.Constant_Value, &sensorFusionTask_B.sf_calibrate1,
      &sensorFusionTask_DW.sf_calibrate1);

    /* Concatenate: '<S9>/Matrix Concatenate' */
    sensorFusionTask_B.MatrixConcatenate[0] = sensorFusionTask_B.UDPReceive_o1
      [24];
    sensorFusionTask_B.MatrixConcatenate[3] = sensorFusionTask_B.UDPReceive_o1
      [25];
    sensorFusionTask_B.MatrixConcatenate[1] = sensorFusionTask_B.UDPReceive_o1
      [26];
    sensorFusionTask_B.MatrixConcatenate[4] = sensorFusionTask_B.UDPReceive_o1
      [27];
    sensorFusionTask_B.MatrixConcatenate[2] = sensorFusionTask_B.UDPReceive_o1
      [28];
    sensorFusionTask_B.MatrixConcatenate[5] = sensorFusionTask_B.UDPReceive_o1
      [29];

    /* MATLAB Function: '<S3>/runMahonyUpdate' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    /* MATLAB Function 'runSensorFusion/runMahonyUpdate': '<S8>:1' */
    /* '<S8>:1:6' */
    /* '<S8>:1:10' */
    for (k = 0; k < 3; k++) {
      varargin_2[k << 1] = sensorFusionTask_B.MatrixConcatenate[k];
      varargin_2[1 + (k << 1)] = sensorFusionTask_B.MatrixConcatenate[k + 3];
    }

    for (k = 0; k < 12; k++) {
      rtb_MatrixConcatenate1[k] = (rtNaNF);
    }

    /* '<S8>:1:12' */
    for (k = 0; k < 4; k++) {
      r = (((real_T)k + 1.0) - 1.0) / 3.0;
      if (r == 0.0) {
        rtb_MatrixConcatenate1[k] = varargin_2[0];
        rtb_MatrixConcatenate1[k + 4] = varargin_2[2];
        rtb_MatrixConcatenate1[k + 8] = varargin_2[4];
      } else if (r == 1.0) {
        rtb_MatrixConcatenate1[k] = varargin_2[1];
        rtb_MatrixConcatenate1[k + 4] = varargin_2[3];
        rtb_MatrixConcatenate1[k + 8] = varargin_2[5];
      } else {
        if (varargin_2[0] == varargin_2[1]) {
          rtb_MatrixConcatenate1[k] = varargin_2[0];
        } else {
          rtb_MatrixConcatenate1[k] = (real32_T)(1.0 - r) * varargin_2[0] +
            (real32_T)r * varargin_2[1];
        }

        if (varargin_2[2] == varargin_2[3]) {
          rtb_MatrixConcatenate1[k + 4] = varargin_2[2];
        } else {
          rtb_MatrixConcatenate1[k + 4] = (real32_T)(1.0 - r) * varargin_2[2] +
            (real32_T)r * varargin_2[3];
        }

        if (varargin_2[4] == varargin_2[5]) {
          rtb_MatrixConcatenate1[k + 8] = varargin_2[4];
        } else {
          rtb_MatrixConcatenate1[k + 8] = (real32_T)(1.0 - r) * varargin_2[4] +
            (real32_T)r * varargin_2[5];
        }
      }

      magInterp[3 * k] = rtb_MatrixConcatenate1[k];
      magInterp[1 + 3 * k] = rtb_MatrixConcatenate1[k + 4];
      magInterp[2 + 3 * k] = rtb_MatrixConcatenate1[k + 8];

      /* '<S8>:1:12' */
      /* '<S8>:1:14' */
      tmp[0] = sensorFusionTask_B.sf_calibrate.cal[3 * k];
      magInterp_0[0] = magInterp[3 * k];
      tmp[1] = sensorFusionTask_B.sf_calibrate.cal[3 * k + 1];
      magInterp_0[1] = magInterp[3 * k + 1];
      tmp[2] = sensorFusionTask_B.sf_calibrate.cal[3 * k + 2];
      magInterp_0[2] = magInterp[3 * k + 2];
      sensorFusionTa_runMadwickUpdate(sensorFusionTask_DW.qLocal, tmp,
        *(real32_T (*)[3])&sensorFusionTask_B.sf_calibrate1.cal[3 * k],
        magInterp_0, sensorFusionTask_P.Constant2_Value, sensorFusionTask_B.q);

      /* '<S8>:1:15' */
      sensorFusionTask_DW.qLocal[0] = sensorFusionTask_B.q[0];
      sensorFusionTask_DW.qLocal[1] = sensorFusionTask_B.q[1];
      sensorFusionTask_DW.qLocal[2] = sensorFusionTask_B.q[2];
      sensorFusionTask_DW.qLocal[3] = sensorFusionTask_B.q[3];

      /* '<S8>:1:12' */
    }

    /* MATLAB Function: '<S3>/MATLAB Function' */
    /* '<S8>:1:19' */
    /* MATLAB Function 'runSensorFusion/MATLAB Function': '<S6>:1' */
    /* QUATERN2EULER Converts a quaternion orientation to ZYX Euler angles */
    /*  */
    /*    q = quatern2euler(q) */
    /*  */
    /*    Converts a quaternion orientation to ZYX Euler angles where phi is a */
    /*    rotation around X, theta around Y and psi around Z. */
    /*  */
    /*    For more information see: */
    /*    http://www.x-io.co.uk/node/8#quaternions */
    /*  */
    /* 	Date          Author          Notes */
    /* 	27/09/2011    SOH Madgwick    Initial release */
    /* '<S6>:1:17' */
    /* '<S6>:1:18' */
    /* '<S6>:1:19' */
    R_idx_2 = (sensorFusionTask_B.q[1] * sensorFusionTask_B.q[3] +
               sensorFusionTask_B.q[0] * sensorFusionTask_B.q[2]) * 2.0F;

    /* SignalConversion: '<S3>/OutportBufferForZYX' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    /* '<S6>:1:20' */
    /* '<S6>:1:21' */
    /* '<S6>:1:23' */
    /* '<S6>:1:24' */
    /* '<S6>:1:25' */
    /* '<S6>:1:27' */
    sensorFusionTask_B.OutportBufferForZYX[0] = rt_atan2f_snf
      ((sensorFusionTask_B.q[2] * sensorFusionTask_B.q[3] -
        sensorFusionTask_B.q[0] * sensorFusionTask_B.q[1]) * 2.0F,
       (sensorFusionTask_B.q[0] * sensorFusionTask_B.q[0] * 2.0F - 1.0F) +
       sensorFusionTask_B.q[3] * sensorFusionTask_B.q[3] * 2.0F);
    sensorFusionTask_B.OutportBufferForZYX[1] = -(real32_T)atan(R_idx_2 /
      (real32_T)sqrt(1.0F - R_idx_2 * R_idx_2));
    sensorFusionTask_B.OutportBufferForZYX[2] = rt_atan2f_snf
      ((sensorFusionTask_B.q[1] * sensorFusionTask_B.q[2] -
        sensorFusionTask_B.q[0] * sensorFusionTask_B.q[3]) * 2.0F,
       (sensorFusionTask_B.q[0] * sensorFusionTask_B.q[0] * 2.0F - 1.0F) +
       sensorFusionTask_B.q[1] * sensorFusionTask_B.q[1] * 2.0F);

    /* MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[0] = sensorFusionTask_B.q[0];

    /* SignalConversion: '<S3>/OutportBufferForq' */
    sensorFusionTask_B.OutportBufferForq[0] = sensorFusionTask_B.q[0];

    /* MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[1] = sensorFusionTask_B.q[1];

    /* SignalConversion: '<S3>/OutportBufferForq' */
    sensorFusionTask_B.OutportBufferForq[1] = sensorFusionTask_B.q[1];

    /* MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[2] = sensorFusionTask_B.q[2];

    /* SignalConversion: '<S3>/OutportBufferForq' */
    sensorFusionTask_B.OutportBufferForq[2] = sensorFusionTask_B.q[2];

    /* MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[3] = sensorFusionTask_B.q[3];

    /* SignalConversion: '<S3>/OutportBufferForq' */
    sensorFusionTask_B.OutportBufferForq[3] = sensorFusionTask_B.q[3];
    srUpdateBC(sensorFusionTask_DW.runSensorFusion_SubsysRanBC);
  } else {
    if (sensorFusionTask_DW.runSensorFusion_MODE) {
      sensorFusionTask_DW.runSensorFusion_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/runSensorFusion' */

  /* Gain: '<Root>/Gain' */
  sensorFusionTask_B.Gain[0] = sensorFusionTask_P.Gain_Gain *
    sensorFusionTask_B.OutportBufferForZYX[0];
  sensorFusionTask_B.Gain[1] = sensorFusionTask_P.Gain_Gain *
    sensorFusionTask_B.OutportBufferForZYX[1];
  sensorFusionTask_B.Gain[2] = sensorFusionTask_P.Gain_Gain *
    sensorFusionTask_B.OutportBufferForZYX[2];

  /* Switch: '<S5>/Init' incorporates:
   *  Constant: '<S5>/Initial Condition'
   *  Logic: '<S5>/FixPt Logical Operator'
   *  UnitDelay: '<S5>/FixPt Unit Delay1'
   *  UnitDelay: '<S5>/FixPt Unit Delay2'
   */
  if (rtb_Compare || (sensorFusionTask_DW.FixPtUnitDelay2_DSTATE != 0)) {
    sensorFusionTask_B.Init = sensorFusionTask_P.UnitDelayResettable_vinit;
  } else {
    sensorFusionTask_B.Init = sensorFusionTask_DW.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S5>/Init' */

  /* Switch: '<S5>/Reset' incorporates:
   *  Constant: '<S5>/Initial Condition'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Sum: '<S2>/Sum'
   */
  if (rtb_Compare) {
    sensorFusionTask_B.Xnew = sensorFusionTask_P.UnitDelayResettable_vinit;
  } else {
    sensorFusionTask_B.Xnew = 1.0F + sensorFusionTask_B.Init;
  }

  /* End of Switch: '<S5>/Reset' */
}

/* Model update function */
void sensorFusionTask_update(void)
{
  /* Update for UnitDelay: '<S5>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   */
  sensorFusionTask_DW.FixPtUnitDelay2_DSTATE =
    sensorFusionTask_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S5>/FixPt Unit Delay1' */
  sensorFusionTask_DW.FixPtUnitDelay1_DSTATE = sensorFusionTask_B.Xnew;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(sensorFusionTask_M)!=-1) &&
        !((rtmGetTFinal(sensorFusionTask_M)-sensorFusionTask_M->Timing.taskTime0)
          > sensorFusionTask_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sensorFusionTask_M, "Simulation finished");
    }

    if (rtmGetStopRequested(sensorFusionTask_M)) {
      rtmSetErrorStatus(sensorFusionTask_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sensorFusionTask_M->Timing.taskTime0 =
    (++sensorFusionTask_M->Timing.clockTick0) *
    sensorFusionTask_M->Timing.stepSize0;
}

/* Model initialize function */
void sensorFusionTask_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sensorFusionTask_M, 0,
                sizeof(RT_MODEL_sensorFusionTask_T));
  rtmSetTFinal(sensorFusionTask_M, -1);
  sensorFusionTask_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  sensorFusionTask_M->Sizes.checksums[0] = (2618813554U);
  sensorFusionTask_M->Sizes.checksums[1] = (3418306947U);
  sensorFusionTask_M->Sizes.checksums[2] = (2583336299U);
  sensorFusionTask_M->Sizes.checksums[3] = (1243147224U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    sensorFusionTask_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &sensorFusionTask_DW.runSensorFusion_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &sensorFusionTask_DW.runSensorFusion_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &sensorFusionTask_DW.runSensorFusion_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &sensorFusionTask_DW.runSensorFusion_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &sensorFusionTask_DW.runSensorFusion_SubsysRanBC;
    rteiSetModelMappingInfoPtr(sensorFusionTask_M->extModeInfo,
      &sensorFusionTask_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sensorFusionTask_M->extModeInfo,
                        sensorFusionTask_M->Sizes.checksums);
    rteiSetTPtr(sensorFusionTask_M->extModeInfo, rtmGetTPtr(sensorFusionTask_M));
  }

  /* block I/O */
  (void) memset(((void *) &sensorFusionTask_B), 0,
                sizeof(B_sensorFusionTask_T));

  /* states (dwork) */
  (void) memset((void *)&sensorFusionTask_DW, 0,
                sizeof(DW_sensorFusionTask_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sensorFusionTask_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
    sErr = GetErrorBuffer(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U], 0,
                        "0.0.0.0", 25000, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(sensorFusionTask_M, sErr);
        rtmSetStopRequested(sensorFusionTask_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S7>/calibrate' */
    sensorFusionTask_calibrate_Init(&sensorFusionTask_DW.sf_calibrate);

    /* InitializeConditions for MATLAB Function: '<S7>/calibrate1' */
    sensorFusionTask_calibrate_Init(&sensorFusionTask_DW.sf_calibrate1);

    /* InitializeConditions for MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[0] = 1.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S3>/q' */
    sensorFusionTask_B.OutportBufferForq[0] = sensorFusionTask_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[1] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S3>/q' */
    sensorFusionTask_B.OutportBufferForq[1] = sensorFusionTask_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[2] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S3>/q' */
    sensorFusionTask_B.OutportBufferForq[2] = sensorFusionTask_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S3>/runMahonyUpdate' */
    sensorFusionTask_DW.qLocal[3] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S3>/q' */
    sensorFusionTask_B.OutportBufferForq[3] = sensorFusionTask_P.q_Y0;

    /* VirtualOutportStart for Outport: '<S3>/ZYX' */
    sensorFusionTask_B.OutportBufferForZYX[0] = sensorFusionTask_P.ZYX_Y0;
    sensorFusionTask_B.OutportBufferForZYX[1] = sensorFusionTask_P.ZYX_Y0;
    sensorFusionTask_B.OutportBufferForZYX[2] = sensorFusionTask_P.ZYX_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for UnitDelay: '<S5>/FixPt Unit Delay2' */
    sensorFusionTask_DW.FixPtUnitDelay2_DSTATE =
      sensorFusionTask_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S5>/FixPt Unit Delay1' */
    sensorFusionTask_DW.FixPtUnitDelay1_DSTATE =
      sensorFusionTask_P.UnitDelayResettable_vinit;
  }
}

/* Model terminate function */
void sensorFusionTask_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(sensorFusionTask_M, sErr);
    rtmSetStopRequested(sensorFusionTask_M, 1);
  }

  LibDestroy(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&sensorFusionTask_DW.UDPReceive_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
