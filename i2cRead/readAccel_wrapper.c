

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

union{
    unsigned char byte[2];
    unsigned short shortValue;
} sU;
union{
    struct {
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int bit8 : 1;
};
    unsigned char byte;
} bitArray; 


//Magnetometer Registers
#define AK8963_ADDRESS   0x0C<<1
#define WHO_AM_I_AK8963  0x00 // should return 0x48
#define INFO             0x01
#define AK8963_ST1       0x02  // data ready status bit 0
#define AK8963_XOUT_L    0x03  // data
#define AK8963_XOUT_H    0x04
#define AK8963_YOUT_L    0x05
#define AK8963_YOUT_H    0x06
#define AK8963_ZOUT_L    0x07
#define AK8963_ZOUT_H    0x08
#define AK8963_ST2       0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL      0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC      0x0C  // Self test control
#define AK8963_I2CDIS    0x0F  // I2C disable
#define AK8963_ASAX      0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY      0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ      0x12  // Fuse ROM z-axis sensitivity adjustment value

#define SELF_TEST_X_GYRO 0x00                  
#define SELF_TEST_Y_GYRO 0x01                                                                          
#define SELF_TEST_Z_GYRO 0x02

/*#define X_FINE_GAIN      0x03 // [7:0] fine gain
#define Y_FINE_GAIN      0x04
#define Z_FINE_GAIN      0x05
#define XA_OFFSET_H      0x06 // User-defined trim values for accelerometer
#define XA_OFFSET_L_TC   0x07
#define YA_OFFSET_H      0x08
#define YA_OFFSET_L_TC   0x09
#define ZA_OFFSET_H      0x0A
#define ZA_OFFSET_L_TC   0x0B */

#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E    
#define SELF_TEST_Z_ACCEL 0x0F

#define SELF_TEST_A      0x10

#define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define XG_OFFSET_L      0x14
#define YG_OFFSET_H      0x15
#define YG_OFFSET_L      0x16
#define ZG_OFFSET_H      0x17
#define ZG_OFFSET_L      0x18
#define SMPLRT_DIV       0x19
#define CONFIG           0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG     0x1C
#define ACCEL_CONFIG2    0x1D
#define LP_ACCEL_ODR     0x1E   
#define WOM_THR          0x1F   

#define MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define FIFO_EN          0x23
#define I2C_MST_CTRL     0x24   
#define I2C_SLV0_ADDR    0x25
#define I2C_SLV0_REG     0x26
#define I2C_SLV0_CTRL    0x27
#define I2C_SLV1_ADDR    0x28
#define I2C_SLV1_REG     0x29
#define I2C_SLV1_CTRL    0x2A
#define I2C_SLV2_ADDR    0x2B
#define I2C_SLV2_REG     0x2C
#define I2C_SLV2_CTRL    0x2D
#define I2C_SLV3_ADDR    0x2E
#define I2C_SLV3_REG     0x2F
#define I2C_SLV3_CTRL    0x30
#define I2C_SLV4_ADDR    0x31
#define I2C_SLV4_REG     0x32
#define I2C_SLV4_DO      0x33
#define I2C_SLV4_CTRL    0x34
#define I2C_SLV4_DI      0x35
#define I2C_MST_STATUS   0x36
#define INT_PIN_CFG      0x37
#define INT_ENABLE       0x38
#define DMP_INT_STATUS   0x39  // Check DMP interrupt
#define INT_STATUS       0x3A
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define MOT_DETECT_STATUS 0x61
#define I2C_SLV0_DO      0x63
#define I2C_SLV1_DO      0x64
#define I2C_SLV2_DO      0x65
#define I2C_SLV3_DO      0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET  0x68
#define MOT_DETECT_CTRL  0x69
#define USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define PWR_MGMT_2       0x6C
#define DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define DMP_REG_1        0x70
#define DMP_REG_2        0x71 
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define WHO_AM_I_MPU9250 0x75 // Should return 0x71
#define XA_OFFSET_H      0x77
#define XA_OFFSET_L      0x78
#define YA_OFFSET_H      0x7A
#define YA_OFFSET_L      0x7B
#define ZA_OFFSET_H      0x7D
#define ZA_OFFSET_L      0x7E


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
void readAccel_Outputs_wrapper(real32_T *AccelXYZ,
			real32_T *DataSamples,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
unsigned int dh;
unsigned int dl;
signed short temp;
float count;


if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
    //get FIFO count
    
        sU.shortValue=wiringPiI2CReadReg16(fd,FIFO_COUNTH);
        dh= sU.byte[0];
        dl= sU.byte[1];
        count =((dh<<8)|dl);
        DataSamples[0]=count;
                
        sU.shortValue=wiringPiI2CReadReg16(fd,0x3B);
        dh= sU.byte[0];
        dl= sU.byte[1];
        temp =((dh<<8)|dl);
        AccelXYZ[0] = ((float)temp) * (2.0/32768.0);// 2G Accel Res
        
        sU.shortValue=wiringPiI2CReadReg16(fd,0x3D);
        dh= sU.byte[0];
        dl= sU.byte[1];
        temp =((dh<<8)|dl);
        AccelXYZ[1] = ((float)temp) * (2.0/32768.0);// 2G Accel Res
        
        sU.shortValue=wiringPiI2CReadReg16(fd,0x3F);
        dh= sU.byte[0];
        dl= sU.byte[1];
        temp =((dh<<8)|dl);
        AccelXYZ[2] = ((float)temp) * (2.0/32768.0);// 2G Accel Res
        
        
        

        
#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void readAccel_Update_wrapper(const real32_T *AccelXYZ,
			const real32_T *DataSamples,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1){
# ifndef MATLAB_MEX_FILE     
	// Check that MPU6050 is connected ad setup:

    fd = wiringPiI2CSetup(0x68);  // 0x68 is default MPU6050 address
    int status;
    // Set clock source to be PLL with x-axis gyroscope reference, bits 2:0 = 001
    status = wiringPiI2CWriteReg8(fd,PWR_MGMT_1,0x00);
    delay(100);
    status = wiringPiI2CWriteReg8(fd,PWR_MGMT_1,0x01);
	status = wiringPiI2CWriteReg8(fd,PWR_MGMT_2,0x00);
    
   //Configure Gyro and Accelerometer
   //Disable FSYNC and set accelerometer and gyro bandwidth to 44 and 42 Hz, respectively; 
   //DLPF_CFG = bits 2:0 = 010; this sets the sample rate at 1 kHz for both
   //Maximum delay is 4.9 ms which is just over a 200 Hz maximum rate
    bitArray.byte=0x03;
    bitArray.bit7=1;  // when FIFO is full, do not overwrite data
    status = wiringPiI2CWriteReg8(fd,CONFIG,bitArray.byte);
    status = wiringPiI2CWriteReg8(fd,SMPLRT_DIV,0x04); //200 hz rate
    
    // gyroscope full range
    bitArray.byte=wiringPiI2CReadReg8(fd,GYRO_CONFIG);
    bitArray.bit1=0;
    bitArray.bit2=0;
    bitArray.bit4=0;
    bitArray.bit5=0;
    bitArray.bit6=0;
    bitArray.bit7=0;
    bitArray.bit8=0;
    status = wiringPiI2CWriteReg8(fd,GYRO_CONFIG,bitArray.byte);
    
    //accel full range
    bitArray.byte=wiringPiI2CReadReg8(fd,ACCEL_CONFIG);
    bitArray.bit4=0;
    bitArray.bit5=0;
    bitArray.bit6=0;
    bitArray.bit7=0;
    bitArray.bit8=0;
    status = wiringPiI2CWriteReg8(fd,ACCEL_CONFIG,bitArray.byte);
    
    //accel sample rate
    bitArray.byte=wiringPiI2CReadReg8(fd,ACCEL_CONFIG2);
    bitArray.bit1=0;
    bitArray.bit2=0;
    bitArray.bit3=0;
    bitArray.bit4=0;
    status = wiringPiI2CWriteReg8(fd,ACCEL_CONFIG2,bitArray.byte);
    
    //set FIFO
    status = wiringPiI2CWriteReg8(fd,FIFO_EN,0x00); //disable
    status = wiringPiI2CWriteReg8(fd,FIFO_EN,0x0C); // reset FIFO and DMP
    printf("status %d\n",status);
    delay(100);
    
    status = wiringPiI2CWriteReg8(fd,USER_CTRL,0x40); // Enable FIFO
    //status = wiringPiI2CWriteReg8(fd,FIFO_EN,0x78);   // Enable gyro and accel
    
#endif
//done with initialization
    xD[0] = 1;           
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
