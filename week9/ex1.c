#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Struct for storing page frames
typedef struct page_frame
{
    int age;
    int r_bit;
    int number;
} page_frame;

int main()
{
    // Input table size and number of requests
    int n, m;
    scanf("%d %d", &n, &m);

    // Create page frames
    page_frame frames[n];

    for (int j = 0; j < n; j++)
    {
        frames[j].number = 0;
        frames[j].age = 0;
        frames[j].r_bit = 0;
    }

    int previous_clock_cycle = 0;
    int hits = 0;
    int misses = 0;

    for (int j = 0; j < m; j++)
    {
        // Get request clock cycle and page number
        int i, a;
        scanf("%d %d", &i, &a);
        if (j == 0)
            previous_clock_cycle = i;

        // Age frames if at least one clock cycle has passed since
        // previous request
        if (i != previous_clock_cycle)
        {
            for (int l = 0; l < n; l++)
            {
                frames[l].age = (frames[l].age >> 1) | (frames[l].r_bit << 7);
                frames[l].r_bit = 0;
            }
        }

        // Find out if we already have the requested page in the table
        int hit = 0;
        for (int k = 0; k < n; k++)
        {
            if (frames[k].number == a)
            {
                // Hit
                printf("%d\n", 1);
                hit = 1;
                hits++;
                frames[k].r_bit = 1;
                break;
            }
        }

        previous_clock_cycle = i;

        // We didnt find the requested page
        if (hit)
            continue;
        printf("%d\n", 0);
        misses++;

        // Find a frame with lowest age and page number
        int min_idx = 0;
        int min_age = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            if (frames[k].number == 0)
            {
                // Found an empty frame
                min_idx = k;
                break;
            }
            if (frames[k].age < min_age || (frames[k].age == min_age && frames[k].number < frames[min_idx].number))
            {
                min_age = frames[k].age;
                min_idx = k;
            }
        }

        // Replace the frame page with the new page
        frames[min_idx].age = 0;
        frames[min_idx].r_bit = 1;
        frames[min_idx].number = a;
    }

    // Compute the hit/miss ratio
    printf("%.16f\n", ((double)hits) / misses);
    return 0;
}