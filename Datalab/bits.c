/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "soham-shah", 
   /* Student name 1: Replace with the full name of first team member */
   "Soham Nalin Shah",
   /* Login ID 1: Replace with the login ID of first team member */
   "sosh8590",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4
// rating 1

/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  //use demorgan's law to compute 'not x or y' as 'not x and not y'
  return ~x & ~y;
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /*
  First it sets all the digits to 0 in the 32 bit unsigned int.
  Then it compliments all the 0's to 1. 
  Then is does a logical right shift by 1 leaving 01111111 so the highest twos compliment number. 
  */
  unsigned int x = 0;
  x = ~x;
  x = x >> 1;
  return x;
}
// rating 2

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*
  place the number and then shift it by however many digits there are on both sides.
  Then check it against the original to make sure all the information is preserved.
  */
  int shift = 33 + ~n;
  return !(((x<<shift)>>shift)^x);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /*
    First shift left 1 by n thus multiplying 1 by 2^n this will be the amount of bias needed
    shift x right by 31 to determine if x is positive or negative. if positive then it will be all 0 and no bias will be needed
    if negative then all will be 1 and the bias will need to be applied.
    */
    int bias = (1 << n) + ~0; 
    int fixer = (x >> 31) & bias; 
    return (x+fixer) >> n; 
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  /*
  first use logical xor to determine if the numbers match.
  use bang twice - once to determine if they match again to inverse that for the correct function output.
  */
  return !!(x^y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  /* note that ~(x|y) = ~x & ~y - demorgan's law
  apply that to a larger problem 
  (~x & y) | (x & ~y)
  then apply demorgan's law on that property.
  */
  return ~(~(x&~y) & ~(~x&y));
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
  first shift left 31 to get the LSB. Then shift right 31 to fill with LSB
  */
  return ((x<<31)>>31);
}
// rating 3
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /*work on this
  first use the shifts to grab the necessary Byte
  Use the mask to set the MSD to 0
  shift left as necessary and or the results to reconstruct the final answer.
  */
  int byte1 = x  & 0xFF;
  int byte2 = (x >> 8) & 0xFF;
  int byte3 = (x >> 16) & 0xFF;
  int byte4 = (x >> 24) & 0xFF;
 
  byte1 = byte1 << 24;
  byte2 = byte2 << 16;
  byte3 = byte3 << 8;

  return byte1 | byte2 | byte3 | byte4;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*first shift 1 to the left 31 times so it's 0x10000000
  second shift the mask to the right n-1 times and take the compliment
  & it with the x shifted right arithmetically to get the logical shift
  */
  int mask = (1 << 31);
  int mask2 = mask >> (n+~0);
  mask2 = ~mask2;
  return ((x >> n) & mask2);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /*
  check if x is negative or y is negative - thus telling if one is less than the other. 
  subtract x from y and find the sign bit. if it's 0 then x > y if 1 then y>x
  
  if they're both the same than use another check.
  
  */
  int x_bool = x >> 31;
  int y_bool = y >> 31;

  int subtract = ((x + ~y) >> 31);
  
  int test = ((!(x_bool ^ y_bool)) & subtract);

  //if they're not equal
  int unEqual = x_bool & !y_bool;

  return !(test | unEqual);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + <<   >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /*
  create a mask of 1 then delete the extraneous stuff on the low side
  for the high mask first shift it over by how much the high mask is, then 
  compliment the high mask and use a 1 to include the position at high mask
  or the two together and take the compliment to get the mask.
  */
  int lowmask = (~(~0 << lowbit));
  int highmask = (~0 << highbit);
  int extramask = (1 << highbit);
  highmask = highmask ^ extramask;

  return (~(lowmask | highmask));
}
// rating 4
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  /*
  first figure out whether it is positive or negative
  then take that and push it back to ^ it with the original. 1^1 - 0 0^0 - 0
  There issues towards the end of the range of values so a bias needs to be calculated and applied
  if it is positive 
  */
  int sign = x >> 31;
  //only trigger the +1 if going from
  return (((x ^ (sign)) + (1 + (~(sign)))));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*
  Create a mask that is essentially 0001 {x8}
  this allows you to & with the number to get the number of 1's in each word
  from there you just have to shift it right by 1 each time to get all the 1's in
  a smaller and smaller portion. 
  eventually it goes down to 0x3F wich represents 6 bits which is 2^5 therefore 32 - the highest number of 1's possible in a 32 bit integer.
  */
  int count, mask, mask2;

  mask = 0x11 | (0x11 << 8);
  mask = mask | (mask << 16);

  count = x & mask;
  count = count + ((x >> 1) & mask);
  count = count + ((x >> 2) & mask);
  count = count + ((x >> 3) & mask);

  count = count + (count >> 16);

  mask2 = 0x0F0F;

  count = (count & mask2) + ((count >> 4) & mask2);

  return((count + (count >> 8)) & 0x3F);
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  /*
  check if the number is nonzero by first checking if it's negative
  if it is positive check turn it negative by doing ~x +1 and check if there's a negative 
  */
  int negcheck = ((x>>31) & 1 );
  int poscheck = (((~x +1)>>31)&1);
  return (negcheck | poscheck) ;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*
  extremenly similar to isNonZero just inverse the output
  */

  int negcheck = ((x>>31) & 1 );
  int poscheck = (((~x +1)>>31)&1);
  return (((negcheck | poscheck) + 1) &1);
}
