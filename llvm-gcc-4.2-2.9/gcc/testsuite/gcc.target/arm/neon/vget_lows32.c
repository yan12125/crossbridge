/* APPLE LOCAL file v7 merge */
/* Test the `vget_lows32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vget_lows32 (void)
{
  int32x2_t out_int32x2_t;
  int32x4_t arg0_int32x4_t;

  out_int32x2_t = vget_low_s32 (arg0_int32x4_t);
}

/* { dg-final { scan-assembler "vmov\[ 	\]+\[dD\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */