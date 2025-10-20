/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_6.c
 *
 * Code generated for Simulink model 'TempControl_OpenLoop_5_6'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Fri Oct 17 17:51:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TempControl_OpenLoop_5_6.h"
#include "rtwtypes.h"
#include "TempControl_OpenLoop_5_6_private.h"

/* Block signals (default storage) */
B_TempControl_OpenLoop_5_6_T TempControl_OpenLoop_5_6_B;

/* Continuous states */
X_TempControl_OpenLoop_5_6_T TempControl_OpenLoop_5_6_X;

/* Disabled State Vector */
XDis_TempControl_OpenLoop_5_6_T TempControl_OpenLoop_5_6_XDis;

/* Block states (default storage) */
DW_TempControl_OpenLoop_5_6_T TempControl_OpenLoop_5_6_DW;

/* Real-time model */
static RT_MODEL_TempControl_OpenLoop_T TempControl_OpenLoop_5_6_M_;
RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_5_6_M =
  &TempControl_OpenLoop_5_6_M_;

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
  TempControl_OpenLoop_5_6_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TempControl_OpenLoop_5_6_step();
  TempControl_OpenLoop_5_6_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TempControl_OpenLoop_5_6_step();
  TempControl_OpenLoop_5_6_derivatives();

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

/* Model step function */
void TempControl_OpenLoop_5_6_step(void)
{
  real_T rtb_Clock;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_6_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&TempControl_OpenLoop_5_6_M->solverInfo,
                          ((TempControl_OpenLoop_5_6_M->Timing.clockTick0+1)*
      TempControl_OpenLoop_5_6_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TempControl_OpenLoop_5_6_M)) {
    TempControl_OpenLoop_5_6_M->Timing.t[0] = rtsiGetT
      (&TempControl_OpenLoop_5_6_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = TempControl_OpenLoop_5_6_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_Clock < 80.0) {
    TempControl_OpenLoop_5_6_B.y_ref = 0.1875 * rtb_Clock + 25.0;
    rtb_Clock = 0.1875;
  } else if (rtb_Clock < 120.0) {
    TempControl_OpenLoop_5_6_B.y_ref = 40.0;
    rtb_Clock = 0.0;
  } else if (rtb_Clock < 140.0) {
    TempControl_OpenLoop_5_6_B.y_ref = (rtb_Clock - 120.0) * 0.25 + 40.0;
    rtb_Clock = 0.25;
  } else if (rtb_Clock < 160.0) {
    TempControl_OpenLoop_5_6_B.y_ref = 45.0;
    rtb_Clock = 0.0;
  } else if (rtb_Clock < 220.0) {
    TempControl_OpenLoop_5_6_B.y_ref = 45.0 - (rtb_Clock - 160.0) *
      0.33333333333333331;
    rtb_Clock = -0.33333333333333331;
  } else {
    TempControl_OpenLoop_5_6_B.y_ref = 25.0;
    rtb_Clock = 0.0;
  }

  TempControl_OpenLoop_5_6_B.U_ref = TempControl_OpenLoop_5_6_P.Ti_ZN /
    TempControl_OpenLoop_5_6_P.Kp_ZN * rtb_Clock + 1.0 /
    TempControl_OpenLoop_5_6_P.Kp_ZN * TempControl_OpenLoop_5_6_B.y_ref;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  tmp = rtmIsMajorTimeStep(TempControl_OpenLoop_5_6_M);
  if (tmp) {
    /* MATLABSystem: '<Root>/Analog Read' */
    MW_AnalogIn_Start(TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE);
    MW_AnalogInSingle_ReadResult
      (TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE, &rtb_Clock, 7);

    /* Gain: '<Root>/ ' incorporates:
     *  MATLABSystem: '<Root>/Analog Read'
     */
    TempControl_OpenLoop_5_6_B.Temperature = TempControl_OpenLoop_5_6_P.K_meas *
      rtb_Clock;
  }

  /* Sum: '<Root>/Sum' */
  TempControl_OpenLoop_5_6_B.e = TempControl_OpenLoop_5_6_B.y_ref -
    TempControl_OpenLoop_5_6_B.Temperature;

  /* Sum: '<S46>/Sum' incorporates:
   *  Gain: '<S42>/Proportional Gain'
   *  Integrator: '<S37>/Integrator'
   */
  TempControl_OpenLoop_5_6_B.usat = TempControl_OpenLoop_5_6_P.Kp_ZN *
    TempControl_OpenLoop_5_6_B.e + TempControl_OpenLoop_5_6_X.Integrator_CSTATE;

  /* Saturate: '<Root>/Saturation' */
  if (TempControl_OpenLoop_5_6_B.usat >
      TempControl_OpenLoop_5_6_P.Saturation_UpperSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    TempControl_OpenLoop_5_6_B.usat =
      TempControl_OpenLoop_5_6_P.Saturation_UpperSat;
  } else if (TempControl_OpenLoop_5_6_B.usat <
             TempControl_OpenLoop_5_6_P.Saturation_LowerSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    TempControl_OpenLoop_5_6_B.usat =
      TempControl_OpenLoop_5_6_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* MATLABSystem: '<Root>/PWM Output' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  MW_PWM_SetDutyCycle(TempControl_OpenLoop_5_6_DW.obj_k.MW_PWM_HANDLE,
                      TempControl_OpenLoop_5_6_B.U_ref +
                      TempControl_OpenLoop_5_6_B.usat);
  if (tmp) {
  }

  /* Gain: '<S34>/Integral Gain' */
  TempControl_OpenLoop_5_6_B.IntegralGain = TempControl_OpenLoop_5_6_P.Ki_ZN *
    TempControl_OpenLoop_5_6_B.e;
  if (tmp) {
  }

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_6_M)) {
    if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_6_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((TempControl_OpenLoop_5_6_M->Timing.clockTick1) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_6_M)) {
    rt_ertODEUpdateContinuousStates(&TempControl_OpenLoop_5_6_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++TempControl_OpenLoop_5_6_M->Timing.clockTick0;
    TempControl_OpenLoop_5_6_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TempControl_OpenLoop_5_6_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      TempControl_OpenLoop_5_6_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TempControl_OpenLoop_5_6_derivatives(void)
{
  XDot_TempControl_OpenLoop_5_6_T *_rtXdot;
  _rtXdot = ((XDot_TempControl_OpenLoop_5_6_T *)
             TempControl_OpenLoop_5_6_M->derivs);

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = TempControl_OpenLoop_5_6_B.IntegralGain;
}

/* Model initialize function */
void TempControl_OpenLoop_5_6_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
                          &TempControl_OpenLoop_5_6_M->Timing.simTimeStep);
    rtsiSetTPtr(&TempControl_OpenLoop_5_6_M->solverInfo, &rtmGetTPtr
                (TempControl_OpenLoop_5_6_M));
    rtsiSetStepSizePtr(&TempControl_OpenLoop_5_6_M->solverInfo,
                       &TempControl_OpenLoop_5_6_M->Timing.stepSize0);
    rtsiSetdXPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
                 &TempControl_OpenLoop_5_6_M->derivs);
    rtsiSetContStatesPtr(&TempControl_OpenLoop_5_6_M->solverInfo, (real_T **)
                         &TempControl_OpenLoop_5_6_M->contStates);
    rtsiSetNumContStatesPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
      &TempControl_OpenLoop_5_6_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
      &TempControl_OpenLoop_5_6_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
      &TempControl_OpenLoop_5_6_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
      &TempControl_OpenLoop_5_6_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
      (boolean_T**) &TempControl_OpenLoop_5_6_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
                          (&rtmGetErrorStatus(TempControl_OpenLoop_5_6_M)));
    rtsiSetRTModelPtr(&TempControl_OpenLoop_5_6_M->solverInfo,
                      TempControl_OpenLoop_5_6_M);
  }

  rtsiSetSimTimeStep(&TempControl_OpenLoop_5_6_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&TempControl_OpenLoop_5_6_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&TempControl_OpenLoop_5_6_M->solverInfo, false);
  TempControl_OpenLoop_5_6_M->intgData.y = TempControl_OpenLoop_5_6_M->odeY;
  TempControl_OpenLoop_5_6_M->intgData.f[0] = TempControl_OpenLoop_5_6_M->odeF[0];
  TempControl_OpenLoop_5_6_M->intgData.f[1] = TempControl_OpenLoop_5_6_M->odeF[1];
  TempControl_OpenLoop_5_6_M->intgData.f[2] = TempControl_OpenLoop_5_6_M->odeF[2];
  TempControl_OpenLoop_5_6_M->contStates = ((X_TempControl_OpenLoop_5_6_T *)
    &TempControl_OpenLoop_5_6_X);
  TempControl_OpenLoop_5_6_M->contStateDisabled =
    ((XDis_TempControl_OpenLoop_5_6_T *) &TempControl_OpenLoop_5_6_XDis);
  TempControl_OpenLoop_5_6_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TempControl_OpenLoop_5_6_M->solverInfo, (void *)
                    &TempControl_OpenLoop_5_6_M->intgData);
  rtsiSetSolverName(&TempControl_OpenLoop_5_6_M->solverInfo,"ode3");
  rtmSetTPtr(TempControl_OpenLoop_5_6_M,
             &TempControl_OpenLoop_5_6_M->Timing.tArray[0]);
  rtmSetTFinal(TempControl_OpenLoop_5_6_M, 600.0);
  TempControl_OpenLoop_5_6_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TempControl_OpenLoop_5_6_M->Sizes.checksums[0] = (4215552959U);
  TempControl_OpenLoop_5_6_M->Sizes.checksums[1] = (638000142U);
  TempControl_OpenLoop_5_6_M->Sizes.checksums[2] = (726687624U);
  TempControl_OpenLoop_5_6_M->Sizes.checksums[3] = (3189442919U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    TempControl_OpenLoop_5_6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TempControl_OpenLoop_5_6_M->extModeInfo,
      &TempControl_OpenLoop_5_6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TempControl_OpenLoop_5_6_M->extModeInfo,
                        TempControl_OpenLoop_5_6_M->Sizes.checksums);
    rteiSetTPtr(TempControl_OpenLoop_5_6_M->extModeInfo, rtmGetTPtr
                (TempControl_OpenLoop_5_6_M));
  }

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  TempControl_OpenLoop_5_6_X.Integrator_CSTATE =
    TempControl_OpenLoop_5_6_P.DiscretePIDController_InitialCo;

  /* Start for MATLABSystem: '<Root>/Analog Read' */
  TempControl_OpenLoop_5_6_DW.obj.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_5_6_DW.obj.isSetupComplete = false;
  TempControl_OpenLoop_5_6_DW.obj.isInitialized = 1;
  TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(A0);
  MW_AnalogIn_SetTriggerSource
    (TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE,
     MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  TempControl_OpenLoop_5_6_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM Output' */
  TempControl_OpenLoop_5_6_DW.obj_k.matlabCodegenIsDeleted = false;
  TempControl_OpenLoop_5_6_DW.obj_k.isSetupComplete = false;
  TempControl_OpenLoop_5_6_DW.obj_k.isInitialized = 1;
  TempControl_OpenLoop_5_6_DW.obj_k.MW_PWM_HANDLE = MW_PWM_Open(D2, 10000.0,
    20.0);
  MW_PWM_Start(TempControl_OpenLoop_5_6_DW.obj_k.MW_PWM_HANDLE);
  TempControl_OpenLoop_5_6_DW.obj_k.isSetupComplete = true;
}

/* Model terminate function */
void TempControl_OpenLoop_5_6_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Read' */
  if (!TempControl_OpenLoop_5_6_DW.obj.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_5_6_DW.obj.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_5_6_DW.obj.isInitialized == 1) &&
        TempControl_OpenLoop_5_6_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(TempControl_OpenLoop_5_6_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Read' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!TempControl_OpenLoop_5_6_DW.obj_k.matlabCodegenIsDeleted) {
    TempControl_OpenLoop_5_6_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((TempControl_OpenLoop_5_6_DW.obj_k.isInitialized == 1) &&
        TempControl_OpenLoop_5_6_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(TempControl_OpenLoop_5_6_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(TempControl_OpenLoop_5_6_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
