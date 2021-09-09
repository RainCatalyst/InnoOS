#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_SIZE 100
#define MAX_ARGS_COUNT 10

int main(void)
{
    char command[MAX_COMMAND_SIZE];
    char* args[MAX_ARGS_COUNT];
    const char s = ' ';

    fgets(command, MAX_COMMAND_SIZE, stdin);
    
    int tokens = 0;
    char* token = strtok(command, s);
    char* cmd = strtok(NULL, s);
    while (token != NULL)
    {
        args[tokens] = token;
        tokens += 1;
    }

    execvp(cmd, args);
    return EXIT_SUCCESS;
}
