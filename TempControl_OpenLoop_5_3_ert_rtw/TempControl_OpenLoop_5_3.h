/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_3.h
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

#ifndef TempControl_OpenLoop_5_3_h_
#define TempControl_OpenLoop_5_3_h_
#ifndef TempControl_OpenLoop_5_3_COMMON_INCLUDES_
#define TempControl_OpenLoop_5_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_PWM.h"
#endif                           /* TempControl_OpenLoop_5_3_COMMON_INCLUDES_ */

#include "TempControl_OpenLoop_5_3_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSumInport1;
  real_T Sum;                          /* '<S45>/Sum' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T TmpRTBAtIntegratorInport1;
  real_T Temperature;                  /* '<Root>/ ' */
  real_T StartStep;                    /* '<Root>/Start Step' */
  real_T Sum_k;                        /* '<Root>/Sum' */
} B_TempControl_OpenLoop_5_3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_TempControl__T obj; /* '<Root>/Analog Read' */
  mbed_PWMOutput_TempControl_Op_T obj_k;/* '<Root>/PWM Output' */
  real_T TmpRTBAtSumInport1_Buffer0;   /* synthesized block */
  real_T TmpRTBAtIntegratorInport1_Buffe;/* synthesized block */
} DW_TempControl_OpenLoop_5_3_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
} X_TempControl_OpenLoop_5_3_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
} XDot_TempControl_OpenLoop_5_3_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
} XDis_TempControl_OpenLoop_5_3_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_TempControl_OpenLoop_5_3_T_ {
  real_T K_meas;                       /* Variable: K_meas
                                        * Referenced by: '<Root>/ '
                                        */
  real_T Ki_ZN;                        /* Variable: Ki_ZN
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T Kp_ZN;                        /* Variable: Kp_ZN
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T TmpRTBAtSumInport1_InitialCondi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T TmpRTBAtIntegratorInport1_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Step1_Value;                  /* Expression: 25
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step_Value;                   /* Expression: 35
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
  RTWSolverInfo solverInfo;
  X_TempControl_OpenLoop_5_3_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_TempControl_OpenLoop_5_3_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_P;

/* Block signals (default storage) */
extern B_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_B;

/* Continuous states (default storage) */
extern X_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_X;

/* Disabled states (default storage) */
extern XDis_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_XDis;

/* Block states (default storage) */
extern DW_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_DW;

/* External function called from main */
extern void TempControl_OpenLoop_5_3_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void TempControl_OpenLoop_5_3_initialize(void);
extern void TempControl_OpenLoop_5_3_step0(void);
extern void TempControl_OpenLoop_5_3_step2(void);/* Sample time: [0.01s, 0.0s] */
extern void TempControl_OpenLoop_5_3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_5_3_M;
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
 * '<Root>' : 'TempControl_OpenLoop_5_3'
 * '<S1>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller'
 * '<S2>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Anti-windup'
 * '<S3>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/D Gain'
 * '<S4>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/External Derivative'
 * '<S5>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Filter'
 * '<S6>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Filter ICs'
 * '<S7>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/I Gain'
 * '<S8>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Ideal P Gain'
 * '<S9>'   : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Integrator'
 * '<S11>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Integrator ICs'
 * '<S12>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/N Copy'
 * '<S13>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/N Gain'
 * '<S14>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/P Copy'
 * '<S15>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Parallel P Gain'
 * '<S16>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Reset Signal'
 * '<S17>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Saturation'
 * '<S18>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Saturation Fdbk'
 * '<S19>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Sum'
 * '<S20>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Sum Fdbk'
 * '<S21>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tracking Mode'
 * '<S22>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tsamp - Integral'
 * '<S24>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/postSat Signal'
 * '<S26>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/preInt Signal'
 * '<S27>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/preSat Signal'
 * '<S28>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/D Gain/Disabled'
 * '<S30>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/External Derivative/Disabled'
 * '<S31>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Filter/Disabled'
 * '<S32>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Filter ICs/Disabled'
 * '<S33>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Integrator/Continuous'
 * '<S37>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S39>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/N Gain/Disabled'
 * '<S40>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/P Copy/Disabled'
 * '<S41>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Sum/Sum_PI'
 * '<S46>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S53>'  : 'TempControl_OpenLoop_5_3/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* TempControl_OpenLoop_5_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
