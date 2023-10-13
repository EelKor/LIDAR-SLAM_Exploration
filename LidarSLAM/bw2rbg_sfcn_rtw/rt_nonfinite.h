

        /*
    * rt_nonfinite.h
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
    */


    #ifndef RTW_HEADER_rt_nonfinite_h_
    #define RTW_HEADER_rt_nonfinite_h_



    
#include <stddef.h>

#include "rtwtypes.h"


    

    

    

    

    

    

    

    

    

    

    

    

    

    

        #define NOT_USING_NONFINITE_LITERALS 1

    
                extern real_T rtInf;



                extern real_T rtMinusInf;



                extern real_T rtNaN;



                extern real32_T rtInfF;



                extern real32_T rtMinusInfF;



                extern real32_T rtNaNF;




        extern void rt_InitInfAndNaN(size_t realSize);
            extern boolean_T rtIsInf(real_T value);
            extern boolean_T rtIsInfF(real32_T value);
            extern boolean_T rtIsNaN(real_T value);
            extern boolean_T rtIsNaNF(real32_T value);
    
    typedef struct  {
    struct {
        uint32_T wordH;
        uint32_T wordL;
    } words;
    } BigEndianIEEEDouble;

    typedef struct  {
    struct {
        uint32_T wordL;
        uint32_T wordH;
    } words;
    } LittleEndianIEEEDouble;

    typedef struct  {
    union {
        real32_T wordLreal;
        uint32_T wordLuint;
    } wordL;
    } IEEESingle;

    


    

    

    

    

    

    #endif /* RTW_HEADER_rt_nonfinite_h_ */
