/*
** EPITECH PROJECT, 2019
** playermove
** File description:
** move
*/

#include "../../../include/header.h"

void player_move(game *obj, sfRenderWindow *window)
{
    game *tmp = obj;

    while (obj->id != 'p' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    move_with_key(obj, 1);
    collision(obj, tmp);
    move_with_key(obj, 2);
    collision(obj, tmp);
    recolt(obj, tmp);
    inventory(obj, tmp);
    anime_player(obj, window);
    change_scene(obj);
    compute_player(obj, tmp);
    tp(obj, tmp);
    sfSprite_setPosition(obj->sprite, *(obj->pos));
    sfSprite_setTextureRect(obj->sprite, *(obj->rect));
    anime_gun(obj, tmp);
}
