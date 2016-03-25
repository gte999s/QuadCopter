function imu=initIMU(mypi,imu)
def=getIMUDefines;
if ~exist('imu','var') || isempty(imu)
    if mypi.I2CBusSpeed~=400000
        disableI2C(mypi);
        enableI2C(mypi,400000);
    end
    
    
    imu=i2cdev(mypi,'i2c-1',def.MPU9250_ADDRESS);
    if imu.readRegister(def.WHO_AM_I_MPU9250)~=hex2dec('71')
        error('wrong device');
    end
end

% wake up device
imu.writeRegister(def.PWR_MGMT_1,0); % clear sleep mode bit (6), enable all sensors
pause(0.1); % Delay 100 ms for PLL to get established on x-axis gyro; should check for PLL ready interrupt

% get stable time source
imu.writeRegister(def.PWR_MGMT_1,hex2dec('01')); % set clock source to PLL with x-axis

% Configure Gyro and Accelerometer
% Disable FSYNC and set accelerometer and gyro bandwidth to 44 and 42 Hz, respectively; 
% DLPF_CFG = bits 2:0 = 010; this sets the sample rate at 1 kHz for both
% Maximum delay is 4.9 ms which is just over a 200 Hz maximum rate
config=uint8(hex2dec('03'));
config=bitset(config,7,1); % when FIFO full, do not write more data to buffer.
imu.writeRegister(def.CONFIG, config); % gyro and temp sample rate/filter
imu.writeRegister(def.SMPLRT_DIV, hex2dec('04')); % 200 hz rate

% gyroscope full scale range
config=imu.readRegister(def.GYRO_CONFIG);
for i= [0 1 3 4 5 6 7]+1
    config=bitset(config,i,0);
end
imu.writeRegister(def.GYRO_CONFIG,config);

% accel full scale range
config=imu.readRegister(def.ACCEL_CONFIG);
for i= [3 4 5 6 7]+1
    config=bitset(config,i,0);
end
imu.writeRegister(def.ACCEL_CONFIG,config);

% accel sample rate
config=imu.readRegister(def.ACCEL_CONFIG2);
for i= [0 1 2 3]+1
    config=bitset(config,i,0);
end
config=bitor(config,uint8(hex2dec('03')));
imu.writeRegister(def.ACCEL_CONFIG2,config);

% The accelerometer, gyro, and thermometer are set to 1 kHz sample rates, 
% but all these rates are further reduced by a factor of 5 to 200 Hz because of the SMPLRT_DIV setting

 % Configure Interrupts and Bypass Enable
 % Set interrupt pin active high, push-pull, and clear on read of INT_STATUS, enable I2C_BYPASS_EN so additional chips 
 % can join the I2C bus and all can be controlled by the Arduino as master
imu.writeRegister(def.INT_PIN_CFG,hex2dec('22'));
imu.writeRegister(def.INT_ENABLE,hex2dec('01'));
