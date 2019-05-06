/*
** EPITECH PROJECT, 2019
** alloc
** File description:
** alooc
*/

#include "../../include/header.h"

void game_mod(game *new)
{
    if (new->id == 'i' || new->id == 'p')
        new->mode = 0;
    if (new->id == 'k' || new->id == 'g')
        new->mode = 0;
}

void mob_hp(game *new)
{
    if (new->id == 1 || new->id == 2)
        new->hp = new->id;
    if (new->id == 3 || new->id == 22 || new->id == 58)
        new->hp = new->id + 1;
    if (new->id == 6 || new->id == 12)
        new->hp = new->id * 2;
    if (new->id == 126)
        new->hp = new->id * 3;
}

void ajust_pos(game *obj)
{
    if (obj->id == 123)
        obj->pos->y = obj->pos->y - 24;
    if (obj->id == 'a' || obj->id == '3' || obj->id == 'n')
        obj->pos->y = obj->pos->y - 64;
    if (obj->id == 'h' || obj->id == 'j' || obj->id == 'o') {
        obj->pos->y = obj->pos->y - 252;
        obj->pos->x = obj->pos->x - 252;
    }
}
