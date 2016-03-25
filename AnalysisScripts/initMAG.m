function [mag,calData]=initMAG(mypi)
def=getIMUDefines;
mag=i2cdev(mypi,'i2c-1',def.AK8963_ADDRESS);
if mag.readRegister(0)~=hex2dec('48')
    error('wrong device');
end

%% get factory cal
mag.writeRegister(def.AK8963_CNTL,0); % power down mag
pause(0.01);
mag.writeRegister(def.AK8963_CNTL,hex2dec('0f')); % enter fuse mode
pause(0.01);
rawData=mag.readRegister(def.AK8963_ASAX,3); % read x y z cal values
calData=single(rawData-128)./256+1;
mag.writeRegister(def.AK8963_CNTL,0); % power down mag again
pause(0.01);

%uint8_t Mmode = 0x06;        // Either 8 Hz 0x02) or 100 Hz (0x06) magnetometer data ODR  
ctrlByte=uint8(hex2dec('06'));
ctrlByte=bitset(ctrlByte,5,1); % set 16bit resolution
mag.writeRegister(def.AK8963_CNTL,ctrlByte);


