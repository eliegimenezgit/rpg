/*
** EPITECH PROJECT, 2019
** push to player
** File description:
** push
*/

#include "../../../include/header.h"

void anime_proj(game *obj)
{
    int i = 0;

    while (obj) {
        if (obj->scene == scene && obj->id == 's' && obj->eval != 0) {
            i = obj->lvl * 4;
            while (i > 1) {
                i = i - 1;
                anime_4(obj, 4, 32);
            }
        }
        obj = obj->next;
    }
}

void ajust_pos_proj(game *play, game *proj)
{
    if (play->rect->width > 0) {
        proj->d = 1;
        proj->pos->x = play->pos->x + 35;
        proj->pos->y = play->pos->y + 20;
    } else if (play->rect->width < 0) {
        proj->d = 0;
        proj->pos->x = play->pos->x;
        proj->pos->y = play->pos->y + 20;
    }
}

void push_to_player(game *p, game *tmp, game *gun, sfRenderWindow *window)
{
    sfVector2i pos_mouse =  sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = {pos_mouse.x , pos_mouse.y};
    sfVector2f AB = {10, 0};

    while (tmp->id != 's' || tmp->eval != 1) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    }
    ajust_pos_proj(p, tmp);
    tmp->direction = c_v(&mouse, tmp->pos, 20.0, AB);
    tmp->pos->x += tmp->direction.x * gun->lvl;
    tmp->pos->y += tmp->direction.y * gun->lvl;
    sfSprite_setPosition(tmp->sprite, *(tmp->pos));
    tmp->lvl = gun->lvl;
    anime_proj(tmp);
    tmp->eval = 2;
}
