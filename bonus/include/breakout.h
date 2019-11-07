/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** header
*/

#ifndef H_BREAKOUT
#define H_BREAKOUT

#include <stdlib.h>
#include <SFML/Graphics.h>

#define PATH_BG_IMG "wp1.jpg"
#define PATH_FONT "Pixeled.ttf"
#define W_HEIGHT 900
#define W_WIDTH 700
#define CHAR_SIZE 40
#define FRAMERATE 60

#define SP_TOP_BLK 80
#define SPACE_BLOCK_X 10
#define SPACE_BLOCK_Y 10
#define BLOCK_WIDTH (W_WIDTH - SPACE_BLOCK_X * 12) / 14
#define BLOCK_HEIGHT 10

#define PADDLE_WIDTH 150
#define PADDLE_HEIGHT 16
#define SPACE_PADDLE_Y 10
#define BALLE_SIZE 8
#define INIT_SPEED 5

#define INIT_BALLE_PX W_WIDTH / 2 - BALLE_SIZE / 2
#define INIT_BALLE_PY W_HEIGHT / 3
#define INIT_BALLE_PZ 0

#define SCORE_POS_X W_WIDTH - 130
#define SCORE_POS_Y 20

typedef struct balle {
    sfRectangleShape *rec;
    sfVector2f pos;
    double z;
    double vx;
    double vy;
    double vz;
} balle_t;

typedef struct block {
    sfRectangleShape *block;
    sfVector2f pos;
} block_t;

typedef struct window {
    sfRenderWindow *window;
    sfTexture *txr_bg;
    sfSprite *spr_bg;
    sfFont *font;
    sfText *txt_score;
    sfRectangleShape *paddle;
    block_t *block;
    balle_t balle;
    sfColor color;
    sfVector2f posPaddle;
    int score;
} window_t;

window_t *create_window(void);
void create_el_window(window_t *w);
void destroy_window(window_t *w);
int display(window_t *w);

void move_balle(balle_t *balle, sfVector2f *posPaddle, int is_hit_block);
void set_balle_pos(balle_t *balle, double x, double y, double z);
void set_balle_vel(balle_t *balle, double vx, double vy, double vz);

#endif
