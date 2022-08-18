#include <stdio.h>


double discriminant(double a, double b, double c);
int solution(double a, double b, double c, double *solutions);


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
