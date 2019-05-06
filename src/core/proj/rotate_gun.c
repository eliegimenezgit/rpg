/*
** EPITECH PROJECT, 2019
** rotate_gun.c
** File description:
** rotate
*/

#include "../../../include/header.h"

void rotate_gun(game *gun, sfRenderWindow *window)
{
    sfVector2f AB = {10, 0};
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = {pos.x, pos.y};
    sfVector2f origine = {2, gun->rect->height / 2 - 5};
    float angle = 0.0;

    if (gun->rect->width < 0){
        AB.x = -10;
        origine.x = -gun->rect->width;
    }
    angle = calcule_angle(&mouse, gun->pos, AB) * 180 / M_PI;
    if (pos.y < gun->pos->y && gun->rect->width > 0)
        angle = angle * -1;
    else if ((pos.y > gun->pos->y && gun->rect->width < 0))
        angle = angle * -1;
    sfSprite_setOrigin(gun->sprite, origine);
    sfSprite_setRotation(gun->sprite, angle);
}
