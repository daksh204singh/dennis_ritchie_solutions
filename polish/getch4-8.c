#include <stdio.h>

int buf = 0;			// single character buffer
int filled = 0;			// 1 for filled, 0 for free

int getch(void) {
	return (filled != 0) ?  filled = 0, buf : getchar();
}

void ungetch(int c) {
	if(filled != 0)
		printf("ungetch: too many characters\n");
	else {
		buf = c;
		filled = 1;
	} 
}