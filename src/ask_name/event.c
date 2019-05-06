/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** event
*/

#include "../../include/header.h"

void events_deal(sfEvent *event, player *data)
{
    int key_nbr[6] = {16, 3, 25, 18, 58, -1};
    char key[6] = {"LRUDE\0"};
    int incre = 0;

    while (incre != 5 && data->press == 0) {
        if (sfKeyboard_isKeyPressed(key_nbr[incre])) {
            data->press = 1;
            data->key = key[incre];
        }
        ++incre;
    }
    if (event->type == sfEvtKeyPressed &&
        sfClock_getElapsedTime(data->clock).microseconds > TIME_MOVE) {
        data->press = 0;
        data->key = '\0';
    }
    if (data->what == 4) {
        sfClock_destroy(data->clock);
        data->clock = NULL;
    }
}