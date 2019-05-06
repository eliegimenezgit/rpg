/*
** EPITECH PROJECT, 2019
** alloc_battle
** File description:
** battle
*/

#include "../../include/header.h"

void alloc_proj(game *new)
{
    new->d = 0;
    new->lvl = 1;
    new->timer = 0;
}

void battle(game *new)
{
    if (new->id == 's' || new->id == 'g')
        alloc_proj(new);
}
