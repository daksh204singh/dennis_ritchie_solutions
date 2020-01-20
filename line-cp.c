#include <stdio.h>

#define MAXLENGTH 1000 /* maximum input line size */

int getline1(char line[], int length); /* function prototype of getline1 */
void copy(char to[], char from[]); /* function prototype of copy */

int main() {
    int c, i;
    int max; /* maximum length seen so far */
    int len; /* current line length */
    char line[MAXLENGTH]; /* current input line */
    char longest[MAXLENGTH]; /* longest line saved here */

    max = 0;
    while((len = getline1(line, MAXLENGTH)) > 0)
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

/* getline1: read a line into s, return length */
int getline1(char s[], int lim) {
    int i, c;

    for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

/* copy: copies 'from' into 'to' ; assuming 'to' is be big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}