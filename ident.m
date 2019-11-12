close all;
clear all;

%% Parametros do experimento

load('x.mat')
kp = 420; %Ganho aplicado na planta
Ts = 0.001; %Tempo de amostragem
stepAmp = 15;   %Amplitude do degrau de entrada

%% Identificacao dos parametros por analise da resposta ao degrau

ymax = max(x(:,2)); %Valor de pico da saida
ind = find(x(:,2)==ymax); %acha indices que contem o ymax
tp = mean(x(ind,1));    %Instante de pico
yfin = x(end,2); %Valor final da saida

[a,b,k] = paramIdent(tp, ymax, yfin, stepAmp);

% Criando FT de malha aberta e fechando a malha
G = kp*tf([b],[1 a 0]);
GYc = feedback(G,1);

% Criando a FT de malha fechada diretamente, amplitude final leva em conta
% a zona morta
GY = tf([k],[1 a kp*b]);

% Criando as matrizes de espaco de estados diretamente
A = [0 1;0 -a];
B = [0;b];
C = [1 0];
D = 0;
GYss = ss(A,B,C,D);
GYss = feedback(kp*GYss,1);
    
%% Identificacao usando tfest e ssest (toolbox de identificacao do matlab)

% Passando os sinais de entrada e saida.
% Atrasando o inicio do degraus acrescentando zeros antes
% Removendo atraso da saida para nao identificar funcao de fase n minima
data = iddata([zeros(3,1);x(:,2)],[zeros(3,1);x(:,3)],Ts);
delay = delayest(data);
data = iddata([zeros(3,1);x(delay+1:end,2)],[zeros(3,1);x(1:end-delay,3)],Ts);
GYtfest = tfest(data,2,0); %Estimando com 2 polos e 0 zeros
GYssest = ssest(data,2); %Estimando com dimensao 2

%% Comparando os modelos obtidos.
% compare(data,GY, GYc, GYss, GYtfest, GYssest);

%% Discretizacao do modelo em espaco de estados
Ts = 0.1; %Define o tempo de amostragem a ser usado no projeto


% Usando o modelo obtido com tfest
% [num den] = tfdata(GYtfest);
% [A B C D] = tf2ss(num{1,1}, den{1,1});
% GYss = ss(A,B,C,D);

%Usando o modelo de espaco de estados
GYzss = c2d(GYss,Ts,'zoh');

% opt = stepDataOptions('StepAmplitude',15);
% step(GY, 10,opt);
% compare(data,GYzss);


%% Inicio do projeto do controlador e observador
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

P = [0 0]; %Polos desejados no dominio z

% ou especifica em s e passa para z

% P = [-10 -1]; %Polos desejados no dominio s
% P = exp(P.*Ts); %Polos desejados em z

if rank(ctrb(GYzss))==2 %Verifica controlabilidade
    F = acker(G, H, P) %Determina matriz de realimentacao F
    %Simula e exibe o resultado
    Gc = G-H*F;
    SysCtl = ss(Gc,H,C,D, Ts);
    Kc = dcgain(SysCtl); %Determina ajuste para ganho unitario
    Hc = H/Kc;
    SysCtl = ss(Gc,Hc,C,D, Ts);
    figure();
    step(SysCtl);
end

%% Simula o sistema em espaco de estados

Len = 50;
Xo = [0.25;0.1];
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
    X(:,k+1) = G*X(:,k)+H*U(k);
    Y(k) = C*X(:,k);
    
    Ye(k) = C*Xe(:,k);
    e(k) = Y(k)-Ye(k);
    Xe(:,k+1) = G*Xe(:,k)+H*U(k)+L*(e(k));
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