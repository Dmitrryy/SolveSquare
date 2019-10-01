#include <math.h>


/**
 * Решает линейное уравнение вида bx + c = 0
 * @param[in] b коэффицент при x
 * @param[in] c свободный коэффицент
 * @param[out] x2 решение заданного уравнения
 * @return кол-во решений (0, 1 и -1 если кол-во решений = бесконечность)
 *
 */
double SolveLine(double b, double c, double *x2) {

    const double inaccuracy = 1.0e-15;

    if (fabs(b) < inaccuracy) {
        if (fabs(c) < inaccuracy)
            return -1;
    }
    if (fabs(b) < inaccuracy) {
        if (fabs(c) > inaccuracy)
            return 0;
    }
    if (fabs(b) > inaccuracy) {
        if (fabs(c) < inaccuracy) {
            *x2 = 0;
            return 1;
        }
    }

    *x2 = -b / c;
    if (*x2 == -0)
        *x2 = 0;
    return 1;
}