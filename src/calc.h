#ifndef CALC_H
#define CALC_H

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

// Define colors and reset
// Source: https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
#define BCYN "\e[1;36m"
#define BGRN "\e[1;32m"
#define BMAG "\e[1;35m"
#define BRED "\e[1;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define reset "\e[0m"

// Define expression struct
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

#endif
