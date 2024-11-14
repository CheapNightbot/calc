#include "calc.h"
#include <stdio.h>

int main()
{
    char input[100];

    while (1)
    {
        printf(BGRN ">>> " reset);
        fgets(input, sizeof(input), stdin);
        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is empty or contains only whitespace
        if (input[0] == '\0' || strspn(input, " \t\n") == strlen(input))
        {
            // Prompt again ~
            continue;
        }

        // Exit the program if user types "exit" or "quit"
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0)
        {
            break;
        }
        // Clear the terminal if user types "clear"
        else if (strcmp(input, "clear") == 0 || strcmp(input, "clean") == 0)
        {
            system("clear");
        }
        else if (strcmp(input, "help") == 0)
        {
            show_help();
        }
        else if (evaluate_expression(input))
        {
            perform_calculation();
        }
    }
    return 0;
}
