/**
 * \file
 * \brief This file contains only the main() function
*/

#include "quad_solver.hpp"


/**
 * \brief The main function of the program
*/
int main() {
    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    input(&a, &b, &c);

    // calculate result
    Solution result = solve_quadratic(a, b, c);

    // print result
    output(result);

    return 0;
}
