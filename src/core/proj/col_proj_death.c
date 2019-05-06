/*
** EPITECH PROJECT, 2019
** rm_proj
** File description:
** proj
*/

#include "../../../include/header.h"

void new_death(game *proj, game *tmp, sound *son)
{
    play_that('e', son, 1);
    proj->eval = -1;
    new_obj(tmp, 'd', scene, 0);
    while (tmp) {
        if (tmp->id == 'd' && tmp->eval == 1) {
            tmp->pos->x = proj->pos->x;
            tmp->pos->y = proj->pos->y;
            sfSprite_setPosition(tmp->sprite, *(tmp->pos));
            tmp->eval = 2;
        }
        tmp = tmp->next;
    }
}

int col_proj_decor(game *proj, game *obj, game *tmp, sound *son)
{
    if (obj->id == 'y' || obj->id == 'm' || obj->id == 'a'
        || obj->id == 'n' || obj->id == '3' || obj->id == 'h'
        || obj->id == 'o' || obj->id == 'j' || obj->id == 'l') {
        new_death(proj, tmp, son);
        return (1);
    }
    return (0);
}

int col_proj_mob(game *proj, game *obj, game *tmp, sound *son)
{
    if (obj->id == 2 || obj->id == 3 || obj->id == 1 || obj->id == 6 ||
        obj->id == 22 || obj->id == 58 || obj->id == 12 || obj->id == 126) {
        if (obj->id == 126 && obj->hp < 1) {
            obj->eval = -1;
            game_mode = 3;
        } else if (obj->hp < 1){
            obj->eval = -1;
        } else {
            obj->hp = obj->hp - proj->lvl;
        }
        new_death(proj, tmp, son);
        return (1);
    }
    return (0);
}
