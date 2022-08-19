#include <stdio.h>
#include <float.h>
#include <assert.h>
#include "header.h"


int is_OK(double n);


/* Gets input */
int input(double *a, double *b, double *c) {
    // NULL pointer args check
    if (!(a && b && c)) {
        printf("Pointers are not correct\n");
        return 1;
    }

    // invite && input
    printf("Pass parameters this way: -1.5 2 20.25\n");
    int n = scanf("%lf %lf %lf", a, b, c);

    // input check
    if (n != 3) {
        printf("Incorrect input\n");
        return 1;
    }
    
    // value check
    if (!(is_OK(*a) && is_OK(*b) && is_OK(*c))) {
        printf("Value is not correct\n");
        return 1;
    }

    return 0;
}


/* Prints result */
void output(Solution result) {
    switch (result.n) {
        case TWO_SOLUTIONS:
            printf("x1 = %f, x2 = %f\n", result.x1, result.x2);
            break;
        case ONE_SOLUTION:
            printf("x = %f\n", result.x1);
            break;
        case NO_SOLUTIONS:
            printf("No solutions... sad\n");
            break;
        case ERROR:
            printf("Math error\n");
            break;
        default:
            printf("WTF\n");
            break;
    }
}


/* Checks number */
int is_OK(double n) {
    // assert
    assert(isfinite(n) && "Number is infinite");
    // size check
    return (fabs(n) < DBL_MAX);
}
