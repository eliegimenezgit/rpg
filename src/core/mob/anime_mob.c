/*
** EPITECH PROJECT, 2019
** anime
** File description:
** aniem
*/

#include "../../../include/header.h"

void anime_4(game *o, int speed, int size)
{
    sfVector2i all_rect[4] = {{0, 0}, {size, 0}, {0, size}, {size, size}};

    if (o->nb_rect == 4 * speed)
        o->nb_rect = 1;
    o->rect->left = all_rect[o->nb_rect / speed].x;
    o->rect->top = all_rect[o->nb_rect / speed].y;
    o->nb_rect = o->nb_rect + 1;
}

void anime_boss(game *o, int speed)
{
    sfVector2i all_rect[4] = {{0, 0}, {384, 0}, {0, 256}, {384, 256}};

    if (o->nb_rect == 4 * speed)
        o->nb_rect = 1;
    o->rect->left = all_rect[o->nb_rect / speed].x;
    o->rect->top = all_rect[o->nb_rect / speed].y;
    o->nb_rect = o->nb_rect + 1;
}

void anime_fly(game *obj, int speed)
{
    sfVector2i all_rect[8] = {{0, 0}, {192, 0}, {384, 0}, {0, 192},
                                {192, 192}, {384, 192}, {0, 384}, {192, 384}};

    if (obj->nb_rect == 8 * speed)
        obj->nb_rect = 1;
    obj->rect->left = all_rect[obj->nb_rect / speed].x;
    obj->rect->top = all_rect[obj->nb_rect / speed].y;
    obj->nb_rect = obj->nb_rect + 1;
}

void anime_scorp(game *obj, int speed)
{
    sfVector2i all_rect[6] = {{0, 0}, {192, 0}, {0, 192}, {192, 192},
                                {0, 384}, {192, 384}};

    if (obj->nb_rect == 6 * speed)
        obj->nb_rect = 1;
    obj->rect->left = all_rect[obj->nb_rect / speed].x;
    obj->rect->top = all_rect[obj->nb_rect / speed].y;
    obj->nb_rect = obj->nb_rect + 1;
}

void anime_mob(game *obj)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 3 && obj->eval != 0)
            anime_4(obj, 4, 64);
        if (obj->scene == scene && obj->id == 6 && obj->eval != 0)
            anime_4(obj, 4, 64);
        if (obj->scene == scene && obj->id == 2 && obj->eval != 0)
            anime_4(obj, 4, 64);
        if (obj->scene == scene && obj->id == 1 && obj->eval != 0)
            anime_4(obj, 4, 64);
        if (obj->scene == scene && obj->id == 126 && obj->eval != 0)
            anime_boss(obj, 4);
        if (obj->scene == scene && obj->id == 22 && obj->eval != 0)
            anime_fly(obj, 4);
        if (obj->scene == scene && obj->id == 58 && obj->eval != 0)
            anime_scorp(obj, 4);
        if (obj->scene == scene && obj->id == 12 && obj->eval != 0)
            anime_4(obj, 5, 64);
        obj = obj->next;
    }
}
