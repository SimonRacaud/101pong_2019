/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** create window
*/

#include "breakout.h"

static void create_blocks(window_t *w)
{
    sfVector2f size_block = {BLOCK_WIDTH, BLOCK_HEIGHT};
    int row = 0;
    int column = 0;

    w->block = malloc(sizeof(block_t) * 112);
    if (w->block == NULL)
        exit(-1);
    for (int i = 0; i < 112; i++) {
        w->block[i].block = sfRectangleShape_create();
        sfRectangleShape_setFillColor(w->block[i].block, w->color);
        sfRectangleShape_setSize(w->block[i].block, size_block);
        w->block[i].pos.x = column * (BLOCK_WIDTH + SPACE_BLOCK_X);
        w->block[i].pos.y = SP_TOP_BLK + row * (BLOCK_HEIGHT + SPACE_BLOCK_Y);
        sfRectangleShape_move(w->block[i].block, w->block[i].pos);
        row++;
        if (row == 8) {
            row = 0;
            column++;
        }
    }
}

void create_el_window(window_t *w)
{
    sfVector2f size_paddle = {PADDLE_WIDTH, PADDLE_HEIGHT};
    sfVector2f size_balle = {BALLE_SIZE, BALLE_SIZE};

    w->paddle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(w->paddle, w->color);
    sfRectangleShape_setSize(w->paddle, size_paddle);
    w->posPaddle.y = W_HEIGHT - PADDLE_HEIGHT - SPACE_PADDLE_Y;
    w->posPaddle.x = (W_WIDTH / 2) - (PADDLE_WIDTH / 2);
    sfRectangleShape_move(w->paddle, w->posPaddle);
    w->balle.rec = sfRectangleShape_create();
    sfRectangleShape_setFillColor(w->balle.rec, w->color);
    sfRectangleShape_setSize(w->balle.rec, size_balle);
    set_balle_pos(&(w->balle), INIT_BALLE_PX, INIT_BALLE_PY, INIT_BALLE_PZ);
    set_balle_vel(&(w->balle), 0, INIT_SPEED, 0);
    sfRectangleShape_move(w->balle.rec, (w->balle.pos));
    create_blocks(w);
    w->score = 0;
    sfRenderWindow_setMouseCursorVisible(w->window, sfFalse);
}

window_t *create_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, 32};
    sfColor color = {255, 255, 255, 255};
    sfVector2f pos_score = {SCORE_POS_X, SCORE_POS_Y};

    w->window = sfRenderWindow_create(mode, "101pong Breakout", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w->window, FRAMERATE);
    w->txr_bg = sfTexture_createFromFile(PATH_BG_IMG, NULL);
    w->spr_bg = sfSprite_create();
    sfSprite_setTexture(w->spr_bg, w->txr_bg, sfTrue);
    w->font = sfFont_createFromFile(PATH_FONT);
    if (!w->window || !w->txr_bg || !w->font)
        return NULL;
    w->txt_score = sfText_create();
    sfText_setFont(w->txt_score, w->font);
    sfText_setCharacterSize(w->txt_score, CHAR_SIZE);
    sfText_setString(w->txt_score, "000");
    sfText_setPosition(w->txt_score, pos_score);
    w->color = color;
    return w;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    sfSprite_destroy(w->spr_bg);
    sfTexture_destroy(w->txr_bg);
    sfFont_destroy(w->font);
    sfText_destroy(w->txt_score);
    sfRectangleShape_destroy(w->paddle);
    sfRectangleShape_destroy(w->balle.rec);
    for (int i = 0; i < 112; i++) {
        if (&w->block[i].block != NULL)
            sfRectangleShape_destroy(w->block[i].block);
    }
    free(w->block);
}
