/**
 * \file
 * \brief This is a header file
 * 
 * Included in every project script
*/

#include <math.h>


/// Shows solution status
enum SOLUTION_STATUS {
    ERROR         = -1, ///< Solutions could not be found cause of a math error
    NO_SOLUTIONS  =  0, ///< This equation has no solutions.
    ONE_SOLUTION  =  1, ///< This equation has one solution.
    TWO_SOLUTIONS =  2  ///< This equation has two solutions.
};


/**
 * \brief Contains the solutions of the equation
*/
typedef struct solution {
    int status;
    double x1;
    double x2;
} Solution;


/**
 * \brief Scans the coefficients
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \return Exit code (see #EXIT_CODE)
*/
int input(double *a, double *b, double *c);


/**
 * \brief Prints the solution
 * \param [in] result That will be printed (see #Solution)
*/
void output(Solution result);


/** 
 * \brief Solves a quadratic equation
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \return Solution (see #Solution)
*/
Solution solve_quadratic(double a, double b, double c);


/** 
 * \brief Solves a linear equation
 * \param [in] k Coefficient before x
 * \param [in] b Free coefficient
 * \return Solution (see #Solution)
*/
Solution solve_linear(double k, double b);
