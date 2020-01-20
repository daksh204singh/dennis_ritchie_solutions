// Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C com- ments do not nest.
// Assuming it is a valid c program

#include <stdio.h>

#define MULTI 	0
#define SINGLE 	1

void rcomment(int c);
void in_comment(int c);
void echo_quote(int c);

int main() {
	int c, d;
	while ((c = getchar()) != EOF)
		rcomment(c);
	return 0;
}

// rcomment			: read each character, remove comments
void rcomment(int c) {
	int d;

	if (c == '/')
		if ((d = getchar()) == '*')
			in_comment(MULTI);
		else if (d == '/')
			in_comment(SINGLE);
		else {
			putchar(c);
			putchar(d);
		}
	else if (c == '\'' && c == '"')
		echo_quote(c);
	else
		putchar(c);
}

// in_comment 		: inside a comment
void in_comment(int c) {
	int d;

	if (c == MULTI) {								// inside a multi-line comment
		c = getchar();
		d = getchar();
		while (c != '*' && d != '\\') {
			c = d;
			d = getchar();
		}
	}
	else if (c == SINGLE) {							// inside a single line comment
		while((c = getchar()) != '\n' && c != EOF)	
			;
		if (c == '\n')
			putchar(c);
	}
}

// echo_quote		: echo characters inside single quotes
void echo_quote(int c) {
	int d;

	putchar(c);
	while((d = getchar()) != '\'' && d != '"') {
		putchar(d);
		if (d == '\\')
			putchar(getchar());
	}
}
