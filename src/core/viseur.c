/*
** EPITECH PROJECT, 2019
** viseur
** File description:
** viseur
*/

#include "../../include/header.h"

void viseur(game *obj, sfRenderWindow *window)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

    while (obj->next) {
        if (obj->id == 'b' && obj->eval != 0) {
            if (obj->eval == 1) {
                sfRenderWindow_setMouseCursorVisible(window, sfFalse);
                obj->eval = 2;
            }
            obj->pos->x = pos_mouse.x;
            obj->pos->y = pos_mouse.y;
            sfSprite_setPosition(obj->sprite, *(obj->pos));
        }
        obj = obj->next;
    }
}
