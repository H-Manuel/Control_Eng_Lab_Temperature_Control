/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_5_private.h
 *
 * Code generated for Simulink model 'TempControl_OpenLoop_5_5'.
 *
 * Model version                  : 5.4
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Oct 17 16:58:36 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TempControl_OpenLoop_5_5_private_h_
#define TempControl_OpenLoop_5_5_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "TempControl_OpenLoop_5_5_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* private model entry point functions */
extern void TempControl_OpenLoop_5_5_derivatives(void);

#endif                                 /* TempControl_OpenLoop_5_5_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
