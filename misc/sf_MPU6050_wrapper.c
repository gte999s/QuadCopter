

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
///////////////////////////////////////////////////////////////////
/////  LIBRARIES

# ifndef MATLAB_MEX_FILE

// must run command:
// gpio load i2c 
// on RPI to start I2C

// path to files on the local RPi:
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.h>
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.c>
#include </home/pi/wiringPi/wiringPi/wiringPi.c>
#include </home/pi/wiringPi/wiringPi/piHiPri.c>

//---->  MPU6050 Info: <-----
// setup defines: Register definitions
#define MPU6050_RA_PWR_MGMT_1 0x6B

// Device identification:
#define MPU6050_RA_WHO_AM_I 0x75

// Sensor Read registers:
#define MPU6050_RA_ACCEL_XOUT_H     0x3B
#define MPU6050_RA_ACCEL_XOUT_L     0x3C
#define MPU6050_RA_ACCEL_YOUT_H     0x3D
#define MPU6050_RA_ACCEL_YOUT_L     0x3E
#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
#define MPU6050_RA_ACCEL_ZOUT_L     0x40
#define MPU6050_RA_TEMP_OUT_H       0x41
#define MPU6050_RA_TEMP_OUT_L       0x42
#define MPU6050_RA_GYRO_XOUT_H      0x43
#define MPU6050_RA_GYRO_XOUT_L      0x44
#define MPU6050_RA_GYRO_YOUT_H      0x45
#define MPU6050_RA_GYRO_YOUT_L      0x46
#define MPU6050_RA_GYRO_ZOUT_H      0x47
#define MPU6050_RA_GYRO_ZOUT_L      0x48

//DLFP register
#define MPU6050_RA_CONFIG           0x1A

// global variables for address, high and low bits for data
int fd,dh,dl;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void sf_MPU6050_Outputs_wrapper(int16_T *gx,
			int16_T *gy,
			int16_T *gz,
			int16_T *ax,
			int16_T *ay,
			int16_T *az,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
///////////////////////////////////////////////////////////////////
//// OUTPUTS
if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
        // Read high byte, low byte, then combine:
    	dh = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_XOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_XOUT_L) ;
        gx[0]=((dh<<8)|dl);;
		dh = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_YOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_YOUT_L) ;
        gy[0]=((dh<<8)|dl);;
		dh = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_ZOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_GYRO_ZOUT_L) ;
        gz[0]=((dh<<8)|dl);;
		// Accel
		dh = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_XOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_XOUT_L) ;
        ax[0]=((dh<<8)|dl);;
		dh = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_YOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_YOUT_L) ;
        ay[0]=((dh<<8)|dl);;
		dh = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_ZOUT_H) ;
        dl = wiringPiI2CReadReg8(fd,MPU6050_RA_ACCEL_ZOUT_L) ;
        az[0]=((dh<<8)|dl);;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void sf_MPU6050_Update_wrapper(const int16_T *gx,
			const int16_T *gy,
			const int16_T *gz,
			const int16_T *ax,
			const int16_T *ay,
			const int16_T *az,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
///////////////////////////////////////////////////////////////////
//// DISCRETE UPDATE

if(xD[0] != 1){
# ifndef MATLAB_MEX_FILE     
	// Check that MPU6050 is connected ad setup:
	fd = wiringPiI2CSetup(0x68);  // 0x68 is default MPU6050 address
    
    // MPU6050 setup:
	//Sets clock source to gyro reference w/ PLL
	wiringPiI2CWriteReg8(fd, MPU6050_RA_PWR_MGMT_1, 0b00000010);
	// Set Digital Low Pass Filter with MPU6050_RA_CONFIG (see documentation)
	wiringPiI2CWriteReg8(fd, MPU6050_RA_CONFIG, 0b00000110);
	

#endif
//done with initialization
    xD[0] = 1;           
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
