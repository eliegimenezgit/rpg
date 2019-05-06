/*
** EPITECH PROJECT, 2019
** alloc_anime
** File description:
** anime
*/

#include "../../include/header.h"

void alloc_anime_other(game *new)
{
    sfVector2f position = {192 / 2, 192 / 2};

    new->rect = malloc(sizeof(sfIntRect));
    if (new->rect == NULL)  {
        game_mode = -1;
        return;
    }
    if (new->id == 22 || new->id == 58) {
        new->rect->width = 192;
        new->rect->height = 192;
    }
    sfSprite_setOrigin(new->sprite, position);
    new->nb_rect = 1;
}

void alloc_anime(game *new)
{
    sfVector2f position = {384 / 2, 256 / 2};

    new->rect = malloc(sizeof(sfIntRect));
    new->rect->width = 64;
    new->rect->height = 64;
    if (new->id == 'a' || new->id == '3' || new->id == 'n') {
        new->rect->height = 128;
    } if (new->id == 126) {
        new->rect->width = 384;
        new->rect->height = 256;
        sfSprite_setOrigin(new->sprite, position);
    } if (new->id == 'g') {
        new->rect->width = 80;
        new->rect->height = 30;
    } if (new->id == 'v' || new->id == 'x') {
        new->rect->height = 4;
    } if (new->id == 's') {
        new->rect->width = 32;
        new->rect->height = 32;
    } new->nb_rect = 1;
}

void animation(game *new)
{
    if (new->id == 'p' || new->id == '1' || new->id == 'f' || new->id == 1)
        alloc_anime(new);
    if (new->id == 2 || new->id == 126 || new->id == 'g' || new->id == 'v')
        alloc_anime(new);
    if (new->id == 'a' || new->id == 's' || new->id == 'x')
        alloc_anime(new);
    if (new->id == 'd' || new->id == '3' || new->id == '4' || new->id == 3)
        alloc_anime(new);
    if (new->id == 7 || new->id == 8 || new->id == 9 || new->id == 10)
        alloc_anime(new);
    if (new->id == 'n' || new->id == 6 || new->id == 12)
        alloc_anime(new);
    if (new->id == 22 || new->id == 58)
        alloc_anime_other(new);
}
