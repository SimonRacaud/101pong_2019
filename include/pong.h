/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** header
*/

#ifndef PONG_H
#define PONG_H

#define ERR_ARG "ERROR: argument invalid or missing\n"
#define RAD_TO_DEGREE 57.29577951

#define POW(x, y) my_compute_power_rec(x, y);

#include "my.h"
#include <stdlib.h>
#include <math.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector_t;

int pong(vector_t *zero, vector_t *one, unsigned int time_shift);

double extract_arg(char *nbr);
unsigned int *len_nbr(char *nbr);

void my_put_double(double nb, int nb_decimal);

#endif
