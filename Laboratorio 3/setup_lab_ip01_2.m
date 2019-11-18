% SETUP_LAB_IP01_2
%
% IP01 or IP02 Position Control Lab: PV Controller
% 
% SETUP_LAB_IP01_2_PV_POSITION sets the IP01 or IP02 system model parameters 
% accordingly to the user-defined configuration.
% SETUP_LAB_IP01_2_PV_POSITION can also set the controller parameters, 
% accordingly to the user-defined specifications.
%
% Copyright (C) 2003 Quanser Consulting Inc.
% Quanser Consulting Inc.

clear all;


% ############### USER-DEFINED IP01 or IP02 CONFIGURATION ###############
% Type of motorized cart: set to 'IP01', 'IP02'
% CART_TYPE = 'IP01';
CART_TYPE = 'IP02';
% if IP02: Type of Cart Load: set to 'NO_LOAD', 'WEIGHT'
%IP02_LOAD_TYPE = 'NO_LOAD';
IP02_LOAD_TYPE = 'WEIGHT';
% Turn on or off the safety watchdog on the cart position: set it to 1 , or 0 
X_LIM_ENABLE = 1;       % safety watchdog turned ON
%X_LIM_ENABLE = 0;      % safety watchdog turned OFF
% Safety Limits on the cart displacement (m)
X_MAX = 0.3;            % cart displacement maximum safety position
X_MIN = - X_MAX;        % cart displacement minimum safety position
% Amplifier Gain: set VoltPAQ amplifier gain to 1
K_AMP = 1;
% Power Amplifier Type: set to 'VoltPAQ' or 'Q3'
AMP_TYPE = 'VoltPAQ';
% Digital-to-Analog Maximum Voltage (V); for Q4/Q8 cards set to 10
VMAX_DAC = 10;
% ############### END OF USER-DEFINED IP01 or IP02 CONFIGURATION ###############

K=1;qsi=1;wn=1; % VALORES ALEATORIOS UTILIZADOS APENAS PARA COMPILAR O CODIGO
b=1;a=1;

% ############### USER-DEFINED CONTROLLER DESIGN ###############
% Type of Controller: set it to 'PV', 'MANUAL'
CONTROLLER_TYPE = 'PV';     % PV controller design: automatic mode
%CONTROLLER_TYPE = 'MANUAL';    % controller design: manual mode
% PV Controller Design Specifications
PO = 10;         % spec #1: maximum of 10% overshoot
tp = 0.15;     % spec #2: 150 ms time of first peak
% Rising (and Falling) Slew Rate (mm/s)
% obtained for +/- 20 cm square wave position setpoint
if strcmp( CART_TYPE, 'IP02' ) & strcmp( IP02_LOAD_TYPE, 'WEIGHT' )
    R_SLEW_RATE = 500;
else
    R_SLEW_RATE = 250;
end
% Specifications of a second-order low-pass filter 
if strcmp( CART_TYPE, 'IP01' )
    % Cart Potentiometer Sensitivity
    global K_PC K_PP
    % Specifications of a second-order low-pass filter
    wcf = 2 * pi * 20;  % filter cutting frequency
    zetaf = 0.9;        % filter damping ratio
elseif strcmp( CART_TYPE, 'IP02' )
    % Cart Encoder Resolution
    global K_EC K_EP
    % Specifications of a second-order low-pass filter
    wcf = 2 * pi * 50;  % filter cutting frequency
    zetaf = 0.9;        % filter damping ratio
else
    error( 'Error: Set the type of motorized cart.' )
end
% ############### END OF USER-DEFINED CONTROLLER DESIGN ###############


% variables required in the Simulink diagrams
global VMAX_AMP IMAX_AMP

% Set the model parameters accordingly to the USER-DEFINED IP01 or IP02 system configuration.
% These parameters are used for model representation and controller design.
[ Rm, Jm, Kt, Eff_m, Km, Kg, Eff_g, M, r_mp, Beq ] = setup_ip01_2_configuration( CART_TYPE, IP02_LOAD_TYPE, AMP_TYPE );


if strcmp ( CONTROLLER_TYPE, 'PV' )
    % Automatically design a Proportional-Velocity (PV) controller as per the user-specifications above
    %[ Kp, Kv ] = d_ip01_2_position_pv( Rm, Jm, Kt, Eff_m, Km, Kg, Eff_g, M, r_mp, Beq, PO, tp, AMP_TYPE );
    
elseif strcmp ( CONTROLLER_TYPE, 'MANUAL' )
    disp( ' ' )
    disp( 'STATUS: manual mode' ) 
    disp( 'The model parameters of your IP01 or IP02 system have been set.' )
    disp( 'You can now design your position controller.' )
    disp( ' ' )
    Kp = 0; Kv = 0;
else
    error( 'Error: Please set the type of controller that you wish to implement.' )
end
%
% Display the calculated gains
% disp( ' ' )
% disp( 'Calculated PV controller gains: ' )
% % Depending on type of amplifier
% if ( strcmp(AMP_TYPE,'Q3') || strcmp(AMP_TYPE,'AMPAQ') )
%     disp( [ 'Kp = ' num2str( Kp ) ' A/m' ] )
%     disp( [ 'Kv = ' num2str( Kv ) ' A.s/m' ] )
% else
%     disp( [ 'Kp = ' num2str( Kp ) ' V/m' ] )
%     disp( [ 'Kv = ' num2str( Kv ) ' V.s/m' ] )
% end