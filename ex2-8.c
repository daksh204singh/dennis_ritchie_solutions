// solution of dennis ritchie problem ex2-8

#include <stdio.h>

// rightrot: rotates bits of x by n bits to the right
int rightrot(unsigned x, int n) {
	extern int wordlength(void); 	// function declaration
	unsigned rbit; 					// rightmost bit

	while(n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1); 			// get the rightmost bit and make it the most leftmost bit
		x >>= 1;										// shift right by 1
		x |= rbit;										// complete the rotation
	}

	return x;
}

// wordlength : obtains the wordlength of the machine
int wordlength(void) {
	int i;
	unsigned v = (unsigned)~0;

	for(i = 1; (v >>= 1) > 0; i++)
		;

	return i;
}

int main() {
	printf("%u\\n", rightrot(1, 1));
}