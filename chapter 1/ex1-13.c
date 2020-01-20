#include <stdio.h>

#define MAXHIST 15 /* maximum length of histogram */
#define MAXWORD 10 /* maximum length of word */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main() {
	int c, i, j, state, nc;
	int wl[MAXWORD]; /* word length counters */
	int ovflow; /* number of overflow words */
	int maxvalue; /* maximum value in wl[] */
	int length; /* length of bars in histogram */

	for(i = 0; i < 10; i++)
		wl[i] = 0;
	
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if(nc > 0)
				if(nc <= MAXWORD)
					++wl[nc - 1];
				else
					++ovflow;
			nc = 0;
		} else if(state == OUT) {
			state = IN;
			nc = 1; /* beginning of word */
		} else
			++nc;
	}
	
	maxvalue = 0;
	for(i = 0; i < 10; i++)
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	
	// horizontal histogram
	for(i = 0; i < MAXWORD; ++i) {
		printf("%d: %d\t", i + 1, wl[i]);
		if(wl[i] != 0) {
			length = wl[i] * MAXHIST / maxvalue;
		}
		for(j = 0; j < length; ++j)
			printf("  * ");
		putchar('\n');
	}
	printf("There are %d words >= %d\n", ovflow, MAXWORD);

	// vertical histogram
	for(i = MAXHIST; i > 0; --i) {
		for(j = 0; j < MAXWORD; ++j)
			if(wl[j] * MAXHIST / maxvalue >= i)
				printf(" * \t");
			else
				printf("   \t");
		putchar('\n');
	}

	for(i = 0; i < MAXWORD; ++i)
		printf("%3d\t", i + 1);
	putchar('\n');
	for(i = 0; i < MAXWORD; ++i)
		printf("%3d\t", wl[i]);
	putchar('\n');
	printf("%d words were >= %d\n", ovflow, MAXWORD);
}