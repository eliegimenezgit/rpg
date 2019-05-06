/*
** EPITECH PROJECT, 2019
** core_game
** File description:
** compute of game
*/

#include "../../include/header.h"

void rm_obj(game *obj)
{
    while (obj->next->next) {
        if (obj->next->eval == -1) {
            obj->next = obj->next->next;
        } else
            obj = obj->next;
    }
}

void anime_npc(game *obj)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 7 && obj->eval != 0)
            anime_4(obj, 8, 64);
        if (obj->scene == scene && obj->id == 8 && obj->eval != 0)
            anime_4(obj, 8, 64);
        if (obj->scene == scene && obj->id == 9 && obj->eval != 0)
            anime_4(obj, 8, 64);
        if (obj->scene == scene && obj->id == 10 && obj->eval != 0)
            anime_4(obj, 8, 64);
        obj = obj->next;
    }
}

void core_game(game *obj, sfRenderWindow *window, sound *son)
{
    viseur(obj, window);
    player_move(obj, window);
    anime_mob(obj);
    move_mob(obj);
    proj(obj, window, son);
    anime_background(obj);
    anime_npc(obj);
    anime_death(obj);
    move_inventory(obj);
    quest(obj);
    rm_obj(obj);
    background_sound(son);
}
