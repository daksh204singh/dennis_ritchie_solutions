// solution of k&r problem 3-4

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define abs(x) ((x < 0) ? -(x) : x)

void reverse(char s[]) {
	int i, j, temp;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
		temp = s[i], s[i] = s[j], s[j] = temp; // swapping
}


void itoa(int n, char s[]) {
	int i, sign;

	sign = n; // record sign
	i = 0;
	do {			// generate digits in reverse order
		s[i++] = (abs(n % 10)) + '0'; // get next digit
	} while((n /= 10) != 0); // delete it
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main() {
	char s[100];
	itoa(INT_MIN, s);
	puts(s);
}
