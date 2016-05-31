

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


// path to files on the local RPi:
#include </home/pi/PIGPIO/pigpio.h>
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.h>
#include </home/pi/wiringPi/wiringPi/wiringPiI2C.c>
#include </home/pi/wiringPi/wiringPi/wiringPi.c>
#include </home/pi/wiringPi/wiringPi/piHiPri.c>

float motor0=0;
float motor1=0;
float motor2=0;
float motor3=0;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 4
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
void motorControlFCN_Outputs_wrapper(const real32_T *motorSpeed,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
#ifndef MATLAB_MEX_FILE
    
 
//x = (2*2500)/5ms
//m=1000/100
    if (motorSpeed[0]!=motor0)
    {
        motor0=motorSpeed[0];
        gpioPWM(17,(ulong)(10*motor0));
    }
    if (motorSpeed[1]!=motor1)
    {
        motor1=motorSpeed[1];
        gpioPWM(27,(ulong)(10*motor1));
    }
    if (motorSpeed[2]!=motor2)
    {
        motor2=motorSpeed[2];
        gpioPWM(22,(ulong)(10*motor2));
    }
    if (motorSpeed[3]!=motor3)
    {
        motor3=motorSpeed[3];
        gpioPWM(23,(ulong)(10*motor3));
    }
        
#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void motorControlFCN_Update_wrapper(const real32_T *motorSpeed,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1){
# ifndef MATLAB_MEX_FILE     
if (gpioInitialise() < 0)
{
   printf("Init Failed\n");
}
else
{
   printf("Init Successful\n");
}

if (gpioSetPWMfrequency(17, 200) < 0 || 
        gpioSetPWMfrequency(27, 200) < 0 ||
        gpioSetPWMfrequency(22, 200) < 0 || 
        gpioSetPWMfrequency(23, 200) < 0 )
{
    printf("Freq Set Fail\n");
}
else
{
    printf("Freq Set Successful\n");
}

if (gpioSetPWMrange(17,2500) < 0     ||
        gpioSetPWMrange(27,2500) < 0 ||
        gpioSetPWMrange(22,2500) < 0 ||
        gpioSetPWMrange(23,2500) < 0)
{
    printf("Range Set Failed\n");
}
else
{
    printf("Range Set Successful\n");
}
    


#endif
//done with initialization
    xD[0] = 1;           
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
