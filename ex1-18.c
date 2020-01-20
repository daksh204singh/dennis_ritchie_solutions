#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline1(char line[], int maxline);
int remove1(char s[]);

main() {
	char line[MAXLINE]; /* current input line */

	while(getline1(line, MAXLINE) > 0)
		if(remove1(line) > 0)
			printf("%s", line);
	
	return 0; 		
}

/* getline1: takes input into s, return length */
int getline1(char s[], int lim) {
	int i, c;

	for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* remove: removes occurances trailing blanks and tabs from s[] */
int remove1(char s[]) {
	int i;

	i = 0;
	while (s[i] != '\n') /* find new line character */
		++i;
	--i; /* back off from '\n' */
	while (i >= 0 && (s[i] == '\t' || s[i] == '\t'))
		--i;
	if(i > 0) { /* is it a nonblank line? */
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}