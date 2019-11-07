/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** balle manager
*/

#include "breakout.h"
#include "my.h"
#include <math.h>

void set_balle_pos(balle_t *balle, double x, double y, double z)
{
    balle->pos.x = x;
    balle->pos.y = y;
    balle->z = z;
}

void set_balle_vel(balle_t *balle, double vx, double vy, double vz)
{
    balle->vx = vx;
    balle->vy = vy;
    balle->vz = vz;
}

static void bounce(balle_t *bl, char axis, double coef)
{
    if (axis == 'X') {
        set_balle_vel(bl, bl->vx, -(bl->vy), 0);
    } else if (axis == 'Y') {
        set_balle_vel(bl, -(bl->vx), bl->vy, 0);
    } else {
        if (coef > 6.5)
            coef = 6;
        if (coef < -6.5)
            coef = -6.5;
        if (bl->vx > 15)
            bl->vx -= 2;
        if (bl->vx < -15)
            bl->vx += 2;
        set_balle_vel(bl, bl->vx + coef, -(bl->vy), 0);
    }
}

void move_balle(balle_t *balle, sfVector2f *posPdle, int is_hit_block)
{
    double newPos[3] = {balle->pos.x, balle->pos.y, balle->z};
    double coef_bounce;

    if (balle->pos.y <= 0 || is_hit_block) {
        bounce(balle, 'X', 0);
    } else if (balle->pos.y >= W_HEIGHT) {
        my_putstr("\n\n\n\n\tGAME OVER!!!\n\n\n\n");
        exit(0);
    }
    if (balle->pos.x <= 0 || balle->pos.x >= W_WIDTH)
        bounce(balle, 'Y', 0);
    if (balle->pos.y >= W_HEIGHT - PADDLE_HEIGHT - SPACE_PADDLE_Y) {
        if (balle->pos.x >= posPdle->x &&
        balle->pos.x <= posPdle->x + PADDLE_WIDTH) {
            coef_bounce = -(posPdle->x + PADDLE_WIDTH / 2 - balle->pos.x) / 8;
            bounce(balle, '.', coef_bounce);
        }
    }
    set_balle_pos(balle, newPos[0] + balle->vx, newPos[1] + balle->vy, 0);
    sfRectangleShape_setPosition(balle->rec, balle->pos);
}
