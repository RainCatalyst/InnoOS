#include <string.h>
#include <memory.h>
#include <linux/input.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    const char *event_states[] = { "RELEASE",
                                   "PRESS",
                                   "HOLD" };

    // Initialize the input structure
    struct input_event event;

    // Open files
    FILE *input = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    FILE *result = fopen("./ex2.txt", "w+");

    // Check if we can open the input file
    if (input == NULL)
    {
        printf("Unable to open the input");
        return 0;
    }

    // Process events
    while (1)
    {
        // Read an event into the event structure
        fread(&event, sizeof(struct input_event), 1, input);

        if (event.type == EV_KEY)
        {
            fprintf(result, "%s [%04x] (%d)\n", event_states[event.value], event.code, event.code);
            fflush(result);
        }
    }

    fclose(input);
    fclose(result);
}