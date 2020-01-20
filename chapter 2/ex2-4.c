// Write an alternate version of squeeze (s 1,s2) that deletes
// each character in s 1 that matches any character in the string s2.

#include <stdio.h>

/**
 *
 * squeeze : delete each char in s1 which is in s2 
 *
 */

void squeeze(char s1[], char s2[]) {
	int i, j, k;

	for(i = k = 0; s1[i] != '\0'; i++) {
		for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if(s2[j] == '\0')									// end of string, no match found
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main() {
	char s2[] = "daksh";
	char s1[] = "dakshpratapsingh";
	squeeze(s1, s2);
	printf("%s\n", s1);
}