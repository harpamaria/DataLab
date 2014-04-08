/* 
 * CS:APP Data Lab 
 * 
 * Nalseez Duke dukex048
 * Eric Nguyen  nguy1973 
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

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
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
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
 /* If x is the highest value, adding one will turn it to Tmin, then add Tmax and Tmin to manipulate bits*/
  int maxOut = x+1;

  x += maxOut;
  x = ~x;
  maxOut = !(maxOut);
  x = x|maxOut;
  x = !x;

  return x;
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
/* using Demorgan's laws one can see the equivalent inequality. Returns everything in common with complements of passed values*/
  return (~x & ~y);

}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
/* declare a bit sequence in hex form that will give every even numbered bit a value of 1 and odds zero (0x55 = 01010101), then since we can't make a hex number larger than 0xFF, shift it over for all 32 bits, then return that*/
  int x = 0x55;
  int y = (x + (x << 8) + (x << 16) + (x << 24));

  return y;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
/* Sets a variable equal to x being shifted to the right by 15 (equaling to 16 bits). Then Xor of shifted variable with 0, whatever is non zero will be returned, if it is negative then it will return 0, if it is positive or zero it will return 1 then add that to y Xor'd by -1, if negative will return 1, if positive or 0 will return 0). If negative, positive, or zero, will return 1. Otherwise 0 due to extra bits hanging off at end will throw off !*/
  int y = x >> 15;

  return !(y ^ 0) + !(y ^ (~0));
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
/* right shift all bits, if negative (11111..1) !!x will always return -1, giving -1 each time. If 0 (00000..0) !!x will always return 0. If positive (00000..0) !!x will give 1.*/
    return (x >> 31) | (!!x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
/*create a mask of (10101010, where all odd bits are 1, make the mask 32 bits, then compare x and mask with & to return whatever is in common, Xor that with the mask so that if all are in common, it returns 0, then ! that to get 1*/
  int mask = (0xAA << 8) + 0xAA;
  mask = (mask << 16) + mask;
  
  return !((x & mask) ^ mask);
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
/*take complement of x (ex 0110 - 1001), add one (1011) & with original - (0110 & 1011) = (0010).
 If zero - (1111 + 1 = 0000) (0000 & 1111) = 0.*/
  return ((~x + 1) & x);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
/*Make 2 variables with n and m shifted left 3 (this gets the whole byte), make 32 bit that is (00000..10101010 << 1 byte) | (00000..10101010 << 3 bytes) which will return*/
  int y = n << 3;
  int z = m << 3;
  int swap = ~((0xFF << y) | (0xFF << z));

  int byte1 = (x >> y) & 0xFF;
  int byte2 = (x >> z) & 0xFF;

  return (x & swap) | ((byte2 << y) | (byte1 << z));
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
/*make mask of (11111..11), variable that shifts -1 by highbit (ex = 11111111111111111111111111100000) Then shift that 1 more (11111.. 11000000). Variable that shifts -1 by lowbit (11111..11111000). XOR the two, (000..00111000) then & with low - (000..00111000) = 0x38*/
  int neg = ~0;
  int high = (neg << highbit) << 1;
  int low = (neg << lowbit);

  return (high ^ low) & low;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
/* shift x and y all the way to right to get leading value of neg or positive. Make variable that compares xval to !yval so get 0, */
int isLessOrEqual(int x, int y) {
  int xval = x >> 31;
  int yval = y >> 31;

  int vary = xval & (!yval);
  int similar = ((x + (~y)) >> 31) & (!(xval ^ yval));

 return vary | similar;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
/* Variable that holds x shifted to right by n. Variable that shifts all 1's to left by opposite of n then - 1, then shift one more time. Complement that and return & of that and original shifted*/
  int y = x >> n;
  int move = ~0 << (32 + ~n) << 1;
  move = ~move;
  return move & y;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
/*Variable that holds bytes of n, make mask that shifts (00000..10101010 by byte). Make variable that shifts wanted byte by other byte. Return passed x & with complement of mask and or with shifted to get them replaced. */
  int y = n << 3;
  int mask = 0xFF << y;
  int move = c << y;
  
  return (x & ~mask) | move;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
  *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
/*if zero, twos complement of zero is zero, then or with original and shift to far right, then add one to return 1.*/
  int neg = ~x + 1;
  int sign = (x | neg) >> 31;

  return sign + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
/* create mask that 00010001 over 4 bytes, make second mask over the next 4 bytes. Put every 1 in 1's digit into sum, then with remaining 3 bits in byte, check each by comparing with full mask. Shift sum right by 4 bytes, set first mask equal to 011100001111. Then set final sum equal to sum & first mask, shift right a byte and & again with first mask and add the two. Return sum + sum shifted 2 bytes and & with 00111111 as 2^6 */
  int mask1 = 0x11 | (0x11 << 8);
  int mask2 = mask1 | (mask1 << 16);

  int sum = x & mask2;
  sum += ((x >> 1) & mask2);
  sum += ((x >> 2) & mask2);
  sum += ((x >> 3) & mask2);

  sum += (sum >> 16);
  mask1 = 0xF | (0xF << 8);

  sum = (sum & mask1) + ((sum >> 4) & mask1);

  return((sum + (sum >> 8)) & 0x3F);

}
