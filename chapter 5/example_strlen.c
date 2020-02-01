#include <stdio.h>

/* strlen return length of a string */
int strlen_1(char s[])
{
	/*
	 * Since s is a pointer, it is perfectly legal to increment it
	 * since it merely increments the strlen's private copy.
	 */
	int n;
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

// another version of strlen
int strlen_2(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}

int main() 
{
	printf("length: %d\n", strlen_1("daksh"));
	return 0;
}
