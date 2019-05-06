/*
** EPITECH PROJECT, 2019
** init
** File description:
** init obj.c
*/

#include "../include/header.h"

void init(game *obj, char id, char *path)
{
    game *new = malloc(sizeof(game));

    if (new == NULL)  {
        game_mode = -1;
        return;
    }
    new->path = my_dup(path);
    if (new->path == NULL)
        game_mode = -1;
    new->eval = 0;
    new->id = id;
    new->next = NULL;
    if (obj == NULL)
        obj = new;
    else {
        while (obj->next)
            obj = obj->next;
        obj->next = new;
    }
}

void init_obj3(game *obj)
{
    init(obj, 'm', "./res/rock.png");
    init(obj, 'p', "./res/play.png");
    init(obj, 'q', "./res/point.png");
    init(obj, 'r', "./res/roche.png");
    init(obj, 's', "./res/proj.png");
    init(obj, 't', "./res/9.TTF");
    init(obj, 200, "./res/9.TTF");
    init(obj, 'u', "./res/up.png");
    init(obj, 'v', "./res/hp.png");
    init(obj, 'w', "./res/wood.png");
    init(obj, 'x', "./res/xp.png");
    init(obj, 'y', "./res/brick.png");
    init(obj, 126, "./res/boss.png");
    init(obj, 22, "./res/fly.png");
}

void init_obj2(game *obj)
{
    init(obj, 9, "./res/NPC3.png");
    init(obj, 10, "./res/NPC4.png");
    init(obj, 58, "./res/scorp.png");
    init(obj, 'f', "./res/flo.png");
    init(obj, 59, "./res/start.png");
    init(obj, 60, "./res/option.png");
    init(obj, 61, "./res/quit.png");
    init(obj, 'z', "./res/back.png");
    init(obj, 123, "./res/Logo.png");
    init(obj, 12, "./res/mob5.png");
    init(obj, 'g', "./res/gun.png");
    init(obj, 'h', "./res/hous.png");
    init(obj, 'i', "./res/bag.png");
    init(obj, 'j', "./res/hous3.png");
    init(obj, 'k', "./res/key.png");
    init(obj, 'l', "./res/invisible.png");
    init(obj, 'n', "./res/treen.png");
    init(obj, 'o', "./res/hous2.png");
    init_obj3(obj);
}

void init_obj(game *obj)
{
    obj->next = NULL;
    init(obj, '#', "./res/pnl.png");
    init(obj, '0', "./res/gras.png");
    init(obj, '1', "./res/wate.png");
    init(obj, '2', "./res/sand.png");
    init(obj, '3', "./res/cactus.png");
    init(obj, '4', "./res/bush.png");
    init(obj, '5', "./res/snow.png");
    init(obj, 'a', "./res/tree.png");
    init(obj, 'b', "./res/viseur.png");
    init(obj, 'c', "./res/heal.png");
    init(obj, 'd', "./res/death.png");
    init(obj, 'e', "./res/table.png");
    init(obj, 1, "./res/mob1.png");
    init(obj, 2, "./res/mob2.png");
    init(obj, 3, "./res/mob3.png");
    init(obj, 6, "./res/mob4.png");
    init(obj, 7, "./res/NPC1.png");
    init(obj, 8, "./res/NPC2.png");
    init_obj2(obj);
}
