// solution of dennis and ritchie problem 3-1.

#include <stdio.h>
#include <time.h>

// slow_binarysearch: implementation of binary search algorithm using 2 tests inside loop
// x is the element position to be determined, v is the array and n is the length of the array
int slow_binarysearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = low + (high - low)/2; // to avoid overflow
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else // match found
			return mid;
	}
	return -1; // no match
}

// fast_binarysearch: implementation of binary search using 1 test inside loop
// x is the element whose position is to be determined, v is the array and n is the length of the array
int fast_binarysearch(int x, int v[], int n) {
	int low, high, mid; 

	low = 0;
	high = n - 1;
	mid = low + (high - low)/2; // to avoid overflow
	while(low <= high && x != v[mid]) {
		if(x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = low + (high - low)/2;
	}
	if(x == v[mid])
		return mid; // found match
	else 
		return -1; // no match
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
				21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
				41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
				61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
				81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
				};
	int length = 100;
	clock_t start, end;

	start = clock();
	printf("%d\n", slow_binarysearch(100, arr, length));
	end = clock();
	printf("%f\n", ((double)end - start)/CLOCKS_PER_SEC);

	start = clock();
	printf("%d\n", fast_binarysearch(100, arr, length));
	end = clock(); 
	printf("%f\n", ((double)end - start)/CLOCKS_PER_SEC);

	return 0;
}