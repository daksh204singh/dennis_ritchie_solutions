// shell sort implementation

#include <stdio.h>

// shellsort:	implementation of shell sort algorithm
void shellsort(int v[], int n) {
	int temp, gap, i, j;

	for(gap = n/2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				temp = v[j], v[j] = v[j + gap], v[j + gap] = temp;	// swapping
}

// print_array:	print array arr of length n
void print_array(int v[], int n) {
	int i;

	for(i = 0; i < n; i++)
		printf("%6d ", v[i]);
	puts("");
}

int main() {
	int arr[] = {7, 6, 8, 9, 3, 2, 10, 5, 1};
	int len = 9;

	print_array(arr, len);
	shellsort(arr, len);
	print_array(arr, len);
}