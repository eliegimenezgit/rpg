/*
** EPITECH PROJECT, 2019
** ask_name.c
** File description:
** all function loop
*/

#include "../../include/header.h"
#include <stdlib.h>

sfVector2f set_all(sfText *my_text, sfFont *my_font, sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2f position = {0, 0};
    sfVector2f origine = {25, 25};
    position.x = size.x * 2/5;
    position.y = size.y * 1/3;
    sfText_setPosition(my_text, position);
    sfText_setOrigin(my_text, origine);
    sfText_setFont(my_text, my_font);
    sfText_setColor(my_text, sfWhite);
    sfText_setCharacterSize(my_text, 50);
    return (position);
}

char *file_name(void)
{
    char *str = malloc(sizeof(char) * 16);
    int incre = 0;

    while (incre != 15) {
        str[incre] = '\0';
        ++incre;
    }
    return (str);
}

void print_name(sfRenderWindow *window, char *name,
                sfText *my_text, player *data)
{
    sfVector2f position = {0, data->pos_null.y - 80 };
    sfTime time;
    int size = 0;

    wave(-1);
    size = name_leng(window, name, my_text, data);
    time = sfClock_getElapsedTime(data->clock);
    if (data->size < 15 && time.microseconds > 350000) {
        position.y = data->pos_null.y - 80;
        position.x = data->pos_null.x + size * 34;
        give_str('_', &position, my_text);
        sfRenderWindow_drawText(window, my_text, NULL);
        if (time.microseconds > 550000)
            sfClock_restart(data->clock);
    }
}

void loop_name(sfRenderWindow *window, player *data, char *name, sfText *text)
{
    sfEvent event;
    char *alpha[5] = {"ABCDEFG\0", "HIJKLMN\0", "OPQRSTU", "VWXYZ-!\0", NULL};
    char *option[5] = {"SUPP\0", "SPACE", "ENTER\0", NULL};

    name_take(data, alpha, name);
    my_alpha(window, text, data, alpha);
    my_option(window, text, data, option);
    print_name(window, name, text, data);
    sfRenderWindow_pollEvent(window, &event);
    events_deal(&event, data);
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        sfClock_destroy(data->clock);
    }
    event.type = -1;
}

char *ask_name(sfRenderWindow *window)
{
    char *name = file_name();
    sfText *text = sfText_create();
    sfFont *font =  sfFont_createFromFile("res/9.TTF");
    player data = {sfClock_create(), 0, {0, 0},
                set_all(text, font, window), 0, 0, 0};

    while (sfRenderWindow_isOpen(window) && data.what != 4) {
        sfRenderWindow_clear(window, sfBlack);
        loop_name(window, &data, name, text);
        sfRenderWindow_display(window);
    }
    sfFont_destroy(font);
    sfText_destroy(text);
    return (name);
}