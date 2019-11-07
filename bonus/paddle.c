/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** Paddle manager
*/

#include "breakout.h"

void move_paddle(int x, sfVector2f *posPaddle, sfRectangleShape *paddle)
{
    if (x >= PADDLE_WIDTH / 2 && x <= W_WIDTH - PADDLE_WIDTH / 2) {
        posPaddle->x = x - PADDLE_WIDTH / 2;
        sfRectangleShape_setPosition(paddle, *posPaddle);
    }
}
