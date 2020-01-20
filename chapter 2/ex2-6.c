// solution of dennis ritchie problem 2-6

#include <stdio.h> 

// setbits : sets the rightmost n bits of y with the bits of x beginning at position p (n bits) 
int setbits(unsigned x, int p, int n, unsigned y) {
	return (x & ~(~(~0 << n) << (p + 1 - n)) ) | 
		(y & ~(~0 << n)) << (p + 1 - n); 
}

int main() {
	printf("%d\n", setbits(349, 4, 3, 13));
}