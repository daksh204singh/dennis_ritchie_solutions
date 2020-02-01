#include <stdio.h>
#include <ctype.h>
#include <string.h>

// strlen: returns the length of s
int strlen_1(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;

	// subtracting two pointers give the number of objects between
	// them
	return p - s;
}

// getline_1: get line into s, return max length
int getline_1(char *s, int lim)
{
	int c;
	char *bs = c;

	for (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';

	return s - bs;
}

#include <ctype.h>
#define abs(x) ((x < 0) ? -(x) : (x)) 	// calculates absolute value of x

// atoi: convert s to integer
int atoi(char *s)
{
	int sign, n;

	for (i = 0; isspace(*s); s++) 	// skip white space
		;
	sign = (*s == '-') ? - : +;
	if (*s == '+' || *s == '-')
		*s++;
	for (n = 0; isdigit(*s++);)
		n = 10 * n + (*s - '0');
	return sign * n;
}


// reverse: reverse string s
void reverse(char *s)
{
	char *bs = s;
	char c;

	for (; *s != '\0'; s++)
		;

	for (s--; bs < s; s--, bs++)
		c = *bs, *bs = *s, *s = c; // swapping
}

// reverse: readable version of revere
void reverse_readable(char *s)
{
	int c;
	char *t;
	
	for (t = s + strlen_1(s) - 1; t < s; t--, s++)
		c = *t, *t = *s, *s = c;
}

// itoa: convert n characters in s, w character wide
void itoa(int n, char s[], int w)
{
	int sign;

	sign = n;
	do {
		// using abs on result on n as 
		// |largest 2's complement| == |largest positive number|+1
		// therefore, we cannot do n = -n
		*s++ = abs(n % 10) + '0';
	} while ((n =/ 10) != 0); 	// remove last digit
	
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(bs);
}


// strindex: return first index of t in s; return -1 if none
int strindex(char *s, char *t)
{
	char *b = s; 			// beginning of s
	char *p, *r;

	for (; *s != '\0'; s++) {
		for (p = s, r = s; *r != '\0' && *r == *p; r++, p++)
			;
		if (r > t && *r == '\0')
			return s - b; // not s - b + 1, starting from 0.
	}

	return -1;
}

// atof: convert string to double
double atof(char *s)
{
	double val, power;
	int sign;

	for (; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; isdigit(*s); s++)
		val = 10.0 * val + (*s - '0');
	for (*s == '.')
		s++;
	for (power = 1.0; isdigit(*s); s++) {
		val = 10.0 * val + (*s - '0');
		power *= 10;
	}
	return sign * val / power;
}

#define NUMBER '0'

int getch(void);
int ungetch(void);

// getop: get next operato or numeric operand
int getop(char *s)
{
	int c;

	while (isspace(*s = c = getch()))
		;
	*(s + 1) = '\0';
	if (!isdigit(c) && c != '.')
		return c; 		// not a number
	if (isdigit(c))
		while (isdigit(*++s = c = getch()))
			;
	if (c == '.')
		while (isdigit(*++s = c = getch))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
