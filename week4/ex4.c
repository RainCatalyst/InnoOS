#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_SIZE 100
#define MAX_ARGS_COUNT 10

int tokenize(char str[], char* tokens[], char* s)
{
    int token_count = 0;
    char* token = strtok(str, s);
    while (token != NULL)
    {
        tokens[token_count] = token;
        
        token = strtok(NULL, s);
        token_count++;
    }
    return token_count;
}

int main(void)
{
    char input[MAX_COMMAND_SIZE];
    char* args[MAX_ARGS_COUNT] = {NULL};

    fgets(input, MAX_COMMAND_SIZE, stdin);

    int token_count = tokenize(input, args, " \n");
    
    pid_t PID = fork();
    if (PID == 0)
    {
        execvp(args[0], args);
    }else{
        printf("Running command in a child process (PID=%d)\n\n", PID);
        wait(NULL);
        printf("\nDone.\n");
    }
    return EXIT_SUCCESS;
}
