#include <stdio.h>

#define printArr(v, a, b)	{	int i; \
								for(i = a; i <= b; i++)	\
									printf("%d ", v[i]);\
								putchar('\n');}

void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right)
		return;
	swap(v, left, left+(right - left)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int a, int b) {
	int temp;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printArr(arr, 0, 9);
	qsort(arr, 0, 9);
	printArr(arr, 0, 9);
	return 0;
}
