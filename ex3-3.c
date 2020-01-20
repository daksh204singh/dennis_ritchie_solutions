// solutuion of k&r problem 3-3

#include <stdio.h>
#include <ctype.h>

// expand:	expand shorthand notation in s1 into string s2
void expand(char s1[], char s2[]) {
	char c;
	int i, j;

	i = j = 0;
	while((c = s1[i++]) != '\0') // fetch a character from s1
		if((c = s1[i]) == '-' && s[i + 1] >= c) {
			i++;
			while(c < s[i])
				s2[j++] = c++;
		} else 
			s2[j++] = c;
	s2[j] = '\0';
}