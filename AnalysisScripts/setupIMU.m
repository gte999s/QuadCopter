function imu=setupIMU(mypi)
def=getIMUDefines;
 
imu=i2cdev(mypi,'i2c-1',hex2dec('68'));

%% Configure gyroscope range
writeRegister(imu,27,GYRO_FULL_SCALE_250_DPS);
%% Configure accelerometers range
writeRegister(imu,28,ACC_FULL_SCALE_2_G);
%% Set by pass mode for the magnetometers
writeRegister(imu,hex2dec('37'),hex2dec('02'));
%% Request first magnetometer single measurement
writeRegister(imu,hex2dec('0A'),hex2dec('01'));