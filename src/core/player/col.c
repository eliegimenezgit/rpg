/*
** EPITECH PROJECT, 2019
** col
** File description:
** col
*/

#include "../../../include/header.h"

int upgrade_gun(game *obj, game *p)
{
    while (obj) {
        if (obj->id == 'g' && obj->mode == 1 && obj->eval != 0) {
            obj->lvl = obj->lvl + 1;
        }
        obj = obj->next;
    }
    p->timer_max = p->timer_max - 9;
    return (1);
}

int col_hous(game *p, game *o, char id)
{
    while (o) {
        if (o->scene == scene && o->id == id && o->eval != 0) {
            if (p->pos->x > o->pos->x - 52 + 64 &&
                p->pos->x < o->pos->x + 52 + 250 &&
                p->pos->y > o->pos->y - 59 + 189 &&
                p->pos->y < o->pos->y + 59 + 440) {
                return (1);
            }
        }
        o = o->next;
    }
    return (0);
}

int col_play(game *p, game *o, char id, int dif)
{
    while (o) {
        if (o->scene == scene && o->id == id && o->eval == 1) {
            if (p->pos->x > o->pos->x - 53 &&
                p->pos->x < o->pos->x + 53 &&
                p->pos->y > o->pos->y - 59 + dif &&
                p->pos->y < o->pos->y + 59 + dif) {
                return (1);
            }
        }
        o = o->next;
    }
    return (0);
}

void collision(game *p, game *obj)
{
    new_collision(p, obj);
    local_pnl(obj, 2);
    if (col_play(p, obj, '#', 0) == 1)
        local_pnl(obj, 3);
    if (col_play(p, obj, 8, 0) == 1 || col_play(p, obj, 7, 0) == 1)
        local_pnl(obj, 3);
    if (col_play(p, obj, 9, 0) == 1 || col_play(p, obj, 10, 0) == 1)
        local_pnl(obj, 3);
}
