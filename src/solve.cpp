/**
 * \file
 * \brief Contains solver functions
 * 
 * This file contains functions for solving quadratic and linear equations, and tool function for comparing two real numbers.
*/

#include "quad_solver.hpp"


/// The largest value that will be rounded down to zero
static const double NEAR_ZERO = 1e-6;


/** 
 * \brief Calculates the discriminant
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \return Discriminant value
*/
static double get_discriminant(double a, double b, double c);


Solution solve_quadratic(double a, double b, double c) {
    // in case 'a' equals zero
    if (compare(a, 0.0) == EQUAL)
        return solve_linear(b, c);

    double d = get_discriminant(a, b, c);

    // init result
    Solution result = {INIT, NAN, NAN};
    a *= 2;

    // check discriminant
    if (compare(d, 0.0) == GREATER) {
        d = sqrt(d);

        result = {
            TWO_SOLUTIONS, 
            (-b + d) / a, 
            (-b - d) / a,
        };
    }
    else if (compare(d, 0.0) == EQUAL)
        result = {
            ONE_SOLUTION, 
            -b / a,
            NAN
        };
    else
        result.status = NO_SOLUTIONS;
    
    return result;
}


Solution solve_linear(double k, double b) {
    // init result
    Solution result = {INIT, NAN, NAN};

    if (compare(k, 0.0) == EQUAL)
        result = {MATH_ERROR, NAN, NAN}; // in case 'k' equals zero
    else
        result = {ONE_SOLUTION, -b / k, NAN};
    
    return result;
}


int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return GREATER;
    else if ((a - b) < -NEAR_ZERO)
        return LESS;
    return EQUAL;
}


static double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}
