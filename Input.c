#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * Кол-во попыток
 */
const int maxtry = 10;
/**
 * Обеспечивает безопасный ввод чисел в массив
 * При любой попытке ввести НЕ число, пользователь получит шанс повторить попытку (кол-во попыток ограниченно)
 * При вводе символа отличного от числа, запускается цыкл с MAXTRY кругов
 * \code
 * for ( ;right != 1 ; fflush (stdin)) {
            if (try == MAXTRY) {
                printf ("please try again later");
                return 0;
            }
            if (try < MAXTRY) {
                printf ("try again please\n");
                try++;
            }
            printf ("[%d/%d]:", i + 1, n);
            right = scanf ("%lg", &data[i]);
 * \endcode
 *
 * Также при ошибочном вводе числа, есть аозможность его изменить (с точностью до номера изменяемого элемента)
 * Часть кода:
 * \code
 *  printf ("Do you want to change?\n\"+\" YES\nanother - NO\n");
    do {
        scanf ("%s", ask);
        if (strcmp (ask, ye) == 0) {
            printf ("Input num:");
            scanf ("%d", &nchange);
            ...
 * \endcode
 * @param text [in] строка, выводимая на экран. Сообщает пользователю, что необходимо ввести
 * @param n [in] кол-во вводимых значений
 * @return Возвращает адрес массива с задаными значениями
 */
double* Input (const char text[], int n) {
    double* data = (double*) calloc (n, sizeof(data[0]));
    int try = 0;
    int right = 0;
    char ask[2];

    if (data == 0)
        return 0;

    printf ("%s", text);

    for (int i = 0; i < n; ) {
        printf ("[%d/%d]:", i + 1, n);
        right = scanf ("%lg", &data[i]);
        fflush (stdin);
        if (right == 1)
            i++;

        for ( ;right != 1 ; fflush (stdin)) {
            if (try == maxtry) {
                printf ("please try again later");
                return 0;
            }
            if (try < maxtry) {
                printf ("try again please\n");
                try++;
            }
            printf ("[%d/%d]:", i + 1, n);
            right = scanf ("%lg", &data[i]);
            if (right == 1)
                i++;
        }
    }

    const char ye[2] = "+";
    int nchange = 0;

    printf ("Do you want to change?\n\"+\" YES\nanother - NO\n");
    do {
        scanf ("%s", ask);
        if (strcmp (ask, ye) == 0) {
            printf ("Input num:");
            scanf ("%d", &nchange);
            fflush(stdin);

            for ( ; nchange > n; fflush(stdin)) {
                printf("invalid value, need num <= %d\n", n);
                printf ("Input num:");
                scanf ("%d", &nchange);
            }
            printf ("[%d/%d]:", nchange, n);
            right = scanf ("%lg", &data[nchange - 1]);
            fflush(stdin);

            for ( ;right != 1 ; ) {
                if (try == maxtry) {
                    printf ("please try again later");
                    return 0;
                }
                if (try < maxtry) {
                    printf ("try again please\n");
                    try++;
                }
                printf ("[%d/%d]:", nchange, n);
                right = scanf ("%lg", &data[nchange - 1]);
                fflush(stdin);
            }
            printf ("again?\n");
        }
    } while (strcmp (ask, ye) == 0);

    return data;
}