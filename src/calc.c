#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define BGRN "\e[1;32m"
#define reset "\e[0m"

typedef struct
{
    int x;
    int y;
    char oper;
} expression;

// Function declarations
int addition(int x, int y);
double division(int x, int y);
bool evaluate_expression(char *expr_str);
int multiplication(int x, int y);
int subtraction(int x, int y);

// Global expression struct
expression expr;

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
        else if (strcmp(input, "clear") == 0)
        {
            system("clear");
        }
        else if (evaluate_expression(input))
        {
            switch (expr.oper)
            {
            case '+':
                printf("%d\n", addition(expr.x, expr.y));
                break;
            case '-':
                printf("%d\n", subtraction(expr.x, expr.y));
                break;
            case '*':
                printf("%d\n", multiplication(expr.x, expr.y));
                break;
            case '/':
            {
                double result = division(expr.x, expr.y);
                if (!isnan(result))
                    printf("%.2f\n", result);
                break;
            }
            case '_':
            {
                double result = division(expr.x, expr.y);
                if (!isnan(result))
                    printf("%d\n", (int)round(result));
                break;
            }
            default:
                printf("Error: Unknown operator '%c'!\n", expr.oper);
                break;
            }
        }
    }
    return 0;
}

bool evaluate_expression(char *expr_str)
{
    regex_t regex;
    const char *pattern = "^[ \\t]*(-?[0-9]+)[ \\t]*([+*/-]{1,2})[ \\t]*(-?[0-9]+)?[ \\t]*$";

    // Compile the regex pattern
    int compile_status = regcomp(&regex, pattern, REG_EXTENDED);
    if (compile_status != 0)
    {
        // For debugging ~!!!
        printf("Could not compile regex. Error code: %d\n", compile_status);
        return false;
    }

    // Match the input with regex
    regmatch_t matches[4];
    int exec_status = regexec(&regex, expr_str, 4, matches, 0);
    if (exec_status == 0)
    {
        // Extract first number
        char num1[20];
        snprintf(num1, matches[1].rm_eo - matches[1].rm_so + 1, "%s", expr_str + matches[1].rm_so);
        expr.x = atoi(num1);

        // Extract operator
        if (matches[2].rm_eo - matches[2].rm_so == 2 &&
            expr_str[matches[2].rm_so] == '/' && expr_str[matches[2].rm_so + 1] == '/')
        {
            expr.oper = '_'; // Using `_` internally to represent `//`
        }
        else
        {
            expr.oper = expr_str[matches[2].rm_so];
        }

        // Extract second number
        char num2[20];
        snprintf(num2, matches[3].rm_eo - matches[3].rm_so + 1, "%s", expr_str + matches[3].rm_so);
        expr.y = atoi(num2);

        regfree(&regex);
        return true;
    }
    else
    {
        printf("Error: Invalid expression format.\n");
        printf("Please enter an expression in the format: <number> <operator> <number>\n");
        printf("For example: 5 + 3, 10 - 4, 6 * 7, or 12 / 4\n");
        regfree(&regex);
        return false;
    }
}

// HELPER FUNCTIONS ~

int addition(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}

double division(int x, int y)
{
    if (y == 0)
    {
        printf("Error: Division by zero!\n");
        return NAN;
    }
    return (double)x / y;
}
