/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** deal the print of name
*/

#include "../../include/header.h"

void name_take(player *data, char **alpha, char *name)
{
    if (data->what == 0 && data->key == 'E' && data->size < 15) {
        name[data->size] = alpha[data->pos.y][data->pos.x];
        ++data->size;
    }
    if (data->what == 1 && data->key == 'E' && data->size > 0){
        --data->size;
        name[data->size] = '\0';
    }
    if (data->what == 2 && data->key == 'E' && data->size < 15){
        name[data->size] = ' ';
        ++data->size;
    }
    if (data->what == 3 && data->key == 'E' && data->size > 0){
        data->what = 4;
    }
}