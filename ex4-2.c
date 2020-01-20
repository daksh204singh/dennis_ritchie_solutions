// solution of problem 4 in k&r

#include <stdio.h>
#include <ctype.h>
#include <math.h>

// atof:	convert string s to double
double atof(char s[]) {
	double val, power;
	int i, sign, exp;

	for(i = 0; s[i] == ' '; i++) // skip white spaces
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + s[i] - '0';
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + s[i] - '0';
		power *= 10.0;
	}
	val = sign * val / power;

	if(s[i] == 'e' || s[i] == 'E') {
		sign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')	// skip sign
			i++;
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + s[i] - '0';
		if(sign == 1)					// positive exponent
			while (exp-- > 0)
				val *= 10;
		else 							// negative exponent
			while(exp-- > 0)
				val /= 10; 
	}

	return val;

}

int main() {
	char s[] = "123.45e-1";
	printf("%f\n", atof(s));
}