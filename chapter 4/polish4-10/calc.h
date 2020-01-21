#define NUMBER '0'		// signal that a number was found
#define MAXOP 100
#define REPEAT 'r'
#define NAME 'n'

void push(double);
double pop(void);
void clear(void);
int getop(char []);
int getch(void); 
void ungetch(int);