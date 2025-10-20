/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_3.c
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
#include "rtwtypes.h"
#include "TempControl_OpenLoop_5_3_private.h"

/* Block signals (default storage) */
B_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_B;

/* Continuous states */
X_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_X;

/* Disabled State Vector */
XDis_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_XDis;

/* Block states (default storage) */
DW_TempControl_OpenLoop_5_3_T TempControl_OpenLoop_5_3_DW;

/* Real-time model */
static RT_MODEL_TempControl_OpenLoop_T TempControl_OpenLoop_5_3_M_;
RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_5_3_M =
  &TempControl_OpenLoop_5_3_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void TempControl_OpenLoop_5_3_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(TempControl_OpenLoop_5_3_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (TempControl_OpenLoop_5_3_M->Timing.TaskCounters.TID[1] == 0) {
    TempControl_OpenLoop_5_3_M->Timing.RateInteraction.TID1_2 =
      (TempControl_OpenLoop_5_3_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TempControl_OpenLoop_5_3_M->Timing.TaskCounters.TID[2])++;
  if ((TempControl_OpenLoop_5_3_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    TempControl_OpenLoop_5_3_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TempControl_OpenLoop_5_3_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TempControl_OpenLoop_5_3_step0();
  TempControl_OpenLoop_5_3_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TempControl_OpenLoop_5_3_step0();
  TempControl_OpenLoop_5_3_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function for TID0 */
void TempControl_OpenLoop_5_3_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  boolean_T tmp;
  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_3_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&TempControl_OpenLoop_5_3_M->solverInfo,
                          ((TempControl_OpenLoop_5_3_M->Timing.clockTick0+1)*
      TempControl_OpenLoop_5_3_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TempControl_OpenLoop_5_3_M)) {
    TempControl_OpenLoop_5_3_M->Timing.t[0] = rtsiGetT
      (&TempControl_OpenLoop_5_3_M->solverInfo);
  }

  /* RateTransition generated from: '<S45>/Sum' */
  tmp = rtmIsMajorTimeStep(TempControl_OpenLoop_5_3_M);
  if (tmp && TempControl_OpenLoop_5_3_M->Timing.RateInteraction.TID1_2) {
    /* RateTransition generated from: '<S45>/Sum' */
    TempControl_OpenLoop_5_3_B.TmpRTBAtSumInport1 =
      TempControl_OpenLoop_5_3_DW.TmpRTBAtSumInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S45>/Sum' */

  /* Sum: '<S45>/Sum' incorporates:
   *  Integrator: '<S36>/Integrator'
   */
  TempControl_OpenLoop_5_3_B.Sum = TempControl_OpenLoop_5_3_B.TmpRTBAtSumInport1
    + TempControl_OpenLoop_5_3_X.Integrator_CSTATE;
  if (tmp) {
  }

  /* Saturate: '<Root>/Saturation' */
  if (TempControl_OpenLoop_5_3_B.Sum >
      TempControl_OpenLoop_5_3_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    TempControl_OpenLoop_5_3_B.Saturation =
      TempControl_OpenLoop_5_3_P.Saturation_UpperSat;
  } else if (TempControl_OpenLoop_5_3_B.Sum <
             TempControl_OpenLoop_5_3_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    TempControl_OpenLoop_5_3_B.Saturation =
      TempControl_OpenLoop_5_3_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    TempControl_OpenLoop_5_3_B.Saturation = TempControl_OpenLoop_5_3_B.Sum;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(TempControl_OpenLoop_5_3_DW.obj_k.MW_PWM_HANDLE,
                      TempControl_OpenLoop_5_3_B.Saturation);
  if (tmp) {
    /* RateTransition generated from: '<S36>/Integrator' */
    if (TempControl_OpenLoop_5_3_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<S36>/Integrator' */
      TempControl_OpenLoop_5_3_B.TmpRTBAtIntegratorInport1 =
        TempControl_OpenLoop_5_3_DW.TmpRTBAtIntegratorInport1_Buffe;
    }

    /* End of RateTransition generated from: '<S36>/Integrator' */
  }

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_3_M)) {
    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((TempControl_OpenLoop_5_3_M->Timing.clockTick1) * 0.001);

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1, extmodeTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_3_M)) {
    rt_ertODEUpdateContinuousStates(&TempControl_OpenLoop_5_3_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++TempControl_OpenLoop_5_3_M->Timing.clockTick0;
    TempControl_OpenLoop_5_3_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TempControl_OpenLoop_5_3_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    TempControl_OpenLoop_5_3_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TempControl_OpenLoop_5_3_derivatives(void)
{
  XDot_TempControl_OpenLoop_5_3_T *_rtXdot;
  _rtXdot = ((XDot_TempControl_OpenLoop_5_3_T *)
             TempControl_OpenLoop_5_3_M->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE =
    TempControl_OpenLoop_5_3_B.TmpRTBAtIntegratorInport1;
}

/* Model step function for TID2 */
void TempControl_OpenLoop_5_3_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_IntegralGain;

  /* MATLABSystem: '<Root>/Analog Read' */
  MW_AnalogIn_Start(TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult
    (TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE, &rtb_IntegralGain, 7);

  /* Gain: '<Root>/ ' incorporates:
   *  MATLABSystem: '<Root>/Analog Read'
   */
  TempControl_OpenLoop_5_3_B.Temperature = TempControl_OpenLoop_5_3_P.K_meas *
    rtb_IntegralGain;

  /* ManualSwitch: '<Root>/Start Step' */
  if (TempControl_OpenLoop_5_3_P.StartStep_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Start Step' incorporates:
     *  Constant: '<Root>/Step1'
     */
    TempControl_OpenLoop_5_3_B.StartStep =
      TempControl_OpenLoop_5_3_P.Step1_Value;
  } else {
    /* ManualSwitch: '<Root>/Start Step' incorporates:
     *  Constant: '<Root>/Step'
     */
    TempControl_OpenLoop_5_3_B.StartStep = TempControl_OpenLoop_5_3_P.Step_Value;
  }

  /* End of ManualSwitch: '<Root>/Start Step' */

  /* Sum: '<Root>/Sum' */
  TempControl_OpenLoop_5_3_B.Sum_k = TempControl_OpenLoop_5_3_B.StartStep -
    TempControl_OpenLoop_5_3_B.Temperature;

  /* Gain: '<S33>/Integral Gain' */
  rtb_IntegralGain = TempControl_OpenLoop_5_3_P.Ki_ZN *
    TempControl_OpenLoop_5_3_B.Sum_k;

  /* RateTransition generated from: '<S36>/Integrator' */
  TempControl_OpenLoop_5_3_DW.TmpRTBAtIntegratorInport1_Buffe = rtb_IntegralGain;

  /* Gain: '<S41>/Proportional Gain' */
  rtb_IntegralGain = TempControl_OpenLoop_5_3_P.Kp_ZN / 4.0 *
    TempControl_OpenLoop_5_3_B.Sum_k;

  /* RateTransition generated from: '<S45>/Sum' */
  TempControl_OpenLoop_5_3_DW.TmpRTBAtSumInport1_Buffer0 = rtb_IntegralGain;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  TempControl_OpenLoop_5_3_M->Timing.clockTick2++;
}

/* Model initialize function */
void TempControl_OpenLoop_5_3_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
                          &TempControl_OpenLoop_5_3_M->Timing.simTimeStep);
    rtsiSetTPtr(&TempControl_OpenLoop_5_3_M->solverInfo, &rtmGetTPtr
                (TempControl_OpenLoop_5_3_M));
    rtsiSetStepSizePtr(&TempControl_OpenLoop_5_3_M->solverInfo,
                       &TempControl_OpenLoop_5_3_M->Timing.stepSize0);
    rtsiSetdXPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
                 &TempControl_OpenLoop_5_3_M->derivs);
    rtsiSetContStatesPtr(&TempControl_OpenLoop_5_3_M->solverInfo, (real_T **)
                         &TempControl_OpenLoop_5_3_M->contStates);
    rtsiSetNumContStatesPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
      &TempControl_OpenLoop_5_3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
      &TempControl_OpenLoop_5_3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
      &TempControl_OpenLoop_5_3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
      &TempControl_OpenLoop_5_3_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
      (boolean_T**) &TempControl_OpenLoop_5_3_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
                          (&rtmGetErrorStatus(TempControl_OpenLoop_5_3_M)));
    rtsiSetRTModelPtr(&TempControl_OpenLoop_5_3_M->solverInfo,
                      TempControl_OpenLoop_5_3_M);
  }

  rtsiSetSimTimeStep(&TempControl_OpenLoop_5_3_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&TempControl_OpenLoop_5_3_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&TempControl_OpenLoop_5_3_M->solverInfo, false);
  TempControl_OpenLoop_5_3_M->intgData.y = TempControl_OpenLoop_5_3_M->odeY;
  TempControl_OpenLoop_5_3_M->intgData.f[0] = TempControl_OpenLoop_5_3_M->odeF[0];
  TempControl_OpenLoop_5_3_M->intgData.f[1] = TempControl_OpenLoop_5_3_M->odeF[1];
  TempControl_OpenLoop_5_3_M->intgData.f[2] = TempControl_OpenLoop_5_3_M->odeF[2];
  TempControl_OpenLoop_5_3_M->contStates = ((X_TempControl_OpenLoop_5_3_T *)
    &TempControl_OpenLoop_5_3_X);
  TempControl_OpenLoop_5_3_M->contStateDisabled =
    ((XDis_TempControl_OpenLoop_5_3_T *) &TempControl_OpenLoop_5_3_XDis);
  TempControl_OpenLoop_5_3_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TempControl_OpenLoop_5_3_M->solverInfo, (void *)
                    &TempControl_OpenLoop_5_3_M->intgData);
  rtsiSetSolverName(&TempControl_OpenLoop_5_3_M->solverInfo,"ode3");
  rtmSetTPtr(TempControl_OpenLoop_5_3_M,
             &TempControl_OpenLoop_5_3_M->Timing.tArray[0]);
  rtmSetTFinal(TempControl_OpenLoop_5_3_M, 600.0);
  TempControl_OpenLoop_5_3_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  TempControl_OpenLoop_5_3_M->Sizes.checksums[0] = (1389423475U);
  TempControl_OpenLoop_5_3_M->Sizes.checksums[1] = (3501687288U);
  TempControl_OpenLoop_5_3_M->Sizes.checksums[2] = (1754143179U);
  TempControl_OpenLoop_5_3_M->Sizes.checksums[3] = (2969606827U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    TempControl_OpenLoop_5_3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TempControl_OpenLoop_5_3_M->extModeInfo,
      &TempControl_OpenLoop_5_3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TempControl_OpenLoop_5_3_M->extModeInfo,
                        TempControl_OpenLoop_5_3_M->Sizes.checksums);
    rteiSetTPtr(TempControl_OpenLoop_5_3_M->extModeInfo, rtmGetTPtr
                (TempControl_OpenLoop_5_3_M));
  }

  /* Start for RateTransition generated from: '<S45>/Sum' */
  TempControl_OpenLoop_5_3_B.TmpRTBAtSumInport1 =
    TempControl_OpenLoop_5_3_P.TmpRTBAtSumInport1_InitialCondi;

  /* Start for RateTransition generated from: '<S36>/Integrator' */
  TempControl_OpenLoop_5_3_B.TmpRTBAtIntegratorInport1 =
    TempControl_OpenLoop_5_3_P.TmpRTBAtIntegratorInport1_Initi;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  TempControl_OpenLoop_5_3_X.Integrator_CSTATE =
    TempControl_OpenLoop_5_3_P.DiscretePIDController_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<S45>/Sum' */
  TempControl_OpenLoop_5_3_DW.TmpRTBAtSumInport1_Buffer0 =
    TempControl_OpenLoop_5_3_P.TmpRTBAtSumInport1_InitialCondi;

  /* InitializeConditions for RateTransition generated from: '<S36>/Integrator' */
  TempControl_OpenLoop_5_3_DW.TmpRTBAtIntegratorInport1_Buffe =
    TempControl_OpenLoop_5_3_P.TmpRTBAtIntegratorInport1_Initi;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  TempControl_OpenLoop_5_3_DW.obj_k.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_5_3_DW.obj_k.isSetupComplete = false;
  TempControl_OpenLoop_5_3_DW.obj_k.isInitialized = 1;
  TempControl_OpenLoop_5_3_DW.obj_k.MW_PWM_HANDLE = MW_PWM_Open(D2, 10000.0,
    20.0);
  MW_PWM_Start(TempControl_OpenLoop_5_3_DW.obj_k.MW_PWM_HANDLE);
  TempControl_OpenLoop_5_3_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Read' */
  TempControl_OpenLoop_5_3_DW.obj.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_5_3_DW.obj.isSetupComplete = false;
  TempControl_OpenLoop_5_3_DW.obj.isInitialized = 1;
  TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(A0);
  MW_AnalogIn_SetTriggerSource
    (TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE,
     MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  TempControl_OpenLoop_5_3_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void TempControl_OpenLoop_5_3_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!TempControl_OpenLoop_5_3_DW.obj_k.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_5_3_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_5_3_DW.obj_k.isInitialized == 1) &&
        TempControl_OpenLoop_5_3_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(TempControl_OpenLoop_5_3_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(TempControl_OpenLoop_5_3_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
  /* Terminate for MATLABSystem: '<Root>/Analog Read' */
  if (!TempControl_OpenLoop_5_3_DW.obj.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_5_3_DW.obj.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_5_3_DW.obj.isInitialized == 1) &&
        TempControl_OpenLoop_5_3_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(TempControl_OpenLoop_5_3_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
