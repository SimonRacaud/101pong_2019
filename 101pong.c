/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** main file of the project
*/

#include "pong.h"

static vector_t pos_time_n(vector_t *init, vector_t *velocity, double n)
{
    vector_t vec;

    vec.x = velocity->x * n + init->x;
    vec.y = velocity->y * n + init->y;
    vec.z = velocity->z * n + init->z;
    return vec;
}

static void display_part_one(vector_t v, vector_t time_n, int n)
{
    my_putstr("The velocity vector of the ball is:\n(");
    my_put_double(v.x, 2);
    my_putstr(", ");
    my_put_double(v.y, 2);
    my_putstr(", ");
    my_put_double(v.z, 2);
    my_putstr(")\n");
    my_putstr("At time t + ");
    my_put_nbr(n);
    my_putstr(", ball coordinates will be:\n(");
    my_put_double(time_n.x, 2);
    my_putstr(", ");
    my_put_double(time_n.y, 2);
    my_putstr(", ");
    my_put_double(time_n.z, 2);
    my_putstr(")\n");
}

static int is_reach_paddle(vector_t *velocity, vector_t *one)
{
    if (velocity->z == 0 && one->z == 0)
        return (1);
    if (velocity->z < 0 && one->z >= 0)
        return (1);
    if (velocity->x == 0 && velocity->y == 0 && velocity->z == 0) {
        if (one->z == 0)
            return (1);
    }
    return (0);
}

static void compute_display_incidence(vector_t *v)
{
    double magnit_v;
    double magnit_voxy;
    double angle;

    if (v->x == 0 && v->y == 0 && v->z < 0) {
        angle = 90;
    } else if (v->z == 0) {
        angle = 0;
    } else {
        magnit_v = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
        magnit_voxy = sqrt(pow(v->x, 2) + pow(v->y, 2));
        angle = acos(magnit_voxy / magnit_v) * RAD_TO_DEGREE;
    }
    my_put_double(angle, 2);
    my_putstr(" degrees\n");
}

int pong(vector_t *zero, vector_t *one, unsigned int time_shift)
{
    vector_t v = {one->x - zero->x, one->y - zero->y, one->z - zero->z};
    vector_t time_n = pos_time_n(one, &v, time_shift);

    display_part_one(v, time_n, time_shift);
    if (is_reach_paddle(&v, one) == 0) {
        my_putstr("The ball won't reach the paddle.\n");
    } else {
        my_putstr("The incidence angle is:\n");
        compute_display_incidence(&v);
    }
    return (0);
}
