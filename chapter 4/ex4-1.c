// solution of k&r problem 4-1

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000	// maximum input line length

int getline1(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main() {
	char line[MAXLINE];	// input line
	int found = 0;

	while(getline1(line, MAXLINE) > 0)
		if(strrindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}

	return found;
}

// getline1:	get line into s, return max length
int getline1(char s[], int lim) {
	int i, c;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;		
}

// strrindex:	return index of t in s from the right
int strrindex(char s[], char t[]) {
	int i, j, k;

	for(i = strlen(s) - strlen(t); i >= 0; i--) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0') {
			printf("%d\n", i);
			return i;
		}
	}

	return -1;	// no match found
}