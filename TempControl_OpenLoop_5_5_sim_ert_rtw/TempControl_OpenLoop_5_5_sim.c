/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TempControl_OpenLoop_5_5_sim.c
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

#include "TempControl_OpenLoop_5_5_sim.h"
#include "rtwtypes.h"
#include "TempControl_OpenLoop_5_5_sim_private.h"

/* Block signals (default storage) */
B_TempControl_OpenLoop_5_5_si_T TempControl_OpenLoop_5_5_sim_B;

/* Continuous states */
X_TempControl_OpenLoop_5_5_si_T TempControl_OpenLoop_5_5_sim_X;

/* Disabled State Vector */
XDis_TempControl_OpenLoop_5_5_T TempControl_OpenLoop_5_5_s_XDis;

/* Block states (default storage) */
DW_TempControl_OpenLoop_5_5_s_T TempControl_OpenLoop_5_5_sim_DW;

/* Real-time model */
static RT_MODEL_TempControl_OpenLoop_T TempControl_OpenLoop_5_5_sim_M_;
RT_MODEL_TempControl_OpenLoop_T *const TempControl_OpenLoop_5_5_sim_M =
  &TempControl_OpenLoop_5_5_sim_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TempControl_OpenLoop_5_5_sim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TempControl_OpenLoop_5_5_sim_step();
  TempControl_OpenLoop_5_5_sim_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TempControl_OpenLoop_5_5_sim_step();
  TempControl_OpenLoop_5_5_sim_derivatives();

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
void TempControl_OpenLoop_5_5_sim_step(void)
{
  real_T rtb_Clock;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_5_sim_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                          ((TempControl_OpenLoop_5_5_sim_M->Timing.clockTick0+1)*
      TempControl_OpenLoop_5_5_sim_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TempControl_OpenLoop_5_5_sim_M)) {
    TempControl_OpenLoop_5_5_sim_M->Timing.t[0] = rtsiGetT
      (&TempControl_OpenLoop_5_5_sim_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = TempControl_OpenLoop_5_5_sim_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_Clock < 80.0) {
    TempControl_OpenLoop_5_5_sim_B.y_ref = 0.1875 * rtb_Clock;
    TempControl_OpenLoop_5_5_sim_B.U_ref = TempControl_OpenLoop_5_5_sim_P.Ti_ZN /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN * 0.1875 + 1.0 /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN *
      TempControl_OpenLoop_5_5_sim_B.y_ref;
  } else if (rtb_Clock < 120.0) {
    TempControl_OpenLoop_5_5_sim_B.y_ref = 15.0;
    TempControl_OpenLoop_5_5_sim_B.U_ref = TempControl_OpenLoop_5_5_sim_P.Ti_ZN /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN * 0.0 + 1.0 /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN * 15.0;
  } else {
    TempControl_OpenLoop_5_5_sim_B.y_ref = -0.125 * rtb_Clock + 30.0;
    TempControl_OpenLoop_5_5_sim_B.U_ref = TempControl_OpenLoop_5_5_sim_P.Ti_ZN /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN * -0.125 + 1.0 /
      TempControl_OpenLoop_5_5_sim_P.Kp_ZN *
      TempControl_OpenLoop_5_5_sim_B.y_ref;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  tmp = rtmIsMajorTimeStep(TempControl_OpenLoop_5_5_sim_M);
  if (tmp) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  TempControl_OpenLoop_5_5_sim_B.y_cont = 0.0;
  TempControl_OpenLoop_5_5_sim_B.y_cont +=
    TempControl_OpenLoop_5_5_sim_P.TransferFcn_C *
    TempControl_OpenLoop_5_5_sim_X.TransferFcn_CSTATE;

  /* Sum: '<Root>/Sum' */
  TempControl_OpenLoop_5_5_sim_B.e = TempControl_OpenLoop_5_5_sim_B.y_ref -
    TempControl_OpenLoop_5_5_sim_B.y_cont;

  /* Sum: '<S46>/Sum' incorporates:
   *  Gain: '<S42>/Proportional Gain'
   *  Integrator: '<S37>/Integrator'
   */
  TempControl_OpenLoop_5_5_sim_B.usat = TempControl_OpenLoop_5_5_sim_P.Kp_ZN *
    TempControl_OpenLoop_5_5_sim_B.e +
    TempControl_OpenLoop_5_5_sim_X.Integrator_CSTATE;

  /* Saturate: '<Root>/Saturation' */
  if (TempControl_OpenLoop_5_5_sim_B.usat >
      TempControl_OpenLoop_5_5_sim_P.Saturation_UpperSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    TempControl_OpenLoop_5_5_sim_B.usat =
      TempControl_OpenLoop_5_5_sim_P.Saturation_UpperSat;
  } else if (TempControl_OpenLoop_5_5_sim_B.usat <
             TempControl_OpenLoop_5_5_sim_P.Saturation_LowerSat) {
    /* Sum: '<S46>/Sum' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    TempControl_OpenLoop_5_5_sim_B.usat =
      TempControl_OpenLoop_5_5_sim_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/Sum1' */
  TempControl_OpenLoop_5_5_sim_B.Sum1 = TempControl_OpenLoop_5_5_sim_B.U_ref +
    TempControl_OpenLoop_5_5_sim_B.usat;
  if (tmp) {
  }

  /* Gain: '<S34>/Integral Gain' */
  TempControl_OpenLoop_5_5_sim_B.IntegralGain =
    TempControl_OpenLoop_5_5_sim_P.Ki_ZN * TempControl_OpenLoop_5_5_sim_B.e;
  if (tmp) {
  }

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_5_sim_M)) {
    if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_5_sim_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((TempControl_OpenLoop_5_5_sim_M->Timing.clockTick1) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TempControl_OpenLoop_5_5_sim_M)) {
    rt_ertODEUpdateContinuousStates(&TempControl_OpenLoop_5_5_sim_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++TempControl_OpenLoop_5_5_sim_M->Timing.clockTick0;
    TempControl_OpenLoop_5_5_sim_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TempControl_OpenLoop_5_5_sim_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      TempControl_OpenLoop_5_5_sim_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TempControl_OpenLoop_5_5_sim_derivatives(void)
{
  XDot_TempControl_OpenLoop_5_5_T *_rtXdot;
  _rtXdot = ((XDot_TempControl_OpenLoop_5_5_T *)
             TempControl_OpenLoop_5_5_sim_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = TempControl_OpenLoop_5_5_sim_P.TransferFcn_A *
    TempControl_OpenLoop_5_5_sim_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += TempControl_OpenLoop_5_5_sim_B.Sum1;

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = TempControl_OpenLoop_5_5_sim_B.IntegralGain;
}

/* Model initialize function */
void TempControl_OpenLoop_5_5_sim_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                          &TempControl_OpenLoop_5_5_sim_M->Timing.simTimeStep);
    rtsiSetTPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo, &rtmGetTPtr
                (TempControl_OpenLoop_5_5_sim_M));
    rtsiSetStepSizePtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                       &TempControl_OpenLoop_5_5_sim_M->Timing.stepSize0);
    rtsiSetdXPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                 &TempControl_OpenLoop_5_5_sim_M->derivs);
    rtsiSetContStatesPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo, (real_T **)
                         &TempControl_OpenLoop_5_5_sim_M->contStates);
    rtsiSetNumContStatesPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
      &TempControl_OpenLoop_5_5_sim_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
      &TempControl_OpenLoop_5_5_sim_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&TempControl_OpenLoop_5_5_sim_M->solverInfo,
       &TempControl_OpenLoop_5_5_sim_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&TempControl_OpenLoop_5_5_sim_M->solverInfo,
       &TempControl_OpenLoop_5_5_sim_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
      (boolean_T**) &TempControl_OpenLoop_5_5_sim_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                          (&rtmGetErrorStatus(TempControl_OpenLoop_5_5_sim_M)));
    rtsiSetRTModelPtr(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                      TempControl_OpenLoop_5_5_sim_M);
  }

  rtsiSetSimTimeStep(&TempControl_OpenLoop_5_5_sim_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&TempControl_OpenLoop_5_5_sim_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&TempControl_OpenLoop_5_5_sim_M->solverInfo, false);
  TempControl_OpenLoop_5_5_sim_M->intgData.y =
    TempControl_OpenLoop_5_5_sim_M->odeY;
  TempControl_OpenLoop_5_5_sim_M->intgData.f[0] =
    TempControl_OpenLoop_5_5_sim_M->odeF[0];
  TempControl_OpenLoop_5_5_sim_M->intgData.f[1] =
    TempControl_OpenLoop_5_5_sim_M->odeF[1];
  TempControl_OpenLoop_5_5_sim_M->intgData.f[2] =
    TempControl_OpenLoop_5_5_sim_M->odeF[2];
  TempControl_OpenLoop_5_5_sim_M->contStates = ((X_TempControl_OpenLoop_5_5_si_T
    *) &TempControl_OpenLoop_5_5_sim_X);
  TempControl_OpenLoop_5_5_sim_M->contStateDisabled =
    ((XDis_TempControl_OpenLoop_5_5_T *) &TempControl_OpenLoop_5_5_s_XDis);
  TempControl_OpenLoop_5_5_sim_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TempControl_OpenLoop_5_5_sim_M->solverInfo, (void *)
                    &TempControl_OpenLoop_5_5_sim_M->intgData);
  rtsiSetSolverName(&TempControl_OpenLoop_5_5_sim_M->solverInfo,"ode3");
  rtmSetTPtr(TempControl_OpenLoop_5_5_sim_M,
             &TempControl_OpenLoop_5_5_sim_M->Timing.tArray[0]);
  rtmSetTFinal(TempControl_OpenLoop_5_5_sim_M, 600.0);
  TempControl_OpenLoop_5_5_sim_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TempControl_OpenLoop_5_5_sim_M->Sizes.checksums[0] = (1872100702U);
  TempControl_OpenLoop_5_5_sim_M->Sizes.checksums[1] = (3363265509U);
  TempControl_OpenLoop_5_5_sim_M->Sizes.checksums[2] = (1005859183U);
  TempControl_OpenLoop_5_5_sim_M->Sizes.checksums[3] = (2708308157U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    TempControl_OpenLoop_5_5_sim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TempControl_OpenLoop_5_5_sim_M->extModeInfo,
      &TempControl_OpenLoop_5_5_sim_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TempControl_OpenLoop_5_5_sim_M->extModeInfo,
                        TempControl_OpenLoop_5_5_sim_M->Sizes.checksums);
    rteiSetTPtr(TempControl_OpenLoop_5_5_sim_M->extModeInfo, rtmGetTPtr
                (TempControl_OpenLoop_5_5_sim_M));
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  TempControl_OpenLoop_5_5_sim_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  TempControl_OpenLoop_5_5_sim_X.Integrator_CSTATE =
    TempControl_OpenLoop_5_5_sim_P.DiscretePIDController_InitialCo;
}

/* Model terminate function */
void TempControl_OpenLoop_5_5_sim_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
