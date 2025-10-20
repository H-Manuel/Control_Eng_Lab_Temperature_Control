/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_5_data.c
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

#include "TempControl_OpenLoop_5_5.h"

/* Block parameters (default storage) */
P_TempControl_OpenLoop_5_5_T TempControl_OpenLoop_5_5_P = {
  /* Variable: K_meas
   * Referenced by: '<Root>/ '
   */
  330.0,

  /* Variable: Ki_ZN
   * Referenced by: '<S34>/Integral Gain'
   */
  8.0963337885446087,

  /* Variable: Kp_ZN
   * Referenced by:
   *   '<Root>/MATLAB Function'
   *   '<S42>/Proportional Gain'
   */
  202.40834471351167,

  /* Variable: Ti_ZN
   * Referenced by: '<Root>/MATLAB Function'
   */
  0.666,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
