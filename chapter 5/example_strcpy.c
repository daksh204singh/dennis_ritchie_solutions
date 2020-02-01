#include <stdio.h>

// strcpy: copy t to s; array subscript version
void strcpy_1(char *s, char *t)
{
	int i;
	
	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

// strcpy: pointer version
void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((*s = *t) != '\0')
		s++, t++;
}

// strcpy: pointer version 2
void strcpy(char *s, char *t) 
{
	while ((*s++ = *t++) != '\0')
		;
}

// strcpy: pointer version 3
// comparison with '\0' is redundant as integer value of
// '\0' is 0
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}
