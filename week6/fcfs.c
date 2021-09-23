#include <stdio.h>
#include <stdlib.h>

typedef struct process_data
{
    // Initial data
    int arrival_time;
    int burst_time;
    // Computed data
    int waiting_time;
    int turnaround_time;
    int completion_time;
} process_data;

int compare(const void *s1, const void *s2)
{
    process_data *pd1 = (process_data *)s1;
    process_data *pd2 = (process_data *)s2;
    return pd1->arrival_time - pd2->arrival_time;
}

void main()
{
    int count;
    scanf("%d", &count);
    process_data processes[count];

    // Input processes
    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Sort processes
    qsort(processes, count, sizeof(process_data), compare);

    // Calculate waiting times
    for (int i = 0; i < count; i++)
    {
        int total_burst = 0;
        for (int j = 0; j < i; j++)
        {
            total_burst += processes[j].burst_time;
        }
        processes[i].waiting_time = processes[0].arrival_time + total_burst - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].completion_time = processes[i].arrival_time + processes[i].turnaround_time;
    }

    // Compute average values
    float average_turnaround = 0;
    for (int i = 0; i < count; i++)
        average_turnaround += processes[i].turnaround_time;
    average_turnaround /= count;

    float average_waiting_time = 0;
    for (int i = 0; i < count; i++)
        average_waiting_time += processes[i].waiting_time;
    average_waiting_time /= count;

    // Print the results
    printf("------------\nN.  AT. BT. WT. CT. TAT.\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d.  %d   %d   %d   %d   %d\n",
               i, processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].completion_time,
               processes[i].turnaround_time);
    }
    printf("Avg. WT - %f\nAvg. TAT - %f\n", average_waiting_time, average_turnaround);
}