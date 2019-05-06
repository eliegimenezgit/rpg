/*
** EPITECH PROJECT, 2019
** panel check
** File description:
** local pnl
*/

#include "../../../include/header.h"

void local_pnl(game *o, int eval)
{
    while (o) {
        if (o->scene == scene && o->id == 't' && o->eval != 0)
            o->eval = eval;
        o = o->next;
    }
}
