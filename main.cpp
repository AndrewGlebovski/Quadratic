/**
 * \file
 * \brief Этот файл содержит только функцию main()
 * 
 * Именно этот файл из кучки разрозненных функций порождает настоящую программу
*/

#include "header.h"


/**
 * \brief Основная функция программы
 * 
 * С неё все начинается, ей все заканчивается
*/
int main() {
    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    input(&a, &b, &c);

    // calculate result
    Solution result = solve_quadratic(a, b, c);

    // print result
    output(result);
    
    // return
    return 0;
}
