#include <stdio.h>

/*
 * strcmp: return < 0 if s<t, if s==t, >0 if s>t
 * The value is obtained by subtracting the characters at the
 * first position where s and t disagree
 */
int strcmp_1(char *s, char *t)
{
	int i;
	
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] = '\0')
			return 0;
	return s[i] - t[i];
}

// strcmp_2: pointer version
int strcmp_2(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
