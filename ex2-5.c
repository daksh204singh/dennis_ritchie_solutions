/**
 *
 * 
 *
 */
#include <stdio.h>
int any(char s1[], char s2[]) {
	int i, j;

	for(i = 0; s1[i] != '\0'; i++)
		for(j = 0; s2[j] != '\0'; j++)
			if(s2[j] == s1[i])			// match found ?
				return i;				// return first match
	return -1;							// no match
}

int main() {
	char s1[] = "dakshpratapsingh";
	char s2[] = "p";

	printf("%d\n", any(s1, s2));
	return 0;
}