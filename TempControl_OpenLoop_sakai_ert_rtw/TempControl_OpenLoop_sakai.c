/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_sakai.c
 *
 * Code generated for Simulink model 'TempControl_OpenLoop_sakai'.
 *
 * Model version                  : 5.0
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Oct 10 13:41:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TempControl_OpenLoop_sakai.h"
#include "rtwtypes.h"
#include "TempControl_OpenLoop_sakai_private.h"

/* Block signals (default storage) */
B_TempControl_OpenLoop_sakai_T TempControl_OpenLoop_sakai_B;

/* Block states (default storage) */
DW_TempControl_OpenLoop_sakai_T TempControl_OpenLoop_sakai_DW;

/* Real-time model */
static RT_MODEL_TempControl_OpenLoop_T TempControl_OpenLoop_sakai_M_;
RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_sakai_M =
  &TempControl_OpenLoop_sakai_M_;

/* Model step function */
void TempControl_OpenLoop_sakai_step(void)
{
  real_T rtb_analogoutput_0;

  /* MATLABSystem: '<Root>/Analog Read' */
  MW_AnalogIn_Start(TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE, &rtb_analogoutput_0,
     7);

  /* Gain: '<Root>/ ' incorporates:
   *  MATLABSystem: '<Root>/Analog Read'
   */
  TempControl_OpenLoop_sakai_B.Temperature = TempControl_OpenLoop_sakai_P.K_meas
    * rtb_analogoutput_0;

  /* ManualSwitch: '<Root>/Start Step' incorporates:
   *  Constant: '<Root>/Step'
   */
  if (TempControl_OpenLoop_sakai_P.StartStep_CurrentSetting == 1) {
    rtb_analogoutput_0 = 0.0;
  } else {
    rtb_analogoutput_0 = TempControl_OpenLoop_sakai_P.Step_Value;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Operating Point'
   *  ManualSwitch: '<Root>/Start Step'
   */
  TempControl_OpenLoop_sakai_B.StepInput =
    TempControl_OpenLoop_sakai_P.OperatingPoint_Value + rtb_analogoutput_0;

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(TempControl_OpenLoop_sakai_DW.obj_k.MW_PWM_HANDLE,
                      TempControl_OpenLoop_sakai_B.StepInput);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TempControl_OpenLoop_sakai_M->Timing.taskTime0 =
    ((time_T)(++TempControl_OpenLoop_sakai_M->Timing.clockTick0)) *
    TempControl_OpenLoop_sakai_M->Timing.stepSize0;
}

/* Model initialize function */
void TempControl_OpenLoop_sakai_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(TempControl_OpenLoop_sakai_M, 600.0);
  TempControl_OpenLoop_sakai_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TempControl_OpenLoop_sakai_M->Sizes.checksums[0] = (2934176668U);
  TempControl_OpenLoop_sakai_M->Sizes.checksums[1] = (3357122498U);
  TempControl_OpenLoop_sakai_M->Sizes.checksums[2] = (1633647115U);
  TempControl_OpenLoop_sakai_M->Sizes.checksums[3] = (1214935498U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    TempControl_OpenLoop_sakai_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TempControl_OpenLoop_sakai_M->extModeInfo,
      &TempControl_OpenLoop_sakai_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TempControl_OpenLoop_sakai_M->extModeInfo,
                        TempControl_OpenLoop_sakai_M->Sizes.checksums);
    rteiSetTPtr(TempControl_OpenLoop_sakai_M->extModeInfo, rtmGetTPtr
                (TempControl_OpenLoop_sakai_M));
  }

  /* Start for MATLABSystem: '<Root>/Analog Read' */
  TempControl_OpenLoop_sakai_DW.obj.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_sakai_DW.obj.isSetupComplete = false;
  TempControl_OpenLoop_sakai_DW.obj.isInitialized = 1;
  TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (A0);
  MW_AnalogIn_SetTriggerSource
    (TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE,
     MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  TempControl_OpenLoop_sakai_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  TempControl_OpenLoop_sakai_DW.obj_k.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_sakai_DW.obj_k.isSetupComplete = false;
  TempControl_OpenLoop_sakai_DW.obj_k.isInitialized = 1;
  TempControl_OpenLoop_sakai_DW.obj_k.MW_PWM_HANDLE = MW_PWM_Open(D2, 10000.0,
    20.0);
  MW_PWM_Start(TempControl_OpenLoop_sakai_DW.obj_k.MW_PWM_HANDLE);
  TempControl_OpenLoop_sakai_DW.obj_k.isSetupComplete = true;
}

/* Model terminate function */
void TempControl_OpenLoop_sakai_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Read' */
  if (!TempControl_OpenLoop_sakai_DW.obj.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_sakai_DW.obj.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_sakai_DW.obj.isInitialized == 1) &&
        TempControl_OpenLoop_sakai_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(TempControl_OpenLoop_sakai_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Read' */
  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!TempControl_OpenLoop_sakai_DW.obj_k.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_sakai_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_sakai_DW.obj_k.isInitialized == 1) &&
        TempControl_OpenLoop_sakai_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(TempControl_OpenLoop_sakai_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(TempControl_OpenLoop_sakai_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
