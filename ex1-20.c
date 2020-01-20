/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the 
next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a 
symbolic parame- ter? */

#include <stdio.h>

#define TABINC 8			// tab increment size

int main(void) {
	int c, nb, pos;

	c = 0;
	pos = 1;

	while ((c = getchar()) != EOF)
		if (c == '\t')
			for (nb = TABINC - (pos  - 1) % TABINC; nb > 0; --nb, ++pos)
				putchar(' ');
		else if (c == '\n') {
			putchar('\n');
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}

	return 0;
}