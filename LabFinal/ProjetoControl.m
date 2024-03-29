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

%% Criando observador de estados
% Sistema dual
Gd = G';
Hd = C';
Cd = H';

% Escolhendo os polos do observador
P = [0 0]; %Polos desejados no dominio z

if rank(ctrb(GYzss))==2 %Verifica controlabilidade
    L = acker(Gd, Hd, P) %Determina L
    %Simula e mostra o resultado
    Gcd = Gd-Hd*L;
    SysCtl = ss(Gcd,Hd,Cd,D, Ts);
    figure();
    step(SysCtl);
    %Define o L final
    L = L';
end


%% Criando realimentacao do controlador

% P = [0 0]; %Polos desejados no dominio z

% ou especifica em s e passa para z

P = [-15 -15]; %Polos desejados no dominio s
P = exp(P.*Ts); %Polos desejados em z

if rank(ctrb(GYzss))==2 %Verifica controlabilidade
    F = acker(G, H, P) %Determina matriz de realimentacao F
    %Simula e exibe o resultado
    Gc = G-H*F;
    SysCtl = ss(Gc,H,C,D, Ts);
    Kc = 1/dcgain(SysCtl); %Determina ajuste para ganho unitario
    Hc = H/Kc;
    SysCtl = ss(Gc,Hc,C,D, Ts);
    figure();
    step(SysCtl);
end

%% Simula o sistema em espaco de estados

Len = 50;
Xo = [0.001;0.005];
R = [zeros(1,5), ones(1,Len-5)];
U = [zeros(1,Len)];
X = zeros(2,Len+1);
X(:,1) = Xo;
Xe = zeros(2,Len+1);
Xe(:,1) = [0;0];
Y = zeros(1,Len);
Ye = zeros(1,Len);
e = zeros(1,Len);

for k=1:Len
    U(k) = R(k)-F*Xe(:,k);
    X(:,k+1) = G*X(:,k)+(H/Kc)*U(k);
    Y(k) = C*X(:,k);
    
    Ye(k) = C*Xe(:,k);
    e(k) = Y(k)-Ye(k);
    Xe(:,k+1) = G*Xe(:,k)+(H/Kc)*U(k)+L*(e(k));
end

figure();hold on;title('Saida simulada e estimada');
plot(Y,'k');stairs(Ye,'r');
legend('Ysim(k)','Yest(k)');

figure();hold on;title('Erro de estima��o');
plot(e,'k*');

figure();hold on;title('Variaveis de estado');
plot(X(1,:),'k');plot(X(2,:),'r');legend('Pos','Vel');

figure();hold on;title('Entrada, Saida e Sinal de Controle');
stairs(R,'k');stairs(Y,'r');stairs(U,'b');
legend('R(k)','Y(k)','U(k)');


