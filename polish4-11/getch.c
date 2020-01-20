#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

static int buf[BUFSIZE];		// buffer for ungetch
static int bufp = 0;			// next free position in buf

int getch(void) { 		// get a (possibly pushed back) character
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// void ungetch(int c) {	// push character back on input
// 	if(bufp >= BUFSIZE)
// 		printf("ungetch: too many characters\n");
// 	else
// 		buf[bufp++] = c;
// }

void ungets(char s[]) {
	int len = strlen(s);
	while(len > 0)
		ungetch(s[--len]);
}