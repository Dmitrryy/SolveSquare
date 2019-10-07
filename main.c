/**
 * @mainpage Программа для решения уравнений второй степени
 * \brief Работа с уравнениями второй степени
 * \author Дроздов Д.А.
 * \version 6.0 (final)
 * \date сентябрь 2019 года
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "else.h"

int UnitTest(void);
double* Input (const char text[], int n);
double SolveSquare(double a, double b, double c, double *x1, double *x2);

int main() {
    double x1 = NAN, x2 = NAN;
    double NRoots = 0;

    printf("||**********************************************||\n");
    printf("||The program for solving the quadratic equation||\n");
    printf("||v6.0 (final)                                  ||\n");
    printf("||Made by Dmitry Drozdov                 09.2019||\n");
    printf("||                                 (C)for \"Ilab\"||\n");
    printf("||**********************************************||\n");

    int stat = UnitTest();
    if (stat == 1)
        return 1;

    double *coeffs = Input ("Entering coeffs\n", 3);

    assert(&x1 != &x2);
    assert(coeffs != NULL);

    NRoots = SolveSquare (*coeffs, *(coeffs + 1), *(coeffs + 2), &x1, &x2);

    assert(&x1 != &x2);

    free(coeffs);

    switch((int)NRoots) {
        case oneroot :
            printf("%1s%15s\n", "N", "x");
            printf("%1lg%15lg\n", NRoots, x1);
            break;
        case tworoots :
            printf("%1s%15s%15s\n", "N", "x1", "x2");
            printf("%1lg%15lg%15lg\n", NRoots, x1, x2);
            break;
        case noroots :
            printf("NO Roots!\n");
            break;
        case infinityroots :
            printf("Roots = Infinity\n");
            break;
        default:
            printf ("ERROR\n");
    }
}