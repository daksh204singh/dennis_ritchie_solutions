#include <stdio.h>

#ifndef MAXBUFSIZE
#define MAXBUFSIZE 100
#endif

int buffer[MAXBUFSIZE]; 	// buffer for ungetch
int bufp; 			// buffer's vacant position'

int getch(void)
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= MAXBUFSIZE)
		printf("Buffer limit exceeded!");
	else
		buffer[bufp++] = c;
}

#include <ctype.h>
/*
 * getint(): 	returns EOF for end-of-file
 * 		returns 0 if input is not number
 * 		positive value if input is a number
 */
int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch())) 	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); 	/* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		d = c; 			/* remember sign char */
		if (!isdigit(c = getch())) {
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
