// Write the function htoi(s),which converts a string of hexa- decimal digits (including an optional 0x 0X) into its equivalent integer value. The allowable digits are 0 through 9,a through f,and A through F

#include <stdio.h>

enum flag { NO, YES };

int htoi(char s[], unsigned int lim) {
	int i, n, inhex, hexdigit;
	enum flag inhex;

	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	n = 0;
	inhex = YES;									// Asumming the string is a valid hexadecimal number
	for (; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else 
			inhex = NO								// Not a valid hexadecial number
		n = 16 * n + hexdigit;
	}

	return n;
}