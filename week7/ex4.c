#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int* customRealloc(int* ptr, size_t size_old, size_t size_new)
{
    // Allocate new memory
    int* new_ptr = malloc(size_new);
    
    // Copy bytes to a newly allocated memory
    memcpy(new_ptr, ptr, size_new > size_old ? size_new : size_old);
    
    // Free previosly allocated memory
    free(ptr);
    
    return new_ptr;
}

int main()
{
    const int N = 5;
    const int M = N + 5;
    // Allocate memory
    int *array = calloc(N, sizeof(int));

    // Fill the array
    for (int i = 0; i < N; i++)
    {
        array[i] = i;
    }

    // Print the array
    printf("Original array.\n");
    for (int i = 0; i < N; i++)
    {
        printf("array[%d]=%d\n", i, array[i]);
    }
    printf("\n");

    // Reallocate memory
    array = customRealloc(array, N * sizeof(int), M * sizeof(int));

    printf("Reallocated array.\n");
    for (int i = 0; i < M; i++)
    {
        printf("array[%d]=%d\n", i, array[i]);
    }
    printf("\n");
}