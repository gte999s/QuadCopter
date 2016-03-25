function data=readTempData(imu)
def=getIMUDefines;

data=imu.readRegister(def.TEMP_OUT_H,2);

data=typecast(data,'int16');
data=swapbytes(data);

data=single(data)/ 333.87 + 21.0;


