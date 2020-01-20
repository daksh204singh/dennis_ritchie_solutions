// solution of k&r problem ex3-2

#include <stdio.h>

// escape:	convert newline and tab into visible characters
//			while copying string t to s
void escape(char s[], char t[]) {
	int i, j;

	for(i = j = 0; t[i] != '\0'; i++, j++) {
		switch(t[i]) {
			case '\n': s[j++] = '\\'; s[j] = 'n'; break;
			case '\t': s[j++] = '\\'; s[j] = 't'; break;
			default: s[j] = t[i]; break;
		}
	}
	s[j] = '\0';
}

// unescape:	convert escape sequences into real charaacters
// 				while copying string t to s 
void unescape(char s[], char t[]) {
	int i, j;

	for(i = j = 0; t[i] != '\0'; i++, j++)
		if(t[i] != '\\')
			s[j] = t[i];
		else 
			switch(t[++i]) {
				case 'n':
					t[j] = '\n';
					break;
				case 't':
					t[j] = '\t';
					break;
				default:
					t[j++] = '\\';
					t[j] = s[i];
			}
	s[j] = '\0';
}

int main() {
	return 0;                                                                                                                                                                                                            
}