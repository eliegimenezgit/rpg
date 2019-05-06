/*
** EPITECH PROJECT, 2019
** anime
** File description:
** anime
*/

#include "../../../include/header.h"

void dont_move_anime(game *p, int val)
{
    sfVector2i all_rect[6] = {{0, 0}, {64, 0}, {128, 0}, {0, 64},
                    {64, 64}, {128, 64}};
    if (p->nb_rect > 6)
        p->nb_rect = 1;
    p->rect->left = all_rect[p->nb_rect - 1].x + val;
    p->rect->top = all_rect[p->nb_rect - 1].y;
    p->nb_rect = p->nb_rect + 1;
}

void move_anime(game *p, int val)
{
    sfVector2i all_rect[4] = {{128, 64}, {0, 128}, {64, 128}, {128, 128}};
    if (p->nb_rect < 6 || p->nb_rect > 9)
        p->nb_rect = 6;
    p->rect->left = all_rect[p->nb_rect - 6].x + val;
    p->rect->top = all_rect[p->nb_rect - 6].y;
    p->nb_rect = p->nb_rect + 1;
}

void anime_player(game *p, sfRenderWindow *window)
{
    int value = 0;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

    if (pos_mouse.x < p->pos->x)
        p->rect->width = - 64;
    if (pos_mouse.x >= p->pos->x)
        p->rect->width = 64;
    if (p->rect->width == -64)
        value = 64;
    if (p->z == 0 && p->q == 0 && p->s == 0 && p->d == 0) {
        dont_move_anime(p, value);
    } else {
        move_anime(p, value);
    }
}
