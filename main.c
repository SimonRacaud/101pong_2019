/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** Main file
*/

#include <stdlib.h>
#include "my.h"
#include "pong.h"

static void check_time_shift(char *tc)
{
    unsigned int *len = len_nbr(tc);

    if (len[0] == 0 || tc[0] == '-' || len[2] != 0 ||
    tc[my_strlen(tc) - 1] == '.') {
        my_putstr_error(ERR_ARG);
        free(len);
        exit(84);
    }
    free(len);
}

int main(int ac, char **av)
{
    vector_t zero;
    vector_t one;
    unsigned int time_shift;

    if (ac == 8) {
        zero.x = extract_arg(av[1]);
        zero.y = extract_arg(av[2]);
        zero.z = extract_arg(av[3]);
        one.x = extract_arg(av[4]);
        one.y = extract_arg(av[5]);
        one.z = extract_arg(av[6]);
        check_time_shift(av[7]);
        time_shift = my_getnbr(av[7]);
        return pong(&zero, &one, time_shift);
    }
    my_putstr_error(ERR_ARG);
    return (84);
}
