// Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.


#include <stdio.h>

#define MAXCOL	10							// maximum column of input
#define TABINC	8							// tab increment size

char line[MAXCOL];

int exptab(int pos);
int newpos(int pos);
int findblnk(int pos);
void printl(int pos);

int main() {
	int c, pos;

	pos = 0;
	while ((c = getchar()) != EOF) {
		line[pos] = (char)c;
		if (c == '\t')
			pos = exptab(pos);
		else if (c == '\n') {
			printl(pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}

	return 0;
}


// printl	:	prints line until column pos
void printl(int pos) {
	int i;
	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	if (pos > 0)
		putchar('\n');
}

// exptab	: expands tab into blanks
int exptab(int pos) {
	line[pos] = ' ';
	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';
	if (pos >= MAXCOL) {					// There is no space left
		printl(pos);
		return 0;							// reset pos
	}
	else
		return pos;							// There is space left
}

// findbl	: find blank's postion
int findblnk(int pos) {
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)
		return MAXCOL;
	else
		return pos + 1;
}

// newpos 	: rearranges line to new position
int newpos(int pos) {
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)						
		return 0;							// reset position
	else {
		// rearrange line
		i = 0;
		for (j = pos; j < MAXCOL; ++j) {
			line[i] = line[j];
			++i;
		}
		return i;							// new position in line
	}
}