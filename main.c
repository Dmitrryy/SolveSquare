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

const int oneroot = 1;
const int tworoots = 2;
const int noroots = 0;
const int infinityroots = -1;

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

    assert(coeffs != 0);
    assert(&x1 != &x2);

    NRoots = SolveSquare (*coeffs, *(coeffs + 1), *(coeffs + 2), &x1, &x2);

    free(coeffs);

    switch((int)NRoots) {
        case 1 :
            printf("%1s%15s\n", "N", "x");
            printf("%1lg%15lg\n", NRoots, x1);
            break;
        case 2 :
            printf("%1s%15s%15s\n", "N", "x1", "x2");
            printf("%1lg%15lg%15lg\n", NRoots, x1, x2);
            break;
        case 0 :
            printf("NO Roots!\n");
            break;
        case -1 :
            printf("Roots = Infinity\n");
            break;
        default:
            printf ("ERROR\n");
    }
}