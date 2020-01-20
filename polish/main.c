#include <stdio.h>
#include <stdlib.h>		// for atof()
#include <math.h>		// for fmod, sin, exp, pow, etc
#include <string.h>		// for strcmp
#include "calc.h"

void mathfunc(char []);

main() {
	int type, i, var = 0;
	double op1, op2, v;
	char s[MAXOP];
	double variable[26];

	for(i = 0; i < 26; i++)
		variable[i] = 0.0;
	while((type = getop(s))) {
		printf("type: %d\n", type);
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfunc(s);
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
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else 
					printf("error: divide by zero\n");
				break;
			case '%':
				if((op2 = pop()) != 0.0)
					push(fmod(pop(), op2));
				else 
					printf("error: zero divisor\n");
				break;
			case '=':
				pop();		// remove the value of variable from the stack which was pushed earlier
				if(var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else 
					printf("error: no variable name\n");
				break;
			case '?':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's':
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case 'c':
				clear();
				break;
			case REPEAT:
				printf("error: invalid input\n");
				break;
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if(type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if(type == 'v')
					push(v);
				else
					printf("error: unknown command %s\n", s);
				break;
		}
		var = type;
	}
	return 0;
}

void mathfunc(char s[]) {
	double op2;

	if(!strcmp(s, "sin"))
		push(sin(pop()));
	else if(!strcmp(s, "cos"))
		push(cos(pop()));
	else if(!strcmp(s, "exp"))
		push(exp(pop()));
	 else if(!strcmp(s, "pow")) {
		op2 = pop();
		push(pow(pop(), op2));
	} else
		printf("error: operation not supported %s\n", s);
}