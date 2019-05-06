/*
** EPITECH PROJECT, 2019
** compte
** File description:
** compute
*/

#include "../../../include/header.h"

void respawn(game *player)
{
    if (scene < 43 && scene > 24) {
        scene = 40;
        player->pos->x = 900;
        player->pos->y = 500;
    } if (scene < 20 && scene > 0) {
        scene = 19;
        player->pos->x = 900;
        player->pos->y = 500;
    } if (scene == 71 || scene == 70 || (scene < 63 && scene > 51)) {
        scene = 43;
        player->pos->x = 900;
        player->pos->y = 500;
    } if (scene == 68 || scene == 69 || (scene < 80 && scene > 76)) {
        scene = 79;
        player->pos->x = 900;
        player->pos->y = 500;
    }
    player->hp = 1;
}

int anime_vita(game *p, game *obj)
{
    sfVector2i all_rect[17] = {{0, 0}, {0, 4}, {0, 8}, {0, 12},
                                {0, 16}, {0, 20}, {0, 24}, {0, 28},
                                {0, 32}, {0, 36}, {0, 40}, {0, 44},
                                {0, 48}, {0, 52}, {0, 56}, {0, 60},
                                {0, 64}};

    while (obj->id != 'v' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return (0);
    }
    if (obj->nb_rect == 17)
        obj->nb_rect = 1;
    obj->rect->left = all_rect[obj->nb_rect].x;
    obj->rect->top = all_rect[obj->nb_rect].y;
    obj->nb_rect = (p->hp_max - p->hp) / (p->hp_max / 16);
    return (1);
}

int compute_xp(int timer, int max)
{
    int i = 0;
    int nb = 0;
    int posib = (max * 100 / 16);

    if (timer >= max)
        return (17);
    while (nb < timer * 100) {
        nb = posib * i;
        i = i + 1;
    }
    return (i);
}

void anime_xp(game *p, game *obj)
{
    game *tmp = obj;
    sfVector2i all_rect[17] = {{0, 64}, {0, 60}, {0, 56}, {0, 52},
    {0, 48}, {0, 44}, {0, 40}, {0, 36}, {0, 32}, {0, 28}, {0, 24}, {0, 20},
    {0, 16}, {0, 12}, {0, 8}, {0, 4}, {0, 0}};

    while (tmp->id != 'g' || tmp->eval == 0) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    } while (obj->id != 'x' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    obj->rect->left = all_rect[obj->nb_rect].x;
    obj->rect->top = all_rect[obj->nb_rect].y;
    obj->nb_rect = compute_xp(tmp->timer, p->timer_max);
    obj->pos->x = p->pos->x;
    obj->pos->y = p->pos->y - 8;
    sfSprite_setPosition(obj->sprite, *(obj->pos));
}

void compute_player(game *p, game *obj)
{
    if (col_play(p, obj, 2, 0) == 1 || col_play(p, obj, 1, 0) == 1) {
        p->hp = p->hp - 2;
    } if (col_play(p, obj, 3, 0) == 1) {
        p->hp = p->hp - 3;
    } if (col_play(p, obj, 22, 0) == 1) {
        p->hp = p->hp - 10;
    } if (col_play(p, obj, 58, 0) == 1) {
        p->hp = p->hp - 15;
    } if (col_play(p, obj, 6, 0) == 1) {
        p->hp = p->hp - 5;
    } if (col_play(p, obj, 12, 0) == 1) {
        p->hp = p->hp - 6;
    } if (col_play(p, obj, 126, 0) == 1) {
        p->hp = p->hp - 10;
    } anime_vita(p, obj);
    anime_xp(p, obj);
    if (p->hp < 0)
        respawn(p);
}
