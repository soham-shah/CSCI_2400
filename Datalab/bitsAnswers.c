#include "btest.h"
#include <limits.h>

/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       /* NOR Equivelent of AND */
  return ~(~x | ~y);
  
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  /* NAND Equivelent of XOR */
  return ~(~(x & ~y) & ~(y & ~x));

}

/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* XOR gives a measure of inequal bits (and thus subtraction)
     and so NOT-XOR is equality */
  return !(x ^ y);

}

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
  /* mask the sign bit against ~x and vice versa to get highest bit in x. Shift by n-1, and not. */
  int mask = x >> 31;

  return !(((~x & mask) + (x & ~mask)) >> (n + ~0));

}

/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /* mask1 masks the bits above highbit.
     mask2 masks the bits below lowbit.
     mask3 masks all but highest bit.
     combine masks to get 1's above and below. Not to get 1's in final mask
  */

  int mask1 = ~0 << highbit;
  int mask2 = ~(~0 << lowbit);
  int mask3 = ~(1 << highbit);
  
  mask1 = mask1 & mask3;

  return ~(mask1 | mask2);

}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  /* XORing two numbers returns a number with same bit parity.
     Keep shifting half of our number until reduced to 1 bit simple case.*/

  x = ( x >> 16 ) ^ x;
  x = ( x >> 8 ) ^ x;
  x = ( x >> 4 ) ^ x;
  x = ( x >> 2 ) ^ x;
  x = ( x >> 1) ^ x;
  return (x & 1);
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* Similar to bit parity, except use OR to accumlate any 1's in the number.*/

  x = ( x >> 16 ) | x;
  x = ( x >> 8 ) | x;
  x = ( x >> 4 ) | x;
  x = ( x >> 2 ) | x;
  x = ( x >> 1) | x;
  
  return ~x & 1;

}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
  /* get all 1's in mask. Negate x so that if its a pow of 2, it has only 1 zero.
     XOR against all 1's mask, since a non-pow-2 would have a diff bit pattern and not
     come out non-zero */

  int mask = ~0;
  return (!(mask ^ (~x + 1)));

}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /* TMax is 0xEFFF..., so move a 1 to MSB and not it */

  return ~(1 << 31);

}

/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  /* use XOR to subtract nums. Take difference other way and test for equality. 
     Get sign bit from x. Combine out with diff and sign, then with 1<<31 to check
     for the diff being negative. Use ! to reduce to 0x1 and 0x0*/

  int sign = x ^ y;
  int out = ~sign;
  int diff = y + (~x + 1);
  int equal = !diff;

  sign = sign & x;
  
  diff = ~diff;
  
  out = out & diff;
  out = out | sign;
  out = out & (1 << 31);

  out = (!!out) & (!equal);

  return out;  

}

/* 
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}

int sum3(int x, int y, int z) {

  /* use XOR to combine x, y, and z, use word2 to store carry bit. */



  int word1 = 0;
  int word2 = 0;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     without using any '+' operations 
  ***************************************************************/


  word1 = (x^y) ^ z;
  word2 = ( (x&y) | (x&z) | (y&z) ) << 1;


  /**************************************************************
     Don't change anything below here
  ***************************************************************/
  return sum(word1,word2);

}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* Use 1<<31 to mask sign bit. Use !x to test for x=0. XOR to combine them. */


  int out = !((1 << 31) & x);
  int iszero = !x;

  return out ^ iszero;

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
  /* 0 is special since negating it returns same number (and thus both have 0 sign bit).
     Shift sign bits, OR them, and mask against 1 to see if either had a 1 sing bit */

  int n = ~x + 1;

  return ((n >> 31) | (x >> 31)) & 1;

}

/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /* neg and pos are either 0, or set if the number was negative or positive respectively. 
     Reverse complement neg just in case its set. Add up all numbers to get TC. */

  int mask = 1 << 31;
  int neg = (mask & x) >> 31;
  int pos = ~neg;
  int sign = mask & x;

  pos = pos & x;
  neg = neg & x;

  neg = ~(neg + ~0);

  return (neg + pos + sign);
  

}
