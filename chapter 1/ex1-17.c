#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define LONGLINE 80 /* size of long line */

int getline1(char line[], int maxline); /* function prototype of getline1 */

int main() {
    int i, c;
    char line[MAXLINE]; /* current input line */
    int len; /* current line length */

    while ( (len = getline1(line, MAXLINE)) > 0)
        if(len > LONGLINE)
            printf("%s", line);
    
    return 0;
}

/* getline1: read a line into s, return length */
int getline1(char s[], int lim) {
	int i, c;

	for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = '\n';
		++i;
	} 
	c  = '\0';
	return i;
}