#include <stdio.h>
#include <string.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
}
