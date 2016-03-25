function data=readGyroData(imu,doFifo)
if ~exist('doFifo','var') || isempty(doFifo)
    doFifo=false;
end
def=getIMUDefines;

if doFifo
    data=imu.readRegister(def.FIFO_R_W,6);
else
    data=imu.readRegister(def.GYRO_XOUT_H,6);
end

data=typecast(data,'int16');
data=swapbytes(data);

data=single(data)*def.Gres;


