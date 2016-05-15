/*
 * File: readAccelGryoMag.c
 *
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is an S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_defines_Changes_BEGIN
  *        #define NAME 'replacement text' 
  *        %%% SFUNWIZ_defines_Changes_END
  *
  *   DO NOT change NAME--Change the 'replacement text' only.
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *  -------------------------------------------------------------------------
  * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
  *  ------------------------------------------------------------------------- 
* Created: Sun May 15 14:15:50 2016
*/
#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME readAccelGryoMag
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS           0

#define NUM_OUTPUTS          10
/* Output Port  0 */
#define OUT_PORT_0_NAME      AccelX
#define OUTPUT_0_WIDTH       4
#define OUTPUT_DIMS_0_COL    1
#define OUTPUT_0_DTYPE       real32_T
#define OUTPUT_0_COMPLEX     COMPLEX_NO
#define OUT_0_FRAME_BASED    FRAME_NO
#define OUT_0_BUS_BASED      0
#define OUT_0_BUS_NAME       
#define OUT_0_DIMS           1-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125
/* Output Port  1 */
#define OUT_PORT_1_NAME      AccelY
#define OUTPUT_1_WIDTH       4
#define OUTPUT_DIMS_1_COL    1
#define OUTPUT_1_DTYPE       real32_T
#define OUTPUT_1_COMPLEX     COMPLEX_NO
#define OUT_1_FRAME_BASED    FRAME_NO
#define OUT_1_BUS_BASED      0
#define OUT_1_BUS_NAME       
#define OUT_1_DIMS           1-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125
/* Output Port  2 */
#define OUT_PORT_2_NAME      AccelZ
#define OUTPUT_2_WIDTH       4
#define OUTPUT_DIMS_2_COL    1
#define OUTPUT_2_DTYPE       real32_T
#define OUTPUT_2_COMPLEX     COMPLEX_NO
#define OUT_2_FRAME_BASED    FRAME_NO
#define OUT_2_BUS_BASED      0
#define OUT_2_BUS_NAME       
#define OUT_2_DIMS           1-D
#define OUT_2_ISSIGNED        1
#define OUT_2_WORDLENGTH      8
#define OUT_2_FIXPOINTSCALING 1
#define OUT_2_FRACTIONLENGTH  3
#define OUT_2_BIAS            0
#define OUT_2_SLOPE           0.125
/* Output Port  3 */
#define OUT_PORT_3_NAME      GyroX
#define OUTPUT_3_WIDTH       4
#define OUTPUT_DIMS_3_COL    1
#define OUTPUT_3_DTYPE       real32_T
#define OUTPUT_3_COMPLEX     COMPLEX_NO
#define OUT_3_FRAME_BASED    FRAME_NO
#define OUT_3_BUS_BASED      0
#define OUT_3_BUS_NAME       
#define OUT_3_DIMS           1-D
#define OUT_3_ISSIGNED        1
#define OUT_3_WORDLENGTH      8
#define OUT_3_FIXPOINTSCALING 1
#define OUT_3_FRACTIONLENGTH  3
#define OUT_3_BIAS            0
#define OUT_3_SLOPE           0.125
/* Output Port  4 */
#define OUT_PORT_4_NAME      GyroY
#define OUTPUT_4_WIDTH       4
#define OUTPUT_DIMS_4_COL    1
#define OUTPUT_4_DTYPE       real32_T
#define OUTPUT_4_COMPLEX     COMPLEX_NO
#define OUT_4_FRAME_BASED    FRAME_NO
#define OUT_4_BUS_BASED      0
#define OUT_4_BUS_NAME       
#define OUT_4_DIMS           1-D
#define OUT_4_ISSIGNED        1
#define OUT_4_WORDLENGTH      8
#define OUT_4_FIXPOINTSCALING 1
#define OUT_4_FRACTIONLENGTH  3
#define OUT_4_BIAS            0
#define OUT_4_SLOPE           0.125
/* Output Port  5 */
#define OUT_PORT_5_NAME      GyroZ
#define OUTPUT_5_WIDTH       4
#define OUTPUT_DIMS_5_COL    1
#define OUTPUT_5_DTYPE       real32_T
#define OUTPUT_5_COMPLEX     COMPLEX_NO
#define OUT_5_FRAME_BASED    FRAME_NO
#define OUT_5_BUS_BASED      0
#define OUT_5_BUS_NAME       
#define OUT_5_DIMS           1-D
#define OUT_5_ISSIGNED        1
#define OUT_5_WORDLENGTH      8
#define OUT_5_FIXPOINTSCALING 1
#define OUT_5_FRACTIONLENGTH  3
#define OUT_5_BIAS            0
#define OUT_5_SLOPE           0.125
/* Output Port  6 */
#define OUT_PORT_6_NAME      MagX
#define OUTPUT_6_WIDTH       2
#define OUTPUT_DIMS_6_COL    1
#define OUTPUT_6_DTYPE       real32_T
#define OUTPUT_6_COMPLEX     COMPLEX_NO
#define OUT_6_FRAME_BASED    FRAME_NO
#define OUT_6_BUS_BASED      0
#define OUT_6_BUS_NAME       
#define OUT_6_DIMS           1-D
#define OUT_6_ISSIGNED        1
#define OUT_6_WORDLENGTH      8
#define OUT_6_FIXPOINTSCALING 1
#define OUT_6_FRACTIONLENGTH  3
#define OUT_6_BIAS            0
#define OUT_6_SLOPE           0.125
/* Output Port  7 */
#define OUT_PORT_7_NAME      MagY
#define OUTPUT_7_WIDTH       2
#define OUTPUT_DIMS_7_COL    1
#define OUTPUT_7_DTYPE       real32_T
#define OUTPUT_7_COMPLEX     COMPLEX_NO
#define OUT_7_FRAME_BASED    FRAME_NO
#define OUT_7_BUS_BASED      0
#define OUT_7_BUS_NAME       
#define OUT_7_DIMS           1-D
#define OUT_7_ISSIGNED        1
#define OUT_7_WORDLENGTH      8
#define OUT_7_FIXPOINTSCALING 1
#define OUT_7_FRACTIONLENGTH  3
#define OUT_7_BIAS            0
#define OUT_7_SLOPE           0.125
/* Output Port  8 */
#define OUT_PORT_8_NAME      MagZ
#define OUTPUT_8_WIDTH       2
#define OUTPUT_DIMS_8_COL    1
#define OUTPUT_8_DTYPE       real32_T
#define OUTPUT_8_COMPLEX     COMPLEX_NO
#define OUT_8_FRAME_BASED    FRAME_NO
#define OUT_8_BUS_BASED      0
#define OUT_8_BUS_NAME       
#define OUT_8_DIMS           1-D
#define OUT_8_ISSIGNED        1
#define OUT_8_WORDLENGTH      8
#define OUT_8_FIXPOINTSCALING 1
#define OUT_8_FRACTIONLENGTH  3
#define OUT_8_BIAS            0
#define OUT_8_SLOPE           0.125
/* Output Port  9 */
#define OUT_PORT_9_NAME      FIFOCount
#define OUTPUT_9_WIDTH       1
#define OUTPUT_DIMS_9_COL    1
#define OUTPUT_9_DTYPE       real32_T
#define OUTPUT_9_COMPLEX     COMPLEX_NO
#define OUT_9_FRAME_BASED    FRAME_NO
#define OUT_9_BUS_BASED      0
#define OUT_9_BUS_NAME       
#define OUT_9_DIMS           1-D
#define OUT_9_ISSIGNED        1
#define OUT_9_WORDLENGTH      8
#define OUT_9_FIXPOINTSCALING 1
#define OUT_9_FRACTIONLENGTH  3
#define OUT_9_BIAS            0
#define OUT_9_SLOPE           0.125

#define NPARAMS              0

#define SAMPLE_TIME_0        INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES      1
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      0
#define CONT_STATES_IC       [0]

#define SFUNWIZ_GENERATE_TLC 1
#define SOURCEFILES "__SFB__"
#define PANELINDEX           6
#define USE_SIMSTRUCT        0
#define SHOW_COMPILE_STEPS   1                   
#define CREATE_DEBUG_MEXFILE 1
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"

extern void readAccelGryoMag_Outputs_wrapper(real32_T *AccelX,
			real32_T *AccelY,
			real32_T *AccelZ,
			real32_T *GyroX,
			real32_T *GyroY,
			real32_T *GyroZ,
			real32_T *MagX,
			real32_T *MagY,
			real32_T *MagZ,
			real32_T *FIFOCount,
			const real_T *xD);
extern void readAccelGryoMag_Update_wrapper(const real32_T *AccelX,
			const real32_T *AccelY,
			const real32_T *AccelZ,
			const real32_T *GyroX,
			const real32_T *GyroY,
			const real32_T *GyroZ,
			const real32_T *MagX,
			const real32_T *MagY,
			const real32_T *MagZ,
			const real32_T *FIFOCount,
			real_T *xD);

/*====================*
 * S-function methods *
 *====================*/
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);
     if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
	 return; /* Parameter mismatch will be reported by Simulink */
     }

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);

    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;

    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    /* Output Port 0 */
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
    ssSetOutputPortDataType(S, 0, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
    /* Output Port 1 */
    ssSetOutputPortWidth(S, 1, OUTPUT_1_WIDTH);
    ssSetOutputPortDataType(S, 1, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);
    /* Output Port 2 */
    ssSetOutputPortWidth(S, 2, OUTPUT_2_WIDTH);
    ssSetOutputPortDataType(S, 2, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 2, OUTPUT_2_COMPLEX);
    /* Output Port 3 */
    ssSetOutputPortWidth(S, 3, OUTPUT_3_WIDTH);
    ssSetOutputPortDataType(S, 3, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 3, OUTPUT_3_COMPLEX);
    /* Output Port 4 */
    ssSetOutputPortWidth(S, 4, OUTPUT_4_WIDTH);
    ssSetOutputPortDataType(S, 4, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 4, OUTPUT_4_COMPLEX);
    /* Output Port 5 */
    ssSetOutputPortWidth(S, 5, OUTPUT_5_WIDTH);
    ssSetOutputPortDataType(S, 5, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 5, OUTPUT_5_COMPLEX);
    /* Output Port 6 */
    ssSetOutputPortWidth(S, 6, OUTPUT_6_WIDTH);
    ssSetOutputPortDataType(S, 6, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 6, OUTPUT_6_COMPLEX);
    /* Output Port 7 */
    ssSetOutputPortWidth(S, 7, OUTPUT_7_WIDTH);
    ssSetOutputPortDataType(S, 7, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 7, OUTPUT_7_COMPLEX);
    /* Output Port 8 */
    ssSetOutputPortWidth(S, 8, OUTPUT_8_WIDTH);
    ssSetOutputPortDataType(S, 8, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 8, OUTPUT_8_COMPLEX);
    /* Output Port 9 */
    ssSetOutputPortWidth(S, 9, OUTPUT_9_WIDTH);
    ssSetOutputPortDataType(S, 9, SS_SINGLE);
    ssSetOutputPortComplexSignal(S, 9, OUTPUT_9_COMPLEX);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetSimulinkVersionGeneratedIn(S, "8.6");

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_USE_TLC_WITH_ACCELERATOR | 
		     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    ssSetOffsetTime(S, 0, 0.0);
}
#define MDL_INITIALIZE_CONDITIONS
 /* Function: mdlInitializeConditions ========================================
  * Abstract:
  *    Initialize the states
  */
 static void mdlInitializeConditions(SimStruct *S)
 {
   real_T *xD   = ssGetRealDiscStates(S);
   
    
    xD[0] =  0;
    
 }
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
   ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}
/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    real32_T        *AccelX  = (real32_T *)ssGetOutputPortRealSignal(S,0);
    real32_T        *AccelY  = (real32_T *)ssGetOutputPortRealSignal(S,1);
    real32_T        *AccelZ  = (real32_T *)ssGetOutputPortRealSignal(S,2);
    real32_T        *GyroX  = (real32_T *)ssGetOutputPortRealSignal(S,3);
    real32_T        *GyroY  = (real32_T *)ssGetOutputPortRealSignal(S,4);
    real32_T        *GyroZ  = (real32_T *)ssGetOutputPortRealSignal(S,5);
    real32_T        *MagX  = (real32_T *)ssGetOutputPortRealSignal(S,6);
    real32_T        *MagY  = (real32_T *)ssGetOutputPortRealSignal(S,7);
    real32_T        *MagZ  = (real32_T *)ssGetOutputPortRealSignal(S,8);
    real32_T        *FIFOCount  = (real32_T *)ssGetOutputPortRealSignal(S,9);
    const real_T   *xD = ssGetDiscStates(S);

    readAccelGryoMag_Outputs_wrapper(AccelX, AccelY, AccelZ, GyroX, GyroY, GyroZ, MagX, MagY, MagZ, FIFOCount, xD);

}
#define MDL_UPDATE  /* Change to #undef to remove function */
/* Function: mdlUpdate ======================================================
   * Abstract:
   *    This function is called once for every major integration time step.
   *    Discrete states are typically updated here, but this function is useful
   *    for performing any tasks that should only take place once per
   *    integration step.
   */
  static void mdlUpdate(SimStruct *S, int_T tid)
  {
    real_T         *xD  = ssGetDiscStates(S);
    real32_T        *AccelX  = (real32_T *)ssGetOutputPortRealSignal(S,0);
    real32_T        *AccelY  = (real32_T *)ssGetOutputPortRealSignal(S,1);
    real32_T        *AccelZ  = (real32_T *)ssGetOutputPortRealSignal(S,2);
    real32_T        *GyroX  = (real32_T *)ssGetOutputPortRealSignal(S,3);
    real32_T        *GyroY  = (real32_T *)ssGetOutputPortRealSignal(S,4);
    real32_T        *GyroZ  = (real32_T *)ssGetOutputPortRealSignal(S,5);
    real32_T        *MagX  = (real32_T *)ssGetOutputPortRealSignal(S,6);
    real32_T        *MagY  = (real32_T *)ssGetOutputPortRealSignal(S,7);
    real32_T        *MagZ  = (real32_T *)ssGetOutputPortRealSignal(S,8);
    real32_T        *FIFOCount  = (real32_T *)ssGetOutputPortRealSignal(S,9);

    readAccelGryoMag_Update_wrapper(AccelX, AccelY, AccelZ, GyroX, GyroY, GyroZ, MagX, MagY, MagZ, FIFOCount,  xD);
}


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{

}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


