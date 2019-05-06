/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** deal with underline style
*/

#include "../../include/header.h"

void print_underline(sfText *my_text, sfVector2i *tab
                    , player *data)
{
    if (data->what == 0 && tab != NULL) {
        if (data->pos.x == tab->x && data->pos.y == tab->y)
            sfText_setStyle(my_text, sfTextUnderlined);
        return;
    }
    if (data->what != 0 && tab == NULL) {
        sfText_setStyle(my_text, sfTextUnderlined);
        return;
    }
}