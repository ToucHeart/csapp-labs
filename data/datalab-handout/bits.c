/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  return (~(x & y)) & (~((~x) & (~y)));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return 1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  return (!((~(x + 1)) ^ x)) & (!!(x + 1));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  int A2 = 0xAA;
  int A4 = A2 << 8 | A2;
  int A8 = A4 << 16 | A4;
  return !((x & A8) ^ A8); // x & 0xAAAAAAAA == 0xAAAAAAAA
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return (~x) + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *   11 0000
 *   11 1001
 */
int isAsciiDigit(int x)
{
  int highbits = !(x >> 6);                         // high bits is all 0
  int mid2bits = !((x & 0x30) ^ 0x30);              // mid2 bits is '11'
  int lessThanA = ((x & 0xf) + ((~0xa) + 1)) >> 31; // x&0xf - a < 0 --> x&0xf + (~a+1 ) < 0, so its sign bit is 1
  return highbits & mid2bits & lessThanA;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  int val = !x;               // if x is true,then val=0, else val = 1
  int falsecond = (~val) + 1; // if val = 1, falsecond= -1, else falsecond = 0
  int truecond = ~falsecond;  // if val = 1, truecond = 0, else truecond =-1
  return (truecond & y) | (falsecond & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int xposyneg = (~(x >> 31)) & 0x1 & (y >> 31); // x>0 && y<0 ? 1 : 0
  int xnegypos = (x >> 31) & 0x1 & (~(y >> 31)); // x<0 && y>0 ? 1 : 0
  int xeqy = !(x ^ y);                           // x== y ? 1 : 0
  int xminusy = ((x + ((~y) + 1)) >> 31) & 0x1;  // x-y<0 ? 1 : 0
  return ((!xposyneg) & xminusy) | xeqy | xnegypos;
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  return (~((x | ((~x) + 1)) >> 31)) & 0x1; // x 和 -x 符号相反,相或为1
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  int sign = x >> 31;
  int b16, b8, b4, b2, b1, b0;
  x = (x & (~sign)) | (x ^ sign); // 如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）

  b16 = (!!(x >> 16)) << 4; // 高十六位是否有1
  x >>= b16;                // 如果有（至少需要16位），则将原数右移16位
  b8 = (!!(x >> 8)) << 3;   // 剩余位高8位是否有1
  x >>= b8;                 // 如果有（至少需要16+8=24位），则右移8位
  b4 = (!!(x >> 4)) << 2;
  x >>= b4;
  b2 = (!!(x >> 2)) << 1;
  x >>= b2;
  b1 = !!(x >> 1);
  x >>= b1;
  b0 = x;                                  // 最后一位是不是1
  return b16 + b8 + b4 + b2 + b1 + b0 + 1; // 加上符号位
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
  /*
    IEEE 754 float format:
    sign     exp      fraction
    1        8        23

    exp           fraction      number
    全1           全0           --> inf
    全1           非0           --> NaN
    全0           全0           --> 0
    全0           非0           --> 非规格化数
    非全0非全1     任意          --> 规格化数

    0和特别小的数,指数都是全零的,inf和NaN指数是全1的
  */
  unsigned int sign = uf >> 31;
  unsigned int exp = (uf >> 23) & 0xff;
  unsigned int fraction = uf & 0x7fffff;
  unsigned int ans = 0;

  if (exp == 0xff && fraction != 0) // NaN , return NaN
    return uf;
  if (exp == 0xff && fraction == 0) // inf ,return inf
    return uf;
  if (exp == 0)
  {
    if (fraction == 0) // 0,return 0
      return uf;
    else // 非规格化数,0.010..1  *  2^ (-126)
    {
      if (fraction & 0x400000) // 尾数的最高位为1
      {
        fraction &= 0x3fffff; // 尾数最高位清零
        fraction <<= 1;       // 尾数左移一位
        exp = 1;              // 将指数设为1,结果还是乘以2^(-126)
      }
      else // 最高位不为1
      {
        fraction <<= 1; // 直接将尾数左移一位
      }
    }
  }
  else // 规格化数
  {
    exp++;           // 阶码++
    if (exp == 0xff) // 如果阶码变成全1,设置为inf
    {
      fraction = 0; // 将fraction 清零,变为inf
    }
  }
  ans |= (sign << 31); // set sign bit
  ans |= (exp << 23);
  ans |= fraction;
  return ans;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  int INTMIN = 0x80000000u;
  unsigned sign = uf >> 31;
  int exp = (uf >> 23) & 0xff;
  unsigned fraction = uf & 0x7fffff;
  int ans = 0;

  if (exp == 0xff && fraction != 0) // NaN , return INTMIN
    return INTMIN;
  if (exp == 0xff && fraction == 0) // inf ,return INTMIN
    return INTMIN;
  if (exp == 0)
  {
    if (fraction == 0) // 0,return 0
      return 0;
    else // 非规格化数,0.010..1  *  2^ (-126) 结果为小数,取0
    {
      return 0;
    }
  }
  else // 规格化数
  {
    exp -= 127;
    if (exp < 0) // 结果为小数,取0
      return 0;
    if (exp <= 23) // 如果阶码<=23,只取部分尾数
    {
      ans = 1 << exp;          // 还原隐藏的1
      fraction >>= (23 - exp); // 取fraction的前exp位
      ans |= fraction;         // 加上fraction的前exp位
    }
    else
    {
      ans = (1 << 23) | fraction; // 还原隐藏的1,加上fraction全部位
      exp -= 23;                  // 此时结果应该为ans<<(2^exp),但是可能会溢出
      while (exp)                 // 循环左移,直到溢出或者exp为0
      {
        ans <<= 1;
        exp--;
        // ans的范围: 0~0x80000000
        // ans表示真正结果的绝对值,如果此时ans为负,原数为正的话已经溢出,原数为负的话,可能溢出负数的绝对值的最大范围,也可能等于最小负数,都应该返回INTMIN
        if (ans < 0)
          return 0x80000000u;
      }
    }
    return sign ? -ans : ans; // 乘上符号位
  }
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
  int INF = 0xff << 23;
  int exp = x + 127;
  int fraction = 0x400000;
  if (x >= 128)
    return INF;
  if (x < -149) // 最小数是1*2^(-126 + -23)
    return 0;
  if (x >= 0)
  {
    return exp << 23;
  }
  else
  {
    if (x >= -126)
    {
      return exp << 23;
    }
    else // x<=-127
    {
      x = -x;
      fraction >>= (x - 127);
      return fraction;
    }
  }
}
