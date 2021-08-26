#include <stdio.h>
#include <string.h>

void main()
{
	int n;
	scanf("%d", &n);
	putchar('\n');
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			putchar(' ');
		}
		for (int j = 0; j < i * 2 + 1; j++){
			putchar('*');
		}
		for (int j = 0; j < n - i - 1; j++){
			putchar(' ');
		}
		putchar('\n');
	}
}
