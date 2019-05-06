/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** menu
*/

#include "../../include/header.h"

void quit_game(game *player, game *obj, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfColor color = {150, 150, 150, 150};
    sfColor normal = {255, 255, 255, 255};

    while (obj->id != 61 || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    if (mouse.x > obj->pos->x && mouse.x < obj->pos->x + 400) {
        if (mouse.y > obj->pos->y && mouse.y < obj->pos->y + 100) {
            sfSprite_setColor(obj->sprite, color);
            game_mode = (player->f == 1 ? -1 : game_mode);
        } else
            sfSprite_setColor(obj->sprite, normal);
    } else
        sfSprite_setColor(obj->sprite, normal);
}

void start_game(game *player, game *obj, sfRenderWindow *window)
{
    sfColor color = {150, 150, 150, 150};
    sfColor normal = {255, 255, 255, 255};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    while (obj->id != 59 || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    if (mouse.x > obj->pos->x && mouse.x < obj->pos->x + 400) {
        if (mouse.y > obj->pos->y && mouse.y < obj->pos->y + 100) {
            sfSprite_setColor(obj->sprite, color);
            game_mode = (player->f == 1 ? 0 : game_mode);
        } else
            sfSprite_setColor(obj->sprite, normal);
    } else
        sfSprite_setColor(obj->sprite, normal);
}

void anime_back(game *obj)
{
    sfVector2f scale2 = {2.5, 2.5};
    sfVector2f position = {1920 / 2, 1080 / 2};

    while (obj->id != 'z' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    sfSprite_setOrigin(obj->sprite, position);
    sfSprite_rotate(obj->sprite, 1.05);
    if (obj->eval == 1) {
        sfSprite_setScale(obj->sprite, scale2);
        obj->eval = 2;
    }
}

void pause_all(sound *son)
{
    while (son) {
        if (son->id != 'm')
            sfMusic_stop(son->music);
        son = son->next;
    }
}

void menu_music(sound *son)
{
    pause_all(son);
    if (play_or_stop('m', son) == 0)
        play_that('m', son, 1);
    if (game_mode == 0)
        play_that('m', son, 0);
}
