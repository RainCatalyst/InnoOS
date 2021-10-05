#include <stdio.h>
#include <stdlib.h>

void main()
{
    int N;
    
    // Prompt user for a number
    printf("Input N: ");
    scanf("%d", &N);
    printf("\n");

    // Check if the number is valid
    if (N < 1)
    {
        printf("N should be >= 1\n");
        return;  
    }
    
    // Allocate memory
    int* array = calloc(N, sizeof(int));
    
    // Fill the array
    for (int i = 0; i < N; i++)
    {
        array[i] = i;
    }
    
    // Print the array
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free the memory
    free(array);
}
