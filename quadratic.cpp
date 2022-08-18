#include <math.h>
#include "quadratic.hpp"


static const double NEAR_ZERO = 10e-7; // The biggest value that will be rounded to zero


int compare(double a, double b);


/* Calculates discriminant */
double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}


/* Calculates solutions */
int solution(double a, double b, double c, double *solutions) {
    // in case 'a' equals zero
    if (compare(a, 0.0) == 0) {

        // in case 'b' equals zero
        if (compare(b, 0.0) == 0)
            return -1;
        
        // linear function
        solutions[0] = -c / b;
        return 1;
    }

    double d = discriminant(a, b, c);
    /* DEBUG
    printf("%f %f %f\n", a, b, c);
    printf("%f\n", d);
    */
    if (compare(d, 0.0) == 1) {
        solutions[0] = (-b + d) / (2 * a);
        solutions[1] = (-b - d) / (2 * a);
        return 2;
    }
    else if (compare(d, 0.0) == 0) {
        solutions[0]=(-b) / (2 * a);
        return 1;
    }
    else {
        return 0;
    }
}


// if a > b returns 1, if a == b returns 0, if a < b returns -1, 
int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return 1;
    else if ((a - b) < -NEAR_ZERO)
        return -1;
    return 0;
}
