#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n = 5;
    pid_t CHILD_PID = fork();
    
    if (CHILD_PID == 0)
    {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }else{
        printf("Hello from parent [%d - %d]\n", getpid(), n);
        wait(NULL);
    }
    return EXIT_SUCCESS;
}
