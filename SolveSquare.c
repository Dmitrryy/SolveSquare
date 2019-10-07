#include <math.h>
#include "else.h"
/**
 * Возможная погрешнасть вычислений
 */

double SolveLine(double b, double c, double *x2);

/**
 * Решает квадратное уравнение с задаваемыми коэффицентами
 * решение происходит путем нахождения дискриминанта
 *
 * Учтены случаи, когда, при определенных коэффицентах, уравнение становится линейного типа,
 * тогда программа обаращется к функции Solveline
 * \code
 *  if(a == 0)
        return SolveLine(b, c, x1);
    if(c == 0) {
        *x2 = 0;
        return SolveLine(a, b, x1) + 1;
    }
 * \endcode
 * Функция является универсальной и может использоваться везде, где требуется получить решения уравнения (не только для печати)
 * @param[in] a коэффицент при x^2
 * @param[in] b коэффицент при x
 * @param[in] c свободный коэффицент
 * @param[out] x1 первое решение
 * @param[out] x2 второе ркшкние
 * @return Количество решений (0, 1, 2 или -1 если кол-во решений = бесконечность)
 */
double SolveSquare(double a, double b, double c, double* x1, double* x2) {
    double d = 0;
    double k = 0;

    if(fabs(a) < inaccuracy)
        return SolveLine(b, c, x1);
    if(fabs(c) < inaccuracy) {
        *x1 = 0;
        k =  SolveLine(a, b, x2) + 1;
        if (*x2 == *x1)
            return 1;
        else
            return k;
    }
    d = b*b - 4.0*a*c;

    if(d < -inaccuracy)
        return 0;
    if(fabs(d) < inaccuracy) {
        *x1 = -b / (2 * a);
        return 1;
    }
    else {
        d = sqrt(d);
        *x1 = (-b - d) / (2 * a);
        *x2 = (-b + d) / (2 * a);
        return 2;
    }

}