// Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This pro- gram is hard if you do it in full generality.)
// This program only checks for unbalanced parentheses, brackets and braces.

#include <stdio.h>

#define MULTI	0
#define SINGLE 	1

int brace, brack, paren;

void in_comment(int c);
void en_quote(int c);
void search(int c);

int main() {
	int c;
	extern int brace, brack, paren;
	brace = brack = paren = 0;

	while ((c = getchar()) != EOF)
		if (c == '/') {
			if ((c = getchar()) == '*')
				in_comment(MULTI);
			else if (c == '/')
				in_comment(SINGLE);
		} else if (c == '\'' || c == '"')
			en_quote(c);
		else 
			search(c);

	if (brace != 0)
		printf("Unbalanced braces\n");
	if (brack != 0)
		printf("Unbalanced brackets\n");
	if (paren != 0)
		printf("Unbalanced parentheses\n");

	return 0;
}

// in_comment	: inside a valid comment
void in_comment(int c) {
	int d;

	if (c == MULTI) {
		c = getchar();
		d = getchar();
		while (c != '*' && d != '/') {
			c = d;
			d = getchar();
		}
	}
	else if (c == SINGLE)
		while ((c = getchar()) != '\n' && c != EOF)
			;
}

// en_quote 	: iniside quote
void en_quote(int c) {
	int d;

	while ((d = getchar()) != c) 
		if (d == '\\')
			getchar();
}

// search		: search for unbalanced braces, brackets, parenthesis
void search(int c) {
	extern int brace, brack, paren;

	if (c == '{')
		++brace;
	else if (c == '[')
		++brack;
	else if (c == '(')
		++paren;
	else if (c == '}')
		--brace;
	else if (c == ']')
		--brack;
	else if (c == ')')
		--paren;
}