#include <stdio.h>
#include <float.h>
#include <limits.h>

void main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("%lu %lu %lu", sizeof(a), sizeof(b), sizeof(c));
}
