#include <stdio.h>

#ifndef MAXBUFSIZE
#define MAXBUFSIZE 100
#endif

int buf[MAXBUFSIZE]; 	// buffer or ungetch()
int bufp; 		// index of vacant slot of buffer

int getch(void)
{
	return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= MAXBUFSIZE)
		printf("buffer limit exceeded!");
	else
		buf[bufp++] = c;
}

#include <ctype.h>

int getfloat(float *pf)
{
	int sign, exp, c, d, e, flag;
	float val;

	sign = exp = c = d = e = 0;

	while ((c = getch()) == ' ') 	// skip whitespaces
		;
	if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = ((c == '-') ? -1 : 1);
	if (c == '-' || c == '+') {
		d = c;
		if (isdigit(c = getch())) {
			;
		} else if (c == '.') {
			e = d;
			d = c;
			if (isdigit(c = getch())) {
				ungetch(c);
				c = d;
			} else {
				(c != EOF) ? ungetch(c) : EOF;
				ungetch(d);
				ungetch(e);
				return 0;
			}
		} else {
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return 0;
		}
	}
	for (*pf = 0; isdigit(c); c = getch())
		*pf = 10.0f * *pf + (c - '0');
	if (c == '.') { 
		d = c;
		if (!isdigit(c = getch())) {
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
		flag = 1;
		val = 0.1f;
		for (; isdigit(c); c = getch(), val *= 0.1f)
			*pf += (c - '0') * val;
	}
	if (c == 'e' || c == 'E') {
		if (flag == 0) {
			ungetch(c);
			return 0;
		}
		d = c;
		if (!(isdigit(c = getch())) && c != '-' && c != '+') {
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		} else if (c == '-') {
			d = c;
			if (!isdigit(c = getch())) {
				if (c != EOF)
					ungetch(c);
				ungetch(d);
				return d;
			}
			for (val = 0; isdigit(c); c = getch())
				val = 10*val + (c - '0');
			for (; val > 0; val--)
				*pf /= 10.0f;
		} else {
			if (c == '+') {
				d = c;
				if (!isdigit(c = getch())) {
					if (c != EOF)
						ungetch(c);
					ungetch(d);
					return d;
				}
			}
			for (val = 0; isdigit(c); c = getch())
				val = 10*val + (c - '0');
			for (; val > 0; val--)
				*pf *= 10.0f;
		}
	}
	*pf *= sign;	
	if (c != EOF)
		ungetch(c);
	return c;
}

int main() {
	float a;
	int ret; 
	ret = getfloat(&a);
	printf("Answer: %f\nReturn val: %d\n", a, ret);
}
