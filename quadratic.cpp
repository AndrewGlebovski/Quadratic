#include <math.h>
#include "quadratic.h"


enum COMPARE_FLAG {LESS = -1, EQUAL, GREATER}; // Flags that returns compare function
static const double NEAR_ZERO = 1e-6; // The biggest value that will be rounded to zero


static double get_discriminant(double a, double b, double c);
static int compare(double a, double b);


/* Calculates discriminant */
double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}


/* Calculates solutions */
Solution get_solution(double a, double b, double c) {
    // init result
    Solution result = {0, 0, 0};

    // in case 'a' equals zero
    if (compare(a, 0.0) == EQUAL) {

        // in case 'b' equals zero
        if (compare(b, 0.0) == EQUAL)
            result = {-1, 0, 0};
        // linear function
        else
            result = {1, -c / b, 0};

        return result;
    }

    // get discriminant
    double d = get_discriminant(a, b, c);

    // check discriminant
    if (compare(d, 0.0) == GREATER)
        result = {2, (-b + d) / (2 * a), (-b - d) / (2 * a)};
    else if (compare(d, 0.0) == EQUAL)
        result = {1, -b / (2 * a), 0};
    
    // return
    return result;
}


/* Compares two digits */
int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return GREATER;
    else if ((a - b) < -NEAR_ZERO)
        return LESS;
    return EQUAL;
}
