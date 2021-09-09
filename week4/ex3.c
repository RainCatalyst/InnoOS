#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    char command[MAX_SIZE];
    fgets(command, MAX_SIZE, stdin);
    system(command);
    return EXIT_SUCCESS;
}
