#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

#define MAXLINE 100			// max size of input

int getline1(char line[], int limit);

int li = 0;					// input line index 
char line[MAXLINE];			// one input line

int getop(char s[]) {
	int i, c;

	if(line[li] == '\0') {
		if(getline1(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	}

	while((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';

	i = 0;
	if(islower(c)) {
		while(islower(s[++i] = c = line[li++]))
			;
		s[i] = '\0';
		li--;
		if(strlen(s) > 1)		// it is a name
			return NAME;
		else					// it may be a command
			return s[0];
	}

	if(!isdigit(c) && c != '.' && c != '-')
		return c;

	if(c == '-') {			// a negative number or a sign?
		if(isdigit(s[++i] = c = line[li++]) || c == '.')	// a number
			;
		else {
			li--;				// read a character extra
			return '-';
		}
	}

	if(isdigit(c))				// collect integer part
		while(isdigit(s[++i] = c = line[li++]))
			;

	if(c == '.')				// collect fraction part
		while(isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;
}