#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        fork();
        sleep(5);
    }
    
    return EXIT_SUCCESS;
}
