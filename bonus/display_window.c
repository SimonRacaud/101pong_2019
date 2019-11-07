/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** display window
*/

#include "breakout.h"

static void update_score(window_t *w)
{
    char str_score[4] = "000";
    int score = w->score + 1;
    int i = 2;

    if (w->score < 999)
        w->score++;
    while (score >= 1) {
        str_score[i--] = score % 10 + '0';
        score /= 10;
    }
    sfText_setString(w->txt_score, str_score);
}

int display(window_t *w)
{
    int is_block_hit = 0;

    sfRenderWindow_drawSprite(w->window, w->spr_bg, NULL);
    sfRenderWindow_drawText(w->window, w->txt_score, NULL);
    for (int i = 0; i < 112; i++) {
        if (w->block[i].block == NULL)
            continue;
        sfRenderWindow_drawRectangleShape(w->window, w->block[i].block, NULL);
    }
    is_block_hit = eval_impact_block(w);
    if (is_block_hit)
        update_score(w);
    move_balle(&(w->balle), &(w->posPaddle), is_block_hit);
    sfRenderWindow_drawRectangleShape(w->window, w->balle.rec, NULL);
    sfRenderWindow_drawRectangleShape(w->window, w->paddle, NULL);
    sfRenderWindow_display(w->window);
    return 0;
}
