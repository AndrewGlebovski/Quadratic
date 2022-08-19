#include "quadratic.h"


int main() {
    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    if (input(&a, &b, &c) != 0)
        return 0;

    // calculate result
    Solution result = solve_quadratic(a, b, c);

    // print result
    output(result);
    
    // return
    return 0;
}
