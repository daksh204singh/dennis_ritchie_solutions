/*
 * Contains code examples of storage allocator in chapter 5
 */

#include <stdio.h>

#define ALLOCSIZE 1000 	/* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char * alloc(int n) 	// return pointer to n characters
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
		allocp += n;
		return allocp - n; // old p
	}
}

void afree(char *p) 	// free storage pointed to by p
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
