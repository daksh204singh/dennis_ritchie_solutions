//  Write a loop equivalent to the for loop above without using &.&. or ||. 

#include <stdio.h>

typedef enum loop { NO, YES } flag;

int getline1(char s[], int lim) {
	int c, i;
	flag okloop = YES;
	
	while(okloop == YES) {
		if(i >= lim - 1) 					// value out of range
			okloop = NO;
		else if( (c = getchar()) == '\n')	// if the new character read is a new line
			okloop = NO;
		else if(c == EOF)					// reached the end-of-file
			okloop = NO;
		else {
			s[i] = c;						// store the character read in the array
			i++; 
		}
	}
 
	return i;	
}