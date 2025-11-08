#include <stdio.h>
#include "myops.h"

double calculate(char*op, double a, double b)
{
    printf("Calculating...\n");

    if (strcmp(op,"+")==0) {
        return add(a,b);
    }
    else if (strcmp(op, "-")==0) {
        return sub(a,b);
    }
    else if (strcmp(op,"*")==0) {
        return mul(a,b);
    }
    else if (strcmp(op, "/")==0) {
        return div(a,b);
    }
    else if (strcmp(op, "^")==0) {
        return pows(a,b);
    }
    else if (strcmp(op, "%")==0) {
        return mod(a,b);
    }
    else {
        printf("Unsupported operation: %s\n", op);
        return 0;
    }
}

int main(void)
{
    double a, b;
    char op[3];

    printf("~~~Welcome to my calculator ~~");
    printf("Enter expression (e.g 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result = %.2lf\n", calculate(op, a, b));
    printf("~~~ Goodbye. See you again ~~~\n\n");

    return 0;
}