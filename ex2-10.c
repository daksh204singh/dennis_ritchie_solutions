// solution of dennis ritchie problem 2-10

#include <stdio.h>

// lower: convert c to lower case : ASCII only
int lower(int c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
	printf("%c\n", lower('B'));
}