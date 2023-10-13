/*
 * bw2rbg_sf.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "bw2rbg_sf".
 *
 * Model version              : 4.1
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Oct 13 12:37:46 2023
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bw2rbg_sf_h_
#define RTW_HEADER_bw2rbg_sf_h_
#ifndef bw2rbg_sf_COMMON_INCLUDES_
#define bw2rbg_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                bw2rbg_sf
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
#endif                                 /* bw2rbg_sf_COMMON_INCLUDES_ */

#include "bw2rbg_sf_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rt_defines.h"

/* Block signals (default storage) */
typedef struct {
  real_T Image[12582912];              /* '<Root>/bw2rbg' */
} B_bw2rbg_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T *mapData[4194304];            /* '<Root>/I' */
} ExternalUPtrs_bw2rbg_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T *Image[12582912];             /* '<Root>/Image' */
} ExtY_bw2rbg_T;

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
 * hilite_system('Lidar_Slam_Sim/Triggered Lidar SLAM/bw2rbg')    - opens subsystem Lidar_Slam_Sim/Triggered Lidar SLAM/bw2rbg
 * hilite_system('Lidar_Slam_Sim/Triggered Lidar SLAM/bw2rbg/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Lidar_Slam_Sim/Triggered Lidar SLAM'
 * '<S1>'   : 'Lidar_Slam_Sim/Triggered Lidar SLAM/bw2rbg'
 */
#endif                                 /* RTW_HEADER_bw2rbg_sf_h_ */
