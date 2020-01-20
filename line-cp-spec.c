#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int getline1(void); /* function prototype of getline1 */
void copy(void); /* function prototype of copy */

main() {
    int len;
    extern int max; /* maximum length seen so far */
    extern char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while((len = getline1()) > 0)
        if(len > max) {
            max = len;
            copy();
        }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

/* getline1: specialized version */
int getline1(void) {
    int i, c;
    extern char line[];

    for(i = 0; i<MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    
    return i;
}

/* copy: specialized version */
void copy(void) {
    int i;
    extern char line[], longest[];
    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}