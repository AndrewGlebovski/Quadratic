/**
 * \file
 * \brief Contains all for testing
*/

#include "quad_solver.hpp"


// Contains coefficients of an equation and a solution for this equation (see #Solution)
typedef struct {
    double a; ///< Coefficient before x^2
    double b; ///< Coefficient before x
    double c; ///< Free coefficient
    Solution ans; ///< Solution struct that contains right roots
} QuadSolverTest;


/**
 * \brief Creates test
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \param [in] status Right status
 * \param [in] x1 Right x1
 * \param [in] x2 Right x2
 * \return Test for solve_quadratic()
*/
QuadSolverTest create_test(double a, double b, double c, int status, double x1, double x2);


/**
 * \brief Reads test from file
 * \param [in] stream To read test
 * \param [out] test This test will be read from file
 * \return Test for solve_quadratic()
*/
int read_test(FILE *stream, QuadSolverTest *test);


/**
 * \brief Runs test
 * \param [in] test For testing
 * \param [out] msg Test result message
 * \return 0 if test passed, 1 - otherwise
*/
int run_test(QuadSolverTest test, char* msg);


/**
 * \brief Prints test result with index
 * \param [in] quad_test Test to run
 * \param [in] test_index Test index
 * \return 0 if test passed, 1 - otherwise
*/
int print_test(QuadSolverTest quad_test, int test_index);


QuadSolverTest create_test(double a, double b, double c, int status, double x1, double x2) {
    Solution ans = {status, x1, x2};
    QuadSolverTest new_test = {a, b, c, ans};
    return new_test;
}


int read_test(FILE *stream, QuadSolverTest *test) {
    if (!stream) {
        printf("Stream was NULL\n");
        return 1;
    }

    if (!test){
        printf("Test was NULL\n");
        return 1;
    }
    
    int n = fscanf(stream, "%lf %lf %lf %d %lf %lf", 
                &(test->a), &(test->b), &(test->c), &(test->ans.status), &(test->ans.x1), &(test->ans.x2));
    
    if (n != 6)
        return 1;
    
    return 0;
}


int run_test(QuadSolverTest test, char* msg) {
    // get solution
    Solution sol = solve_quadratic(test.a, test.b, test.c);
    // test result message
    if (msg)
        sprintf(msg, "Got: status = %d, x1 = %lg, x2 = %lg Expected: status = %d, x1 = %lg, x2 = %lg", 
                sol.status, sol.x1, sol.x2, test.ans.status, test.ans.x1, test.ans.x2);
    // status check
    if (sol.status != test.ans.status)
        return 1;
    // roots check
    switch (sol.status) {
        case TWO_SOLUTIONS:
            return !(compare(sol.x1, test.ans.x1) == EQUAL && compare(sol.x2, test.ans.x2) == EQUAL);

        case ONE_SOLUTION:
            return !(compare(sol.x1, test.ans.x1) == EQUAL && isnan(sol.x2) && isnan(test.ans.x2));

        default:
            return !(isnan(sol.x1) && isnan(test.ans.x1) && isnan(sol.x2) && isnan(test.ans.x2));
    }
}


int print_test(QuadSolverTest quad_test, int test_index) {
    char msg[100] = {0};
    int result = run_test(quad_test, msg);

    if (result)
        printf("%2d |   FAIL | %s\n", test_index, msg);
    else
        printf("%2d |     OK |\n", test_index);
    
    return result;
}


int start_testing(FILE *stream) {
    QuadSolverTest tests[] = {
        // predefined tests
        create_test(1, 2, 3, NO_SOLUTIONS, NAN, NAN),
        create_test(1, 2, -3, TWO_SOLUTIONS, 1, -3),
        create_test(0, 2, 3, ONE_SOLUTION, -1.5, NAN),
        create_test(0, 0, 2, MATH_ERROR, NAN, NAN),
        create_test(0, 0, 0, MATH_ERROR, NAN, NAN),
        create_test(2, 0, 3, NO_SOLUTIONS, NAN, NAN),
        create_test(2, 3, 0, TWO_SOLUTIONS, 0, -1.5)
    };

    int n = sizeof(tests) / sizeof(QuadSolverTest);
    int success_counter = 0;

    printf("~~~~~~~~ Quadratic Solve Testing ~~~~~~~~~\n");
    printf("id | status | message\n");

    for(int i = 1; i <= n; i++)
        success_counter += 1 - print_test(tests[i-1], i);

    if (stream) {
        QuadSolverTest test;
        
        while (!read_test(stream, &test))
            success_counter += 1 - print_test(test, ++n);
    }

    printf("~~~~~~~~~~~~~~~~~~ %2d/%-2d ~~~~~~~~~~~~~~~~~\n", success_counter, n);

    return success_counter;
}
