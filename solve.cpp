/**
 * \file
 * \brief This file contains solutions to equations
 * 
 * This file contains functions for solving quadratic and linear equations, and tool function for comparing two real numbers.
*/

#include "header.h"


/// Shows the result of comparing two numbers
enum COMPARE_RESULT {
    LESS    = -1, ///< The first number is less than the second
    EQUAL   =  0, ///< The first number is equal to the second
    GREATER =  1  ///< The first number is greater than the second
};

/// The largest value that will be rounded down to zero
static const double NEAR_ZERO = 1e-6;


/** 
 * \brief Compares two real numbers
 * \param a,b Two real numbers
 * \return Comparison result (see #COMPARE_RESULT)
*/
static int compare(double a, double b);


/** 
 * \brief Calculates the discriminant
 * \param a,b,с Coefficients of a quadratic equation
 * \return Discriminant value
*/
static double get_discriminant(double a, double b, double c);


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


Solution solve_linear(double k, double b) {
    // init result
    Solution result = {NO_SOLUTIONS, NAN, NAN};

    if (compare(k, 0.0) == EQUAL)
        result = {ERROR, NAN, NAN}; // in case 'k' equals zero
    else
        result = {ONE_SOLUTION, -b / k, 0};
    
    return result;
}


int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return GREATER;
    else if ((a - b) < -NEAR_ZERO)
        return LESS;
    return EQUAL;
}


double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}
