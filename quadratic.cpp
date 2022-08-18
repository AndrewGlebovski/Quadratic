#include <math.h>


double discriminant(double a, double b, double c);
int solution(double a, double b, double c, double *solutions);


/* Calculates discriminant */
double discriminant(double a, double b, double c){
    return pow(b, 2) - 4 * a * c;
}


/* Calculates solutions */
int solution(double a, double b, double c, double *solutions){
    const double zero_delta=0.0000001; // for zero compare

    // in case of zero
    if (abs(a) <= zero_delta){
        solutions[0]=(-c) / b;
        return 1;
    }

    double d=discriminant(a, b, c);
    /* DEBUG
    printf("%f %f %f\n", a, b, c);
    printf("%f\n", d);
    */
    if (d > zero_delta){
        solutions[0]=(-b + d) / (2 * a);
        solutions[1]=(-b - d) / (2 * a);
        return 2;
    }
    else if (d >= 0.0){
        solutions[0]=(-b) / (2 * a);
        return 1;
    }
    else{
        return 0;
    }
}