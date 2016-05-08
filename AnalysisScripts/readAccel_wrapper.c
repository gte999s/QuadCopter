

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


// Globals
int fd;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void readAccel_Outputs_wrapper(real_T *AccelXYZ,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
int dh;
int dl;

if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
        // Read high byte, low byte, then combine:
    	dh = wiringPiI2CReadReg8(fd,0x3B) ;
        dl = wiringPiI2CReadReg8(fd,0x3C) ;
        AccelXYZ[0]=((dh<<8)|dl);;
        
        dh = wiringPiI2CReadReg8(fd,0x3D) ;
        dl = wiringPiI2CReadReg8(fd,0x3E) ;
        AccelXYZ[1]=((dh<<8)|dl);;
        
        dh = wiringPiI2CReadReg8(fd,0x3F) ;
        dl = wiringPiI2CReadReg8(fd,0x40) ;
        AccelXYZ[2]=((dh<<8)|dl);;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void readAccel_Update_wrapper(const real_T *AccelXYZ,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1){
# ifndef MATLAB_MEX_FILE     
	// Check that MPU6050 is connected ad setup:
	fd = wiringPiI2CSetup(0x68);  // 0x68 is default MPU6050 address
   
	

#endif
//done with initialization
    xD[0] = 1;           
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
