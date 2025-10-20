/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_3_data.c
 *
 * Code generated for Simulink model 'TempControl_OpenLoop_5_3'.
 *
 * Model version                  : 5.3
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Oct 17 16:08:42 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TempControl_OpenLoop_5_3.h"

/* Block parameters (default storage) */
P_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_P = {
  /* Variable: K_meas
   * Referenced by: '<Root>/ '
   */
  330.0,

  /* Variable: Ki_ZN
   * Referenced by: '<S33>/Integral Gain'
   */
  8.0963337885446087,

  /* Variable: Kp_ZN
   * Referenced by: '<S41>/Proportional Gain'
   */
  809.63337885404667,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 25
   * Referenced by: '<Root>/Step1'
   */
  25.0,

  /* Expression: 35
   * Referenced by: '<Root>/Step'
   */
  35.0,

  /* Computed Parameter: StartStep_CurrentSetting
   * Referenced by: '<Root>/Start Step'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
