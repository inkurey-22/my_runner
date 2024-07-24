/*
** EPITECH PROJECT, 2024
** my_runner
** File description:
** textures.c
*/

#include "runner.h"

static DIR *open_textures_dir(void)
{
    DIR *dir = opendir(TEXTURES_DIR);

    if (dir == NULL) {
        perror("opendir");
    }
    return dir;
}

static int is_image_file(const char *filename)
{
    return strstr(filename, ".png") || strstr(filename, ".jpg");
}

static textures_t *create_texture_node(const char *filename)
{
    textures_t *new_texture = malloc(sizeof(textures_t));
    char filepath[1024];

    if (new_texture == NULL) {
        perror("malloc");
        return NULL;
    }
    snprintf(filepath, sizeof(filepath), "%s/%s", TEXTURES_DIR, filename);
    new_texture->texture = sfTexture_createFromFile(filepath, NULL);
    if (new_texture->texture == NULL) {
        free(new_texture);
        return NULL;
    }
    new_texture->next = NULL;
    return new_texture;
}

textures_t *load_textures(void)
{
    DIR *dir = open_textures_dir();
    struct dirent *entry;
    textures_t *head = NULL;
    
    if (dir == NULL) {
        return NULL;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && is_image_file(entry->d_name)) {
            textures_t *new_texture = create_texture_node(entry->d_name);
            if (new_texture != NULL) {
                new_texture->next = head;
                head = new_texture;
            }
        }
    }
    closedir(dir);
    return head;
}

sfTexture *get_texture(char *name, textures_t *list)
{
    textures_t *tmp = list;

    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0)
            return tmp->texture;
        tmp = tmp->next;
    }
    return NULL;
}
