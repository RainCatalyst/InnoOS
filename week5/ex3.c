#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

const float UPDATE_INTERVAL = 1.0;
const int MAX_BUFFER_SIZE = 5;

int producer_awake = 1;
int consumer_awake = 0;
int buffer_size = 0;

// Consume buffer when awake
void* thread_consumer(void* t_args)
{
    printf("Consumer thread started.\n");
    while (1)
    {
        if (consumer_awake)
        {
            if (buffer_size > 0)
            {
                buffer_size--;
                if (buffer_size <= 0)
                {
                    consumer_awake = 0;
                    producer_awake = 1;
                }
            }
        }
    }
}

// Fill up buffer when awake
void* thread_producer(void* t_args)
{
    printf("Producer thread started.\n");
    while (1)
    {
        if (producer_awake)
        {
            if (buffer_size < MAX_BUFFER_SIZE)
            {
                buffer_size++;
                if (buffer_size >= MAX_BUFFER_SIZE)
                {
                    producer_awake = 0;
                    consumer_awake = 1;
                }
            }
        }
    }
}

// Log the status of other threads
void* thread_logger(void* t_args)
{
    while (1)
    {
        printf("Buffer size: %d, Producer awake: %d, ConsumerAwake: %d\n", buffer_size, producer_awake, consumer_awake);
        sleep(UPDATE_INTERVAL);
    }
}

void main()
{
    pthread_t tid;
    // Create all threads
    pthread_create(&tid, NULL, thread_producer, NULL);   
    pthread_create(&tid, NULL, thread_consumer, NULL);
    pthread_create(&tid, NULL, thread_logger, NULL);
    pthread_exit(NULL);
}