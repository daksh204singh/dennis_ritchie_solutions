// example of pattern matching program like grep in chapter 4 of k&r

#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int getline1(char line[], int max); 
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search for

main() {
	char line[MAXLINE];
	int found = 0;

	while(getline1(line, MAXLINE) > 0)
		if(strindex(line, pattern) >= 0) {
			printf("%s\n", line);
			found++;
		}
	return found;
}

// getline1:	get line into s, return length
int getline1(char s[], int lim) {
	int i, c;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

// strindex:	return first index of t in s, return -1 if none
int strindex(char s[], char t[]) {
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k++, j++)
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
