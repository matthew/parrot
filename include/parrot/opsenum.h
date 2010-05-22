
/* ex: set ro ft=c:
* !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
*
* This file is generated automatically from 'ops2c'.
*
* Any changes made here will be lost!
*
*/

#ifndef OPSENUM_H_GUARD
#define OPSENUM_H_GUARD

enum OPS_ENUM {
    enum_ops_load_bytecode_s               =    5,
    enum_ops_load_bytecode_sc              =    6,
    enum_ops_load_language_s               =    7,
    enum_ops_load_language_sc              =    8,
    enum_ops_branch_i                      =    9,
    enum_ops_branch_ic                     =   10,
    enum_ops_local_branch_p_i              =   11,
    enum_ops_local_branch_p_ic             =   12,
    enum_ops_local_return_p                =   13,
    enum_ops_jump_i                        =   14,
    enum_ops_jump_ic                       =   15,
    enum_ops_enternative                   =   16,
    enum_ops_if_i_ic                       =   17,
    enum_ops_if_n_ic                       =   18,
    enum_ops_if_s_ic                       =   19,
    enum_ops_if_p_ic                       =   20,
    enum_ops_unless_i_ic                   =   21,
    enum_ops_unless_n_ic                   =   22,
    enum_ops_unless_s_ic                   =   23,
    enum_ops_unless_p_ic                   =   24,
    enum_ops_invokecc_p                    =   25,
    enum_ops_invoke_p_p                    =   26,
    enum_ops_yield                         =   27,
    enum_ops_tailcall_p                    =   28,
    enum_ops_returncc                      =   29,
    enum_ops_capture_lex_p                 =   30,
    enum_ops_newclosure_p_p                =   31,
    enum_ops_set_args_pc                   =   32,
    enum_ops_get_params_pc                 =   33,
    enum_ops_set_returns_pc                =   34,
    enum_ops_get_results_pc                =   35,
    enum_ops_set_result_info_p             =   36,
    enum_ops_set_result_info_pc            =   37,
    enum_ops_result_info_p                 =   38,
    enum_ops_set_addr_i_ic                 =   39,
    enum_ops_set_addr_p_ic                 =   40,
    enum_ops_set_addr_p_i                  =   41,
    enum_ops_get_addr_i_p                  =   42,
    enum_ops_schedule_p                    =   43,
    enum_ops_addhandler_p                  =   44,
    enum_ops_push_eh_ic                    =   45,
    enum_ops_push_eh_p                     =   46,
    enum_ops_pop_eh                        =   47,
    enum_ops_throw_p                       =   48,
    enum_ops_throw_p_p                     =   49,
    enum_ops_rethrow_p                     =   50,
    enum_ops_count_eh_i                    =   51,
    enum_ops_die_s                         =   52,
    enum_ops_die_sc                        =   53,
    enum_ops_die_p                         =   54,
    enum_ops_die_pc                        =   55,
    enum_ops_die_i_i                       =   56,
    enum_ops_die_ic_i                      =   57,
    enum_ops_die_i_ic                      =   58,
    enum_ops_die_ic_ic                     =   59,
    enum_ops_exit_i                        =   60,
    enum_ops_exit_ic                       =   61,
    enum_ops_debug_i                       =   62,
    enum_ops_debug_ic                      =   63,
    enum_ops_bounds_i                      =   64,
    enum_ops_bounds_ic                     =   65,
    enum_ops_profile_i                     =   66,
    enum_ops_profile_ic                    =   67,
    enum_ops_trace_i                       =   68,
    enum_ops_trace_ic                      =   69,
    enum_ops_gc_debug_i                    =   70,
    enum_ops_gc_debug_ic                   =   71,
    enum_ops_interpinfo_i_i                =   72,
    enum_ops_interpinfo_i_ic               =   73,
    enum_ops_interpinfo_p_i                =   74,
    enum_ops_interpinfo_p_ic               =   75,
    enum_ops_interpinfo_s_i                =   76,
    enum_ops_interpinfo_s_ic               =   77,
    enum_ops_warningson_i                  =   78,
    enum_ops_warningson_ic                 =   79,
    enum_ops_warningsoff_i                 =   80,
    enum_ops_warningsoff_ic                =   81,
    enum_ops_errorson_i                    =   82,
    enum_ops_errorson_ic                   =   83,
    enum_ops_errorsoff_i                   =   84,
    enum_ops_errorsoff_ic                  =   85,
    enum_ops_runinterp_p_i                 =   86,
    enum_ops_runinterp_p_ic                =   87,
    enum_ops_getinterp_p                   =   88,
    enum_ops_sweep_ic                      =   89,
    enum_ops_collect                       =   90,
    enum_ops_sweepoff                      =   91,
    enum_ops_sweepon                       =   92,
    enum_ops_collectoff                    =   93,
    enum_ops_collecton                     =   94,
    enum_ops_needs_destroy_p               =   95,
    enum_ops_loadlib_p_s                   =   96,
    enum_ops_loadlib_p_sc                  =   97,
    enum_ops_loadlib_p_s_p                 =   98,
    enum_ops_loadlib_p_sc_p                =   99,
    enum_ops_loadlib_p_s_pc                =  100,
    enum_ops_loadlib_p_sc_pc               =  101,
    enum_ops_dlfunc_p_p_s_s                =  102,
    enum_ops_dlfunc_p_p_sc_s               =  103,
    enum_ops_dlfunc_p_p_s_sc               =  104,
    enum_ops_dlfunc_p_p_sc_sc              =  105,
    enum_ops_dlvar_p_p_s                   =  106,
    enum_ops_dlvar_p_p_sc                  =  107,
    enum_ops_compreg_s_p                   =  108,
    enum_ops_compreg_sc_p                  =  109,
    enum_ops_compreg_p_s                   =  110,
    enum_ops_compreg_p_sc                  =  111,
    enum_ops_new_callback_p_p_p_s          =  112,
    enum_ops_new_callback_p_p_p_sc         =  113,
    enum_ops_annotations_p                 =  114,
    enum_ops_annotations_p_s               =  115,
    enum_ops_annotations_p_sc              =  116,
    enum_ops_abs_i                         =  117,
    enum_ops_abs_n                         =  118,
    enum_ops_abs_i_i                       =  119,
    enum_ops_abs_n_n                       =  120,
    enum_ops_abs_p                         =  121,
    enum_ops_abs_p_p                       =  122,
    enum_ops_add_i_i                       =  123,
    enum_ops_add_i_ic                      =  124,
    enum_ops_add_n_n                       =  125,
    enum_ops_add_n_nc                      =  126,
    enum_ops_add_p_p                       =  127,
    enum_ops_add_p_i                       =  128,
    enum_ops_add_p_ic                      =  129,
    enum_ops_add_p_n                       =  130,
    enum_ops_add_p_nc                      =  131,
    enum_ops_add_i_i_i                     =  132,
    enum_ops_add_i_ic_i                    =  133,
    enum_ops_add_i_i_ic                    =  134,
    enum_ops_add_n_n_n                     =  135,
    enum_ops_add_n_nc_n                    =  136,
    enum_ops_add_n_n_nc                    =  137,
    enum_ops_add_p_p_p                     =  138,
    enum_ops_add_p_p_i                     =  139,
    enum_ops_add_p_p_ic                    =  140,
    enum_ops_add_p_p_n                     =  141,
    enum_ops_add_p_p_nc                    =  142,
    enum_ops_cmod_i_i_i                    =  143,
    enum_ops_cmod_i_ic_i                   =  144,
    enum_ops_cmod_i_i_ic                   =  145,
    enum_ops_cmod_p_p_i                    =  146,
    enum_ops_cmod_p_p_ic                   =  147,
    enum_ops_cmod_p_p_p                    =  148,
    enum_ops_cmod_n_n_n                    =  149,
    enum_ops_cmod_n_nc_n                   =  150,
    enum_ops_cmod_n_n_nc                   =  151,
    enum_ops_cmod_p_p_n                    =  152,
    enum_ops_cmod_p_p_nc                   =  153,
    enum_ops_dec_i                         =  154,
    enum_ops_dec_n                         =  155,
    enum_ops_dec_p                         =  156,
    enum_ops_div_i_i                       =  157,
    enum_ops_div_i_ic                      =  158,
    enum_ops_div_n_n                       =  159,
    enum_ops_div_n_nc                      =  160,
    enum_ops_div_p_p                       =  161,
    enum_ops_div_p_i                       =  162,
    enum_ops_div_p_ic                      =  163,
    enum_ops_div_p_n                       =  164,
    enum_ops_div_p_nc                      =  165,
    enum_ops_div_i_i_i                     =  166,
    enum_ops_div_i_ic_i                    =  167,
    enum_ops_div_i_i_ic                    =  168,
    enum_ops_div_i_ic_ic                   =  169,
    enum_ops_div_n_n_n                     =  170,
    enum_ops_div_n_nc_n                    =  171,
    enum_ops_div_n_n_nc                    =  172,
    enum_ops_div_n_nc_nc                   =  173,
    enum_ops_div_p_p_p                     =  174,
    enum_ops_div_p_p_i                     =  175,
    enum_ops_div_p_p_ic                    =  176,
    enum_ops_div_p_p_n                     =  177,
    enum_ops_div_p_p_nc                    =  178,
    enum_ops_fdiv_i_i                      =  179,
    enum_ops_fdiv_i_ic                     =  180,
    enum_ops_fdiv_n_n                      =  181,
    enum_ops_fdiv_n_nc                     =  182,
    enum_ops_fdiv_p_p                      =  183,
    enum_ops_fdiv_p_i                      =  184,
    enum_ops_fdiv_p_ic                     =  185,
    enum_ops_fdiv_p_n                      =  186,
    enum_ops_fdiv_p_nc                     =  187,
    enum_ops_fdiv_i_i_i                    =  188,
    enum_ops_fdiv_i_ic_i                   =  189,
    enum_ops_fdiv_i_i_ic                   =  190,
    enum_ops_fdiv_n_n_n                    =  191,
    enum_ops_fdiv_n_nc_n                   =  192,
    enum_ops_fdiv_n_n_nc                   =  193,
    enum_ops_fdiv_p_p_p                    =  194,
    enum_ops_fdiv_p_p_i                    =  195,
    enum_ops_fdiv_p_p_ic                   =  196,
    enum_ops_fdiv_p_p_n                    =  197,
    enum_ops_fdiv_p_p_nc                   =  198,
    enum_ops_ceil_n                        =  199,
    enum_ops_ceil_i_n                      =  200,
    enum_ops_ceil_n_n                      =  201,
    enum_ops_floor_n                       =  202,
    enum_ops_floor_i_n                     =  203,
    enum_ops_floor_n_n                     =  204,
    enum_ops_inc_i                         =  205,
    enum_ops_inc_n                         =  206,
    enum_ops_inc_p                         =  207,
    enum_ops_mod_i_i                       =  208,
    enum_ops_mod_i_ic                      =  209,
    enum_ops_mod_n_n                       =  210,
    enum_ops_mod_n_nc                      =  211,
    enum_ops_mod_p_p                       =  212,
    enum_ops_mod_p_i                       =  213,
    enum_ops_mod_p_ic                      =  214,
    enum_ops_mod_p_n                       =  215,
    enum_ops_mod_p_nc                      =  216,
    enum_ops_mod_i_i_i                     =  217,
    enum_ops_mod_i_ic_i                    =  218,
    enum_ops_mod_i_i_ic                    =  219,
    enum_ops_mod_n_n_n                     =  220,
    enum_ops_mod_n_nc_n                    =  221,
    enum_ops_mod_n_n_nc                    =  222,
    enum_ops_mod_p_p_p                     =  223,
    enum_ops_mod_p_p_i                     =  224,
    enum_ops_mod_p_p_ic                    =  225,
    enum_ops_mod_p_p_n                     =  226,
    enum_ops_mod_p_p_nc                    =  227,
    enum_ops_mul_i_i                       =  228,
    enum_ops_mul_i_ic                      =  229,
    enum_ops_mul_n_n                       =  230,
    enum_ops_mul_n_nc                      =  231,
    enum_ops_mul_p_p                       =  232,
    enum_ops_mul_p_i                       =  233,
    enum_ops_mul_p_ic                      =  234,
    enum_ops_mul_p_n                       =  235,
    enum_ops_mul_p_nc                      =  236,
    enum_ops_mul_i_i_i                     =  237,
    enum_ops_mul_i_ic_i                    =  238,
    enum_ops_mul_i_i_ic                    =  239,
    enum_ops_mul_n_n_n                     =  240,
    enum_ops_mul_n_nc_n                    =  241,
    enum_ops_mul_n_n_nc                    =  242,
    enum_ops_mul_p_p_p                     =  243,
    enum_ops_mul_p_p_i                     =  244,
    enum_ops_mul_p_p_ic                    =  245,
    enum_ops_mul_p_p_n                     =  246,
    enum_ops_mul_p_p_nc                    =  247,
    enum_ops_neg_i                         =  248,
    enum_ops_neg_n                         =  249,
    enum_ops_neg_p                         =  250,
    enum_ops_neg_i_i                       =  251,
    enum_ops_neg_n_n                       =  252,
    enum_ops_neg_p_p                       =  253,
    enum_ops_pow_n_n_n                     =  254,
    enum_ops_pow_n_nc_n                    =  255,
    enum_ops_pow_n_n_nc                    =  256,
    enum_ops_pow_p_p_p                     =  257,
    enum_ops_pow_p_p_i                     =  258,
    enum_ops_pow_p_p_ic                    =  259,
    enum_ops_pow_p_p_n                     =  260,
    enum_ops_pow_p_p_nc                    =  261,
    enum_ops_pow_n_n_i                     =  262,
    enum_ops_pow_n_nc_i                    =  263,
    enum_ops_pow_n_n_ic                    =  264,
    enum_ops_pow_n_nc_ic                   =  265,
    enum_ops_sub_i_i                       =  266,
    enum_ops_sub_i_ic                      =  267,
    enum_ops_sub_n_n                       =  268,
    enum_ops_sub_n_nc                      =  269,
    enum_ops_sub_p_p                       =  270,
    enum_ops_sub_p_i                       =  271,
    enum_ops_sub_p_ic                      =  272,
    enum_ops_sub_p_n                       =  273,
    enum_ops_sub_p_nc                      =  274,
    enum_ops_sub_i_i_i                     =  275,
    enum_ops_sub_i_ic_i                    =  276,
    enum_ops_sub_i_i_ic                    =  277,
    enum_ops_sub_n_n_n                     =  278,
    enum_ops_sub_n_nc_n                    =  279,
    enum_ops_sub_n_n_nc                    =  280,
    enum_ops_sub_p_p_p                     =  281,
    enum_ops_sub_p_p_i                     =  282,
    enum_ops_sub_p_p_ic                    =  283,
    enum_ops_sub_p_p_n                     =  284,
    enum_ops_sub_p_p_nc                    =  285,
    enum_ops_sqrt_n_n                      =  286,
    enum_ops_acos_n_n                      =  287,
    enum_ops_asec_n_n                      =  288,
    enum_ops_asin_n_n                      =  289,
    enum_ops_atan_n_n                      =  290,
    enum_ops_atan_n_n_n                    =  291,
    enum_ops_atan_n_nc_n                   =  292,
    enum_ops_atan_n_n_nc                   =  293,
    enum_ops_cos_n_n                       =  294,
    enum_ops_cosh_n_n                      =  295,
    enum_ops_exp_n_n                       =  296,
    enum_ops_ln_n_n                        =  297,
    enum_ops_log10_n_n                     =  298,
    enum_ops_log2_n_n                      =  299,
    enum_ops_sec_n_n                       =  300,
    enum_ops_sech_n_n                      =  301,
    enum_ops_sin_n_n                       =  302,
    enum_ops_sinh_n_n                      =  303,
    enum_ops_tan_n_n                       =  304,
    enum_ops_tanh_n_n                      =  305,
};

#endif /* OPSENUM_H_GUARD */

/* GENERATED BY ops2c */
/*
* Local variables:
*   c-file-style: "parrot"
* End:
* vim: expandtab shiftwidth=4:
*/