  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControladorPI_LAB_P)
    ;%
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControladorPI_LAB_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControladorPI_LAB_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ControladorPI_LAB_P.Conversiontom_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ControladorPI_LAB_P.Constant_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ControladorPI_LAB_P.Conversiontord_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% ControladorPI_LAB_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% ControladorPI_LAB_P.mtomm_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% ControladorPI_LAB_P.Step1_Time
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% ControladorPI_LAB_P.Step1_Y0
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% ControladorPI_LAB_P.Step1_YFinal
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% ControladorPI_LAB_P.SquareWave_Amplitude
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% ControladorPI_LAB_P.SquareWave_Frequency
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% ControladorPI_LAB_P.mmtom_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% ControladorPI_LAB_P.Gain6_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% ControladorPI_LAB_P.Delay2_InitialCondition
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% ControladorPI_LAB_P.Gain3_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% ControladorPI_LAB_P.Delay3_InitialCondition
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% ControladorPI_LAB_P.Gain2_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% ControladorPI_LAB_P.AmplifierVoltageLimit_UpperSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 34;
	
	  ;% ControladorPI_LAB_P.AmplifierVoltageLimit_LowerSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 35;
	
	  ;% ControladorPI_LAB_P.CableGainPreCompensation_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 36;
	
	  ;% ControladorPI_LAB_P.DACLimit_UpperSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 37;
	
	  ;% ControladorPI_LAB_P.DACLimit_LowerSat
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 38;
	
	  ;% ControladorPI_LAB_P.CableGain_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 39;
	
	  ;% ControladorPI_LAB_P.mtomm1_Gain
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 40;
	
	  ;% ControladorPI_LAB_P.Gain13_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 41;
	
	  ;% ControladorPI_LAB_P.Gain10_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 43;
	
	  ;% ControladorPI_LAB_P.Gain11_Gain
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 45;
	
	  ;% ControladorPI_LAB_P.Gain12_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 49;
	
	  ;% ControladorPI_LAB_P.XMAX_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 51;
	
	  ;% ControladorPI_LAB_P.XIN_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 50;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 51;
	  section.data(6).dtTransOffset = 7;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 52;
	  section.data(7).dtTransOffset = 8;
	
	  ;% ControladorPI_LAB_P.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 53;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 8;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 16;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 24;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 32;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 33;
	
	  ;% ControladorPI_LAB_P.EncoderInput0CartPositionEnco_m
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 41;
	
	  ;% ControladorPI_LAB_P.EncoderInput0CartPositionEnco_l
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 43;
	
	  ;% ControladorPI_LAB_P.AnalogOutput0ToAmplifierDriving
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.ShowMessageonHost_MsgIcon
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.ShowMessageonHost_MsgIcon_a
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.Constant_Value_l
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControladorPI_LAB_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 76;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 77;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ControladorPI_LAB_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 78;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 79;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 80;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 81;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 82;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 83;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 84;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 85;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 86;
	  section.data(20).dtTransOffset = 19;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 87;
	  section.data(21).dtTransOffset = 20;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 88;
	  section.data(22).dtTransOffset = 21;
	
	  ;% ControladorPI_LAB_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 89;
	  section.data(23).dtTransOffset = 22;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 90;
	  section.data(24).dtTransOffset = 23;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 91;
	  section.data(25).dtTransOffset = 24;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 92;
	  section.data(26).dtTransOffset = 25;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 93;
	  section.data(27).dtTransOffset = 26;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 94;
	  section.data(28).dtTransOffset = 27;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 95;
	  section.data(29).dtTransOffset = 28;
	
	  ;% ControladorPI_LAB_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 96;
	  section.data(30).dtTransOffset = 29;
	
	  ;% ControladorPI_LAB_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 97;
	  section.data(31).dtTransOffset = 30;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 98;
	  section.data(32).dtTransOffset = 31;
	
	  ;% ControladorPI_LAB_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 99;
	  section.data(33).dtTransOffset = 32;
	
	  ;% ControladorPI_LAB_P.EncoderInput0CartPositionEnco_e
	  section.data(34).logicalSrcIdx = 100;
	  section.data(34).dtTransOffset = 33;
	
	  ;% ControladorPI_LAB_P.AnalogOutput0ToAmplifierDrivi_k
	  section.data(35).logicalSrcIdx = 101;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControladorPI_LAB_B)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_B.Conversiontom
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControladorPI_LAB_B.mtomm
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControladorPI_LAB_B.Delay2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_B.Sum5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ControladorPI_LAB_B.xk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ControladorPI_LAB_B.Gain2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% ControladorPI_LAB_B.U
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% ControladorPI_LAB_B.AmplifierVoltageLimit
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% ControladorPI_LAB_B.CableGain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% ControladorPI_LAB_B.mtomm1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% ControladorPI_LAB_B.Gain13
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% ControladorPI_LAB_B.xk1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_B.CheckMaximumAllowedPosition
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_B.CheckMinimumAllowedPosition
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ControladorPI_LAB_DWork)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.Delay2_X
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_DWork.Delay3_X
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 11;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 19;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 27;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 35;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 43;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_POSortedFreqs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 51;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_POValues
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.AnalogOutput0ToAmplifierDriving
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_DWork.VCommandV_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ControladorPI_LAB_DWork.Controle1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ControladorPI_LAB_DWork.Estados1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_DWork.Saidas1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 3;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 11;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 19;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 27;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 35;
	
	  ;% ControladorPI_LAB_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 43;
	
	  ;% ControladorPI_LAB_DWork.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.EncoderInput0CartPositionEnco_m
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.CartPositionWatchdog_MODE
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.CartPositionWatchdog_SubsysRanB
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ControladorPI_LAB_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3996521114;
  targMap.checksum1 = 2325476511;
  targMap.checksum2 = 2834264086;
  targMap.checksum3 = 245202598;

