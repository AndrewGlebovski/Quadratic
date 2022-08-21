/**
 * \file
 * \brief Содержит решения уравнений
 * 
 * Этот файл содержит функции для решения квадратных и линейных уравнений, а также вспомогательную функцию сравнения двух вещественных чисел
*/

#include "header.h"


/// Отражает результат сравнения двух чисел
enum COMPARE_RESULT {
    LESS    = -1, ///< Первое число меньше второго
    EQUAL   =  0, ///< Первое число равно второму
    GREATER =  1  ///< Первое число больше второго
};

/// Наибольшее значение, котороое будет округляться до нуля
static const double NEAR_ZERO = 1e-6;


/** 
 * \brief Сравнивает два вещественных числа
 * \param a,b Два вещественных числа
 * \return Результат сравнения (Смотри COMPARE_RESULT)
*/
static int compare(double a, double b);


/** 
 * \brief Подсчитывает дискриминант
 * \param a,b,с Коэффициенты квадратного уравнения
 * \return Значение дискриминанта
*/
static double get_discriminant(double a, double b, double c);


Solution solve_quadratic(double a, double b, double c) {
    // in case 'a' equals zero
    if (compare(a, 0.0) == EQUAL)
        return solve_linear(b, c);

    // get discriminant
    double d = get_discriminant(a, b, c);

    // init result
    Solution result = {NO_SOLUTIONS, NAN, NAN};

    // check discriminant
    if (compare(d, 0.0) == GREATER)
        result = {TWO_SOLUTIONS, (-b + d) / (2 * a), (-b - d) / (2 * a)};
    else if (compare(d, 0.0) == EQUAL)
        result = {ONE_SOLUTION, -b / (2 * a), NAN};
    
    // return
    return result;
}


Solution solve_linear(double k, double b) {
    // init result
    Solution result = {NO_SOLUTIONS, NAN, NAN};

    if (compare(k, 0.0) == EQUAL)
        result = {ERROR, NAN, NAN}; // in case 'k' equals zero
    else
        result = {ONE_SOLUTION, -b / k, 0};
    
    return result;
}


int compare(double a, double b) {
    if ((a - b) > NEAR_ZERO)
        return GREATER;
    else if ((a - b) < -NEAR_ZERO)
        return LESS;
    return EQUAL;
}


double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}
