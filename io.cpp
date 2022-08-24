/**
 * \file
 * \brief This stream handles input and output.
*/

#include <float.h>
#include "quad_solver.hpp"


/**
 * \brief Function to check the bounds of a variable
 * \param [in] n Real number
 * \return 1 or 0, if the number is in bounds
 * 
 * This function checks the size of the entered value and compares it with DBL_MAX
*/
static int is_bounded(double n);


INPUT_EXIT_CODE input(FILE *stream, double *a, double *b, double *c) {
    // NULL pointer args check
    if ((a && b && c) == 0) // An argument is a NULL pointer
        return NULL_ARG;

    // invite && input
    if (stream==stdin) // invite only requires in stdin
        printf("Pass parameters this way: -1.5 2 20.25\n");
    int n = fscanf(stream, "%lf %lf %lf", a, b, c);

    // input type check
    if (n != 3) //Wrong input. Pass numbers only
        return WRONG_INPUT;
    
    // bound check
    if ((is_bounded(*a) && is_bounded(*b) && is_bounded(*c)) == 0) // Number is too big
        return BIG_NUMBER;

    // smart check
    if ((fabs(*b) < sqrt(DBL_MAX) && 4 * (*a) * (*c) < DBL_MAX) == 0) // Quadratic expression is too big
        return BIG_EXP;
    
    return OK;
}


void output(FILE* stream, Solution result) {
    switch (result.status) {
        case TWO_SOLUTIONS:
            fprintf(stream, "x1 = %f, x2 = %f\n", result.x1, result.x2);
            break;
        case ONE_SOLUTION:
            fprintf(stream, "x = %f\n", result.x1);
            break;
        case NO_SOLUTIONS:
            fprintf(stream, "No solutions\n");
            break;
        case ERROR:
            fprintf(stream, "Math error\n");
            break;
        case INIT:
            fprintf(stream, "Not used\n");
            break;
        default:
            fprintf(stream, "WTF\n");
            break;
    }
}


int is_bounded(double n) {
    return isfinite(n) && (fabs(n) < DBL_MAX);
}
