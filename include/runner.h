/*
** EPITECH PROJECT, 2024
** my_runner
** File description:
** runner.h
*/

#ifndef RUNNER_H
    #define RUNNER_H

    #define TEXTURES_DIR "assets/textures/"
    #define MUSICS_DIR "assets/musics/"

    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>

    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <dirent.h>

/*
** PLAYER
*/
typedef struct player_s {
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    sfBool is_jumping;
} player_t;

player_t *create_player(void);
void update_player(player_t *player);

/*
** TEXTURE MANAGEMENT
*/
typedef struct textures_s {
    sfTexture *texture;
    char *name;
    struct textures_s *next;
} textures_t;

textures_t *load_textures(void);
sfTexture *get_texture(char *name, textures_t *list);

/*
** GAME BASE
*/
void handle_input(player_t *player);
void render(sfRenderWindow *window, player_t *player);

#endif
