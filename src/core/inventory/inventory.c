/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory
*/

#include "../../../include/header.h"

void move_inventory(game *obj)
{
    game *tmp = obj;

    while (obj->id != 'p' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    } while (tmp->id != 'i' || tmp->eval == 0) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    } (tmp->pos->x) = (obj->pos->x) - 300;
    (tmp->pos->y) = (obj->pos->y) - 180;
    sfSprite_setPosition(tmp->sprite, *(tmp->pos));
}
