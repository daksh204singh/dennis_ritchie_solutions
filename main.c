#include <stdio.h>
#include <stdlib.h>			// for atof()

#define MAXOP 100 			// max length for operator and operand
#define NUMBER '0'			// signal that a number was found

int getop(char []);
void push(double);
double pop(); 

// reverse polish calculator
main() {
	int type; 
	double op2;
	char s[MAXOP]; 

	while((type = getop(s)) != EOF)
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				if((op2 = pop()) != 0.0);
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%d.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	return 0;
}