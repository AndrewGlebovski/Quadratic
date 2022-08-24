/**
 * \file
 * \brief This is a header stream
 * 
 * Included in every project script
*/

#include <stdio.h>
#include <math.h>


/// Input exit codes
typedef enum INPUT_EXIT_CODE {
    UNEXPECTED  = -1, ///< For unknown cases
    OK          =  0, ///< Well done
    NULL_ARG    =  1, ///< Argument was NULL pointer
    WRONG_INPUT =  2, ///< Wrong input
    BIG_NUMBER  =  4, ///< Number was too big to handle
    BIG_EXP     =  5, ///< Expression result was too big to handle
} INPUT_EXIT_CODE;


/// Shows solution status
typedef enum SOLUTION_STATUS {
    ERROR         = -1, ///< Solutions could not be found cause of a math error
    NO_SOLUTIONS  =  0, ///< This equation has no solutions.
    ONE_SOLUTION  =  1, ///< This equation has one solution.
    TWO_SOLUTIONS =  2, ///< This equation has two solutions.
    INF_SOLUTIONS =  3, ///< This equation has infinite number of solutions
    INIT          =  4, ///< Has been just initialized
} SOLUTION_STATUS;


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
 * \param [out] stream Input will be taken from this file
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \return Exit code (see #INPUT_EXIT_CODE)
*/
INPUT_EXIT_CODE input(FILE *stream, double *a, double *b, double *c);


/**
 * \brief Prints the solution
 * \param [out] stream Output will be printed to this file
 * \param [in] result That will be printed (see #Solution)
*/
void output(FILE *stream, Solution result);


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
