#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct page_frame {
    int age;
    int r_bit;
    int number;
} page_frame;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // Create page frames
    page_frame frames[n];

    for (int j = 0; j < n; j++){
        frames[j].number = 0;
        frames[j].age = 0;
        frames[j].r_bit = 0;
    }

    int previous_clock_cycle = 0;
    int hits = 0;
    int misses = 0;

    for (int j = 0; j < m; j++)
    {
        int i, a;
        scanf("%d %d", &i, &a);

        // Age frames for each clock cycle passed
        for (int k = 0; k < i - previous_clock_cycle; k++)
        {
            for (int l = 0; l < n; l++)
            {
                frames[l].age = (frames[l].age >> 1) || (frames[l].r_bit << 7);
                frames[l].r_bit = 0;
            }
        }
        
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

        if (hit)
            continue;
        printf("%d\n", 0);
        misses++;
        // On miss load page from the memory
        int min_idx = 0;
        int min_age = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            if (frames[k].number == -1)
            {
                // Found an empty page
                min_idx = k;
                break;
            }
            if (frames[k].age < min_age
                || (frames[k].age == min_age && frames[k].number < frames[min_idx].number))
            {
                min_age = frames[k].age;
                min_idx = k;
            }
        }
        frames[min_idx].age = 0;
        frames[min_idx].r_bit = 1;
        frames[min_idx].number = a;
        previous_clock_cycle = i;
    }

    printf("%.16f\n", ((double) hits) / misses);
    return 0;
}