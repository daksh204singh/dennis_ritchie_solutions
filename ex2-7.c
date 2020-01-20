// solution of dennis ritchie problem 2-7

#include <stdio.h>

// invert: inverts n bits of x starting at position p
int invert(unsigned x, int p, int n) {
	return x ^ (~(~0 << n) << (p + 1 - n));
}

int main() {
	printf("%d\n", invert(443, 2, 3));
	return 0;
}

