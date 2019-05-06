/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory
*/

#include "../../../include/header.h"

void inventory(game *p, game *obj)
{
    while (obj) {
        if (obj->id == 'v' && obj->eval != 0) {
            obj->pos->x = p->pos->x;
            obj->pos->y = p->pos->y - 15;
            sfSprite_setPosition(obj->sprite, *(obj->pos));
        }
        if (obj->id == 'k' && obj->eval != 0 && obj->mode == 1) {
            obj->pos->x = p->pos->x - 253;
            obj->pos->y = p->pos->y - 139;
            sfSprite_setPosition(obj->sprite, *(obj->pos));
        }
        obj = obj->next;
    }
}
