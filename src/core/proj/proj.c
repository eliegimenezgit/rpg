/*
** EPITECH PROJECT, 2019
** proj
** File description:
** proj
*/

#include "../../../include/header.h"

void move_proj(game *obj)
{
    while (obj) {
        if (obj->id == 's' && obj->eval == 2) {
            obj->timer = obj->timer + 1;
            sfSprite_move(obj->sprite, obj->direction);
            *(obj->pos) = sfSprite_getPosition(obj->sprite);
        }
        obj = obj->next;
    }
}

void proj_2(game *play, game *obj, sfRenderWindow *window, sound *son)
{
    game *gun = obj;

    while (gun->id != 'g' || gun->eval == 0) {
        gun = gun->next;
        if (gun == NULL)
            return;
    }
    if (gun->mode == 1)
        rotate_gun(gun, window);
    if (play->f == 1) {
        if (gun->mode == 1 && gun->timer > play->timer_max) {
            new_obj(obj, 's', scene, 0);
            play_that('t', son, 1);
            push_to_player(play, obj, gun, window);
            gun->timer = 0;
        }
    }
    gun->timer = gun->timer + 1;
    move_proj(obj);
    rm_proj(obj, obj, son);
}

void proj(game *obj, sfRenderWindow *window, sound *son)
{
    game *tmp = obj;

    while (obj->id != 'p' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    proj_2(obj, tmp, window, son);
}
