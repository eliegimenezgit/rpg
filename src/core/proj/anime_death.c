/*
** EPITECH PROJECT, 2019
** anime_death
** File description:
** anime
*/

#include "../../../include/header.h"

void anime_death(game *obj)
{
    sfVector2i all_rect[7] = {{0, 0}, {64, 0}, {128, 0}, {0, 64},
                                {64, 64}, {128, 64}, {0, 128}};

    while (obj) {
        if (obj->id == 'd' && obj->eval == 2) {
            obj->rect->left = all_rect[obj->nb_rect - 1].x;
            obj->rect->top = all_rect[obj->nb_rect - 1].y;
            obj->nb_rect = obj->nb_rect + 1;
            if (obj->nb_rect == 8)
                obj->eval = -1;
        }
        obj = obj->next;
    }
}
