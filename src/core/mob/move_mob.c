/*
** EPITECH PROJECT, 2019
** move_mob
** File description:
** move
*/

#include "../../../include/header.h"

float calcule_angle(sfVector2f *pos_1, sfVector2f *pos_2, sfVector2f AB)
{
    sfVector2f AC = {pos_1->x - pos_2->x, pos_1->y - pos_2->y};
    float angle = ((AB.x * AC.x) + (AB.y * AC.y)) /
    (sqrt(pow(AB.x, 2) + pow(AB.y, 2)) * sqrt(pow(AC.x, 2) + pow(AC.y, 2)));
    angle = acos(angle);
    return (angle);
}

void rect_turn(game *obj)
{
    int width = (obj->rect->width < 0) ? obj->rect->width * -1
                                        : obj->rect->width;
    if (obj->d == 1) {
        obj->rect->width = -width;
        obj->rect->left = obj->rect->left + width;
    }else if (obj->d == 0) {
        obj->rect->width = width;
        obj->rect->left = obj->rect->left;
    }
}

void i_a_mob(game *m, game *p, int speed)
{
    sfVector2f AB = {10, 0};
    sfVector2f move = c_v(p->pos, m->pos, speed, AB);


    m->pos->x = m->pos->x + move.x;
    m->pos->y = m->pos->y + move.y;
    if (m->pos->x > p->pos->x) {
        m->d = 1;
    }else if (m->pos->x < p->pos->x) {
        m->d = 0;
    }
    rect_turn(m);
    sfSprite_setPosition(m->sprite, *(m->pos));
}

void ia_direct(game *tmp, game *obj)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 3 && obj->eval != 0)
            i_a_mob(obj, tmp, 6);
        if (obj->scene == scene && obj->id == 2 && obj->eval != 0)
            i_a_mob(obj, tmp, 5);
        if (obj->scene == scene && obj->id == 126 && obj->eval != 0)
            i_a_mob(obj, tmp, 4);
        if (obj->scene == scene && obj->id == 22 && obj->eval != 0)
            i_a_mob(obj, tmp, 6);
        if (obj->scene == scene && obj->id == 58 && obj->eval != 0)
            i_a_mob(obj, tmp, 7);
        if (obj->scene == scene && obj->id == 6 && obj->eval != 0)
            i_a_mob(obj, tmp, 7);
        if (obj->scene == scene && obj->id == 12 && obj->eval != 0)
            i_a_mob(obj, tmp, 8);
        obj = obj->next;
    }
}

void move_mob(game *obj)
{
    game *tmp = obj;

    while (tmp->id != 'p' || tmp->eval == 0) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    } ia_direct(tmp, obj);
}
