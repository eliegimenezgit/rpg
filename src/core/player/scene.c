/*
** EPITECH PROJECT, 2019
** scene
** File description:
** scene
*/

#include "../../../include/header.h"

void change_scene(game *obj)
{
    if (obj->pos->y > 16 * 64 - 10) {
        scene = scene + 8;
        obj->pos->y = 10;
    }
    if (obj->pos->y < 10) {
        scene = scene - 8;
        obj->pos->y = 15 * 64 - 10;
    }
    if (obj->pos->x > 30 * 64 - 10) {
        scene = scene + 1;
        obj->pos->x = 10;
    }
    if (obj->pos->x < 10) {
        scene = scene - 1;
        obj->pos->x = 29 * 64 - 10;
    }
}
