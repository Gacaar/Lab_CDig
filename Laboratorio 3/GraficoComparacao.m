close all
figure(1); plot(output_real.signals.values,'r');hold on;
plot(saidas_estimados.signals.values,'b--');
plot(estados_estimados.signals.values(:,1),'g-.');
plot(estados_estimados.signals.values(:,2),'k');
legend('y medido','y estimado','Posicao estimada','Velocidade estimada');
hold off;