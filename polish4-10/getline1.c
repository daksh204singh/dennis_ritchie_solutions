#include <stdio.h>

int getline1(char s[], int lim) {
	int i, c;

	i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i++] = '\0';
	return --i;
}