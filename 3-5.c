// solution of k&r problem 3-5
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define abs(x) ((x < 0) ? -(x) : x)
#define tosymb(x) ((x > 9) ? (x - 10 + 'a') : (x + '0'))

// itob:	convert n to characters in s
void itob(int n, char s[], int b) {
	int sign, i;
	void reverse(char c[]);
	i = 0;
	sign = n; // record sign
	do {				// generate digits in reverse order
		s[i++] = (char)tosymb(abs(n % b)); // get next digit
	} while((n /= b) != 0); // delete it
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

// reverse:	reverse string s in place
// in place means, that the function will reverse string without using extra storage
void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; // swapping
}

int main() {
	char s[200];
	itob(17, s, 18);
	puts(s);
}