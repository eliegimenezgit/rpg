/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** loop features
*/

#include "../../include/header.h"

int name_leng(sfRenderWindow *window, char *name,
                sfText *my_text, player *data)
{
    sfVector2f position = {0, data->pos_null.y - 80 };
    int incre = 0;

    while (name[incre] != '\0') {
        position.x = data->pos_null.x + incre * 34;
        position.y -= wave(incre);
        give_str(name[incre], &position, my_text);
        sfRenderWindow_drawText(window, my_text, NULL);
        position.y = data->pos_null.y - 80;
        ++incre;
    }
    return (incre);
}

int wave(int number)
{
    static int incre = 0;
    static int wave = 0;

    if (number == -1) {
        if (incre == 16){
            incre = 0;
            ++wave;
        }else if (wave == 16) {
            wave = 0;
        }
        ++incre;
    }else {
        if (wave + number == 14) {
            return ((wave + number));
        }
    }
    return (0);
}

void my_option(sfRenderWindow * window, sfText *my_text,
                player *data, char **option)
{
    sfVector2f position[4] = {{data->pos_null.x , data->pos_null.y + 350},
                            {data->pos_null.x + 180, data->pos_null.y + 350},
                            {data->pos_null.x + 400, data->pos_null.y + 350}};
    int y = 0;

    while (option[y] != NULL) {
        sfText_setPosition(my_text, position[y]);
        sfText_setString(my_text, option[y]);
        sfText_setStyle(my_text, sfTextRegular);
        if (data->what == y + 1)
            print_underline(my_text, NULL, data);
        sfRenderWindow_drawText(window, my_text, NULL);
            ++y;
    }
    if (data->what != 0)
        deal_with_option(data);
}

void my_alpha(sfRenderWindow * window, sfText *my_text,
                player *data, char **alpha)
{
    sfVector2f position = {0, 0};
    sfVector2i tab = {0, 0};

    while (alpha[tab.y] != NULL) {
        if (alpha[tab.y][tab.x] == '\0'){
            tab.x = 0;
            ++tab.y;
        }else{
        position.x = data->pos_null.x + tab.x * 80;
        position.y = data->pos_null.y + tab.y * 80;
        give_str(alpha[tab.y][tab.x], &position, my_text);
        print_underline(my_text, &tab, data);
        sfRenderWindow_drawText(window, my_text, NULL);
            ++tab.x;
        }
    }
    if (data->what == 0)
        deal_with_key_press(data, alpha);
}