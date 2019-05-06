/*
** EPITECH PROJECT, 2019
** move key
** File description:
** key
*/

#include "../../../include/header.h"

void apply_move(game *obj, int speed, int nb)
{
    if (obj->z == 1 && nb == 1) {
        obj->pos->y = obj->pos->y - speed;
    }
    if (obj->q == 1 && nb != 1) {
        obj->pos->x = obj->pos->x - speed;
    }
    if (obj->s == 1 && nb == 1) {
        obj->pos->y = obj->pos->y + speed;
    }
    if (obj->d == 1 && nb != 1) {
        obj->pos->x = obj->pos->x + speed;
    }
}

void move_with_key(game *obj, int nb)
{
    obj->ex_pos->x = obj->pos->x;
    obj->ex_pos->y = obj->pos->y;
    apply_move(obj, (9 + (obj->lvl)), nb);
}
