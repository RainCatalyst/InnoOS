#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct thread_args
{
    int thread_num;
} thread_args;

thread_args* create_thread_args(int thread_num)
{
    thread_args* args = (thread_args*) malloc(sizeof(thread_args));
    args->thread_num = thread_num;
    return args;
} 

void* thread_function(void* t_args)
{
    thread_args* args = (thread_args* ) t_args;
    printf("Hello from thread number %d\n", args->thread_num);
}

void main()
{ 
    const int N = 10;
    pthread_t tid;
    // Create threads
    for (int i = 0; i < N; i++)
    {
        thread_args* t_args = create_thread_args(i);
        pthread_create(&tid, NULL, thread_function, (void* ) t_args);
        // Proposed fix to execute threads sequentially
        pthread_join(tid, NULL);
    }
    // Wait for all threads to exit
    pthread_exit(NULL);
}


