#include <stdio.h>

// getbits: returns n bits from position p in x ; assuming right most bit index is 0
int getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
	printf("%d\n", getbits(349u, 4, 3));
	return 0;
}
