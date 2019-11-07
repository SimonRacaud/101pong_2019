/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** bonus breakout
*/

#include "breakout.h"

int main(void)
{
    sfEvent event;
    window_t *w = create_window();

    create_el_window(w);
    if (!w)
        return -1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(w->window);
        }
        display(w);
    }
    destroy_window(w);
    return 0;
}
