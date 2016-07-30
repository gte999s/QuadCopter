/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControl.c
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

#include "flightControl.h"
#include "flightControl_private.h"
#include "flightControl_dt.h"

/* Block signals (auto storage) */
B_flightControl_T flightControl_B;

/* Block states (auto storage) */
DW_flightControl_T flightControl_DW;

/* Real-time model */
RT_MODEL_flightControl_T flightControl_M_;
RT_MODEL_flightControl_T *const flightControl_M = &flightControl_M_;

/* Forward declaration for local functions */
static real32_T flightControl_norm(const real32_T x[3]);
static real32_T flightControl_norm_e(const real32_T x[4]);

/* Function for MATLAB Function: '<S2>/runMahonyUpdate' */
static real32_T flightControl_norm(const real32_T x[3])
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

/* Function for MATLAB Function: '<S2>/runMahonyUpdate' */
static real32_T flightControl_norm_e(const real32_T x[4])
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

  absxk = (real32_T)fabs(x[3]);
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

/* Model output function */
void flightControl_output(void)
{
  char_T *sErr;
  int32_T samplesRead;
  real32_T magInterp[12];
  real32_T varargin_2[6];
  real_T r;
  int32_T b_k;
  boolean_T b_y;
  boolean_T x[3];
  real_T scale;
  real_T absxk;
  real_T t;
  boolean_T exitg2;
  real32_T q1q2;
  real32_T q1q3;
  real32_T q1q0;
  real32_T q2q3;
  real32_T q2q0;
  real32_T q3q0;
  real32_T q1q1;
  real32_T q2q2;
  real32_T q3q3;
  real32_T rtb_MatrixConcatenate1[12];
  real32_T rtb_MatrixConcatenate[6];
  real32_T rtb_cal[12];
  real32_T rtb_cal_f[12];
  real32_T rtb_qout[4];
  real32_T rtb_c[9];
  int32_T i;
  real32_T tmp[24];
  real32_T tmp_0[6];
  int32_T i_0;
  real_T ab_idx_1;
  real_T ab_idx_2;
  real_T ab_idx_3;
  real_T b_idx_3;
  uint32_T qY;

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControl_DW.runSensorFusion_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&flightControl_DW.UDPReceive_NetworkLib[0U]);
  samplesRead = 31;
  LibOutputs_Network(&flightControl_DW.UDPReceive_NetworkLib[0U],
                     &flightControl_B.UDPReceive_o1[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(flightControl_M, sErr);
    rtmSetStopRequested(flightControl_M, 1);
  }

  flightControl_B.UDPReceive_o2 = (uint16_T)samplesRead;

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

  /* Outputs for Enabled SubSystem: '<Root>/runSensorFusion' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (flightControl_B.UDPReceive_o2 > flightControl_P.Constant_Value_p) {
    if (!flightControl_DW.runSensorFusion_MODE) {
      flightControl_DW.runSensorFusion_MODE = true;
    }

    /* Concatenate: '<S8>/Matrix Concatenate1' */
    rtb_MatrixConcatenate1[0] = flightControl_B.UDPReceive_o1[0];
    rtb_MatrixConcatenate1[3] = flightControl_B.UDPReceive_o1[1];
    rtb_MatrixConcatenate1[6] = flightControl_B.UDPReceive_o1[2];
    rtb_MatrixConcatenate1[9] = flightControl_B.UDPReceive_o1[3];
    rtb_MatrixConcatenate1[1] = flightControl_B.UDPReceive_o1[4];
    rtb_MatrixConcatenate1[4] = flightControl_B.UDPReceive_o1[5];
    rtb_MatrixConcatenate1[7] = flightControl_B.UDPReceive_o1[6];
    rtb_MatrixConcatenate1[10] = flightControl_B.UDPReceive_o1[7];
    rtb_MatrixConcatenate1[2] = flightControl_B.UDPReceive_o1[8];
    rtb_MatrixConcatenate1[5] = flightControl_B.UDPReceive_o1[9];
    rtb_MatrixConcatenate1[8] = flightControl_B.UDPReceive_o1[10];
    rtb_MatrixConcatenate1[11] = flightControl_B.UDPReceive_o1[11];

    /* Selector: '<S2>/Selector' */
    flightControl_B.Selector[0] = rtb_MatrixConcatenate1[9];
    flightControl_B.Selector[1] = rtb_MatrixConcatenate1[10];
    flightControl_B.Selector[2] = rtb_MatrixConcatenate1[11];

    /* MATLAB Function: '<S4>/calibrate' incorporates:
     *  Constant: '<S4>/Constant'
     */
    for (b_k = 0; b_k < 12; b_k++) {
      magInterp[b_k] = rtb_MatrixConcatenate1[b_k];
    }

    /* MATLAB Function 'runSensorFusion/calibrateSensorData/calibrate': '<S9>:1' */
    if ((real_T)flightControl_DW.count_m >= flightControl_P.Constant_Value) {
      /* '<S9>:1:10' */
      /* '<S9>:1:11' */
      rtb_cal_f[0] = rtb_MatrixConcatenate1[0] - flightControl_DW.bias_c[0];
      rtb_cal_f[3] = rtb_MatrixConcatenate1[3] - flightControl_DW.bias_c[0];
      rtb_cal_f[6] = rtb_MatrixConcatenate1[6] - flightControl_DW.bias_c[0];
      rtb_cal_f[9] = rtb_MatrixConcatenate1[9] - flightControl_DW.bias_c[0];
      rtb_cal_f[1] = rtb_MatrixConcatenate1[1] - flightControl_DW.bias_c[1];
      rtb_cal_f[4] = rtb_MatrixConcatenate1[4] - flightControl_DW.bias_c[1];
      rtb_cal_f[7] = rtb_MatrixConcatenate1[7] - flightControl_DW.bias_c[1];
      rtb_cal_f[10] = rtb_MatrixConcatenate1[10] - flightControl_DW.bias_c[1];
      rtb_cal_f[2] = rtb_MatrixConcatenate1[2] - flightControl_DW.bias_c[2];
      rtb_cal_f[5] = rtb_MatrixConcatenate1[5] - flightControl_DW.bias_c[2];
      rtb_cal_f[8] = rtb_MatrixConcatenate1[8] - flightControl_DW.bias_c[2];
      rtb_cal_f[11] = rtb_MatrixConcatenate1[11] - flightControl_DW.bias_c[2];
    } else {
      /* '<S9>:1:13' */
      for (i = 0; i < 12; i++) {
        rtb_cal_f[i] = 0.0F;
      }

      /* '<S9>:1:14' */
      for (i = 0; i < 4; i++) {
        /* '<S9>:1:14' */
        /* '<S9>:1:15' */
        magInterp[2 + 3 * i]--;

        /* '<S9>:1:16' */
        q1q2 = 1.0F / flightControl_P.Constant_Value;
        flightControl_DW.bias_c[0] += magInterp[3 * i] * q1q2;
        flightControl_DW.bias_c[1] += magInterp[3 * i + 1] * q1q2;
        flightControl_DW.bias_c[2] += magInterp[3 * i + 2] * q1q2;

        /* '<S9>:1:17' */
        qY = flightControl_DW.count_m + 1U;
        if (qY < flightControl_DW.count_m) {
          qY = MAX_uint32_T;
        }

        flightControl_DW.count_m = qY;

        /* '<S9>:1:14' */
      }
    }

    /* End of MATLAB Function: '<S4>/calibrate' */

    /* Concatenate: '<S8>/Matrix Concatenate2' */
    /* '<S9>:1:20' */
    rtb_MatrixConcatenate1[0] = flightControl_B.UDPReceive_o1[12];
    rtb_MatrixConcatenate1[3] = flightControl_B.UDPReceive_o1[13];
    rtb_MatrixConcatenate1[6] = flightControl_B.UDPReceive_o1[14];
    rtb_MatrixConcatenate1[9] = flightControl_B.UDPReceive_o1[15];
    rtb_MatrixConcatenate1[1] = flightControl_B.UDPReceive_o1[16];
    rtb_MatrixConcatenate1[4] = flightControl_B.UDPReceive_o1[17];
    rtb_MatrixConcatenate1[7] = flightControl_B.UDPReceive_o1[18];
    rtb_MatrixConcatenate1[10] = flightControl_B.UDPReceive_o1[19];
    rtb_MatrixConcatenate1[2] = flightControl_B.UDPReceive_o1[20];
    rtb_MatrixConcatenate1[5] = flightControl_B.UDPReceive_o1[21];
    rtb_MatrixConcatenate1[8] = flightControl_B.UDPReceive_o1[22];
    rtb_MatrixConcatenate1[11] = flightControl_B.UDPReceive_o1[23];

    /* MATLAB Function: '<S4>/calibrate1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    /* MATLAB Function 'runSensorFusion/calibrateSensorData/calibrate1': '<S10>:1' */
    if ((real_T)flightControl_DW.count >= flightControl_P.Constant_Value) {
      /* '<S10>:1:10' */
      /* '<S10>:1:11' */
      rtb_cal[0] = rtb_MatrixConcatenate1[0] - flightControl_DW.bias[0];
      rtb_cal[3] = rtb_MatrixConcatenate1[3] - flightControl_DW.bias[0];
      rtb_cal[6] = rtb_MatrixConcatenate1[6] - flightControl_DW.bias[0];
      rtb_cal[9] = rtb_MatrixConcatenate1[9] - flightControl_DW.bias[0];
      rtb_cal[1] = rtb_MatrixConcatenate1[1] - flightControl_DW.bias[1];
      rtb_cal[4] = rtb_MatrixConcatenate1[4] - flightControl_DW.bias[1];
      rtb_cal[7] = rtb_MatrixConcatenate1[7] - flightControl_DW.bias[1];
      rtb_cal[10] = rtb_MatrixConcatenate1[10] - flightControl_DW.bias[1];
      rtb_cal[2] = rtb_MatrixConcatenate1[2] - flightControl_DW.bias[2];
      rtb_cal[5] = rtb_MatrixConcatenate1[5] - flightControl_DW.bias[2];
      rtb_cal[8] = rtb_MatrixConcatenate1[8] - flightControl_DW.bias[2];
      rtb_cal[11] = rtb_MatrixConcatenate1[11] - flightControl_DW.bias[2];
    } else {
      /* '<S10>:1:13' */
      for (i = 0; i < 12; i++) {
        rtb_cal[i] = 0.0F;
      }

      /* '<S10>:1:14' */
      for (i = 0; i < 4; i++) {
        /* '<S10>:1:14' */
        /* '<S10>:1:15' */
        q1q2 = 1.0F / flightControl_P.Constant_Value;
        flightControl_DW.bias[0] += rtb_MatrixConcatenate1[3 * i] * q1q2;
        flightControl_DW.bias[1] += rtb_MatrixConcatenate1[3 * i + 1] * q1q2;
        flightControl_DW.bias[2] += rtb_MatrixConcatenate1[3 * i + 2] * q1q2;

        /* '<S10>:1:16' */
        qY = flightControl_DW.count + 1U;
        if (qY < flightControl_DW.count) {
          qY = MAX_uint32_T;
        }

        flightControl_DW.count = qY;

        /* '<S10>:1:14' */
      }
    }

    /* End of MATLAB Function: '<S4>/calibrate1' */

    /* Concatenate: '<S8>/Matrix Concatenate' */
    /* '<S10>:1:19' */
    rtb_MatrixConcatenate[0] = flightControl_B.UDPReceive_o1[24];
    rtb_MatrixConcatenate[3] = flightControl_B.UDPReceive_o1[25];
    rtb_MatrixConcatenate[1] = flightControl_B.UDPReceive_o1[26];
    rtb_MatrixConcatenate[4] = flightControl_B.UDPReceive_o1[27];
    rtb_MatrixConcatenate[2] = flightControl_B.UDPReceive_o1[28];
    rtb_MatrixConcatenate[5] = flightControl_B.UDPReceive_o1[29];

    /* MATLAB Function: '<S2>/runMahonyUpdate' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    /* MATLAB Function 'runSensorFusion/runMahonyUpdate': '<S7>:1' */
    /* '<S7>:1:6' */
    /* '<S7>:1:10' */
    for (b_k = 0; b_k < 3; b_k++) {
      varargin_2[b_k << 1] = rtb_MatrixConcatenate[b_k];
      varargin_2[1 + (b_k << 1)] = rtb_MatrixConcatenate[b_k + 3];
    }

    for (b_k = 0; b_k < 12; b_k++) {
      rtb_MatrixConcatenate1[b_k] = (rtNaNF);
    }

    for (i = 0; i < 4; i++) {
      r = (((real_T)i + 1.0) - 1.0) / 3.0;
      if (r == 0.0) {
        rtb_MatrixConcatenate1[i] = varargin_2[0];
        rtb_MatrixConcatenate1[i + 4] = varargin_2[2];
        rtb_MatrixConcatenate1[i + 8] = varargin_2[4];
      } else if (r == 1.0) {
        rtb_MatrixConcatenate1[i] = varargin_2[1];
        rtb_MatrixConcatenate1[i + 4] = varargin_2[3];
        rtb_MatrixConcatenate1[i + 8] = varargin_2[5];
      } else {
        if (varargin_2[0] == varargin_2[1]) {
          rtb_MatrixConcatenate1[i] = varargin_2[0];
        } else {
          rtb_MatrixConcatenate1[i] = (real32_T)(1.0 - r) * varargin_2[0] +
            (real32_T)r * varargin_2[1];
        }

        if (varargin_2[2] == varargin_2[3]) {
          rtb_MatrixConcatenate1[i + 4] = varargin_2[2];
        } else {
          rtb_MatrixConcatenate1[i + 4] = (real32_T)(1.0 - r) * varargin_2[2] +
            (real32_T)r * varargin_2[3];
        }

        if (varargin_2[4] == varargin_2[5]) {
          rtb_MatrixConcatenate1[i + 8] = varargin_2[4];
        } else {
          rtb_MatrixConcatenate1[i + 8] = (real32_T)(1.0 - r) * varargin_2[4] +
            (real32_T)r * varargin_2[5];
        }
      }

      magInterp[3 * i] = rtb_MatrixConcatenate1[i];
      magInterp[1 + 3 * i] = rtb_MatrixConcatenate1[i + 4];
      magInterp[2 + 3 * i] = rtb_MatrixConcatenate1[i + 8];
    }

    /* '<S7>:1:12' */
    for (i = 0; i < 4; i++) {
      /* '<S7>:1:12' */
      /* '<S7>:1:14' */
      /*  Normalise accelerometer measurement */
      q1q3 = rtb_cal_f[3 * i];
      q1q0 = magInterp[3 * i];
      x[0] = ((real32_T)fabs(rtb_cal_f[3 * i]) < 0.0001);
      q2q3 = rtb_cal_f[3 * i + 1];
      q2q0 = magInterp[3 * i + 1];
      x[1] = ((real32_T)fabs(rtb_cal_f[3 * i + 1]) < 0.0001);
      q3q0 = rtb_cal_f[3 * i + 2];
      q1q1 = magInterp[3 * i + 2];
      x[2] = ((real32_T)fabs(rtb_cal_f[3 * i + 2]) < 0.0001);
      b_y = true;
      b_k = 0;
      exitg2 = false;
      while ((!exitg2) && (b_k < 3)) {
        if (!x[b_k]) {
          b_y = false;
          exitg2 = true;
        } else {
          b_k++;
        }
      }

      if (!b_y) {
        /* '<S7>:1:26' */
        /* '<S7>:1:27' */
        q1q2 = flightControl_norm(*(real32_T (*)[3])&rtb_cal_f[3 * i]);
        q1q3 = rtb_cal_f[3 * i] / q1q2;
        q2q3 = rtb_cal_f[3 * i + 1] / q1q2;
        q3q0 = rtb_cal_f[3 * i + 2] / q1q2;

        /*  normalise magnitude */
      }

      /*  Normalise magnetometer measurement */
      x[0] = ((real32_T)fabs(magInterp[3 * i]) < 0.0001);
      x[1] = ((real32_T)fabs(magInterp[3 * i + 1]) < 0.0001);
      x[2] = ((real32_T)fabs(magInterp[3 * i + 2]) < 0.0001);
      b_y = true;
      b_k = 0;
      exitg2 = false;
      while ((!exitg2) && (b_k < 3)) {
        if (!x[b_k]) {
          b_y = false;
          exitg2 = true;
        } else {
          b_k++;
        }
      }

      if (!b_y) {
        /* '<S7>:1:30' */
        /* '<S7>:1:31' */
        q1q2 = flightControl_norm(*(real32_T (*)[3])&magInterp[3 * i]);
        q1q0 = magInterp[3 * i] / q1q2;
        q2q0 = magInterp[3 * i + 1] / q1q2;
        q1q1 = magInterp[3 * i + 2] / q1q2;

        /*  normalise magnitude */
      }

      /*  Reference direction of Earth's magnetic feild */
      /* '<S7>:1:34' */
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
      /* '<S7>:1:92' */
      rtb_qout[0] = flightControl_DW.qLocal[0];
      rtb_qout[1] = -flightControl_DW.qLocal[1];
      rtb_qout[2] = -flightControl_DW.qLocal[2];
      rtb_qout[3] = -flightControl_DW.qLocal[3];

      /*  normalise quaternion */
      /* '<S7>:1:61' */
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
      /* '<S7>:1:74' */
      b_idx_3 = ((0.0F * flightControl_DW.qLocal[0] - q1q0 *
                  -flightControl_DW.qLocal[1]) - q2q0 *
                 -flightControl_DW.qLocal[2]) - q1q1 * -flightControl_DW.qLocal
        [3];

      /* '<S7>:1:75' */
      ab_idx_1 = ((0.0F * -flightControl_DW.qLocal[1] + q1q0 *
                   flightControl_DW.qLocal[0]) + q2q0 *
                  -flightControl_DW.qLocal[3]) - q1q1 *
        -flightControl_DW.qLocal[2];

      /* '<S7>:1:76' */
      ab_idx_2 = ((0.0F * -flightControl_DW.qLocal[2] - q1q0 *
                   -flightControl_DW.qLocal[3]) + q2q0 *
                  flightControl_DW.qLocal[0]) + q1q1 * -flightControl_DW.qLocal
        [1];

      /* '<S7>:1:77' */
      ab_idx_3 = ((0.0F * -flightControl_DW.qLocal[3] + q1q0 *
                   -flightControl_DW.qLocal[2]) - q2q0 *
                  -flightControl_DW.qLocal[1]) + q1q1 * flightControl_DW.qLocal
        [0];

      /*  normalise quaternion */
      /* '<S7>:1:61' */
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
      /* '<S7>:1:74' */
      /* '<S7>:1:75' */
      /* '<S7>:1:76' */
      /* '<S7>:1:77' */
      /* '<S7>:1:35' */
      scale = 2.2250738585072014E-308;
      absxk = fabs(((flightControl_DW.qLocal[0] * (real32_T)ab_idx_1 +
                     flightControl_DW.qLocal[1] * (real32_T)b_idx_3) +
                    flightControl_DW.qLocal[2] * (real32_T)ab_idx_3) -
                   flightControl_DW.qLocal[3] * (real32_T)ab_idx_2);
      if (absxk > 2.2250738585072014E-308) {
        r = 1.0;
        scale = absxk;
      } else {
        t = absxk / 2.2250738585072014E-308;
        r = t * t;
      }

      absxk = fabs(((flightControl_DW.qLocal[0] * (real32_T)ab_idx_2 -
                     flightControl_DW.qLocal[1] * (real32_T)ab_idx_3) +
                    flightControl_DW.qLocal[2] * (real32_T)b_idx_3) +
                   flightControl_DW.qLocal[3] * (real32_T)ab_idx_1);
      if (absxk > scale) {
        t = scale / absxk;
        r = r * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        r += t * t;
      }

      r = scale * sqrt(r);
      b_idx_3 = ((flightControl_DW.qLocal[0] * (real32_T)ab_idx_3 +
                  flightControl_DW.qLocal[1] * (real32_T)ab_idx_2) -
                 flightControl_DW.qLocal[2] * (real32_T)ab_idx_1) +
        flightControl_DW.qLocal[3] * (real32_T)b_idx_3;

      /*  Gradient decent algorithm corrective step */
      /* '<S7>:1:37' */
      /* '<S7>:1:43' */
      /* '<S7>:1:49' */
      tmp[0] = -2.0F * flightControl_DW.qLocal[2];
      tmp[1] = 2.0F * flightControl_DW.qLocal[3];
      tmp[2] = -2.0F * flightControl_DW.qLocal[0];
      tmp[3] = 2.0F * flightControl_DW.qLocal[1];
      tmp[4] = 2.0F * flightControl_DW.qLocal[1];
      tmp[5] = 2.0F * flightControl_DW.qLocal[0];
      tmp[6] = 2.0F * flightControl_DW.qLocal[3];
      tmp[7] = 2.0F * flightControl_DW.qLocal[2];
      tmp[8] = 0.0F;
      tmp[9] = -4.0F * flightControl_DW.qLocal[1];
      tmp[10] = -4.0F * flightControl_DW.qLocal[2];
      tmp[11] = 0.0F;
      tmp[12] = (real32_T)(-2.0 * b_idx_3) * flightControl_DW.qLocal[2];
      tmp[13] = (real32_T)(2.0 * b_idx_3) * flightControl_DW.qLocal[3];
      tmp[14] = (real32_T)(-4.0 * r) * flightControl_DW.qLocal[2] - (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[0];
      tmp[15] = (real32_T)(-4.0 * r) * flightControl_DW.qLocal[3] + (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[1];
      tmp[16] = (real32_T)(-2.0 * r) * flightControl_DW.qLocal[3] + (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[1];
      tmp[17] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[2] + (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[0];
      tmp[18] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[1] + (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[3];
      tmp[19] = (real32_T)(-2.0 * r) * flightControl_DW.qLocal[0] + (real32_T)
        (2.0 * b_idx_3) * flightControl_DW.qLocal[2];
      tmp[20] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[2];
      tmp[21] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[3] - (real32_T)
        (4.0 * b_idx_3) * flightControl_DW.qLocal[1];
      tmp[22] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[0] - (real32_T)
        (4.0 * b_idx_3) * flightControl_DW.qLocal[2];
      tmp[23] = (real32_T)(2.0 * r) * flightControl_DW.qLocal[1];
      tmp_0[0] = (flightControl_DW.qLocal[1] * flightControl_DW.qLocal[3] -
                  flightControl_DW.qLocal[0] * flightControl_DW.qLocal[2]) *
        2.0F - q1q3;
      tmp_0[1] = (flightControl_DW.qLocal[0] * flightControl_DW.qLocal[1] +
                  flightControl_DW.qLocal[2] * flightControl_DW.qLocal[3]) *
        2.0F - q2q3;
      tmp_0[2] = ((0.5F - flightControl_DW.qLocal[1] * flightControl_DW.qLocal[1])
                  - flightControl_DW.qLocal[2] * flightControl_DW.qLocal[2]) *
        2.0F - q3q0;
      tmp_0[3] = (((0.5F - flightControl_DW.qLocal[2] * flightControl_DW.qLocal
                    [2]) - flightControl_DW.qLocal[3] * flightControl_DW.qLocal
                   [3]) * (real32_T)(2.0 * r) + (flightControl_DW.qLocal[1] *
        flightControl_DW.qLocal[3] - flightControl_DW.qLocal[0] *
        flightControl_DW.qLocal[2]) * (real32_T)(2.0 * b_idx_3)) - q1q0;
      tmp_0[4] = ((flightControl_DW.qLocal[1] * flightControl_DW.qLocal[2] -
                   flightControl_DW.qLocal[0] * flightControl_DW.qLocal[3]) *
                  (real32_T)(2.0 * r) + (flightControl_DW.qLocal[0] *
        flightControl_DW.qLocal[1] + flightControl_DW.qLocal[2] *
        flightControl_DW.qLocal[3]) * (real32_T)(2.0 * b_idx_3)) - q2q0;
      tmp_0[5] = (((0.5F - flightControl_DW.qLocal[1] * flightControl_DW.qLocal
                    [1]) - flightControl_DW.qLocal[2] * flightControl_DW.qLocal
                   [2]) * (real32_T)(2.0 * b_idx_3) + (flightControl_DW.qLocal[0]
        * flightControl_DW.qLocal[2] + flightControl_DW.qLocal[1] *
        flightControl_DW.qLocal[3]) * (real32_T)(2.0 * r)) - q1q1;
      for (b_k = 0; b_k < 4; b_k++) {
        rtb_qout[b_k] = 0.0F;
        for (i_0 = 0; i_0 < 6; i_0++) {
          rtb_qout[b_k] += tmp[(i_0 << 2) + b_k] * tmp_0[i_0];
        }
      }

      /* '<S7>:1:50' */
      q1q2 = flightControl_norm_e(rtb_qout);

      /*  normalise step magnitude */
      /*  Compute rate of change of quaternion */
      /* '<S7>:1:53' */
      /*  normalise quaternion */
      /* '<S7>:1:61' */
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
      /* '<S7>:1:74' */
      /* '<S7>:1:75' */
      r = ((rtb_cal[3 * i] * flightControl_DW.qLocal[0] +
            flightControl_DW.qLocal[1] * 0.0F) + rtb_cal[3 * i + 2] *
           flightControl_DW.qLocal[2]) - rtb_cal[3 * i + 1] *
        flightControl_DW.qLocal[3];

      /* '<S7>:1:76' */
      b_idx_3 = ((rtb_cal[3 * i + 1] * flightControl_DW.qLocal[0] - rtb_cal[3 *
                  i + 2] * flightControl_DW.qLocal[1]) +
                 flightControl_DW.qLocal[2] * 0.0F) + rtb_cal[3 * i] *
        flightControl_DW.qLocal[3];

      /* '<S7>:1:77' */
      ab_idx_1 = ((rtb_cal[3 * i + 2] * flightControl_DW.qLocal[0] + rtb_cal[3 *
                   i + 1] * flightControl_DW.qLocal[1]) - rtb_cal[3 * i] *
                  flightControl_DW.qLocal[2]) + flightControl_DW.qLocal[3] *
        0.0F;

      /*  Integrate to yield quaternion */
      /* '<S7>:1:56' */
      flightControl_DW.qLocal[0] += ((real32_T)((((flightControl_DW.qLocal[0] *
        0.0F - rtb_cal[3 * i] * flightControl_DW.qLocal[1]) - rtb_cal[3 * i + 1]
        * flightControl_DW.qLocal[2]) - rtb_cal[3 * i + 2] *
        flightControl_DW.qLocal[3]) * 0.5) - rtb_qout[0] / q1q2 *
        flightControl_P.Constant2_Value) * 0.005F;
      flightControl_DW.qLocal[1] += ((real32_T)(0.5 * r) - rtb_qout[1] / q1q2 *
        flightControl_P.Constant2_Value) * 0.005F;
      flightControl_DW.qLocal[2] += ((real32_T)(0.5 * b_idx_3) - rtb_qout[2] /
        q1q2 * flightControl_P.Constant2_Value) * 0.005F;
      flightControl_DW.qLocal[3] += ((real32_T)(0.5 * ab_idx_1) - rtb_qout[3] /
        q1q2 * flightControl_P.Constant2_Value) * 0.005F;

      /* '<S7>:1:57' */
      q1q2 = flightControl_norm_e(flightControl_DW.qLocal);

      /* '<S7>:1:15' */
      flightControl_DW.qLocal[0] /= q1q2;
      flightControl_B.q[0] = flightControl_DW.qLocal[0];
      flightControl_DW.qLocal[0] = flightControl_B.q[0];
      flightControl_DW.qLocal[1] /= q1q2;
      flightControl_B.q[1] = flightControl_DW.qLocal[1];
      flightControl_DW.qLocal[1] = flightControl_B.q[1];
      flightControl_DW.qLocal[2] /= q1q2;
      flightControl_B.q[2] = flightControl_DW.qLocal[2];
      flightControl_DW.qLocal[2] = flightControl_B.q[2];
      flightControl_DW.qLocal[3] /= q1q2;
      flightControl_B.q[3] = flightControl_DW.qLocal[3];
      flightControl_DW.qLocal[3] = flightControl_B.q[3];

      /* '<S7>:1:12' */
    }

    /* '<S7>:1:19' */
    flightControl_DW.qLocal[0] = flightControl_B.q[0];
    flightControl_DW.qLocal[1] = flightControl_B.q[1];
    flightControl_DW.qLocal[2] = flightControl_B.q[2];
    flightControl_DW.qLocal[3] = flightControl_B.q[3];

    /* End of MATLAB Function: '<S2>/runMahonyUpdate' */

    /* MATLAB Function: '<S2>/q2cFcn' incorporates:
     *  MATLAB Function: '<S2>/qinvFcn'
     */
    /* MATLAB Function 'runSensorFusion/qinvFcn': '<S6>:1' */
    /*  */
    /* '<S6>:1:5' */
    /* MATLAB Function 'q2cFcn': '<S5>:1' */
    /*  Q2C computes a transformation matrix (c) from the given */
    /*  quaternion (q). */
    /*  */
    /*   usage: c=q2c(q) */
    /*  */
    /*  Transformation matrix is of the form: */
    /*  */
    /*      C = Cbn */
    /*      q = qnb */
    /*  */
    /*      where q(1)   = scalar part */
    /*            q(2-4) = vector part */
    /*  */
    /*     Vb = C * Vn */
    /*     Ib = C'* In * C */
    /*  */
    /* '<S5>:1:19' */
    /*  scalar part */
    /* '<S5>:1:20' */
    /* '<S5>:1:21' */
    /* '<S5>:1:22' */
    /*  */
    /* '<S5>:1:24' */
    q1q2 = -flightControl_B.q[1] * -flightControl_B.q[2];

    /* '<S5>:1:25' */
    q1q3 = -flightControl_B.q[1] * -flightControl_B.q[3];

    /* '<S5>:1:26' */
    q1q0 = -flightControl_B.q[1] * flightControl_B.q[0];

    /* '<S5>:1:27' */
    q2q3 = -flightControl_B.q[2] * -flightControl_B.q[3];

    /* '<S5>:1:28' */
    q2q0 = -flightControl_B.q[2] * flightControl_B.q[0];

    /* '<S5>:1:29' */
    q3q0 = -flightControl_B.q[3] * flightControl_B.q[0];

    /* '<S5>:1:30' */
    q1q1 = -flightControl_B.q[1] * -flightControl_B.q[1];

    /* '<S5>:1:31' */
    q2q2 = -flightControl_B.q[2] * -flightControl_B.q[2];

    /* '<S5>:1:32' */
    q3q3 = -flightControl_B.q[3] * -flightControl_B.q[3];

    /*  */
    /* '<S5>:1:34' */
    /* '<S5>:1:35' */
    /* '<S5>:1:36' */
    /* '<S5>:1:38' */
    rtb_c[0] = 1.0F - (q2q2 + q3q3) * 2.0F;

    /* '<S5>:1:39' */
    rtb_c[3] = (q1q2 + q3q0) * 2.0F;

    /* '<S5>:1:40' */
    rtb_c[6] = (q1q3 - q2q0) * 2.0F;

    /* '<S5>:1:41' */
    rtb_c[1] = (q1q2 - q3q0) * 2.0F;

    /* '<S5>:1:42' */
    rtb_c[4] = 1.0F - (q1q1 + q3q3) * 2.0F;

    /* '<S5>:1:43' */
    rtb_c[7] = (q2q3 + q1q0) * 2.0F;

    /* '<S5>:1:44' */
    rtb_c[2] = (q1q3 + q2q0) * 2.0F;

    /* '<S5>:1:45' */
    rtb_c[5] = (q2q3 - q1q0) * 2.0F;

    /* '<S5>:1:46' */
    rtb_c[8] = 1.0F - (q1q1 + q2q2) * 2.0F;
    for (b_k = 0; b_k < 3; b_k++) {
      /* Product: '<S2>/Product' */
      flightControl_B.Product[b_k] = 0.0F;
      flightControl_B.Product[b_k] += rtb_c[b_k] * flightControl_B.Selector[0];
      flightControl_B.Product[b_k] += rtb_c[b_k + 3] * flightControl_B.Selector
        [1];
      flightControl_B.Product[b_k] += rtb_c[b_k + 6] * flightControl_B.Selector
        [2];

      /* Selector: '<S2>/Selector1' */
      flightControl_B.Selector1[b_k] = rtb_cal[9 + b_k];

      /* Selector: '<S2>/Selector2' */
      flightControl_B.Selector2[b_k] = rtb_MatrixConcatenate[3 + b_k];
    }

    /* SignalConversion: '<S2>/OutportBufferForq' */
    flightControl_B.OutportBufferForq[0] = flightControl_B.q[0];
    flightControl_B.OutportBufferForq[1] = flightControl_B.q[1];
    flightControl_B.OutportBufferForq[2] = flightControl_B.q[2];
    flightControl_B.OutportBufferForq[3] = flightControl_B.q[3];
    srUpdateBC(flightControl_DW.runSensorFusion_SubsysRanBC);
  } else {
    if (flightControl_DW.runSensorFusion_MODE) {
      flightControl_DW.runSensorFusion_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/runSensorFusion' */
}

/* Model update function */
void flightControl_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(flightControl_M)!=-1) &&
        !((rtmGetTFinal(flightControl_M)-flightControl_M->Timing.taskTime0) >
          flightControl_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControl_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightControl_M)) {
      rtmSetErrorStatus(flightControl_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightControl_M->Timing.taskTime0 =
    (++flightControl_M->Timing.clockTick0) * flightControl_M->Timing.stepSize0;
}

/* Model initialize function */
void flightControl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightControl_M, 0,
                sizeof(RT_MODEL_flightControl_T));
  rtmSetTFinal(flightControl_M, -1);
  flightControl_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  flightControl_M->Sizes.checksums[0] = (168196595U);
  flightControl_M->Sizes.checksums[1] = (3266559300U);
  flightControl_M->Sizes.checksums[2] = (3127203824U);
  flightControl_M->Sizes.checksums[3] = (711762722U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    flightControl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&flightControl_DW.runSensorFusion_SubsysRanBC;
    rteiSetModelMappingInfoPtr(flightControl_M->extModeInfo,
      &flightControl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightControl_M->extModeInfo,
                        flightControl_M->Sizes.checksums);
    rteiSetTPtr(flightControl_M->extModeInfo, rtmGetTPtr(flightControl_M));
  }

  /* block I/O */
  (void) memset(((void *) &flightControl_B), 0,
                sizeof(B_flightControl_T));

  /* states (dwork) */
  (void) memset((void *)&flightControl_DW, 0,
                sizeof(DW_flightControl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightControl_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    sErr = GetErrorBuffer(&flightControl_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&flightControl_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&flightControl_DW.UDPReceive_NetworkLib[0U], 0,
                        "0.0.0.0", 25000, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&flightControl_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&flightControl_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(flightControl_M, sErr);
        rtmSetStopRequested(flightControl_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S4>/calibrate' */
    flightControl_DW.count_m = 1U;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate1' */
    flightControl_DW.count = 1U;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate' */
    flightControl_DW.bias_c[0] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate1' */
    flightControl_DW.bias[0] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate' */
    flightControl_DW.bias_c[1] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate1' */
    flightControl_DW.bias[1] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate' */
    flightControl_DW.bias_c[2] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S4>/calibrate1' */
    flightControl_DW.bias[2] = 0.0F;

    /* InitializeConditions for MATLAB Function: '<S2>/runMahonyUpdate' */
    flightControl_DW.qLocal[0] = 1.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S2>/q' */
    flightControl_B.OutportBufferForq[0] = flightControl_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S2>/runMahonyUpdate' */
    flightControl_DW.qLocal[1] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S2>/q' */
    flightControl_B.OutportBufferForq[1] = flightControl_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S2>/runMahonyUpdate' */
    flightControl_DW.qLocal[2] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S2>/q' */
    flightControl_B.OutportBufferForq[2] = flightControl_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* InitializeConditions for MATLAB Function: '<S2>/runMahonyUpdate' */
    flightControl_DW.qLocal[3] = 0.0F;

    /* End of InitializeConditions for SubSystem: '<Root>/runSensorFusion' */

    /* Start for Enabled SubSystem: '<Root>/runSensorFusion' */
    /* VirtualOutportStart for Outport: '<S2>/q' */
    flightControl_B.OutportBufferForq[3] = flightControl_P.q_Y0;

    /* End of Start for SubSystem: '<Root>/runSensorFusion' */
  }
}

/* Model terminate function */
void flightControl_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
  sErr = GetErrorBuffer(&flightControl_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&flightControl_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(flightControl_M, sErr);
    rtmSetStopRequested(flightControl_M, 1);
  }

  LibDestroy(&flightControl_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&flightControl_DW.UDPReceive_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
