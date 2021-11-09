#include <string.h>
#include <memory.h>
#include <linux/input.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    // Initialize input structure
    struct input_event event;

    // Open the input and result files
    FILE *input = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    FILE *result = fopen("./ex3.txt", "w+");

    // Check if we can open the input file
    if (input == NULL)
    {
        printf("Unable to open the input");
        return 0;
    }

    // Set up an array for button events
    short pressed[256] = {0};

    // Process events
    while (1)
    {
        // Read event into the event structure
        fread(&event, sizeof(struct input_event), 1, input);

        if (event.type == EV_KEY)
        {
            // Nonzero value means that the event is either pressed or held (2)
            pressed[event.code] = event.value % 2;

            if (pressed[KEY_P] && pressed[KEY_E]) {
                printf("I passed the Exam!\n");
                fprintf(result, "I passed the Exam!\n");
            }
            if (pressed[KEY_C] && pressed[KEY_A] && pressed[KEY_P]) {
                printf("Get some cappucino!\n");
                fprintf(result, "Get some cappucino!\n");
            }
            if (pressed[KEY_X] && pressed[KEY_Y] && pressed[KEY_Z]) {
                printf("You've just pressed the most uncomfortable shortcut, congrats!\n");
                fprintf(result, "You've just pressed the most uncomfortable shortcut, congrats!\n");
            }
            fflush(result);
        }
    }

    fclose(input);
    fclose(result);
}