#include <stdio.h>
#include <string.h>

// reverse:	reverses s
void reverse(char s[]) {
	int i, j, temp;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
		temp = s[i], s[i] = s[j], s[j] = temp; // swapping
}

// itoa: converts n to characters in s
void itoa(int n, char s[]) {
	int i, sign; 

	if((sign = n)  < 0) // record sign
		n = -n;			// make n positive, as / and % operations are machine-dependent for negative operands
	i = 0; 
	do {
		s[i++] = n % 10 + '0'; // get next digit
	} while((n /= 10) > 0); // delete it
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main() {
	int i = 10;
	char s[3];

	itoa(i, s);
	printf("%s\n", s);
}