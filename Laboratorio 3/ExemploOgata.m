%% Script para identificacao dos parametros e determinacao dos ganhos para controle PI em Espaco de Estados

close all;
clear all;

% Exemplo do Ogata - secao 6-7
G = [0 1 0; 0 0 1; -0.12 -0.01 1];
H = [0;0;1];
C = [0.5 1 0];
D=0;

GYss = ss(G,H,C,D);

%% Projeto do controlador PI (matrizes Ki e F)

% Montando as matrizes estendidas
Ghat = [G H; zeros(1,size(G,2)) zeros(1,size(H,2))];
Hhat = [zeros(size(H,1),1);1];

P = [0 0 0 0]; %Polos desejados no dominio z

if rank(ctrb(GYss))==size(G,1) %Verifica controlabilidade
    Khat = acker(Ghat, Hhat, P) %Determina matriz de realimentacao F
    PHI = [G-eye(size(G)), H; C*G, C*H];
    FKi = (Khat+[zeros(1,size(G,2)),ones(1,size(H,2))])/PHI
    F = FKi(1:size(G,2))
    Ki = FKi(size(G,2)+1:end)
end

% %% Projeto do observador de estados
% % Sistema dual
% Gd = G';
% Hd = C';
% Cd = H';
% 
% % Escolhendo os polos do observador
% P = [0 0]; %Polos desejados no dominio z
% 
% if rank(ctrb(GYzss))==2 %Verifica controlabilidade
%     L = acker(Gd, Hd, P) %Determina L
%     %Simula e mostra o resultado
% %     Gcd = Gd-Hd*L;
% %     SysCtl = ss(Gcd,Hd,Cd,D, Ts);
% %     figure();
% %     step(SysCtl);
% %     %Define o L final
%     L = L';
% end

%% Simula o sistema em espaco de estados

Len = 7;
nx = length(F)+length(Ki);
Xo = [1;-0.5;0;1];
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
plot(Y,'k*');
% plot(X(1,:));plot(X(2,:));plot(X(3,:));plot(X(4,:));
legend;
