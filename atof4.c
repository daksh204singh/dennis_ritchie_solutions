// example of atof in chapter 4 of k&r; my attempt

#include <stdio.h>
#include <ctype.h>

// atof:	convert string s to double
double atof(char s[]) {
	int i, sign, flag;
	double n, frac;
	
	flag = 0;
	i = 0;
	sign = 1;
	n = 0;
	frac = 0.1;
	if(s[i] == '-')
		sign = -1;
	if(s[i] == '-' || s[i] == '+')
		i++; // skip sign
	for(; s[i] != '\0'; i++)
		if(s[i] == '.')
			flag = 1;
		else {
			if(flag) {
				n += (frac * (s[i] - '0'));
				frac /= 10;
			}
			else
				n = n * 10 + s[i] - '0';
		}

	return n*sign;
}

int main() {
	char s[] = "2.33344";
	printf("%f\n", atof(s));
}