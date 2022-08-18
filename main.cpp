#include <stdio.h>
#include "quadratic.h"


int input(double *a, double *b, double *c);
void output(struct result res);


int main() {
    // init params
    double a = 0, b = 0, c = 0;

    // read params
    if (input(&a, &b, &c) != 3)
        return 0;

    // calculate result
    struct result res = solution(a, b, c);

    // print result
    output(res);
    
    // return
    return 0;
}


/* Calculates discriminant */
int input(double *a, double *b, double *c) {
    printf("Pass parameters this way: -1.5 2 20.25\n");
    
    // input check
    int n = scanf("%lf %lf %lf", a, b, c);
    if (n != 3)
        printf("Incorrect input");

    return n;
}


/* Calculates discriminant */
void output(struct result res) {
    if (res.n==2)
        printf("x1 = %f, x2 = %f", res.x1, res.x2);
    else if (res.n==1)
        printf("x = %f", res.x1);
    else if (res.n==0)
        printf("No solutions... sad");
    else
        printf("Math error");
}