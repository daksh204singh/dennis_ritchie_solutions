
#include <stdio.h>
// Defining macro swap assuming the call of swap will not contain a swap will not be called with the 
#define swap(t, x, y) { t _z;	\
			_z = y;	\
			y = x; 	\
			x = _z;	}
int main() {
	int a = 10, b = 11;
	swap(int, a, b)
	printf("a: %d\nb: %d\n", a, b);
	return 0;
}
