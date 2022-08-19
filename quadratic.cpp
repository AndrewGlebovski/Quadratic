#include <math.h>
#include "quadratic.h"


static const double NEAR_ZERO = 10e-7; // The biggest value that will be rounded to zero


double get_discriminant(double a, double b, double c);
int compare(double a, double b);


/* Calculates discriminant */
double get_discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}


/* Calculates solutions */
Solution get_solution(double a, double b, double c) {
    // init result
    Solution result = {0, 0, 0};

    // in case 'a' equals zero
    if (compare(a, 0.0) == 0) {

        // in case 'b' equals zero
        if (compare(b, 0.0) == 0)
            result = {-1, 0, 0};
        // linear function
        else
            result = {1, -c / b, 0};

        return result;
    }

    // get discriminant
    double d = get_discriminant(a, b, c);

    // check discriminant
    if (compare(d, 0.0) == 1)
        result = {2, (-b + d) / (2 * a), (-b - d) / (2 * a)};
    else if (compare(d, 0.0) == 0)
        result = {1, -b / (2 * a), 0};
    
    // return
    return result;
}


// if a > b returns 1, if a == b returns 0, if a < b returns -1, 
int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return 1;
    else if ((a - b) < -NEAR_ZERO)
        return -1;
    return 0;
}
