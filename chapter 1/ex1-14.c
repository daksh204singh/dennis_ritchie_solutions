#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15 /* maximum length of histogram */
#define MAXCHAR 128 /* maximum value of a character */

main() {
    int c, i, j;
    int cc[MAXCHAR]; /* frequency of character counter */
    int length; /* length of bar in histogram */
	int maxvalue; /* maximum value in cc[] */

	for(i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;

	while((c = getchar()) != EOF)
		if(c < MAXCHAR) 
			++cc[c];

	maxvalue = 0;
	for(i = 0; i < MAXCHAR; ++i)
		if(maxvalue < cc[i])
			maxvalue = cc[i];

	/* print horizontal histogram */
	for(i = 0; i < MAXCHAR; ++i) {
		if(isprint(i))
			printf("%3d - %2c - %3d\t", i, i, cc[i]);
		else
			printf("%3d - %2c - %3d\t", i, ' ', cc[i]);
		if(cc[i] > 0) {
			length = cc[i] * MAXHIST / maxvalue;
			for(j = 0; j < length; ++j)
				printf("* ");
		}
		putchar('\n');
	}
	putchar('\n');

	/* print vertical histogram */
	for (i = MAXHIST; i > 0; --i) {
		for(j = 0; j < MAXCHAR; ++j)
			if(cc[i] * MAXHIST / maxvalue >= i)
				printf(" * \t");
		putchar('\n');
	}
	for(i = 0; i < MAXHIST; ++i)
		printf("%3d\t", i);
	putchar('\n');
	for(i = 0; i < MAXHIST; ++i)
		if(isprint(i))
			printf("%3c\t", i);
		else
			printf("%3c\t", ' ');
	putchar('\n');
	for(i = 0; i < MAXCHAR; ++i)
		printf("%3d\t", cc[i]);
	putchar('\n');
	
	return 0;
}