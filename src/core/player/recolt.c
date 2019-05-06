/*
** EPITECH PROJECT, 2019
** recolt
** File description:
** recolt
*/

#include "../../../include/header.h"

void recolt(game *p, game *obj)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 'k' && obj->eval != 0) {
            if (col_play(p, obj, 'k', 0) == 1) {
                obj->mode = 1;
            }
        }
        if (obj->scene == scene && obj->id == 'g' && obj->eval != 0) {
            if (col_play(p, obj, 'g', 0) == 1) {
                obj->mode = 1;
            }
        }
        obj = obj->next;
    }
}
