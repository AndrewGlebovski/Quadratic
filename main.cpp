#include "header.h"


int main() {
    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    if (input(&a, NULL, &c) != 0)
        return 0;

    // calculate result
    Solution result = solve_quadratic(a, b, c);

    // print result
    output(result);
    
    // return
    return 0;
}
