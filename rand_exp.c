/**
 *
 * This is program is just a naive implementation of rand function and srand
 * defined in the c standard library. 
 *
 */

#include <stdio.h>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void) {
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed) {
	next = seed;
}

int main() {
	
}