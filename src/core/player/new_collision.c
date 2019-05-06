/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** new colision
*/

#include "../../../include/header.h"

int check_id(int id, int *get_id)
{
    int incre = 0;
    char str[14] = "hjo1yuclm3an\0";

    while (str[incre] != '\0') {
        if (str[incre] == id) {
            *get_id = incre;
            return (1);
        }
        ++incre;
    }
    return (0);
}

sfIntRect give_col(int id, sfVector2f *position)
{
    int col = 0;
    sfIntRect object = {position->x, position->y, 60, 60};
    sfIntRect all_col[5] = {{0, 0, 60, 60}, {8, 70, 45, 50},
    {70, 220, 240, 285}, {20, 30, 25, 25}, {10, 10, 40, 40}};

    if (id >= 9)
        col = 1;
    if (id < 3)
        col = 2;
    if (id == 6)
        col = 3;
    if (id == 8)
        col = 4;
    all_col[col].left += object.left;
    all_col[col].top += object.top;
    return (all_col[col]);
}

int distance(sfVector2f *object, sfVector2f *player)
{
    int distance = sqrt(pow(player->x - object->x, 2)
                    + pow(player->y - object->y, 2));
    if (distance <= 580) {
        return (1);
    }
    return (0);
}

void specific_col(game *p, game *o, game *save)
{
    if (o->id == 'u' && upgrade_gun(save, p) == 1){
        o->eval = -1;
        return;
    }
    if (o->id == 'c')
        p->hp = p->hp_max;
    p->pos->x = p->ex_pos->x;
    p->pos->y = p->ex_pos->y;
    return;
}

void new_collision(game *p, game *o)
{
    game *save = o;
    sfIntRect player = {p->pos->x, p->pos->y, p->rect->width, p->rect->height};
    sfIntRect col;
    int get_id = -1;

    if (player.width < 0)
        player.width = player.width * -1;
    while (o) {
        if (o->scene == scene && o->eval == 1 && check_id(o->id, &get_id) == 1
            && distance(o->pos, p->pos)) {
            col = give_col(get_id, o->pos);
            if (sfIntRect_intersects(&col, &player, NULL)){
                specific_col(p, o, save);
                return;
            }
        }
        o = o->next;
    }
}