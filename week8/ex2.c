#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    const int MB = 1024 * 1024;
    const int ITERATIONS = 10;

    // Define a pointer and memory time
    char* memory;
    int size = 1024 * MB;

    // Allocate and dellocate memory repeatedly
    for (int i = 0; i < ITERATIONS; i++)
    {
        memory = malloc(size);
        memset(memory, 0, size);
        printf("[%d/%d] Allocated %d MB.\n", i + 1, ITERATIONS, size / MB);
        sleep(1);
        free(memory);
        printf("[%d/%d] Freed %d MB.\n", i + 1, ITERATIONS, size / MB);
    }
}