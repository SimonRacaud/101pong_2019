/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** display window
*/

#include "breakout.h"

int display(window_t *w)
{
    int is_block_hit;

    //sfRenderWindow_clear(w->window, sfBlack);
    sfRenderWindow_drawSprite(w->window, w->spr_bg, NULL);
    sfRenderWindow_drawText(w->window, w->txt_score, NULL);
    for (int i = 0; i < 112; i++)
        sfRenderWindow_drawRectangleShape(w->window, w->block[i].block, NULL);
    is_block_hit = eval_impact_block();
    move_balle(&(w->balle), &(w->posPaddle), is_block_hit);
    printf("POS: %f %f \n", w->balle.pos.x, w->balle.pos.y); // DEBUG
    sfRenderWindow_drawRectangleShape(w->window, w->balle.rec, NULL);
    sfRenderWindow_drawRectangleShape(w->window, w->paddle, NULL);
    sfRenderWindow_display(w->window);
    return 0;
}
