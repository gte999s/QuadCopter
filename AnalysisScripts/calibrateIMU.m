function [accel_bias,gyro_bias]=calibrateIMU(imu)
def=getIMUDefines;
gyrosensitivity  = int16(131);    % = 131 LSB/degrees/sec
accelsensitivity = int16(16384);  % = 16384 LSB/g
%% reset device, reset all registers, clear gyro and accelerometer bias registers
imu.writeRegister(def.PWR_MGMT_1, hex2dec('80')); % Write a one to bit 7 reset bit; toggle reset device
pause(0.1);

%% get stable time source
%  Set clock source to be PLL with x-axis gyroscope reference, bits 2:0 = 001
imu.writeRegister(def.PWR_MGMT_1, hex2dec('01'));
imu.writeRegister(def.PWR_MGMT_2, hex2dec('00'));
pause(0.2);

imu=initIMU([],imu);
pause(0.2);

%% Configure device for bias calculation
% imu.writeRegister(def.INT_ENABLE, 0);             %  Disable all interrupts
imu.writeRegister(def.FIFO_EN, 0);                %  Disable FIFO
% imu.writeRegister(def.PWR_MGMT_1, 0);             %  Turn on internal clock source
% imu.writeRegister(def.I2C_MST_CTRL, 0);           %  Disable I2C master
% imu.writeRegister(def.USER_CTRL, 0);              %  Disable FIFO and I2C master modes
imu.writeRegister(def.USER_CTRL, hex2dec('0C'));  %  Reset FIFO and DMP
pause(0.015);

%% Configure MPU9250 gyro and accelerometer for bias calculation
% imu.writeRegister(def.CONFIG, hex2dec('01'));        % Set low-pass filter to 188 Hz
% imu.writeRegister(def.SMPLRT_DIV, 0);                % Set sample rate to 1 kHz
% imu.writeRegister(def.GYRO_CONFIG, 0);               % Set gyro full-scale to 250 degrees per second, maximum sensitivity
% imu.writeRegister(def.ACCEL_CONFIG, 0);              % Set accelerometer full-scale to 2 g, maximum sensitivity
%  


%% Configure FIFO to capture accelerometer and gyro data for bias calculation
imu.writeRegister(def.USER_CTRL, hex2dec('40'));   %% Enable FIFO  
imu.writeRegister(def.FIFO_EN, hex2dec('78'));     %% Enable gyro and accelerometer sensors for FIFO (max size 512 bytes in MPU-9250)


%% accumulate 40 samples in 80 milliseconds = 480 bytes
dataCount=swapbytes(typecast(imu.readRegister(def.FIFO_COUNTH, 2),'int16'));
while dataCount~=512
    dataCount=swapbytes(typecast(imu.readRegister(def.FIFO_COUNTH, 2),'int16'));
end

%% At end of sample accumulation, turn off FIFO sensor read
imu.writeRegister(def.FIFO_EN, 0);                 % Disable gyro and accelerometer sensors for FIFO
data=imu.readRegister(def.FIFO_COUNTH, 2);         % read FIFO sample count
data=swapbytes(typecast(data,'int16'));
fprintf('Sample Count = %f\n',data);
packet_count=floor(single(data)/12);                              % num of sensor readings

%% Average Sensor Readings
accel_bias=zeros(1,3,'single');
gyro_bias=zeros(1,3,'single');
accels=zeros(packet_count,3,'single');
gyros=zeros(packet_count,3,'single');
for i=1:packet_count
    accels(i,:)=readAccelData(imu,true);
    gyros(i,:)= readGyroData(imu,true);
    accel_bias=accel_bias+accels(i,:)./single(packet_count);
    gyro_bias= gyro_bias +gyros(i,:)./single(packet_count);
end

%figure;plot(accels);figure;plot(gyros);

% Remove gravity
if accel_bias(3) > 0
    accel_bias(3) = accel_bias(3) - 1.0;
else
    accel_bias(3) = accel_bias(3) + 1.0;
end

imu.writeRegister(def.USER_CTRL, hex2dec('0C'));  %  Reset FIFO and DMP
pause(0.015);

initIMU([],imu);
pause(0.1);

