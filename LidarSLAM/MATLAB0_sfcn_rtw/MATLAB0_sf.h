/*
 * MATLAB0_sf.h
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

#ifndef RTW_HEADER_MATLAB0_sf_h_
#define RTW_HEADER_MATLAB0_sf_h_
#ifndef MATLAB0_sf_COMMON_INCLUDES_
#define MATLAB0_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stdio.h>
#define S_FUNCTION_NAME                MATLAB0_sf
#define S_FUNCTION_LEVEL               2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif

#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* MATLAB0_sf_COMMON_INCLUDES_ */

#include "MATLAB0_sf_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rt_defines.h"

/* Block signals (default storage) */
typedef struct {
  uint8_T mapData[4194304];            /* '<Root>/MATLAB Function1' */
} B_MATLAB0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int8_T *Data[4194304];               /* '<Root>/Data' */
  uint32_T *Width;                     /* '<Root>/Width' */
  uint32_T *Height;                    /* '<Root>/Height' */
} ExternalUPtrs_MATLAB0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T *mapData[4194304];           /* '<Root>/mapData' */
} ExtY_MATLAB0_T;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Lidar_Slam_Sim/Triggered Lidar SLAM/MATLAB Function1')    - opens subsystem Lidar_Slam_Sim/Triggered Lidar SLAM/MATLAB Function1
 * hilite_system('Lidar_Slam_Sim/Triggered Lidar SLAM/MATLAB Function1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Lidar_Slam_Sim/Triggered Lidar SLAM'
 * '<S1>'   : 'Lidar_Slam_Sim/Triggered Lidar SLAM/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_MATLAB0_sf_h_ */
