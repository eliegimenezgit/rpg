/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** deal with key
*/

#include "../../include/header.h"

void deal_with_move_too_option(player *data, char **alpha)
{
    if (data->key == 'D' && alpha[data->pos.y + 1] == NULL && data->pos.x <= 1)
        data->what = 1;
    if (data->key == 'D' && alpha[data->pos.y + 1] == NULL
        && data->pos.x >= 2 && data->pos.x < 5)
        data->what = 2;
    if (data->key == 'D' && alpha[data->pos.y + 1] == NULL && data->pos.x >= 5)
        data->what = 3;
    if (data->key == 'R' && alpha[data->pos.y][data->pos.x + 1] == '\0'
                        && alpha[data->pos.y + 1] == NULL)
        data->what = 1;
}

void deal_with_move_key(player *data, char **alpha)
{
    if (data->key == 'R' && alpha[data->pos.y][data->pos.x + 1] == '\0'
                        && alpha[data->pos.y + 1] != NULL ){
        data->pos.x = 0;
        ++data->pos.y;
    }else if (data->key == 'R'){
        ++data->pos.x;
    }
    if (data->key == 'L' && data->pos.x == 0
                        && data->pos.y >= 0 ){
        data->pos.x = 6;
        if (data->pos.y != 0)
        --data->pos.y;
    }else if (data->key == 'L' && data->pos.x - 1 >= 0) {
        --data->pos.x;
    }
    if (data->key == 'D' && alpha[data->pos.y + 1] != NULL)
        ++data->pos.y;
    if (data->key == 'U' && data->pos.y > 0)
        --data->pos.y;
}

void deal_with_key_press(player *data, char **alpha)
{
    if (data->key != '\0'){
        deal_with_move_too_option(data, alpha);
        deal_with_move_key(data, alpha);
    }
    data->key = '\0';
}

void deal_with_option(player *data)
{
    if (data->key == '\0')
        return;
    data->pos.y = 3;
    if (data->key == 'R' && data->what < 3)
        ++data->what;
    if (data->key == 'U') {
        if (data->what == 1)
            data->pos.x = 0;
        else if (data->what == 2)
            data->pos.x = 3;
        else
            data->pos.x = 6;
        data->what = 0;
    }
    if (data->key == 'L' && data->what > 0) {
        data->pos.x = 0;
        --data->what;
    }
    data->key = '\0';
}

void give_str(char c, sfVector2f *position, sfText *my_text)
{
    char str[2] = "\0\0";

    str[0] = c;
    sfText_setPosition(my_text, *position);
    sfText_setString(my_text, str);
    sfText_setStyle(my_text, sfTextRegular);
}