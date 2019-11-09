/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** display a floating number
*/

#include "pong.h"

static void round_nbr(double *nbr)
{
    if ((int)*nbr % 10 >= 5)
        *nbr += 10;
    *nbr /= 10;
}

void my_put_double(double nb, int nb_decimal)
{
    int integer = nb;
    double decimal = (float)(nb - (float)integer) * POW(10, nb_decimal + 1);
    int decimal_len = 0;

    if (decimal < 0)
        decimal = -decimal;
    my_put_nbr((int)nb);
    my_putchar('.');
    if (decimal < 1) {
        decimal_len = 0;
    } else {
        while (decimal / my_compute_power_rec(10, decimal_len) >= 1)
            decimal_len++;
    }
    round_nbr(&decimal);
    if (decimal != 0)
        my_put_nbr(decimal);
    for (int i = (nb_decimal - decimal_len); i > 0; i--)
        my_putchar('0');
}
