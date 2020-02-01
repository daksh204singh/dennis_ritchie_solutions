#include <stdio.h>

// strncpy_1: 	copy at most n characters of t to s; return s; Pad with '\0''s if ct
// 		has fewer than n character; return s.
char *strncpy(char *s, char *t, size_t n)
{
	for (; n > 0; n--)
		(*t) ? (*s++ = *t++) : (*s++ = '\0');
	return s;
}

// strncat_1: 	cocatenate at most n characters t to s, terminate s with '\0';
// 		return s.
char *strncat(char *s, char *t, size_t n)
{
	for (; *s != '\0'; s++)
		;

	for (; n > 0; n--)
		(*t) ? (*s++ = *t++) : (*s++ = '\0'); 

	return s;
}

// strncmp_1: 	compare at most n characters of t to s; 
// 		return < 0, if s < t
// 		return = 0, if s == t
// 		return > 0, if s > t
int strncmp(char *s, char *t, size_t n)
{
	for (; *s == *t && n > 0 && *t != '\0' && *s != '\0'; s++, t++, n--)
		;
	return *s - *t;
}
