#include <stdio.h>

double SolveSquare(double a, double b, double c, double *x1, double *x2);

int UnitTest(void) {
    double x1 = 0, x2 = 0, stat = 0, nroot = 0;

    double testnum[6][6] = {
            0, 0, 0, -1, 0, 0,
            1, 0, 0, 1, 0, 0,
            0, 1, 0, 1, 0, 0,
            0, 0, 1, 0, 0, 0,
            1, 1, 0, 2, 0, -1,
            1, 2, 1, 1, -1, 0,
    };
    for (int i = 0; i < 6; x1 = 0, x2 = 0) {
        nroot = SolveSquare(testnum[i][0], testnum[i][1], testnum[i][2], &x1, &x2);
        if (nroot == testnum[i][3])
            if (x1 == testnum[i][4])
                if (x2 == testnum[i][5])
                    i++;
                else {
                    printf("test N %d\ncoeffs:%g %g %g\nx1 = %8g x2 = %8g\nright:\nx1 = %8g x2 = %8g\n", i,
                           testnum[i][0], testnum[i][1], testnum[i][2], x1, x2, testnum[i][4], testnum[i][5]);
                    printf("nroots = %g(%g)", nroot, testnum[i][3]);
                    return 1;
                }
    }
    return 0;
}