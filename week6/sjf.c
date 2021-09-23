#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int delta = pd1->arrival_time - pd2->arrival_time;
    if (delta == 0)
        return pd1->burst_time - pd2->burst_time;
    return delta;
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
        processes[i].completion_time = -1;
    }

    // Sort processes
    qsort(processes, count, sizeof(process_data), compare);

    // Calculate waiting times
    int k = 0;
    int previous_k[count];
    previous_k[0] = 0;
    int last_k = 0;
    for (int i = 0; i < count; i++)
    {
        if (k > 0)
        {
            int min_burst = INT_MAX;
            int new_k = -1;
            for (int j = 0; j < count; j++)
            {
                if (processes[j].arrival_time <= processes[last_k].completion_time && processes[j].completion_time == -1)
                {
                    if (processes[j].burst_time < min_burst)
                    {
                        min_burst = processes[j].burst_time;
                        new_k = j;
                    }
                }
            }
            previous_k[k] = new_k;
            last_k = new_k;
        }
        int total_burst = 0;
        for (int j = 0; j < k; j++)
        {
            total_burst += processes[previous_k[j]].burst_time;
        }
        processes[last_k].waiting_time = processes[0].arrival_time + total_burst - processes[last_k].arrival_time;
        processes[last_k].turnaround_time = processes[last_k].waiting_time + processes[last_k].burst_time;
        processes[last_k].completion_time = processes[last_k].arrival_time + processes[last_k].turnaround_time;
        k++;
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