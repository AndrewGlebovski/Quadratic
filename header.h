/**
 * \file
 * \brief Это основной заголовочный файл
 * 
 * Он используется во всем проекте и содержит функции, структуры, перечисления необходимые в разных областях проекта
 * 
 * \todo Мне не нравится, что в него включен <math.h>, который нужен для использования NAN и fabs(). Подключать такую огромную библиотеку ко всем файлам проекта ради двух макросов это плохо, на мой взгляд
*/

#include <math.h>


/**
 * \brief Описывает состояние решения
*/
enum SOLUTION_STATUS {
    ERROR = -1, ///< Найти корни не удалось из-за математической ошибки
    NO_SOLUTIONS = 0, ///< У этого уравнения нет корней
    ONE_SOLUTION = 1, ///< У этого уравнения один корень
    TWO_SOLUTIONS = 2 ///< У этого уравнения два корня
};


/**
 * \brief Содержит корни уравнения
 * 
 * \todo Иногда мне хочется, чтобы вместо x1 и x2 был массив с неопределенным размером для переменного числа решений, но это будет трудно реализовать
*/
typedef struct solution {
    int status;
    double x1;
    double x2;
} Solution;


void input(double *a, double *b, double *c);
void output(Solution result);

Solution solve_quadratic(double a, double b, double c);
Solution solve_linear(double k, double b);
