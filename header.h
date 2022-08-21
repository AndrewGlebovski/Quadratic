// Global Includes
#include <math.h>


// Global Enums
enum SOLUTION_FLAGS {ERROR = -1, NO_SOLUTIONS, ONE_SOLUTION, TWO_SOLUTIONS};


// Global Structures
typedef struct Solution {
    int n;
    double x1;
    double x2;
} Solution;


// Global functions

void input(double *a, double *b, double *c);
void output(Solution result);

Solution solve_quadratic(double a, double b, double c);
Solution solve_linear(double k, double b);
