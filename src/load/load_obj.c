/*
** EPITECH PROJECT, 2019
** load_obj.c
** File description:
** main of load
*/

#include "../../include/header.h"

void load_player(game *obj)
{
    new_obj(obj, 200, scene, 0);
    new_obj(obj, 'z', scene, 200);
    new_obj(obj, 123, scene, 187);
    new_obj(obj, 'p', scene, 202);
    new_obj(obj, 'v', 40, 164);
    new_obj(obj, 'x', 40, 164);
    new_obj(obj, 'b', 40, 164);
    new_obj(obj, 'i', 40, 196);
    new_obj(obj, 'g', 33, 297);
}

void load_other(game *obj)
{
    new_obj(obj, 'q', 43, 331);
    new_obj(obj, 'q', 2, 266);
    new_obj(obj, 'q', 43, 255);
    new_obj(obj, 'q', 35, 362);
    new_obj(obj, 'q', 29, 355);
    new_obj(obj, 'q', 30, 355);
    new_obj(obj, 'q', 31, 355);
    new_obj(obj, 'q', 52, 64);
    new_obj(obj, 'q', 71, 137);
    new_obj(obj, 'q', 79, 137);
    new_obj(obj, 'c', 43, 110);
    new_obj(obj, 'c', 40, 141);
    new_obj(obj, 'c', 19, 364);
    new_obj(obj, 'c', 79, 210);
    new_obj(obj, 'u', 87, 296);
}

void load_boss(game *obj)
{
    new_obj(obj, 59, scene, 106);
    new_obj(obj, 60, scene, 203);
    new_obj(obj, 61, scene, 300);
    new_obj(obj, 22, 26, 140);
    new_obj(obj, 58, 1, 137);
    new_obj(obj, 126, 68, 137);
}

void load_obj(game *obj, sound *son)
{
    load_sound(son);
    load_maps(obj);
    load_player(obj);
    load_pnl(obj);
    load_other(obj);
    load_mob(obj);
    load_boss(obj);
}
