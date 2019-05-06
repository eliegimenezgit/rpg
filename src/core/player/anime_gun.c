/*
** EPITECH PROJECT, 2019
** anime gun
** File description:
** gun
*/

#include "../../../include/header.h"

void mod_1(game *p, game *o)
{
    o->rect->width = 80;
    o->rect->left = 0;
    o->pos->x = p->pos->x + 50;
    o->pos->y = p->pos->y + 30;
    o->scene = scene;
}

void mod_2(game *p, game *o)
{
    o->rect->width = - 80;
    o->rect->left = o->rect->left + 80;
    o->pos->x = p->pos->x + 15;
    o->pos->y = p->pos->y + 30;
    o->scene = scene;
}

int anime_gun(game *p, game *o)
{
    sfVector2i all_rect[4] = {{0, 0}, {0, 30}, {0, 60}, {0, 90}};

    while (o->id != 'g' || o->eval == 0) {
        o = o->next;
        if (o == NULL)
            return (0);
    }
    o->rect->left = all_rect[o->lvl - 1].x;
    o->rect->top = all_rect[o->lvl - 1].y;
    if (o->mode == 1 && p->rect->width > 0) {
        mod_1(p, o);
    } else if (o->mode == 1 && p->rect->width < 0) {
        mod_2(p, o);
    }
    sfSprite_setPosition(o->sprite, *(o->pos));
    return (0);
}
