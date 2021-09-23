#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct process_data
{
    // Initial data
    int arrival_time;
    int burst_time;
    // Computed data
    int remaining_burst_time;
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
    int count, quantum;
    scanf("%d %d", &count, &quantum);
    if (count < 1 || quantum < 1)
        return;
    process_data processes[count];

    // Input processes
    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    // Sort processes
    qsort(processes, count, sizeof(process_data), compare);

    // Calculate waiting times
    int timer = processes[0].arrival_time;
    int done = 0;
    while (!done)
    {
        done = 1;
        int last_timer = timer;
        for (int i = 0; i < count; i++)
        {
            // Process still has to be run
            if (processes[i].remaining_burst_time > 0)
            {
                done = 0;
                // Process has arrived
                if (timer >= processes[i].arrival_time)
                {
                    if (processes[i].remaining_burst_time > quantum)
                    {
                        timer += quantum;
                        processes[i].remaining_burst_time -= quantum;
                    }
                    else
                    {
                        timer += processes[i].remaining_burst_time;
                        processes[i].waiting_time = timer - processes[i].burst_time - processes[i].arrival_time;
                        processes[i].remaining_burst_time = 0;
                        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                        processes[i].completion_time = processes[i].arrival_time + processes[i].turnaround_time;
                    }
                }
            }
        }

        // No new processes arrived
        if (last_timer == timer)
        {
            // Advance the timer until the closest process
            int min_delta = INT_MAX;
            for (int i = 0; i < count; i++)
            {
                int delta = processes[i].arrival_time - timer;
                if (delta > 0 && delta < min_delta)
                {
                    min_delta = delta;
                }
            }
            timer += min_delta;
        }
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