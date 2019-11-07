/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** block manager
*/

#include "breakout.h"

static int is_hit(sfVector2f *p_bl, sfVector2f *p_ba)
{
    if (p_ba->x >= p_bl->x - 10 && p_ba->x <= p_bl->x + 10 + BLOCK_WIDTH) {
        if (p_ba->y >= p_bl->y - BLOCK_HEIGHT - 10 && p_ba->y <= p_bl->y)
            return 1;
    }
    return 0;
}

int eval_impact_block(window_t *w)
{
    if (w->balle.pos.y < 80 || w->balle.pos.y > 230)
        return 0;
    for (int i = 0; i < 112; i++) {
        if (w->block[i].block != NULL &&
        is_hit(&w->block[i].pos, &w->balle.pos)) {
            sfRectangleShape_destroy(w->block[i].block);
            w->block[i].block = NULL;
            return 1;
        }
    }
    return 0;
}
