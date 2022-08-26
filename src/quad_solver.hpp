/**
 * \file
 * \brief This is a header file
 * 
 * It's included in every project script
*/

#include <stdio.h>
#include <math.h>


/// Exit codes
typedef enum EXIT_CODE {
	UNEXPECTED  = -1, ///< For unexpected behaviour
	OK          =  0, ///< Well done
	NULL_ARG    =  1, ///< Argument was NULL pointer
	WRONG_INPUT =  2, ///< Wrong input
	BIG_NUMBER  =  4, ///< Number was too big to handle
	BIG_EXP     =  5, ///< Expression result was too big to handle
	NO_FILE     =  6, ///< File not found
	EXE_FAIL    =  7  ///< File executed with incorrect arguments
} EXIT_CODE;


/// Shows solution status
typedef enum SOLUTION_STATUS {
	MATH_ERROR    = -1, ///< Solutions could not be found cause of a math error
	NO_SOLUTIONS  =  0, ///< This equation has no solutions.
	ONE_SOLUTION  =  1, ///< This equation has one solution.
	TWO_SOLUTIONS =  2, ///< This equation has two solutions.
	INF_SOLUTIONS =  3, ///< This equation has infinite number of solutions
	INIT          =  4, ///< Has been just initialized
} SOLUTION_STATUS;


/// Shows the result of comparing two numbers
enum COMPARE_RESULT {
	LESS    = -1, ///< The first number is less than the second
	EQUAL   =  0, ///< The first number is equal to the second
	GREATER =  1  ///< The first number is greater than the second
};


/// Contains the roots of the equation
typedef struct {
	int status; ///< It's solution status
	double x1; ///< The first root
	double x2; ///< The second root
} Solution;


/// Input function will scan file file
extern FILE *in_stream;


/// Output function will print in this file
extern FILE *out_stream;


/**
 * \brief Scans the coefficients
 * \param [in] stream Input will be taken from this file
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \return Exit code (see #EXIT_CODE)
*/
EXIT_CODE input(FILE *stream, double *a, double *b, double *c);


/**
 * \brief Prints the solution
 * \param [in] stream Output will be printed to this file
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


/** 
 * \brief Compares two double numbers
 * \param [in] a The first number to compare
 * \param [in] b The second number to compare
 * \return Comparison result (see #COMPARE_RESULT)
*/
int compare(double a, double b);


/**
 * \brief Runs some tests in any case
 * \param stream If not NULL tests will be readen from this file
 * \return Number of passed tests
*/
int start_testing(FILE *stream);


/** 
 * \brief Parses command line arguments
 * \param [in] argc Argv size
 * \param [in] argv List of commands passed to the main()
 * \return Comparison result (see #COMPARE_RESULT)
*/
int parse(int argc, char *argv[]);
