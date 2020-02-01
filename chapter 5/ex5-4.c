#include <stdio.h>

// strend: returns if t occurs at the end of s. zero otherwise.
int strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	for (; *s; s++)
		;
	for (; *t; t++)
		;

	for (; *s == *t; s--, t--) {
		if (s == bs || t == bt)
			break;
	}

	if (*s == *t && t == bt && *s != '\0')
		return 1;
	return 0;
}

int main()
{
	printf("Res: %d\n", strend("daksh", "sh"));
	printf("Res: %d\n", strend("pratap", "sh"));

	return 0;
}
