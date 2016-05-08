  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 0;
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
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (readRegisterTest_P)
    ;%
    
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
    ;% Auto data (readRegisterTest_B)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 50;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 100;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 150;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 200;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o6
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 250;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o7
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 300;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o8
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 301;
	
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o9
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 302;
	
	  ;% readRegisterTest_B.MatrixConcatenate
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 303;
	
	  ;% readRegisterTest_B.MatrixConcatenate1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 453;
	
	  ;% readRegisterTest_B.Selector
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 603;
	
	  ;% readRegisterTest_B.Selector1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 606;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% readRegisterTest_B.readAccelGyroMagSfun_o10
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
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
    nTotSects     = 3;
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
    ;% Auto data (readRegisterTest_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% readRegisterTest_DW.readAccelGyroMagSfun_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% readRegisterTest_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% readRegisterTest_DW.Scope2_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% readRegisterTest_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 4;
	
	  ;% readRegisterTest_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 5;
	
	  ;% readRegisterTest_DW.Scope2_PWORK_b.LoggedData
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% readRegisterTest_DW.ForIteratorSubsystem_SubsysRanB
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 4207989376;
  targMap.checksum1 = 1993755151;
  targMap.checksum2 = 4201566446;
  targMap.checksum3 = 1286674149;

