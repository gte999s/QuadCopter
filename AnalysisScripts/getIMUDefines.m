function def=getIMUDefines
def.MPU9250_ADDRESS=hex2dec('68');

% higest resolutions
def.Gres=250.0/32768.0; % GFS_250DPS
def.Mres= 10.0*4219.0/32760.0;% 16Bit Proper scale to return milliGauss
def.Ares=2.0/32768.0; % 2Gs

% See also MPU-9250 Register Map and Descriptions, Revision 4.0, RM-MPU-9250A-00, Rev. 1.4, 9/9/2013 for registers not listed in 
% above document; the MPU9250 and MPU9150 are virtually identical but the latter has a different register map
%
%Magnetometer Registers
def.AK8963_ADDRESS   =hex2dec('0C');
def.WHO_AM_I_AK8963  =hex2dec('00'); 
def.INFO             =hex2dec('01');
def.AK8963_ST1       =hex2dec('02');  % data ready status bit 0
def.AK8963_XOUT_L    =hex2dec('03');  % data
def.AK8963_XOUT_H    =hex2dec('04');
def.AK8963_YOUT_L    =hex2dec('05');
def.AK8963_YOUT_H    =hex2dec('06');
def.AK8963_ZOUT_L    =hex2dec('07');
def.AK8963_ZOUT_H    =hex2dec('08');
def.AK8963_ST2       =hex2dec('09');  % Data overflow bit 3 and data read error status bit 2
def.AK8963_CNTL      =hex2dec('0A');  % Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
def.AK8963_ASTC      =hex2dec('0C');  % Self test control
def.AK8963_I2CDIS    =hex2dec('0F');  % I2C disable
def.AK8963_ASAX      =hex2dec('10');  % Fuse ROM x-axis sensitivity adjustment value
def.AK8963_ASAY      =hex2dec('11');  % Fuse ROM y-axis sensitivity adjustment value
def.AK8963_ASAZ      =hex2dec('12');  % Fuse ROM z-axis sensitivity adjustment value

def.SELF_TEST_X_GYRO =hex2dec('00');                  
def.SELF_TEST_Y_GYRO =hex2dec('01');                                                                          
def.SELF_TEST_Z_GYRO =hex2dec('02');

% /*def.X_FINE_GAIN      =hex2dec('03 % [7:0] fine gain
% def.Y_FINE_GAIN      =hex2dec('04
% def.Z_FINE_GAIN      =hex2dec('05
% def.XA_OFFSET_H      =hex2dec('06 % User-defined trim values for accelerometer
% def.XA_OFFSET_L_TC   =hex2dec('07
% def.YA_OFFSET_H      =hex2dec('08
% def.YA_OFFSET_L_TC   =hex2dec('09
% def.ZA_OFFSET_H      =hex2dec('0A
% def.ZA_OFFSET_L_TC   =hex2dec('0B */

def.SELF_TEST_X_ACCEL =hex2dec('0D');
def.SELF_TEST_Y_ACCEL =hex2dec('0E');    
def.SELF_TEST_Z_ACCEL =hex2dec('0F');

def.SELF_TEST_A      =hex2dec('10');

def.XG_OFFSET_H      =hex2dec('13');  % User-defined trim values for gyroscope
def.XG_OFFSET_L      =hex2dec('14');
def.YG_OFFSET_H      =hex2dec('15');
def.YG_OFFSET_L      =hex2dec('16');
def.ZG_OFFSET_H      =hex2dec('17');
def.ZG_OFFSET_L      =hex2dec('18');
def.SMPLRT_DIV       =hex2dec('19');
def.CONFIG           =hex2dec('1A');
def.GYRO_CONFIG      =hex2dec('1B');
def.ACCEL_CONFIG     =hex2dec('1C');
def.ACCEL_CONFIG2    =hex2dec('1D');
def.LP_ACCEL_ODR     =hex2dec('1E');
def.WOM_THR          =hex2dec('1F');   

def.MOT_DUR          =hex2dec('20');  % Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
def.ZMOT_THR         =hex2dec('21');  % Zero-motion detection threshold bits [7:0]
def.ZRMOT_DUR        =hex2dec('22');  % Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

def.FIFO_EN          =hex2dec('23');
def.I2C_MST_CTRL     =hex2dec('24');   
def.I2C_SLV0_ADDR    =hex2dec('25');
def.I2C_SLV0_REG     =hex2dec('26');
def.I2C_SLV0_CTRL    =hex2dec('27');
def.I2C_SLV1_ADDR    =hex2dec('28');
def.I2C_SLV1_REG     =hex2dec('29');
def.I2C_SLV1_CTRL    =hex2dec('2A');
def.I2C_SLV2_ADDR    =hex2dec('2B');
def.I2C_SLV2_REG     =hex2dec('2C');
def.I2C_SLV2_CTRL    =hex2dec('2D');
def.I2C_SLV3_ADDR    =hex2dec('2E');
def.I2C_SLV3_REG     =hex2dec('2F');
def.I2C_SLV3_CTRL    =hex2dec('30');
def.I2C_SLV4_ADDR    =hex2dec('31');
def.I2C_SLV4_REG     =hex2dec('32');
def.I2C_SLV4_DO      =hex2dec('33');
def.I2C_SLV4_CTRL    =hex2dec('34');
def.I2C_SLV4_DI      =hex2dec('35');
def.I2C_MST_STATUS   =hex2dec('36');
def.INT_PIN_CFG      =hex2dec('37');
def.INT_ENABLE       =hex2dec('38');
def.DMP_INT_STATUS   =hex2dec('39');  % Check DMP interrupt
def.INT_STATUS       =hex2dec('3A');
def.ACCEL_XOUT_H     =hex2dec('3B');
def.ACCEL_XOUT_L     =hex2dec('3C');
def.ACCEL_YOUT_H     =hex2dec('3D');
def.ACCEL_YOUT_L     =hex2dec('3E');
def.ACCEL_ZOUT_H     =hex2dec('3F');
def.ACCEL_ZOUT_L     =hex2dec('40');
def.TEMP_OUT_H       =hex2dec('41');
def.TEMP_OUT_L       =hex2dec('42');
def.GYRO_XOUT_H      =hex2dec('43');
def.GYRO_XOUT_L      =hex2dec('44');
def.GYRO_YOUT_H      =hex2dec('45');
def.GYRO_YOUT_L      =hex2dec('46');
def.GYRO_ZOUT_H      =hex2dec('47');
def.GYRO_ZOUT_L      =hex2dec('48');
def.EXT_SENS_DATA_00 =hex2dec('49');
def.EXT_SENS_DATA_01 =hex2dec('4A');
def.EXT_SENS_DATA_02 =hex2dec('4B');
def.EXT_SENS_DATA_03 =hex2dec('4C');
def.EXT_SENS_DATA_04 =hex2dec('4D');
def.EXT_SENS_DATA_05 =hex2dec('4E');
def.EXT_SENS_DATA_06 =hex2dec('4F');
def.EXT_SENS_DATA_07 =hex2dec('50');
def.EXT_SENS_DATA_08 =hex2dec('51');
def.EXT_SENS_DATA_09 =hex2dec('52');
def.EXT_SENS_DATA_10 =hex2dec('53');
def.EXT_SENS_DATA_11 =hex2dec('54');
def.EXT_SENS_DATA_12 =hex2dec('55');
def.EXT_SENS_DATA_13 =hex2dec('56');
def.EXT_SENS_DATA_14 =hex2dec('57');
def.EXT_SENS_DATA_15 =hex2dec('58');
def.EXT_SENS_DATA_16 =hex2dec('59');
def.EXT_SENS_DATA_17 =hex2dec('5A');
def.EXT_SENS_DATA_18 =hex2dec('5B');
def.EXT_SENS_DATA_19 =hex2dec('5C');
def.EXT_SENS_DATA_20 =hex2dec('5D');
def.EXT_SENS_DATA_21 =hex2dec('5E');
def.EXT_SENS_DATA_22 =hex2dec('5F');
def.EXT_SENS_DATA_23 =hex2dec('60');
def.MOT_DETECT_STATUS =hex2dec('61');
def.I2C_SLV0_DO      =hex2dec('63');
def.I2C_SLV1_DO      =hex2dec('64');
def.I2C_SLV2_DO      =hex2dec('65');
def.I2C_SLV3_DO      =hex2dec('66');
def.I2C_MST_DELAY_CTRL =hex2dec('67');
def.SIGNAL_PATH_RESET  =hex2dec('68');
def.MOT_DETECT_CTRL  =hex2dec('69');
def.USER_CTRL        =hex2dec('6A');  % Bit 7 enable DMP, bit 3 reset DMP
def.PWR_MGMT_1       =hex2dec('6B'); % Device defaults to the SLEEP mode
def.PWR_MGMT_2       =hex2dec('6C');
def.DMP_BANK         =hex2dec('6D');  % Activates a specific bank in the DMP
def.DMP_RW_PNT       =hex2dec('6E');  % Set read/write pointer to a specific start address in specified DMP bank
def.DMP_REG          =hex2dec('6F');  % Register in DMP from which to read or to which to write
def.DMP_REG_1        =hex2dec('70');
def.DMP_REG_2        =hex2dec('71 ');
def.FIFO_COUNTH      =hex2dec('72');
def.FIFO_COUNTL      =hex2dec('73');
def.FIFO_R_W         =hex2dec('74');
def.WHO_AM_I_MPU9250 =hex2dec('75');
def.XA_OFFSET_H      =hex2dec('77');
def.XA_OFFSET_L      =hex2dec('78');
def.YA_OFFSET_H      =hex2dec('7A');
def.YA_OFFSET_L      =hex2dec('7B');
def.ZA_OFFSET_H      =hex2dec('7D');
def.ZA_OFFSET_L      =hex2dec('7E');