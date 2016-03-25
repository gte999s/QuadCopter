function [qs,yprs]=runSensorFusion(mypi)
def=getIMUDefines;
imu=initIMU(mypi);
[mag,magCal]=initMAG(mypi);

[accel_bias,gyro_bias]=calibrateIMU(imu);


b=readMagData(mag,magCal);
q=[ 0.9535    0.0000    0.0009    0.3012];
samples=1000;
qs=zeros(samples,4);
r=rotation;
yprs=zeros(samples,3);
for i=1:samples
    
    a=readAccelData(imu)-accel_bias;
    w=readGyroData(imu)-gyro_bias;
    b=readMagData(mag,magCal,b);
    q = UpdateMahony(q,w, a, b);

    qs(i,:)=q;
    r.q=q;
    yprs(i,:)=r.ypr;
end

figure;plot(yprs);

 function q = UpdateMahony(q,Gyroscope, Accelerometer, Magnetometer)
     persistent eInt eLast
     if isempty(eInt)
         eInt=0;
     end
     bandwidth = (1*2*pi);
     damping=1;
     Ki=bandwidth^2*bandwidth*0;
     Kp=bandwidth^2+2*damping*bandwidth*bandwidth;
     Kd=2*damping*bandwidth+bandwidth;

     Ki=0;
     Kp=1;
     Kd=0;
     
     SamplePeriod=1/100;
     % Normalise accelerometer measurement
     if(norm(Accelerometer) == 0), return; end   % handle NaN
     Accelerometer = Accelerometer / norm(Accelerometer);    % normalise magnitude
     
     % Normalise magnetometer measurement
     if(norm(Magnetometer) == 0), return; end    % handle NaN
     Magnetometer = Magnetometer / norm(Magnetometer);   % normalise magnitude
     
     % Reference direction of Earth's magnetic feild
     h = quaternProd(q, quaternProd([0 Magnetometer], quaternConj(q)));
     b = [0 norm([h(2) h(3)]) 0 h(4)];
     
     % Estimated direction of gravity and magnetic field
     v = [2*(q(2)*q(4) - q(1)*q(3))
         2*(q(1)*q(2) + q(3)*q(4))
         q(1)^2 - q(2)^2 - q(3)^2 + q(4)^2];
     w = [2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3))
         2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4))
         2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2)];
     
     % Error is sum of cross product between estimated direction and measured direction of fields
     e = cross(Accelerometer, v) + cross(Magnetometer, w);
     if(Ki > 0)
         eInt = eInt + e * SamplePeriod;
     else
         eInt = [0 0 0];
     end
     if isempty(eLast)
         eLast=e;
     end
     
     % Apply feedback terms
    
     Gyroscope = Gyroscope + Kp * e + Ki * eInt + Kd * (e-eLast) / SamplePeriod;
     eLast=e;
     
     % Compute rate of change of quaternion
     qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]);
     
     % Integrate to yield quaternion
     q = q + qDot * SamplePeriod;
     q = q / norm(q); % normalise quaternion

function ab = quaternProd(a, b)
%QUATERNPROD Calculates the quaternion product
%
%   ab = quaternProd(a, b)
%
%   Calculates the quaternion product of quaternion a and b.
%
%   For more information see:
%   http://www.x-io.co.uk/node/8#quaternions
%
%	Date          Author          Notes
%	27/09/2011    SOH Madgwick    Initial release

    ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4);
    ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3);
    ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2);
    ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1);

function qConj = quaternConj(q)
%QUATERN2ROTMAT Converts a quaternion to its conjugate
%
%   qConj = quaternConj(q)
%
%   Converts a quaternion to its conjugate.
%
%   For more information see:
%   http://www.x-io.co.uk/node/8#quaternions
%
%	Date          Author          Notes
%	27/09/2011    SOH Madgwick    Initial release

    qConj = [q(:,1) -q(:,2) -q(:,3) -q(:,4)];