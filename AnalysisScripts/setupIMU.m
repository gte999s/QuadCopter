function imu=setupIMU(mypi)
def=getIMUDefines;
 
imu=i2cdev(mypi,'i2c-1',hex2dec('68'));

%% Configure gyroscope range
writeRegister(imu,27,0);
%% Configure accelerometers range
writeRegister(imu,28,0);
%% Set by pass mode for the magnetometers
writeRegister(imu,hex2dec('37'),hex2dec('02'));
%% Request first magnetometer single measurement
writeRegister(imu,hex2dec('0A'),hex2dec('01'));