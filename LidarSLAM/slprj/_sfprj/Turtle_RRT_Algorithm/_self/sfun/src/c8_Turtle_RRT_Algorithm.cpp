/* Include files */

#include "Turtle_RRT_Algorithm_sfun.h"
#include "c8_Turtle_RRT_Algorithm.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
const int32_T CALL_EVENT = -1;

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c8_emlrtMCI = { 13, /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c8_b_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c8_c_emlrtMCI = { 14,/* lineNo */
  9,                                   /* colNo */
  "asin",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\asin.m"/* pName */
};

static emlrtMCInfo c8_d_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c8_emlrtRSI = { 50, /* lineNo */
  "quat2eul",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pathName */
};

static emlrtRSInfo c8_b_emlrtRSI = { 75,/* lineNo */
  "quat2eul",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pathName */
};

static emlrtRSInfo c8_c_emlrtRSI = { 76,/* lineNo */
  "quat2eul",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pathName */
};

static emlrtRSInfo c8_d_emlrtRSI = { 77,/* lineNo */
  "quat2eul",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pathName */
};

static emlrtRSInfo c8_e_emlrtRSI = { 15,/* lineNo */
  "normalizeRows",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\+robotics\\+internal\\normalizeRows.m"/* pathName */
};

static emlrtRSInfo c8_f_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c8_g_emlrtRSI = { 4,/* lineNo */
  "Enabled Subsystem/MATLAB Function", /* fcnName */
  "#Turtle_RRT_Algorithm:221"          /* pathName */
};

static emlrtRTEInfo c8_emlrtRTEI = { 78,/* lineNo */
  30,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtRTEInfo c8_b_emlrtRTEI = { 78,/* lineNo */
  62,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtRTEInfo c8_c_emlrtRTEI = { 78,/* lineNo */
  74,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtRTEInfo c8_d_emlrtRTEI = { 78,/* lineNo */
  56,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtRTEInfo c8_e_emlrtRTEI = { 234,/* lineNo */
  20,                                  /* colNo */
  "ixfun",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pName */
};

static emlrtRTEInfo c8_f_emlrtRTEI = { 236,/* lineNo */
  26,                                  /* colNo */
  "ixfun",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pName */
};

static emlrtRTEInfo c8_g_emlrtRTEI = { 236,/* lineNo */
  5,                                   /* colNo */
  "ixfun",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pName */
};

static emlrtRTEInfo c8_h_emlrtRTEI = { 163,/* lineNo */
  14,                                  /* colNo */
  "ixfun",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pName */
};

static emlrtRTEInfo c8_i_emlrtRTEI = { 78,/* lineNo */
  24,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtECInfo c8_emlrtECI = { 1,  /* nDims */
  78,                                  /* lineNo */
  24,                                  /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

static emlrtECInfo c8_b_emlrtECI = { -1,/* nDims */
  78,                                  /* lineNo */
  9,                                   /* colNo */
  "quat2eul",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\shared\\robotics\\robotutils\\quat2eul.m"/* pName */
};

/* Function Declarations */
static void initialize_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void initialize_params_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void mdl_start_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void mdl_terminate_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void enable_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void disable_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void sf_gateway_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void ext_mode_exec_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void c8_update_jit_animation_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void c8_do_animation_call_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void set_sim_state_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance, const mxArray *c8_st);
static void initSimStructsc8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void initSubchartIOPointersc8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static real_T c8_sumColumnB(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, real_T c8_b_x[4]);
static real_T c8_function_handle_parenReference
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance, real_T c8_varargin_1,
   real_T c8_varargin_2);
static void c8_expand_atan2(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, real_T c8_a_data[], int32_T c8_a_size[1], real_T c8_b_data[],
  int32_T c8_b_size[1], real_T c8_c_data[], int32_T c8_c_size[1]);
static real_T c8_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_b_yaw_angle, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static uint8_T c8_c_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Turtle_RRT_Algorithm, const
  char_T *c8_identifier);
static uint8_T c8_d_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_slStringInitializeDynamicBuffers
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance);
static void c8_chart_data_browse_helper(SFc8_Turtle_RRT_AlgorithmInstanceStruct *
  chartInstance, int32_T c8_ssIdNumber, const mxArray **c8_mxData, uint8_T
  *c8_isValueTooBig);
static void c8_times(SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance,
                     real_T c8_in1_data[], int32_T c8_in1_size[1], real_T
                     c8_in2_data[], int32_T c8_in2_size[1]);
static void init_dsm_address_info(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_Turtle_RRT_Algorithm = 0U;
}

static void initialize_params_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void mdl_start_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void mdl_setup_runtime_resources_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  static const uint32_T c8_decisionTxtEndIdx = 0U;
  static const uint32_T c8_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c8_chart_data_browse_helper);
  chartInstance->c8_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c8_RuntimeVar,
    &chartInstance->c8_IsDebuggerActive,
    &chartInstance->c8_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c8_mlFcnLineNumber, &chartInstance->c8_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c8_covrtInstance, 1U, 0U, 1U,
    35U);
  covrtChartInitFcn(chartInstance->c8_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c8_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c8_decisionTxtStartIdx, &c8_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c8_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c8_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c8_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 119);
}

static void mdl_cleanup_runtime_resources_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c8_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c8_covrtInstance);
}

static void enable_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  static char_T c8_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c8_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  static char_T c8_cv1[4] = { 's', 'q', 'r', 't' };

  static char_T c8_cv3[4] = { 'a', 's', 'i', 'n' };

  emlrtStack c8_b_st;
  emlrtStack c8_c_st;
  emlrtStack c8_d_st;
  emlrtStack c8_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c8_f_y = NULL;
  const mxArray *c8_g_y = NULL;
  const mxArray *c8_h_y = NULL;
  const mxArray *c8_r_y = NULL;
  const mxArray *c8_s_y = NULL;
  const mxArray *c8_t_y = NULL;
  real_T c8_d_y[4];
  real_T c8_quat[4];
  real_T c8_eul_angle[3];
  real_T c8_b_tmp_data[1];
  real_T c8_b_x_data[1];
  real_T c8_dv[1];
  real_T c8_dv1[1];
  real_T c8_x_data[1];
  real_T c8_y_data[1];
  real_T c8_a;
  real_T c8_aSinInput;
  real_T c8_angleInRadians;
  real_T c8_b;
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_b_w;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_b_yaw_angle;
  real_T c8_b_z;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_c_x;
  real_T c8_c_y;
  real_T c8_d_a;
  real_T c8_d_b;
  real_T c8_d_x;
  real_T c8_e_a;
  real_T c8_e_b;
  real_T c8_e_x;
  real_T c8_e_y;
  real_T c8_f_a;
  real_T c8_f_x;
  real_T c8_g_a;
  real_T c8_g_x;
  real_T c8_h_a;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_i_y;
  real_T c8_j_a;
  real_T c8_j_x;
  real_T c8_j_y;
  real_T c8_k_a;
  real_T c8_k_x;
  real_T c8_k_y;
  real_T c8_m_a;
  real_T c8_m_x;
  real_T c8_m_y;
  real_T c8_o_a;
  real_T c8_o_y;
  real_T c8_p_a;
  real_T c8_p_y;
  real_T c8_q_a;
  real_T c8_qw;
  real_T c8_qx;
  real_T c8_qy;
  real_T c8_qz;
  real_T c8_r;
  real_T c8_r_a;
  real_T c8_s_a;
  real_T c8_t_a;
  real_T c8_u_a;
  int32_T c8_c_tmp_size[2];
  int32_T c8_b_tmp_size[1];
  int32_T c8_b_x_size[1];
  int32_T c8_c_tmp_data[1];
  int32_T c8_c_trueCount[1];
  int32_T c8_e_trueCount[1];
  int32_T c8_iv[1];
  int32_T c8_iv1[1];
  int32_T c8_tmp_data[1];
  int32_T c8_tmp_size[1];
  int32_T c8_x_size[1];
  int32_T c8_y_size[1];
  int32_T c8_b_end;
  int32_T c8_b_i;
  int32_T c8_b_k;
  int32_T c8_b_loop_ub;
  int32_T c8_b_nx;
  int32_T c8_b_partialTrueCount;
  int32_T c8_b_trueCount;
  int32_T c8_b_varargin_2;
  int32_T c8_c_end;
  int32_T c8_c_i;
  int32_T c8_c_k;
  int32_T c8_c_loop_ub;
  int32_T c8_c_partialTrueCount;
  int32_T c8_d_end;
  int32_T c8_d_i;
  int32_T c8_d_k;
  int32_T c8_d_loop_ub;
  int32_T c8_d_trueCount;
  int32_T c8_e_end;
  int32_T c8_e_i;
  int32_T c8_e_loop_ub;
  int32_T c8_end;
  int32_T c8_f_end;
  int32_T c8_f_i;
  int32_T c8_f_loop_ub;
  int32_T c8_f_trueCount;
  int32_T c8_g_end;
  int32_T c8_g_i;
  int32_T c8_g_loop_ub;
  int32_T c8_g_trueCount;
  int32_T c8_h_i;
  int32_T c8_h_loop_ub;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_i2;
  int32_T c8_i3;
  int32_T c8_i4;
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  int32_T c8_ia;
  int32_T c8_ic;
  int32_T c8_j_i;
  int32_T c8_k;
  int32_T c8_k_i;
  int32_T c8_loop_ub;
  int32_T c8_m_i;
  int32_T c8_partialTrueCount;
  int32_T c8_trueCount;
  int32_T c8_varargin_1;
  int32_T c8_varargin_2;
  int32_T c8_varargin_4;
  boolean_T c8_b_b1;
  boolean_T c8_b_p;
  boolean_T c8_c_p;
  boolean_T c8_d_p;
  boolean_T c8_e_p;
  boolean_T c8_f_b;
  boolean_T c8_mask1;
  boolean_T c8_mask2;
  boolean_T c8_p;
  boolean_T c8_samesize;
  c8_st.tls = chartInstance->c8_fEmlrtCtx;
  c8_b_st.prev = &c8_st;
  c8_b_st.tls = c8_st.tls;
  c8_c_st.prev = &c8_b_st;
  c8_c_st.tls = c8_b_st.tls;
  c8_d_st.prev = &c8_c_st;
  c8_d_st.tls = c8_c_st.tls;
  chartInstance->c8_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 3U, *chartInstance->c8_w);
  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 2U, *chartInstance->c8_z);
  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 1U, *chartInstance->c8_y);
  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 0U, *chartInstance->c8_x);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_b_x = *chartInstance->c8_x;
  c8_b_y = *chartInstance->c8_y;
  c8_b_z = *chartInstance->c8_z;
  c8_b_w = *chartInstance->c8_w;
  covrtEmlFcnEval(chartInstance->c8_covrtInstance, 4U, 0, 0);
  c8_quat[0] = c8_b_w;
  c8_quat[1] = c8_b_x;
  c8_quat[2] = c8_b_y;
  c8_quat[3] = c8_b_z;
  c8_b_st.site = &c8_g_emlrtRSI;
  c8_c_st.site = &c8_emlrtRSI;
  for (c8_k = 0; c8_k < 4; c8_k++) {
    c8_b_k = c8_k;
    c8_a = c8_quat[c8_b_k];
    c8_e_y = c8_a * c8_a;
    c8_d_y[c8_b_k] = c8_e_y;
  }

  c8_c_y = c8_sumColumnB(chartInstance, c8_d_y);
  c8_d_st.site = &c8_e_emlrtRSI;
  c8_c_x = c8_c_y;
  c8_d_x = c8_c_x;
  c8_e_x = c8_d_x;
  if (c8_e_x < 0.0) {
    c8_p = true;
  } else {
    c8_p = false;
  }

  c8_b_p = c8_p;
  if (c8_b_p) {
    c8_f_y = NULL;
    sf_mex_assign(&c8_f_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_g_y = NULL;
    sf_mex_assign(&c8_g_y, sf_mex_create("y", c8_cv, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_h_y = NULL;
    sf_mex_assign(&c8_h_y, sf_mex_create("y", c8_cv1, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c8_d_st, &c8_emlrtMCI, "error", 0U, 2U, 14, c8_f_y, 14,
                sf_mex_call(&c8_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c8_d_st, NULL, "message", 1U, 2U, 14, c8_g_y, 14, c8_h_y)));
  }

  c8_d_x = muDoubleScalarSqrt(c8_d_x);
  c8_b = 1.0 / c8_d_x;
  for (c8_i = 0; c8_i < 4; c8_i++) {
    c8_d_y[c8_i] = c8_quat[c8_i];
  }

  c8_b_b = c8_b;
  for (c8_c_k = 0; c8_c_k < 4; c8_c_k++) {
    c8_ia = c8_c_k;
    c8_ic = c8_c_k;
    c8_c_b = c8_b_b;
    c8_varargin_1 = c8_ic + 1;
    c8_varargin_2 = c8_ia + 1;
    c8_d_b = c8_c_b;
    c8_b_varargin_2 = c8_varargin_1 - 1;
    c8_varargin_4 = c8_varargin_2 - 1;
    c8_quat[c8_b_varargin_2] = c8_d_y[c8_varargin_4] * c8_d_b;
  }

  c8_qw = c8_quat[0];
  c8_qx = c8_quat[1];
  c8_qy = c8_quat[2];
  c8_qz = c8_quat[3];
  c8_aSinInput = -2.0 * (c8_qx * c8_qz - c8_qw * c8_qy);
  c8_mask1 = (c8_aSinInput >= 0.99999999999999778);
  c8_mask2 = (c8_aSinInput <= -0.99999999999999778);
  c8_dv[0] = c8_aSinInput;
  c8_end = 1;
  for (c8_b_i = 0; c8_b_i < c8_end; c8_b_i++) {
    if (c8_aSinInput >= 0.99999999999999778) {
      c8_dv[c8_b_i] = 1.0;
    }
  }

  c8_aSinInput = c8_dv[0];
  c8_dv1[0] = c8_aSinInput;
  c8_b_end = 1;
  for (c8_c_i = 0; c8_c_i < c8_b_end; c8_c_i++) {
    if (c8_mask2) {
      c8_dv1[c8_c_i] = -1.0;
    }
  }

  c8_aSinInput = c8_dv1[0];
  c8_c_st.site = &c8_b_emlrtRSI;
  c8_b_a = c8_qw;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  c8_e_a = c8_d_a;
  c8_i_y = c8_e_a * c8_e_a;
  c8_c_st.site = &c8_b_emlrtRSI;
  c8_f_a = c8_qx;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_g_a = c8_f_a;
  c8_h_a = c8_g_a;
  c8_j_a = c8_h_a;
  c8_j_y = c8_j_a * c8_j_a;
  c8_c_st.site = &c8_b_emlrtRSI;
  c8_k_a = c8_qy;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_m_a = c8_k_a;
  c8_o_a = c8_m_a;
  c8_p_a = c8_o_a;
  c8_k_y = c8_p_a * c8_p_a;
  c8_c_st.site = &c8_b_emlrtRSI;
  c8_q_a = c8_qz;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_r_a = c8_q_a;
  c8_s_a = c8_r_a;
  c8_t_a = c8_s_a;
  c8_m_y = c8_t_a * c8_t_a;
  c8_c_st.site = &c8_d_emlrtRSI;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_c_st.site = &c8_d_emlrtRSI;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_c_st.site = &c8_d_emlrtRSI;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_c_st.site = &c8_d_emlrtRSI;
  c8_d_st.site = &c8_f_emlrtRSI;
  c8_o_y = 2.0 * (c8_qx * c8_qy + c8_qw * c8_qz);
  c8_f_x = ((c8_i_y + c8_j_y) - c8_k_y) - c8_m_y;
  c8_u_a = c8_o_y;
  c8_e_b = c8_f_x;
  c8_p_y = c8_u_a;
  c8_g_x = c8_e_b;
  c8_r = muDoubleScalarAtan2(c8_p_y, c8_g_x);
  c8_c_st.site = &c8_c_emlrtRSI;
  c8_h_x = c8_aSinInput;
  c8_i_x = c8_h_x;
  c8_j_x = c8_i_x;
  c8_f_b = (c8_j_x < -1.0);
  c8_b_b1 = (c8_j_x > 1.0);
  if (c8_f_b || c8_b_b1) {
    c8_c_p = true;
  } else {
    c8_c_p = false;
  }

  c8_d_p = c8_c_p;
  if (c8_d_p) {
    c8_r_y = NULL;
    sf_mex_assign(&c8_r_y, sf_mex_create("y", c8_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_s_y = NULL;
    sf_mex_assign(&c8_s_y, sf_mex_create("y", c8_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c8_t_y = NULL;
    sf_mex_assign(&c8_t_y, sf_mex_create("y", c8_cv3, 10, 0U, 1U, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c8_c_st, &c8_c_emlrtMCI, "error", 0U, 2U, 14, c8_r_y, 14,
                sf_mex_call(&c8_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c8_c_st, NULL, "message", 1U, 2U, 14, c8_s_y, 14, c8_t_y)));
  }

  c8_eul_angle[0] = c8_r;
  c8_c_end = 1;
  c8_trueCount = 0;
  for (c8_d_i = 0; c8_d_i < c8_c_end; c8_d_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_trueCount++;
    }
  }

  c8_tmp_size[0] = c8_trueCount;
  c8_partialTrueCount = 0;
  for (c8_e_i = 0; c8_e_i < c8_c_end; c8_e_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_tmp_data[c8_partialTrueCount] = c8_e_i;
      c8_partialTrueCount++;
    }
  }

  c8_x_size[0] = c8_tmp_size[0];
  c8_loop_ub = c8_tmp_size[0] - 1;
  for (c8_i1 = 0; c8_i1 <= c8_loop_ub; c8_i1++) {
    c8_x_data[c8_i1] = c8_aSinInput;
  }

  c8_b_nx = c8_x_size[0];
  c8_i2 = static_cast<uint8_T>(c8_b_nx) - 1;
  for (c8_d_k = 0; c8_d_k <= c8_i2; c8_d_k++) {
    c8_k_x = c8_x_data[0];
    c8_m_x = c8_k_x;
    c8_m_x = muDoubleScalarSign(c8_m_x);
    c8_x_data[0] = c8_m_x;
  }

  c8_b_loop_ub = c8_x_size[0] - 1;
  for (c8_i3 = 0; c8_i3 <= c8_b_loop_ub; c8_i3++) {
    c8_x_data[c8_i3] = -c8_x_data[c8_i3] * 2.0;
  }

  c8_d_end = 1;
  c8_b_trueCount = 0;
  for (c8_f_i = 0; c8_f_i < c8_d_end; c8_f_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_b_trueCount++;
    }
  }

  c8_c_trueCount[0] = c8_b_trueCount;
  c8_y_size[0] = c8_c_trueCount[0];
  c8_c_loop_ub = c8_c_trueCount[0] - 1;
  for (c8_i4 = 0; c8_i4 <= c8_c_loop_ub; c8_i4++) {
    c8_y_data[c8_i4] = c8_qx;
  }

  c8_e_end = 1;
  c8_d_trueCount = 0;
  for (c8_g_i = 0; c8_g_i < c8_e_end; c8_g_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_d_trueCount++;
    }
  }

  c8_e_trueCount[0] = c8_d_trueCount;
  c8_b_x_size[0] = c8_e_trueCount[0];
  c8_d_loop_ub = c8_e_trueCount[0] - 1;
  for (c8_i5 = 0; c8_i5 <= c8_d_loop_ub; c8_i5++) {
    c8_b_x_data[c8_i5] = c8_qw;
  }

  c8_e_p = (static_cast<real_T>(c8_y_size[0]) == static_cast<real_T>
            (c8_b_x_size[0]));
  c8_samesize = c8_e_p;
  if (c8_samesize) {
    c8_b_tmp_size[0] = c8_y_size[0];
    c8_e_loop_ub = c8_y_size[0] - 1;
    for (c8_i6 = 0; c8_i6 <= c8_e_loop_ub; c8_i6++) {
      c8_b_tmp_data[c8_i6] = c8_function_handle_parenReference(chartInstance,
        c8_y_data[c8_i6], c8_b_x_data[c8_i6]);
    }
  } else {
    c8_expand_atan2(chartInstance, c8_y_data, c8_y_size, c8_b_x_data,
                    c8_b_x_size, c8_b_tmp_data, c8_b_tmp_size);
  }

  if ((c8_x_size[0] != c8_b_tmp_size[0]) && ((c8_x_size[0] != 1) &&
       (c8_b_tmp_size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(c8_x_size[0], c8_b_tmp_size[0], &c8_emlrtECI,
      &c8_b_st);
  }

  c8_f_end = 1;
  c8_f_trueCount = 0;
  for (c8_h_i = 0; c8_h_i < c8_f_end; c8_h_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_f_trueCount++;
    }
  }

  c8_tmp_size[0] = c8_f_trueCount;
  c8_b_partialTrueCount = 0;
  for (c8_j_i = 0; c8_j_i < c8_f_end; c8_j_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_tmp_data[c8_b_partialTrueCount] = c8_j_i;
      c8_b_partialTrueCount++;
    }
  }

  if (c8_x_size[0] == c8_b_tmp_size[0]) {
    c8_f_loop_ub = c8_x_size[0] - 1;
    for (c8_i7 = 0; c8_i7 <= c8_f_loop_ub; c8_i7++) {
      c8_x_data[c8_i7] *= c8_b_tmp_data[c8_i7];
    }
  } else {
    c8_times(chartInstance, c8_x_data, c8_x_size, c8_b_tmp_data, c8_b_tmp_size);
  }

  c8_iv[0] = c8_tmp_size[0];
  emlrtSubAssignSizeCheckR2012b(&c8_iv[0], 1, &c8_x_size[0], 1, &c8_b_emlrtECI,
    &c8_b_st);
  c8_g_loop_ub = c8_x_size[0] - 1;
  for (c8_i8 = 0; c8_i8 <= c8_g_loop_ub; c8_i8++) {
    c8_eul_angle[c8_tmp_data[c8_i8]] = c8_x_data[c8_i8];
  }

  c8_g_end = 1;
  c8_g_trueCount = 0;
  for (c8_k_i = 0; c8_k_i < c8_g_end; c8_k_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_g_trueCount++;
    }
  }

  c8_c_tmp_size[1] = c8_g_trueCount;
  c8_c_partialTrueCount = 0;
  for (c8_m_i = 0; c8_m_i < c8_g_end; c8_m_i++) {
    if (c8_mask1 || c8_mask2) {
      c8_c_tmp_data[c8_c_partialTrueCount] = c8_m_i;
      c8_c_partialTrueCount++;
    }
  }

  c8_iv1[0] = c8_c_tmp_size[1];
  c8_h_loop_ub = c8_iv1[0] - 1;
  for (c8_i9 = 0; c8_i9 <= c8_h_loop_ub; c8_i9++) {
    c8_eul_angle[2 + c8_c_tmp_data[c8_i9]] = 0.0;
  }

  c8_angleInRadians = c8_eul_angle[0];
  c8_b_yaw_angle = 57.295779513082323 * c8_angleInRadians;
  *chartInstance->c8_yaw_angle = c8_b_yaw_angle;
  c8_do_animation_call_c8_Turtle_RRT_Algorithm(chartInstance);
  covrtSigUpdateFcn(chartInstance->c8_covrtInstance, 4U,
                    *chartInstance->c8_yaw_angle);
}

static void ext_mode_exec_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void c8_update_jit_animation_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void c8_do_animation_call_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  const mxArray *c8_d_y = NULL;
  const mxArray *c8_st;
  c8_st = NULL;
  c8_st = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createcellmatrix(2, 1), false);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", chartInstance->c8_yaw_angle, 0, 0U,
    0U, 0U, 0), false);
  sf_mex_setcell(c8_b_y, 0, c8_c_y);
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y",
    &chartInstance->c8_is_active_c8_Turtle_RRT_Algorithm, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c8_b_y, 1, c8_d_y);
  sf_mex_assign(&c8_st, c8_b_y, false);
  return c8_st;
}

static void set_sim_state_c8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  *chartInstance->c8_yaw_angle = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 0)), "yaw_angle");
  chartInstance->c8_is_active_c8_Turtle_RRT_Algorithm = c8_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_Turtle_RRT_Algorithm");
  sf_mex_destroy(&c8_u);
  sf_mex_destroy(&c8_st);
}

static void initSimStructsc8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void initSubchartIOPointersc8_Turtle_RRT_Algorithm
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static real_T c8_sumColumnB(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, real_T c8_b_x[4])
{
  real_T c8_b_y;
  int32_T c8_b_k;
  int32_T c8_k;
  c8_b_y = c8_b_x[0];
  for (c8_k = 0; c8_k < 3; c8_k++) {
    c8_b_k = c8_k;
    c8_b_y += c8_b_x[c8_b_k + 1];
  }

  return c8_b_y;
}

static real_T c8_function_handle_parenReference
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance, real_T c8_varargin_1,
   real_T c8_varargin_2)
{
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_c_x;
  real_T c8_c_y;
  c8_b_x = c8_varargin_1;
  c8_b_y = c8_varargin_2;
  c8_c_y = c8_b_x;
  c8_c_x = c8_b_y;
  return muDoubleScalarAtan2(c8_c_y, c8_c_x);
}

static void c8_expand_atan2(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, real_T c8_a_data[], int32_T c8_a_size[1], real_T c8_b_data[],
  int32_T c8_b_size[1], real_T c8_c_data[], int32_T c8_c_size[1])
{
  real_T c8_b_c_data[1];
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_r;
  int32_T c8_csz[2];
  int32_T c8_i;
  int32_T c8_k;
  int32_T c8_loop_ub;
  int32_T c8_sak;
  int32_T c8_sbk;
  int32_T c8_sck;
  c8_sak = c8_a_size[0];
  c8_sbk = c8_b_size[0];
  if (c8_sbk == 1) {
    c8_sck = c8_sak;
  } else {
    c8_sck = 0;
  }

  c8_csz[0] = c8_sck;
  c8_c_size[0] = c8_csz[0];
  if (c8_c_size[0] != 0) {
    c8_loop_ub = c8_c_size[0] - 1;
    for (c8_i = 0; c8_i <= c8_loop_ub; c8_i++) {
      c8_b_c_data[c8_i] = c8_c_data[c8_i];
    }

    for (c8_k = 0; c8_k < 1; c8_k++) {
      c8_b_y = c8_a_data[0];
      c8_b_x = c8_b_data[0];
      c8_r = muDoubleScalarAtan2(c8_b_y, c8_b_x);
      c8_b_c_data[0] = c8_r;
    }

    c8_c_size[0] = 1;
    c8_c_data[0] = c8_b_c_data[0];
  }
}

const mxArray *sf_c8_Turtle_RRT_Algorithm_get_eml_resolved_functions_info()
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static real_T c8_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_b_yaw_angle, const char_T *c8_identifier)
{
  emlrtMsgIdentifier c8_thisId;
  real_T c8_b_y;
  c8_thisId.fIdentifier = const_cast<const char_T *>(c8_identifier);
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_yaw_angle),
    &c8_thisId);
  sf_mex_destroy(&c8_b_yaw_angle);
  return c8_b_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_b_y;
  real_T c8_d;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d, 1, 0, 0U, 0, 0U, 0);
  c8_b_y = c8_d;
  sf_mex_destroy(&c8_u);
  return c8_b_y;
}

static uint8_T c8_c_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Turtle_RRT_Algorithm, const
  char_T *c8_identifier)
{
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_b_y;
  c8_thisId.fIdentifier = const_cast<const char_T *>(c8_identifier);
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_Turtle_RRT_Algorithm), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_Turtle_RRT_Algorithm);
  return c8_b_y;
}

static uint8_T c8_d_emlrt_marshallIn(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_b_u;
  uint8_T c8_b_y;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b_u, 1, 3, 0U, 0, 0U, 0);
  c8_b_y = c8_b_u;
  sf_mex_destroy(&c8_u);
  return c8_b_y;
}

static void c8_slStringInitializeDynamicBuffers
  (SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance)
{
}

static void c8_chart_data_browse_helper(SFc8_Turtle_RRT_AlgorithmInstanceStruct *
  chartInstance, int32_T c8_ssIdNumber, const mxArray **c8_mxData, uint8_T
  *c8_isValueTooBig)
{
  real_T c8_b_d1;
  real_T c8_d;
  real_T c8_d2;
  real_T c8_d3;
  real_T c8_d4;
  *c8_mxData = NULL;
  *c8_mxData = NULL;
  *c8_isValueTooBig = 0U;
  switch (c8_ssIdNumber) {
   case 4U:
    c8_d = *chartInstance->c8_x;
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &c8_d, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 5U:
    c8_b_d1 = *chartInstance->c8_yaw_angle;
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &c8_b_d1, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 6U:
    c8_d2 = *chartInstance->c8_y;
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &c8_d2, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 7U:
    c8_d3 = *chartInstance->c8_z;
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &c8_d3, 0, 0U, 0U, 0U, 0),
                  false);
    break;

   case 8U:
    c8_d4 = *chartInstance->c8_w;
    sf_mex_assign(c8_mxData, sf_mex_create("mxData", &c8_d4, 0, 0U, 0U, 0U, 0),
                  false);
    break;
  }
}

static void c8_times(SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance,
                     real_T c8_in1_data[], int32_T c8_in1_size[1], real_T
                     c8_in2_data[], int32_T c8_in2_size[1])
{
  real_T c8_b_in1_data[1];
  int32_T c8_b_in1_size[1];
  int32_T c8_aux_0_0;
  int32_T c8_aux_1_0;
  int32_T c8_b_loop_ub;
  int32_T c8_i;
  int32_T c8_i1;
  int32_T c8_i2;
  int32_T c8_loop_ub;
  int32_T c8_stride_0_0;
  int32_T c8_stride_1_0;
  if (c8_in2_size[0] == 1) {
    c8_b_in1_size[0] = c8_in1_size[0];
  } else {
    c8_b_in1_size[0] = c8_in2_size[0];
  }

  c8_stride_0_0 = static_cast<int32_T>(c8_in1_size[0] != 1);
  c8_stride_1_0 = static_cast<int32_T>(c8_in2_size[0] != 1);
  c8_aux_0_0 = 0;
  c8_aux_1_0 = 0;
  if (c8_in2_size[0] == 1) {
    c8_i = c8_in1_size[0];
  } else {
    c8_i = c8_in2_size[0];
  }

  c8_loop_ub = c8_i - 1;
  for (c8_i1 = 0; c8_i1 <= c8_loop_ub; c8_i1++) {
    c8_b_in1_data[c8_i1] = c8_in1_data[c8_aux_0_0] * c8_in2_data[c8_aux_1_0];
    c8_aux_1_0 += c8_stride_1_0;
    c8_aux_0_0 += c8_stride_0_0;
  }

  c8_in1_size[0] = c8_b_in1_size[0];
  c8_b_loop_ub = c8_b_in1_size[0] - 1;
  for (c8_i2 = 0; c8_i2 <= c8_b_loop_ub; c8_i2++) {
    c8_in1_data[c8_i2] = c8_b_in1_data[c8_i2];
  }
}

static void init_dsm_address_info(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance)
{
}

static void init_simulink_io_address(SFc8_Turtle_RRT_AlgorithmInstanceStruct
  *chartInstance)
{
  chartInstance->c8_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c8_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c8_x = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c8_yaw_angle = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c8_z = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c8_w = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c8_Turtle_RRT_Algorithm_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(111385006U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1042276324U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1904650641U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1624785379U);
}

mxArray *sf_c8_Turtle_RRT_Algorithm_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_Turtle_RRT_Algorithm_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_Turtle_RRT_Algorithm_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_Turtle_RRT_Algorithm(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiAWYGJgYAPSHEDMxAABrFA+I1SMES7OAhdXAOKSyoJUkHhxUbJnCpDOS8wF8xN"
    "LKzzz0vLB5lswIMxnw2I+I5L5nFBxCPhgT5l+EQeQfgck/SxY9HMi6ReA8isTy+MT89JzUqHifE"
    "g0+e5RcKBMP8T+CAL+UUTzD4ifWRyfmFySWZYan2wRH1JaVJKTGh8UFBLvmJOeX5RZkpGL5k8Al"
    "bAfNg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Turtle_RRT_Algorithm_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sLUuGRw1Zzrhft0qx1QA12G";
}

static void sf_opaque_initialize_c8_Turtle_RRT_Algorithm(void *chartInstanceVar)
{
  initialize_params_c8_Turtle_RRT_Algorithm
    ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*) chartInstanceVar);
  initialize_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_Turtle_RRT_Algorithm(void *chartInstanceVar)
{
  enable_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_Turtle_RRT_Algorithm(void *chartInstanceVar)
{
  disable_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_Turtle_RRT_Algorithm(void *chartInstanceVar)
{
  sf_gateway_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_Turtle_RRT_Algorithm(SimStruct*
  S)
{
  return get_sim_state_c8_Turtle_RRT_Algorithm
    ((SFc8_Turtle_RRT_AlgorithmInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_Turtle_RRT_Algorithm(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c8_Turtle_RRT_Algorithm(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Turtle_RRT_Algorithm_optimization_info();
    }

    mdl_cleanup_runtime_resources_c8_Turtle_RRT_Algorithm
      ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*) chartInstanceVar);
    ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*) chartInstanceVar)->
      ~SFc8_Turtle_RRT_AlgorithmInstanceStruct();
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c8_Turtle_RRT_Algorithm(void *chartInstanceVar)
{
  mdl_start_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c8_Turtle_RRT_Algorithm(void
  *chartInstanceVar)
{
  mdl_terminate_c8_Turtle_RRT_Algorithm((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Turtle_RRT_Algorithm(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Turtle_RRT_Algorithm
      ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc8_Turtle_RRT_Algorithm
      ((SFc8_Turtle_RRT_AlgorithmInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c8_Turtle_RRT_Algorithm_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrtWM2OG0UQblvLJqtAtIdIiAiJ5MYFsQscEimC9e9iycsuHu+CcrF6Z8qelnt6ZvvHPxHvwRG",
    "OvAEHLnkAHoDH4MgNqsdjx9iOPW2LkCBG8s72zHz1VdXUXw8pNM4IHnfx99N7hOzj+Tb+imRyvJ",
    "WtC3O/yfU98iRbf3eHED8OoAfCM90uGxG3Q5jogkoaKeJ+CBpBC1TMjWaxaIhunB/LRBckCB8FJ",
    "LHUTryKRYYz0a8b4Vtm9U3I/NALY8ODMgqkwbng45fxJkZfIGOVSfB1HSDQoYxNL6xz2lvvBamH",
    "lRD8vjKRs68UaM8k1lR1ZrhmCYfaCPyGUJqiF9QGez1NNVT0yM3J1l7lTdFxlHBGRX5fh1R5kGB",
    "0aLhMAvx7bjR6LxfWD6nUZQjpAFST9VP2WEAudqbw6WsmqI4lo7wW8YqVltPeC442nmFKcNd3hP",
    "aWJdB+EjOhHRPCq6Ofa4Jec6jCtek58npwY2w2XDEYgnR7v91KPABJe3Au3HRO31FtlAblLJdyY",
    "jWL4IrKko+xqyBwqxuYdMqjGI7QRjFOWEhd3FBtyQYYG661rmHTf6taZ6JJ9KutsClvbQDOcTXj",
    "rfuiQjlXbth2nDRhADzlr1JNt8BO+B3ASrGgHWN02GrjWLGMYJgJGbYSi4Dlj8rBAiptbF9hk8o",
    "BZ5FNAwjQzTPVZ4I25ZFROo4qWHKqzWZOvmVsQ2iQXepD7h4jKVOACqdx5cgbMGUTCdHoJZ1amV",
    "vCJAe3ghLVNaI6jGUffezazF74ymaCGxqCHhZmDWmRq2F0X1FucuocqR7mD4bHpcIq68aLWJs/W",
    "4F96ocQ2M7JOJxhnUUBeV+xsi2/hNYOmB5XQfmSJXkzyWBBx6ZrvdQeJ3Ap+iIeirqMIy+bvNbE",
    "FQBWDSoFE70ytnA5rqPy+bSWcNNOq7vrkGP9TDWn1zY2TkFgN7S22qmB+phVNYEjMiq0C9Zjz3C",
    "IEYopjY16PGn1k75n5/cvyYv5fW/F/P7u3Px+mK39R522kZpDp9Vqd0q8h+OODqNU3tGcvLdz7A",
    "emeqzDkSUcmeGm5w/n8IUVvGTuvMh3UPz783sLfEW8UsDD4k7mcO+Q9bj9zGfBrZ9bt364/8u98",
    "vPvP/7x1z838ReW+Avp/xb3vOi237qbrd+fzk2zKj1YKmTbxoNqXprT1vD46TMZdvXRzej469Lx",
    "J6epvMMN+hYX9J1ef2BnNUzitCZIvxFk+za7pmayn7DyH83pu7/BHwdz8UTI71/shr93shgPq/x",
    "1sOAvux7TYYeKHocVcby9Pg9OdsNP+L/dYM/DBXseprN8h9qKDZ2XVYZlO7eNf1ccecW4N0XP//",
    "3yz9uXp//tbYnblo+8Ytyu9rn29Tf9+aM19ZcsPH/4Gtuxrt67zHevm12/Ebf564Ns/fns+0IlZ",
    "DxYscPJbuMmpLvq7n8kvv9w9N903qxZ/2Ufop9+WhKUj3FLM9kyZpcvpP2eOLslgarV+8Z/o59M",
    "z5vmxTsL+W3XQyaCeKg+evzZ453601+TJSDM",
    ""
  };

  static char newstr [1537] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c8_Turtle_RRT_Algorithm(SimStruct *S)
{
  const char* newstr = sf_c8_Turtle_RRT_Algorithm_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1387726692U));
  ssSetChecksum1(S,(3139084039U));
  ssSetChecksum2(S,(2545959444U));
  ssSetChecksum3(S,(4291600431U));
}

static void mdlRTW_c8_Turtle_RRT_Algorithm(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c8_Turtle_RRT_Algorithm(SimStruct *S)
{
  SFc8_Turtle_RRT_AlgorithmInstanceStruct *chartInstance;
  chartInstance = (SFc8_Turtle_RRT_AlgorithmInstanceStruct *)utMalloc(sizeof
    (SFc8_Turtle_RRT_AlgorithmInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_Turtle_RRT_AlgorithmInstanceStruct));
  chartInstance = new (chartInstance) SFc8_Turtle_RRT_AlgorithmInstanceStruct;
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Turtle_RRT_Algorithm;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c8_JITStateAnimation,
    chartInstance->c8_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c8_Turtle_RRT_Algorithm(chartInstance);
}

void c8_Turtle_RRT_Algorithm_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c8_Turtle_RRT_Algorithm(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Turtle_RRT_Algorithm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Turtle_RRT_Algorithm(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Turtle_RRT_Algorithm_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
