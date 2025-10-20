/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_3_types.h
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

#ifndef TempControl_OpenLoop_5_3_types_h_
#define TempControl_OpenLoop_5_3_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/PWM Output' */
#include "MW_SVD.h"
#ifndef struct_tag_Y9X8vOuujEYZFkYgC3qBoC
#define struct_tag_Y9X8vOuujEYZFkYgC3qBoC

struct tag_Y9X8vOuujEYZFkYgC3qBoC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_Y9X8vOuujEYZFkYgC3qBoC */

#ifndef typedef_mbed_AnalogInput_TempControl__T
#define typedef_mbed_AnalogInput_TempControl__T

typedef struct tag_Y9X8vOuujEYZFkYgC3qBoC mbed_AnalogInput_TempControl__T;

#endif                             /* typedef_mbed_AnalogInput_TempControl__T */

#ifndef struct_tag_KO2oCVWkPUpA7C295Xa4DE
#define struct_tag_KO2oCVWkPUpA7C295Xa4DE

struct tag_KO2oCVWkPUpA7C295Xa4DE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_KO2oCVWkPUpA7C295Xa4DE */

#ifndef typedef_mbed_PWMOutput_TempControl_Op_T
#define typedef_mbed_PWMOutput_TempControl_Op_T

typedef struct tag_KO2oCVWkPUpA7C295Xa4DE mbed_PWMOutput_TempControl_Op_T;

#endif                             /* typedef_mbed_PWMOutput_TempControl_Op_T */

/* Parameters (default storage) */
typedef struct P_TempControl_OpenLoop_5_3_T_ P_TempControl_OpenLoop_5_3_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_TempControl_OpenLoop__T RT_MODEL_TempControl_OpenLoop_T;

#endif                                 /* TempControl_OpenLoop_5_3_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
