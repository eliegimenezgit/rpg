/*
** EPITECH PROJECT, 2019
** new_obj.c
** File description:
** create obj
*/

#include "../../include/header.h"

void alloc_player(game *new)
{
    new->hp = 300;
    new->hp_max = 300;
    new->atk = 100;
    new->lvl = 1;
    new->timer = 0;
    new->timer_max = 30;
    new->z = 0;
    new->q = 0;
    new->s = 0;
    new->d = 0;
    new->f = 0;
    new->speed = 10;
    new->ex_pos = malloc(sizeof(sfVector2f));
    if (new->ex_pos == NULL) {
        game_mode = -1;
        return;
    }
    new->ex_pos->x = new->pos->x;
    new->ex_pos->y = new->pos->y;
}

void specific_alloc(game *new, game *obj)
{
    if (game_mode != -1)
        if (new->id == 'p')
            alloc_player(new);
    if (game_mode != -1)
        ajust_pos(new);
    if (game_mode != -1)
        text_or_graphic(new, obj);
    if (game_mode != -1)
        animation(new);
    if (game_mode != -1)
        game_mod(new);
    if (game_mode != -1)
        mob_hp(new);
    if (game_mode != -1)
        battle(new);
}

void new_obj(game *obj, int id, int scene, int pos)
{
    game *new = malloc(sizeof(game));

    new->pos = malloc(sizeof(sfVector2f));
    if (new == NULL || new->pos == NULL) {
        game_mode = -1;
        return;
    }
    new->pos->x = 64*(pos % 31);
    new->pos->y = 64*(pos / 31);
    new->id = id;
    new->eval = 1;
    new->scene = scene;
    specific_alloc(new, obj);
    while (obj->next)
        obj = obj->next;
    new->next = NULL;
    obj->next = new;
}
