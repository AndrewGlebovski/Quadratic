#include "header.h"


enum COMPARE_FLAGS {LESS = -1, EQUAL, GREATER}; // Flags that returns compare function
static const double NEAR_ZERO = 1e-6; // The biggest value that will be rounded to zero


static double get_discriminant(double a, double b, double c);
static int compare(double a, double b);


/* Solves a quadratic equation */
Solution solve_quadratic(double a, double b, double c) {
    // in case 'a' equals zero
    if (compare(a, 0.0) == EQUAL)
        return solve_linear(b, c);

    // get discriminant
    double d = get_discriminant(a, b, c);

    // init result
    Solution result = {NO_SOLUTIONS, NAN, NAN};

    // check discriminant
    if (compare(d, 0.0) == GREATER)
        result = {TWO_SOLUTIONS, (-b + d) / (2 * a), (-b - d) / (2 * a)};
    else if (compare(d, 0.0) == EQUAL)
        result = {ONE_SOLUTION, -b / (2 * a), NAN};
    
    // return
    return result;
}


/* Solves a linear equation */
Solution solve_linear(double k, double b) {
    // init result
    Solution result = {NO_SOLUTIONS, NAN, NAN};

    if (compare(k, 0.0) == EQUAL)
        result = {ERROR, NAN, NAN}; // in case 'k' equals zero
    else
        result = {ONE_SOLUTION, -b / k, 0};
    
    return result;
}


/* Compares two numbers */
int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return GREATER;
    else if ((a - b) < -NEAR_ZERO)
        return LESS;
    return EQUAL;
}


/* Calculates discriminant */
double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}
