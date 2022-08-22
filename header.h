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
 * \brief Input function
 * \warning The function uses assert(). Wrong input will terminate the program
 * \param a,b,c Pointers to double
 * 
 * This function gets coefficients and checks them.
*/
void input(double *a, double *b, double *c);


/**
 * \brief Output function
 * \param result #Solution to print
 * 
 * This function prints the solution
*/
void output(Solution result);


/** 
 * \brief Solves a quadratic equation
 * \param a,b,c Coefficients of a quadratic equation
 * \return Result as a #Solution structure
*/
Solution solve_quadratic(double a, double b, double c);


/** 
 * \brief Solves a linear equation
 * \param k,b Coefficients of a linear equation
 * \return Result as a #Solution structure
*/
Solution solve_linear(double k, double b);
