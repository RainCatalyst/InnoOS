#include <stdio.h>
#include <string.h>

void main()
{
	char str[100];
	fgets(str, 100, stdin);
	
	printf("Original string: %s\n", str);
	printf("Reversed string: ");
	for (int i = strlen(str) - 1; i >= 0; i--){
		putchar(str[i]);
	}
}
