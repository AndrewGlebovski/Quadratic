#include <stdio.h>
#include <math.h>


double discriminant(double, double, double);
int solution(double, double, double, double *);


int main(){
    // read parameters
    double a, b, c;
    printf("Pass parameters this way: -1.5 2 20.25\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    // calculate result
    double solutions[2];
    int n=solution(a, b, c, solutions);
    // print result
    if (n==2)
        printf("x1 = %f, x2 = %f", solutions[0], solutions[1]);
    else if (n==1)
        printf("x = %f", solutions[0]);
    else
        printf("No solutions... sad");
}


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