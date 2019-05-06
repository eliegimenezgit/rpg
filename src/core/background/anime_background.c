/*
** EPITECH PROJECT, 2019
** anime_background.c
** File description:
** back
*/

#include "../../../include/header.h"

void anime_wate(game *w)
{
    sfVector2i all_rect[9] = {{0, 0}, {64, 0}, {128, 0}, {0, 64},
                                {64, 64}, {128, 64}, {0, 128}, {64, 128},
                                {128, 128}};

    if (w->nb_rect == 72)
        w->nb_rect = 1;
    w->rect->left = all_rect[w->nb_rect / 8].x;
    w->rect->top = all_rect[w->nb_rect / 8].y;
    w->nb_rect = w->nb_rect + 1;
}

void anime_tree(game *o, int speed)
{
    sfVector2i all_rect[4] = {{0, 0}, {64, 0}, {128, 0}, {0, 128}};

    if (o->nb_rect == 4 * speed)
        o->nb_rect = 1;
    o->rect->left = all_rect[o->nb_rect / speed].x;
    o->rect->top = all_rect[o->nb_rect / speed].y;
    o->nb_rect = o->nb_rect + 1;
}

void anime_background(game *obj)
{
    while (obj) {
        if (obj->scene == scene && obj->id == '1' && obj->eval != 0)
            anime_wate(obj);
        if (obj->scene == scene && obj->id == 'f' && obj->eval != 0)
            anime_4(obj, 8, 64);
        if (obj->scene == scene && obj->id == '4' && obj->eval != 0)
            anime_4(obj, 8, 64);
        if (obj->scene == scene && obj->id == 'a' && obj->eval != 0)
            anime_tree(obj, 8);
        if (obj->scene == scene && obj->id == 'n' && obj->eval != 0)
            anime_tree(obj, 8);
        if (obj->scene == scene && obj->id == '3' && obj->eval != 0)
            anime_tree(obj, 8);
        obj = obj->next;
    }
}
