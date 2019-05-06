/*
** EPITECH PROJECT, 2019
** rm_proj
** File description:
** proj
*/

#include "../../../include/header.h"

int check_monster(sfVector2f *proj, game *obj)
{
    int enemy_col = -1;
    sfFloatRect enemy[3] = {{100, 100, 150, 150}, {45, 60, 140, 80},
                            {120, 75, 260, 172}};
    if (obj->id == 22 )
        enemy_col = 0;
    if (obj->id == 58 )
        enemy_col = 1;
    if (obj->id == 126)
        enemy_col = 2;
    if (enemy_col != -1) {
        enemy[enemy_col].top = obj->pos->y - enemy[enemy_col].top;
        enemy[enemy_col].left = obj->pos->x - enemy[enemy_col].left;
        if (sfFloatRect_contains(&enemy[enemy_col], proj->x, proj->y))
            return (1);
    }
    return (0);
}

int is_contact(sfVector2f *proj, sfVector2f *obj, int id)
{
    sfFloatRect house = {0, 130, 310, 370};

    if (id == 'h' || id == 'o' || id == 'j'){
        house.top = house.top + obj->y;
        house.left = house.left + obj->x;
        if (sfFloatRect_contains(&house, proj->x, proj->y)) {
            return (1);
        }
    }else {
        if (proj->x + 10 > obj->x && proj->x + 10 < obj->x + 64
        && proj->y + 10 > obj->y && proj->y + 10 < obj->y + 64) {
            return (1);
        }
    }
    return (0);
}

void return_col(game *proj, game *obj, game *tmp, sound *son)
{
    if (col_proj_decor(proj, obj, tmp, son) == 1)
        return;
    if (col_proj_mob(proj, obj, tmp, son) == 1)
        return;
}

void check_proj(game *proj, game *obj, sound *son)
{
    game *tmp = obj;

    while (obj) {
        if (obj->scene == scene && obj->eval != 0 ) {
            if (check_monster(proj->pos, obj) == 1 ||
            is_contact(proj->pos, obj->pos, obj->id) == 1) {
                return_col(proj, obj, tmp, son);
            }
        }
        obj = obj->next;
    }
}

void rm_proj(game *obj, game *tmp, sound *son)
{
    while (obj) {
        if (obj->id == 's' && obj->eval == 2 && obj->scene == scene) {
            check_proj(obj, tmp, son);
            if (obj->timer > 40)
                new_death(obj, tmp, son);
        }
        obj = obj->next;
    }
}
