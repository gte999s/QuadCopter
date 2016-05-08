function main(data,bitNum)

for i=1:bitNum
    fprintf('Bit %2d is %d\n',i,bitget(data,i));
end