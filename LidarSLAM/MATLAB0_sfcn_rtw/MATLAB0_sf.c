/*
 * MATLAB0_sf.c
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "MATLAB0_sf".
 *
 * Model version              : 3.64
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Oct  7 15:09:50 2023
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MATLAB0_sf.h"
#include "rtwtypes.h"
#include <math.h>
#include "MATLAB0_sf_private.h"
#include "MATLAB0_sf_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *MATLAB0_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void MATLAB0_string_disp(void);
static real_T MATLAB0_rt_roundd_snf(real_T u);
static void MATLAB0_sf_gateway_c2_MATLAB0(SimStruct *S);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void MATLAB0_string_disp(void)
{
  printf("%s\n", "msg2matrix : No Data");
  fflush(stdout);
}

static real_T MATLAB0_rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void MATLAB0_sf_gateway_c2_MATLAB0(SimStruct *S)
{
  static int8_T Data[4194304];
  B_MATLAB0_T *_rtB;
  uint64_T tmp;
  int32_T c;
  int32_T e;
  int32_T i;
  int32_T i_0;
  uint32_T qY;
  int8_T tmp_0;
  _rtB = ((B_MATLAB0_T *) ssGetLocalBlockIO(S));
  for (i = 0; i < 4194304; i++) {
    Data[i] = *((const int8_T **)ssGetInputPortSignalPtrs(S, 0))[i];
    _rtB->mapData[i] = 0U;
  }

  if ((*((const uint32_T **)ssGetInputPortSignalPtrs(S, 1))[0] != 0U) && (*((
         const uint32_T **)ssGetInputPortSignalPtrs(S, 2))[0] != 0U)) {
    for (i = 0; i < 4194304; i++) {
      if (*((const int8_T **)ssGetInputPortSignalPtrs(S, 0))[i] < 0) {
        Data[i] = 50;
      }
    }

    c = (int32_T)*((const uint32_T **)ssGetInputPortSignalPtrs(S, 2))[0];
    for (i = 0; i < c; i++) {
      tmp = *((const uint32_T **)ssGetInputPortSignalPtrs(S, 1))[0] * (uint64_T)
        i;
      if (tmp > 4294967295ULL) {
        tmp = 4294967295ULL;
      }

      qY = (uint32_T)tmp + 1U;
      if ((uint32_T)tmp + 1U < (uint32_T)tmp) {
        qY = MAX_uint32_T;
      }

      tmp = (uint64_T)((uint32_T)i + 1U) * *((const uint32_T **)
        ssGetInputPortSignalPtrs(S, 1))[0];
      if (tmp > 4294967295ULL) {
        tmp = 4294967295ULL;
      }

      if (qY > (uint32_T)tmp) {
        e = 1;
      } else {
        e = (int32_T)qY;
      }

      for (i_0 = 0; i_0 < 2048; i_0++) {
        tmp_0 = Data[(e + i_0) - 1];
        if (tmp_0 < 0) {
          tmp_0 = 0;
        }

        _rtB->mapData[i + (i_0 << 11)] = (uint8_T)tmp_0;
      }
    }

    for (i = 0; i < 4194304; i++) {
      _rtB->mapData[i] = (uint8_T)MATLAB0_rt_roundd_snf((real_T)_rtB->mapData[i]
        / 100.0);
    }
  } else {
    MATLAB0_string_disp();
  }
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#endif

  MATLAB0_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  B_MATLAB0_T *_rtB;
  int32_T i;
  _rtB = ((B_MATLAB0_T *) ssGetLocalBlockIO(S));

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  MATLAB0_sf_gateway_c2_MATLAB0(S);

  /* Outport: '<Root>/mapData' */
  for (i = 0; i < 4194304; i++) {
    ((uint8_T *)ssGetOutputPortSignal(S, 0))[i] = _rtB->mapData[i];
  }

  /* End of Outport: '<Root>/mapData' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#include "MATLAB0_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortMatrixDimensions(S, 0, 2048, 2048))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_UINT8);
  }

  ssSetOutputPortSampleTime(S, 0, 0.01);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 3))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 4194304))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_INT8);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.01);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_UINT32);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.01);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_UINT32);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.01);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.01);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
#include "fixedpoint.c"
#include "simulink.c"
#else
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME                MATLAB0_sf
#include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
