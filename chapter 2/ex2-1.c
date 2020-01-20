// Write a program to determine the ranges of char, short, Int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

#include <stdio.h>
#include <limits.h>

int main() {
	printf("Using limits.h to compute range\n");
	printf("signed char min = %d\n", SCHAR_MIN);
	printf("signed char max = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signend short max = %d\n", SHRT_MAX);
	printf("signed int min = %d\n", INT_MIN);
	printf("signed int max = %d\n", INT_MAX);
	// unsigned min will be 0
	printf("signed long max = %ld\n", LONG_MAX);
	printf("unsigned char max = %u\n", UCHAR_MAX);
	printf("unsignd int max = %u\n", UINT_MAX);
	printf("unsigned long min = %lu\n", ULONG_MAX);

	// determining range
	printf("Computing range\n");
	printf("signed char min = %d\n", -(char)((unsigned char)~0 >> 1) - 1);
	printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1));
	printf("signed short min = %d\n", -(char)((unsigned short)~0 >> 1) - 1);
	printf("signed short max = %d\n", (char)((unsigned short)~0 >> 1));
	printf("signed int min = %d\n", -(int)((unsigned int)~0 >> 1) - 1);
	printf("signed int max = %d\n", (int)((unsigned int)~0 >> 1));
	printf("signed long min = %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
	printf("signed long max = %ld\n", (long)((unsigned long)~0 >> 1));
	// unsigned min will be 0
	printf("unsigned char max = %u\n", (unsigned char)~0);
	printf("unsigned short max = %u\n", (unsigned short)~0);
	printf("unsigned int max = %u\n", (unsigned int)~0);
	printf("unsigned long max = %lu\n", (unsigned long)~0);

	return 0;
}