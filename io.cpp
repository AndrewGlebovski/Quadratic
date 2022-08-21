/**
 * \file
 * \brief В этом файле осуществляется ввод и вывод
*/

#include <stdio.h>
#include <float.h>
#include <assert.h>
#include "header.h"


/**
 * \brief Функция проверки границ значения
 * \warning В функции используется assert. Значение равное бесконечности завершит программу
 * \param n Вещественное число
 * \return 0 или 1, если число находится в границах разумного
 * 
 * Эта функция проверяет размер введенного значения и сравнивает его с DBL_MAX
*/
static int is_bounded(double n);


void input(double *a, double *b, double *c) {
    // NULL pointer args check
    assert((a && b && c) && "An argument is a NULL pointer");

    // invite && input
    printf("Pass parameters this way: -1.5 2 20.25\n");
    int n = scanf("%lf %lf %lf", a, b, c);

    // input type check
    assert((n == 3) && "Incorrect input. Pass numbers only");
    
    // bound check
    assert((is_bounded(*a) && is_bounded(*b) && is_bounded(*c)) && "Number is too big");

    // smart check
    assert((fabs(*b) < sqrt(DBL_MAX) && 4 * (*a) * (*c) < DBL_MAX) && "Quadratic expression will be too big");
}


void output(Solution result) {
    switch (result.status) {
        case TWO_SOLUTIONS:
            printf("x1 = %f, x2 = %f\n", result.x1, result.x2);
            break;
        case ONE_SOLUTION:
            printf("x = %f\n", result.x1);
            break;
        case NO_SOLUTIONS:
            printf("No solutions... sad\n");
            break;
        case ERROR:
            printf("Math error\n");
            break;
        default:
            printf("WTF\n");
            break;
    }
}


int is_bounded(double n) {
    // assert
    assert(isfinite(n) && "Number is infinite");
    // size check
    return (fabs(n) < DBL_MAX);
}
