#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

// store_char:		store char in s at position i
int store_char(char s[], int i, int c) {
	if(i < MAXOP - 1) {
		s[i] = c;
		return 1;
	}
	else {
		printf("error: too many characters\n");
		return 0;
	}
}

// getop:	get next operator or numeric operand
int getop(char s[]) {
	int i, c;
	static int lastc = 0;

	if(lastc == 0)
		c = getch();
	else {
		c = lastc;
		lastc = 0;
	}

	while((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	i = 0;

	if(islower(c)) {
		while(islower(c = getch())) {
			if(store_char(s, ++i, c))
				;
			else 
				return REPEAT;
		}
		s[++i] = '\0';
		if(c != EOF)			// read 1 character too far
			lastc = c;			// put it back into input
		
		if(strlen(s) > 1)		// > 1 char, it is a NAME
			return NAME;
		else					// return the single character, it could be a command
			return s[0];
	}
	
	if(!isdigit(c) && c != '-' && c != '.')
		return c;

	if(c == '-') {
		if(isdigit(c = getch()) || c == '.')
			store_char(s, ++i, c);
		else {
			if(c != EOF)
				lastc = c;
			return '-';
		}
	}

	if(isdigit(c)) {		// collect integer part
		while(isdigit(c = getch())) {
			if(store_char(s, ++i, c))
				;
			else 
				return REPEAT;
		}
	}
	if(c == '.') {			// collect fraction part
		if(store_char(s, ++i, c))
			while(isdigit(c = getch())) {	
				if(store_char(s, ++i, c))
					;
				else
					return REPEAT;
			}
		else
			return REPEAT;
	}
	s[++i] = '\0';
	if(c != EOF)
		lastc = c;
	return NUMBER;
}