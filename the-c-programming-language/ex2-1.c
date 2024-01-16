// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  // Signed char
  char min_char = -1 * (1 << 7);
  char max_char = (1 << 7) - 1;

  // Unsigned char
  unsigned char max_unsigned_char = (1 << 8) - 1;

  // Signed short
  short min_short = -1 * (1 << 15);
  short max_short = (1 << 15) - 1;

  // Unsigned short
  unsigned short max_unsigned_short = (1 << 16) - 1;

  // Signed int (assuming 32-bit int)
  int min_int = -1 * (1 << 31);
  int max_int = (1LL << 31) - 1;

  // Unsigned int
  unsigned int max_unsigned_int = (1ULL << 32) - 1;

  // Signed long (assuming 32-bit long)
  long min_long = -1L * (1L << 31);
  long max_long = (1L << 31) - 1;

  // Unsigned long
  unsigned long max_unsigned_long = (1UL << 32) - 1;

  printf("Range of signed char: %15d to %d\n", min_char, max_char);
  printf("Range of unsigned char: %13u to %u\n", 0, max_unsigned_char);

  printf("Range of signed short: %14d to %d\n", min_short, max_short);
  printf("Range of unsigned short: %12u to %u\n", 0, max_unsigned_short);

  printf("Range of signed int: %16d to %10d\n", min_int, max_int);
  printf("Range of unsigned int: %14u to %u\n", 0, max_unsigned_int);

  printf("Range of signed long: %15ld to %ld\n", min_long, max_long);
  printf("Range of unsigned long: %13lu to %lu\n", 0UL, max_unsigned_long);

  printf("Range of float: %21e to %e\n", FLT_MIN, FLT_MAX);

  printf("Range of double: %20e to %e\n", DBL_MIN, DBL_MAX);

  return 0;
}
