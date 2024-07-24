/*
** EPITECH PROJECT, 2024
** my_runner
** File description:
** main.c
*/

#include "runner.h"

void event_manager(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int main(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
        "My Runner", sfClose, NULL);

    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        event_manager(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
