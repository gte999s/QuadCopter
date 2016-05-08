

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
void readAccel_Outputs_wrapper(int16_T *AccelX,
			int16_T *AccelY,
			int16_T *AccelZ,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
unsigned int dh;
unsigned int dl;
unsigned short temp;

if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
       // Read high byte, low byte, then combine:
    	dh = wiringPiI2CReadReg8(fd,0x3B) ;
        dl = wiringPiI2CReadReg8(fd,0x3C) ;
        AccelX[0]  =((dh<<8)|dl); // 2G Accel Res
        //AccelX[0] = (float)temp * (2.0/32768.0);
        
        dh = wiringPiI2CReadReg8(fd,0x3D) ;
        dl = wiringPiI2CReadReg8(fd,0x3E) ;
        AccelY[0]=((dh<<8)|dl); // 2G Accel Res
        //AccelY[0] = (float)temp * (2.0/32768.0);
        
        dh = wiringPiI2CReadReg8(fd,0x3F) ;
        dl = wiringPiI2CReadReg8(fd,0x40) ;
        AccelZ[0]=((dh<<8)|dl); // 2G Accel Res
        //AccelZ[0] = (float)temp * (2.0/32768.0);
        

        
#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void readAccel_Update_wrapper(const int16_T *AccelX,
			const int16_T *AccelY,
			const int16_T *AccelZ,
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
