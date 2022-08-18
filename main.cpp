#include <stdio.h>
#include <math.h>


double discriminant(double, double, double);
int solution(double, double, double, double *);


int main(){
    // init params
    double a=0, b=0, c=0;

    // read params
    printf("Pass parameters this way: -1.5 2 20.25\n");
    
    // input check
    if (scanf("%lf %lf %lf", &a, &b, &c)!=3){
        printf("Incorrect input");
        return 0; // exit program
    }

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
    
    // return
    return 0;
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