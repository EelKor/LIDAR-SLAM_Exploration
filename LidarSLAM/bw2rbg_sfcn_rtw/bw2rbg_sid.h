/*
 * bw2rbg_sid.h
 *
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * Code generation for model "bw2rbg_sf".
 *
 * Model version              : 4.1
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Oct 13 12:37:46 2023
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: bw2rbg_sf.c
 */

/* statically allocated instance data for model: bw2rbg */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_bw2rbg_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_bw2rbg_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1124081275U);
    ssSetChecksumVal(rts, 1, 1056251404U);
    ssSetChecksumVal(rts, 2, 487288697U);
    ssSetChecksumVal(rts, 3, 179502488U);
  }
}
