/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** create window
*/

#include "breakout.h"

window_t *create_window_menu(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {400, 200, 32};
    sfColor color = {255, 255, 255, 255};
    sfVector2f pos_txt = {30, 80};

    w->window = sfRenderWindow_create(mode, "101pong Breakout", sfClose, NULL);
    w->txr_bg = sfTexture_createFromFile(PATH_BG_IMG, NULL);
    w->spr_bg = sfSprite_create();
    sfSprite_setTexture(w->spr_bg, w->txr_bg, sfTrue);
    w->font = sfFont_createFromFile(PATH_FONT);
    if (!w->window || !w->txr_bg || !w->font)
        return NULL;
    w->txt_score = sfText_create();
    sfText_setFont(w->txt_score, w->font);
    sfText_setCharacterSize(w->txt_score, 15);
    sfText_setString(w->txt_score, "End Game\tClick to restart");
    sfText_setPosition(w->txt_score, pos_txt);
    w->color = color;
    return w;
}

void display_menu(window_t *w)
{
    sfRenderWindow_drawSprite(w->window, w->spr_bg, NULL);
    sfRenderWindow_drawText(w->window, w->txt_score, NULL);
    sfRenderWindow_display(w->window);
}

void destroy_window_menu(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    sfSprite_destroy(w->spr_bg);
    sfTexture_destroy(w->txr_bg);
    sfFont_destroy(w->font);
    sfText_destroy(w->txt_score);
}
