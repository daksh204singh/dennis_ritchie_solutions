#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline1(char line[], int maxline);
void reverse(char s[]);

main() {
	char line[MAXLINE]; /* current input line */

	while (getline1(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

/* getline1: takes input into s[], returns length */
int getline1(char s[], int lim) {
	int i, c;

	for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* reverse: reverses string s */
void reverse(char s[]) {
	int i, j, temp;

	i = 0;
	while(s[i] != '\0')		/* find the end of string */
		++i;
	--i;		/* back-off from '\0' */
	if(s[i] == '\n')
		--i; 		/* leave newline in place */		
	j = 0;
	while(j < i) {
		temp = s[i];
		s[i] = s[j];	/* swap s[i] and s[j] */
		s[j] = temp;
		--i;
		++j;
	}		
}