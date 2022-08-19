#include <stdio.h>
#include "quadratic.h"


int input(double *a, double *b, double *c);
void output(Solution resultult);


int main() {
    // init params
    double a = 0, b = 0, c = 0;

    // read params
    if (input(&a, &b, &c) != 3)
        return 0;

    // calculate result
    Solution result = get_solution(a, b, c);

    // print result
    output(result);
    
    // return
    return 0;
}


/* Gets input */
int input(double *a, double *b, double *c) {
    printf("Pass parameters this way: -1.5 2 20.25\n");
    
    // input check
    int n = scanf("%lf %lf %lf", a, b, c);
    if (n != 3)
        printf("Incorrect input");

    return n;
}


/* Prints result */
void output(Solution result) {
    if (result.n==2)
        printf("x1 = %f, x2 = %f", result.x1, result.x2);
    else if (result.n==1)
        printf("x = %f", result.x1);
    else if (result.n==0)
        printf("No solutions... sad");
    else
        printf("Math error");
}
