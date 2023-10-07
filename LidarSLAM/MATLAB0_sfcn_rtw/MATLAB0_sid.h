/*
 * MATLAB0_sid.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "MATLAB0_sf".
 *
 * Model version              : 3.64
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Oct  7 15:09:50 2023
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: MATLAB0_sf.c
 */

/* statically allocated instance data for model: MATLAB0 */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_MATLAB0_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_MATLAB0_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1597247849U);
    ssSetChecksumVal(rts, 1, 1056210436U);
    ssSetChecksumVal(rts, 2, 1818189560U);
    ssSetChecksumVal(rts, 3, 359916079U);
  }
}
