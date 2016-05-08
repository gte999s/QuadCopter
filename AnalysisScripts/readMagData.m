function data=readMagData(mag,magCal,lastVal)
def=getIMUDefines;

if exist('lastVal','var') && mag.readRegister(def.AK8963_ST1)==0;
    data=lastVal;
    return;
else
    while mag.readRegister(def.AK8963_ST1)==0
    end
end

data=mag.readRegister(def.AK8963_XOUT_L,7);

if bitget(data(end),4)==1
    warning('Mag sensor overflow');
    data=[nan nan nan];
    return;
end


data=typecast(data(1:6),'int16');
% data=swapbytes(data);

data=single(data)*def.Mres.*magCal;


