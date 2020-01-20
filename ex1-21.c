/* Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to 
achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice 
to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABINC 8

int main() {
	int nb, pos, nt, c;

	nb = nt = 0;
	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ')
			if (pos % TABINC != 0)								// checking whether the space character or character's be replaced by tabs
				++nb;
			else {
				++nt;											
				nb = 0;											// reset the blank counter
			} 
		else {
			for (; nt > 0; --nt)
				putchar('\t');

			if (c == '\t')										// we do not need any blanks as they will be covered by the tab
				nb = 0;
			else 
				for (; nb > 0; --nb)							// output blank(s)
					putchar(' ');

			putchar(c);

			if (c == '\n')
				pos = 0;										// assingning pos to 0 as later it will be incremeted by the loop 
			else if (c == '\t')
				pos = pos + (TABINC - (pos - 1)%TABINC) - 1;
		}
}