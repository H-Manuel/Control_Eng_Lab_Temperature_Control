/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_5_sim.h
 *
 * Code generated for Simulink model 'TempControl_OpenLoop_5_5_sim'.
 *
 * Model version                  : 5.5
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sat Oct 18 18:00:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TempControl_OpenLoop_5_5_sim_h_
#define TempControl_OpenLoop_5_5_sim_h_
#ifndef TempControl_OpenLoop_5_5_sim_COMMON_INCLUDES_
#define TempControl_OpenLoop_5_5_sim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#endif                       /* TempControl_OpenLoop_5_5_sim_COMMON_INCLUDES_ */

#include "TempControl_OpenLoop_5_5_sim_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T y_cont;                       /* '<Root>/Transfer Fcn' */
  real_T e;                            /* '<Root>/Sum' */
  real_T usat;                         /* '<Root>/Saturation' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T IntegralGain;                 /* '<S34>/Integral Gain' */
  real_T U_ref;                        /* '<Root>/MATLAB Function' */
  real_T y_ref;                        /* '<Root>/MATLAB Function' */
} B_TempControl_OpenLoop_5_5_si_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function' */
} DW_TempControl_OpenLoop_5_5_s_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
} X_TempControl_OpenLoop_5_5_si_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
} XDot_TempControl_OpenLoop_5_5_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S37>/Integrator' */
} XDis_TempControl_OpenLoop_5_5_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_TempControl_OpenLoop_5_5_si_T_ {
  real_T Ki_ZN;                        /* Variable: Ki_ZN
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T Kp_ZN;                        /* Variable: Kp_ZN
                                        * Referenced by:
                                        *   '<Root>/MATLAB Function'
                                        *   '<S42>/Proportional Gain'
                                        */
  real_T Ti_ZN;                        /* Variable: Ti_ZN
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TempControl_OpenLoop__T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_TempControl_OpenLoop_5_5_si_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_TempControl_OpenLoop_5_5_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
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
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TempControl_OpenLoop_5_5_si_T TempControl_OpenLoop_5_5_sim_P;

/* Block signals (default storage) */
extern B_TempControl_OpenLoop_5_5_si_T TempControl_OpenLoop_5_5_sim_B;

/* Continuous states (default storage) */
extern X_TempControl_OpenLoop_5_5_si_T TempControl_OpenLoop_5_5_sim_X;

/* Disabled states (default storage) */
extern XDis_TempControl_OpenLoop_5_5_T TempControl_OpenLoop_5_5_s_XDis;

/* Block states (default storage) */
extern DW_TempControl_OpenLoop_5_5_s_T TempControl_OpenLoop_5_5_sim_DW;

/* Model entry point functions */
extern void TempControl_OpenLoop_5_5_sim_initialize(void);
extern void TempControl_OpenLoop_5_5_sim_step(void);
extern void TempControl_OpenLoop_5_5_sim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_5_5_sim_M;
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
 * '<Root>' : 'TempControl_OpenLoop_5_5_sim'
 * '<S1>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller'
 * '<S2>'   : 'TempControl_OpenLoop_5_5_sim/MATLAB Function'
 * '<S3>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Anti-windup'
 * '<S4>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/D Gain'
 * '<S5>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/External Derivative'
 * '<S6>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Filter'
 * '<S7>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Filter ICs'
 * '<S8>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/I Gain'
 * '<S9>'   : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Ideal P Gain'
 * '<S10>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Integrator'
 * '<S12>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Integrator ICs'
 * '<S13>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/N Copy'
 * '<S14>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/N Gain'
 * '<S15>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/P Copy'
 * '<S16>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Parallel P Gain'
 * '<S17>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Reset Signal'
 * '<S18>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Saturation'
 * '<S19>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Saturation Fdbk'
 * '<S20>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Sum'
 * '<S21>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Sum Fdbk'
 * '<S22>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tracking Mode'
 * '<S23>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tsamp - Integral'
 * '<S25>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/postSat Signal'
 * '<S27>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/preInt Signal'
 * '<S28>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/preSat Signal'
 * '<S29>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/D Gain/Disabled'
 * '<S31>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/External Derivative/Disabled'
 * '<S32>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Filter/Disabled'
 * '<S33>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Integrator/Continuous'
 * '<S38>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/N Gain/Disabled'
 * '<S41>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/P Copy/Disabled'
 * '<S42>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Sum/Sum_PI'
 * '<S47>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S54>'  : 'TempControl_OpenLoop_5_5_sim/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* TempControl_OpenLoop_5_5_sim_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
