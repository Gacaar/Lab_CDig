
function [a,b,K] = paramIdent(tp,ymax,yfin,stepAmp)
% [a,b,k] = paramIdent(0.1455, 21.7704, 15.1050, 15);
    Kp = 420;
    Mp = (ymax-yfin)/yfin;
    Ksi = log(1/Mp)/sqrt(pi^2+log(1/Mp)^2);
    Wn = pi/(tp*sqrt(1-Ksi^2));
    K = (yfin*Wn^2)/stepAmp;
    a = 2*Ksi*Wn;
    b = (Wn^2)/Kp;
    
end