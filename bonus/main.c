/*
** EPITECH PROJECT, 2019
** 101pong_2019
** File description:
** bonus breakout
*/

#include "breakout.h"

int main(void);

void main_menu(void)
{
    window_t *w_menu = create_window_menu();
    sfEvent event;

    if (!w_menu)
        return;
    while (sfRenderWindow_isOpen(w_menu->window)) {
        while (sfRenderWindow_pollEvent(w_menu->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(w_menu->window);
            } else if (event.type == sfEvtMouseButtonPressed) {
                sfRenderWindow_close(w_menu->window);
                main();
            }
        }
        display_menu(w_menu);
    }
    destroy_window_menu(w_menu);
}

static sfMusic *init_music(void)
{
    sfMusic *music = sfMusic_createFromFile(PATH_MUSIC);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

int main(void)
{
    sfEvent event;
    window_t *w = create_window();
    char is_exit = 0;
    sfMusic *main_music = init_music();

    create_el_window(w);
    if (!w || !main_music)
        return -1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(w->window);
                is_exit = 1;
            } else if (event.type == sfEvtMouseMoved)
                move_paddle(event.mouseMove.x, &w->posPaddle, w->paddle);
        }
        if (display(w))
            sfRenderWindow_close(w->window);
    }
    destroy_window(w);
    sfMusic_destroy(main_music);
    if (!is_exit)
        main_menu();
    return 0;
}
