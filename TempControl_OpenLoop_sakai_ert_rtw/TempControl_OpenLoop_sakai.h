/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_sakai.h
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

#ifndef TempControl_OpenLoop_sakai_h_
#define TempControl_OpenLoop_sakai_h_
#ifndef TempControl_OpenLoop_sakai_COMMON_INCLUDES_
#define TempControl_OpenLoop_sakai_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_PWM.h"
#endif                         /* TempControl_OpenLoop_sakai_COMMON_INCLUDES_ */

#include "TempControl_OpenLoop_sakai_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Temperature;                  /* '<Root>/ ' */
  real_T StepInput;                    /* '<Root>/Add' */
} B_TempControl_OpenLoop_sakai_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_TempControl__T obj; /* '<Root>/Analog Read' */
  mbed_PWMOutput_TempControl_Op_T obj_k;/* '<Root>/PWM Output' */
} DW_TempControl_OpenLoop_sakai_T;

/* Parameters (default storage) */
struct P_TempControl_OpenLoop_sakai_T_ {
  real_T K_meas;                       /* Variable: K_meas
                                        * Referenced by: '<Root>/ '
                                        */
  real_T OperatingPoint_Value;         /* Expression: 25
                                        * Referenced by: '<Root>/Operating Point'
                                        */
  real_T Step_Value;                   /* Expression: 10
                                        * Referenced by: '<Root>/Step'
                                        */
  uint8_T StartStep_CurrentSetting;
                                 /* Computed Parameter: StartStep_CurrentSetting
                                  * Referenced by: '<Root>/Start Step'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_TempControl_OpenLoop__T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_TempControl_OpenLoop_sakai_T TempControl_OpenLoop_sakai_P;

/* Block signals (default storage) */
extern B_TempControl_OpenLoop_sakai_T TempControl_OpenLoop_sakai_B;

/* Block states (default storage) */
extern DW_TempControl_OpenLoop_sakai_T TempControl_OpenLoop_sakai_DW;

/* Model entry point functions */
extern void TempControl_OpenLoop_sakai_initialize(void);
extern void TempControl_OpenLoop_sakai_step(void);
extern void TempControl_OpenLoop_sakai_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_sakai_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TempControl_OpenLoop_sakai'
 */
#endif                                 /* TempControl_OpenLoop_sakai_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
