function resetIMU(imu)
def=getIMUDefines;

imu.writeRegister(def.PWR_MGMT_1,hex2dec('80'));
pause(0.1);