/*
** EPITECH PROJECT, 2019
** mobload
** File description:
** load_mob
*/

#include "../../include/header.h"

void load_neige(game *obj)
{
    new_obj(obj, 12, 68, 200);
    new_obj(obj, 12, 68, 300);
    new_obj(obj, 12, 68, 355);
    new_obj(obj, 12, 78, 200);
    new_obj(obj, 12, 78, 300);
    new_obj(obj, 12, 78, 400);
    new_obj(obj, 12, 77, 300);
    new_obj(obj, 12, 77, 293);
    new_obj(obj, 12, 69, 300);
    new_obj(obj, 12, 69, 293);
    new_obj(obj, 12, 69, 320);
}

void load_mob_desert_zone(game *obj)
{
    new_obj(obj, 3, 11, 99);
    new_obj(obj, 3, 11, 103);
    new_obj(obj, 3, 11, 116);
    new_obj(obj, 3, 11, 230);
    new_obj(obj, 3, 11, 380);
    new_obj(obj, 3, 3, 230);
    new_obj(obj, 3, 3, 205);
    new_obj(obj, 3, 3, 380);
    new_obj(obj, 3, 12, 235);
    new_obj(obj, 3, 12, 383);
    new_obj(obj, 3, 1, 235);
    new_obj(obj, 3, 1, 353);
    new_obj(obj, 3, 1, 190);
}

void load_mob_forest_zone(game *obj)
{
    new_obj(obj, 1, 41, 306);
    new_obj(obj, 1, 41, 275);
    new_obj(obj, 1, 41, 336);
    new_obj(obj, 1, 41, 303);
    new_obj(obj, 1, 41, 273);
    new_obj(obj, 1, 41, 335);
    new_obj(obj, 2, 42, 120);
    new_obj(obj, 2, 42, 422);
    new_obj(obj, 2, 42, 320);
    new_obj(obj, 2, 34, 325);
    new_obj(obj, 2, 26, 99);
    new_obj(obj, 2, 26, 103);
    new_obj(obj, 2, 26, 116);
    new_obj(obj, 2, 27, 99);
    new_obj(obj, 2, 27, 103);
    new_obj(obj, 2, 27, 116);
    new_obj(obj, 2, 27, 230);
    new_obj(obj, 2, 27, 380);
}

void load_mob_cave(game *obj)
{
    new_obj(obj, 6, 60, 380);
    new_obj(obj, 6, 60, 384);
    new_obj(obj, 6, 61, 180);
    new_obj(obj, 6, 61, 200);
    new_obj(obj, 6, 62, 290);
    new_obj(obj, 6, 62, 169);
    new_obj(obj, 6, 70, 171);
}

void load_mob(game *obj)
{
    load_mob_forest_zone(obj);
    load_mob_desert_zone(obj);
    load_mob_cave(obj);
    load_neige(obj);
}
