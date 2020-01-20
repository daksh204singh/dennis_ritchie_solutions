// solution of k&r problem 3-6

#include <stdio.h>
#include <string.h>

#define abs(x) ((x < 0) ? -(x) : (x))	// calculates absolute value of x

// itoa: convert n to characters in s, w characters wide
void itoa(int n, char s[], int w) {
	int sign, i;
	void reverse(char s[]);

	sign = n;	// record sign
	i = 0;
	do {		// get digits in reverse order
		s[i++] = abs(n % 10) + '0';	// get next digit
	} while((n /= 10) != 0); // delete it
	if(sign < 0)
		s[i++] = '-';
	while(i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; // swapping
}

int main() {
	char s[200];
	itoa(10, s, 3);
	puts(s);
}