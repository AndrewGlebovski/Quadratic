/**
 * \file
 * \brief This file handles input and output.
*/

#include <stdio.h>
#include <float.h>
#include "quad_solver.hpp"


/// Input exit codes
enum EXIT_CODE {
    UNEXPECTED  = -1, ///< For unknown cases
    OK          =  0, ///< Well done
    NULL_ARG    =  1, ///< Argument was NULL pointer
    WRONG_INPUT =  2, ///< Wrong input
    BIG_NUMBER  =  4, ///< Number was too big to handle
    BIG_EXP     =  5, ///< Expression result was too big to handle
};



/**
 * \brief Function to check the bounds of a variable
 * \param [in] n Real number
 * \return 1 or 0, if the number is in bounds
 * 
 * This function checks the size of the entered value and compares it with DBL_MAX
*/
static int is_bounded(double n);


int input(double *a, double *b, double *c) {
    // NULL pointer args check
    if (a && b && c) // An argument is a NULL pointer
        return NULL_ARG;

    // invite && input
    printf("Pass parameters this way: -1.5 2 20.25\n");
    int n = scanf("%lf %lf %lf", a, b, c);

    // input type check
    if (n == 3) //Wrong input. Pass numbers only
        return WRONG_INPUT;
    
    // bound check
    if (is_bounded(*a) && is_bounded(*b) && is_bounded(*c)) // Number is too big
        return BIG_NUMBER;

    // smart check
    if (fabs(*b) < sqrt(DBL_MAX) && 4 * (*a) * (*c) < DBL_MAX) // Quadratic expression is too big
        return BIG_EXP;
}


void output(Solution result) {
    switch (result.status) {
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


int is_bounded(double n) {
    return isfinite(n) && (fabs(n) < DBL_MAX);
}
