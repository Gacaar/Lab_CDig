  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (so_observador_P)
    ;%
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% so_observador_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% so_observador_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% so_observador_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% so_observador_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% so_observador_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% so_observador_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% so_observador_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% so_observador_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% so_observador_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% so_observador_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% so_observador_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% so_observador_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% so_observador_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% so_observador_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% so_observador_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% so_observador_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% so_observador_P.Conversiontom_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% so_observador_P.Constant_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% so_observador_P.Conversiontord_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% so_observador_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% so_observador_P.mtomm_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% so_observador_P.Step_Time
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% so_observador_P.Step_Y0
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% so_observador_P.Step_YFinal
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% so_observador_P.mmtom_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% so_observador_P.AmplifierVoltageLimit_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% so_observador_P.AmplifierVoltageLimit_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% so_observador_P.CableGainPreCompensation_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% so_observador_P.DACLimit_UpperSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% so_observador_P.DACLimit_LowerSat
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% so_observador_P.CableGain_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% so_observador_P.Delay1_InitialCondition
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% so_observador_P.mtomm_Gain_b
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% so_observador_P.Gain9_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% so_observador_P.Gain5_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 36;
	
	  ;% so_observador_P.Gain7_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 38;
	
	  ;% so_observador_P.Gain8_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 42;
	
	  ;% so_observador_P.XMAX_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 44;
	
	  ;% so_observador_P.XIN_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% so_observador_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 3;
	
	  ;% so_observador_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 4;
	
	  ;% so_observador_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 5;
	
	  ;% so_observador_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 6;
	
	  ;% so_observador_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 7;
	
	  ;% so_observador_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 8;
	
	  ;% so_observador_P.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% so_observador_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 8;
	
	  ;% so_observador_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 16;
	
	  ;% so_observador_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 24;
	
	  ;% so_observador_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 32;
	
	  ;% so_observador_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 33;
	
	  ;% so_observador_P.EncoderInput0CartPositionEnco_h
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 41;
	
	  ;% so_observador_P.EncoderInput0CartPositionEnco_n
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 43;
	
	  ;% so_observador_P.AnalogOutput0ToAmplifierDriving
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% so_observador_P.ShowMessageonHost_MsgIcon
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_P.ShowMessageonHost_MsgIcon_j
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% so_observador_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% so_observador_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% so_observador_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
	  ;% so_observador_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 4;
	
	  ;% so_observador_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 5;
	
	  ;% so_observador_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 6;
	
	  ;% so_observador_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 7;
	
	  ;% so_observador_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 67;
	  section.data(9).dtTransOffset = 8;
	
	  ;% so_observador_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 68;
	  section.data(10).dtTransOffset = 9;
	
	  ;% so_observador_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 69;
	  section.data(11).dtTransOffset = 10;
	
	  ;% so_observador_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 70;
	  section.data(12).dtTransOffset = 11;
	
	  ;% so_observador_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 71;
	  section.data(13).dtTransOffset = 12;
	
	  ;% so_observador_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 72;
	  section.data(14).dtTransOffset = 13;
	
	  ;% so_observador_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 73;
	  section.data(15).dtTransOffset = 14;
	
	  ;% so_observador_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 74;
	  section.data(16).dtTransOffset = 15;
	
	  ;% so_observador_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 75;
	  section.data(17).dtTransOffset = 16;
	
	  ;% so_observador_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 76;
	  section.data(18).dtTransOffset = 17;
	
	  ;% so_observador_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 77;
	  section.data(19).dtTransOffset = 18;
	
	  ;% so_observador_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 78;
	  section.data(20).dtTransOffset = 19;
	
	  ;% so_observador_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 79;
	  section.data(21).dtTransOffset = 20;
	
	  ;% so_observador_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 80;
	  section.data(22).dtTransOffset = 21;
	
	  ;% so_observador_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 81;
	  section.data(23).dtTransOffset = 22;
	
	  ;% so_observador_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 82;
	  section.data(24).dtTransOffset = 23;
	
	  ;% so_observador_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 83;
	  section.data(25).dtTransOffset = 24;
	
	  ;% so_observador_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 84;
	  section.data(26).dtTransOffset = 25;
	
	  ;% so_observador_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 85;
	  section.data(27).dtTransOffset = 26;
	
	  ;% so_observador_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 86;
	  section.data(28).dtTransOffset = 27;
	
	  ;% so_observador_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 87;
	  section.data(29).dtTransOffset = 28;
	
	  ;% so_observador_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 88;
	  section.data(30).dtTransOffset = 29;
	
	  ;% so_observador_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 89;
	  section.data(31).dtTransOffset = 30;
	
	  ;% so_observador_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 90;
	  section.data(32).dtTransOffset = 31;
	
	  ;% so_observador_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 91;
	  section.data(33).dtTransOffset = 32;
	
	  ;% so_observador_P.EncoderInput0CartPositionEnc_hf
	  section.data(34).logicalSrcIdx = 92;
	  section.data(34).dtTransOffset = 33;
	
	  ;% so_observador_P.AnalogOutput0ToAmplifierDrivi_b
	  section.data(35).logicalSrcIdx = 93;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Auto data (so_observador_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% so_observador_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_B.mtomm
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% so_observador_B.R
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% so_observador_B.AmplifierVoltageLimit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% so_observador_B.CableGain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% so_observador_B.xk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% so_observador_B.mtomm_n
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% so_observador_B.Gain9
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% so_observador_B.xk1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% so_observador_B.CheckMaximumAllowedPosition
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_B.CheckMinimumAllowedPosition
	  section.data(2).logicalSrcIdx = 10;
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
    ;% Auto data (so_observador_DWork)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% so_observador_DWork.Delay1_X
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_DWork.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% so_observador_DWork.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 10;
	
	  ;% so_observador_DWork.HILInitialize_AOMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 18;
	
	  ;% so_observador_DWork.HILInitialize_AOMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 26;
	
	  ;% so_observador_DWork.HILInitialize_AOVoltages
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 34;
	
	  ;% so_observador_DWork.HILInitialize_FilterFrequency
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 42;
	
	  ;% so_observador_DWork.HILInitialize_POSortedFreqs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 50;
	
	  ;% so_observador_DWork.HILInitialize_POValues
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% so_observador_DWork.AnalogOutput0ToAmplifierDriving
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_DWork.VCommandV_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% so_observador_DWork.Controle_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% so_observador_DWork.Estados_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% so_observador_DWork.Saidas_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% so_observador_DWork.ToWorkspaceSistemaReal_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% so_observador_DWork.ToWorkspaceSistemaReal1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% so_observador_DWork.ToWorkspaceSistemaReal2_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% so_observador_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% so_observador_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 3;
	
	  ;% so_observador_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 11;
	
	  ;% so_observador_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 19;
	
	  ;% so_observador_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 27;
	
	  ;% so_observador_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 35;
	
	  ;% so_observador_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 43;
	
	  ;% so_observador_DWork.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.EncoderInput0CartPositionEnco_o
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.CartPositionWatchdog_MODE
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.CartPositionWatchdog_SubsysRanB
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% so_observador_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 30;
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


  targMap.checksum0 = 2348297455;
  targMap.checksum1 = 1882864790;
  targMap.checksum2 = 545359229;
  targMap.checksum3 = 2377596519;

