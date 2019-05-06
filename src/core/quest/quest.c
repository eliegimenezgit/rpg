/*
** EPITECH PROJECT, 2019
** quest
** File description:
** quest
*/

#include "../../../include/header.h"

void quest(game *obj)
{
    game *tmp = obj;

    while (obj) {
        if (obj->id == 22 && obj->eval == -1) {
            new_obj(tmp, 'u', 26, 262);
            return;
        }
        if (obj->id == 58 && obj->eval == -1) {
            new_obj(tmp, 'u', 1, 261);
            new_obj(tmp, 'k', 1, 263);
            return;
        }
        obj = obj->next;
    }
}
