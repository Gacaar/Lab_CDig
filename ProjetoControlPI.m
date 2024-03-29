%% Script para identificacao dos parametros e determinacao dos ganhos para controle PI em Espaco de Estados

close all;
clear all;

%% Parametros do experimento

load('x.mat')
kp = 420; %Ganho aplicado na planta
fd = 13; %Fator de decimacao
Ts = 0.001*fd; %Tempo de amostragem
stepAmp = 15;   %Amplitude do degrau de entrada

%% Identificacao dos parametros por analise da resposta ao degrau


t = x(1:end,1); %vetor tempo
y = x(1:end,2); %vetor saida
ymax = max(y); %Valor de pico da saida
ind = find(y==ymax); %acha indices que contem o ymax
tp = mean(t(ind));    %Instante de pico
yfin = y(end); %Valor final da saida


[a,b,k] = paramIdent(tp, ymax, yfin, stepAmp);

% Criando as matrizes de espaco de estados
A = [0 1;0 -a];
B = [0;b];
C = [1 0];
D = 0;
GYss = ss(A,B,C,D);

GYssc = feedback(kp*GYss,1);
% bode(GYssc);

% Discretizacao do modelo
GYzss = c2d(GYss,Ts,'zoh');
% rlocus(GYzss);

% Setup para projeto
G = GYzss.A;
H = GYzss.B;
C = GYzss.C;
D = GYzss.D;

%% Projeto do controlador PI (matrizes Ki e F)

% Montando as matrizes estendidas
Ghat = [G H; zeros(1,size(G,2)) zeros(1,size(H,2))];
Hhat = [zeros(size(H,1),1);1];

%P = [0 0 0]; %Polos desejados no dominio z
% ou especifica em s e passa para z
 P = [-15 -20 -40]; %Polos desejados no dominio s
 P = exp(P.*Ts); %Polos desejados em z

if rank(ctrb(GYzss))==2 %Verifica controlabilidade
    Khat = acker(Ghat, Hhat, P) %Determina matriz de realimentacao F
    PHI = [G-eye(size(G)), H; C*G, C*H];
    FKi = (Khat+[zeros(1,size(G,2)),ones(1,size(H,2))])/PHI
    F = FKi(1:size(G,2))
    Ki = FKi(size(G,2)+1:end)
end

%% Projeto do observador de estados
% Sistema dual
Gd = G';
Hd = C';
Cd = H';

% Escolhendo os polos do observador
P = [0 0]; %Polos desejados no dominio z

if rank(ctrb(GYzss))==2 %Verifica controlabilidade
    L = acker(Gd, Hd, P) %Determina L
    %Simula e mostra o resultado
%     Gcd = Gd-Hd*L;
%     SysCtl = ss(Gcd,Hd,Cd,D, Ts);
%     figure();
%     step(SysCtl);
%     %Define o L final
    L = L';
end

%% Simula o sistema em espaco de estados

Len = 10000;
nx = length(F)+length(Ki);
% Xo = [1;-0.5;0;1];
Xo = [0;0;0];
% R = [zeros(1,5), ones(1,Len-5)];
R = [ones(1,Len)];
U = [zeros(1,Len)];
X = zeros(nx,Len+1);
% Xe = zeros(2,Len+1);
% Xe(:,1) = [0;0];
Y = zeros(size(Ki,2),Len);
% Ye = zeros(1,Len);
% e = zeros(1,Len);
PHI = [G-H*F, H*Ki; -C*G+C*H*F, eye(size(C*H*Ki))-C*H*Ki];

X(:,1) = Xo;
for k=1:Len
    Y(:,k) = C*X(1:end-1,k);
    X(:,k+1) = PHI*X(:,k)+Hhat*R(k);
end

Kc = 1/Y(end);

figure();hold on;
plot(t(1:20),Y(1:20),'k*');
% plot(X(1,:));plot(X(2,:));plot(X(3,:));plot(X(4,:));
legend;

%% Funcao de estimacao dos parametros

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