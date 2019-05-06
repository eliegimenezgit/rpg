/*
** EPITECH PROJECT, 2019
** loop.c
** File description:
** loop of the game
*/

#include "../include/header.h"

void init_text_end(sfRenderWindow *window, sfText *text, sfFont *font)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2f position = {0, 0};
    sfVector2f origine = {25, 25};
    position.x = size.x * 2/5;
    position.y = size.y * 1/3;
    sfText_setPosition(text, position);
    sfText_setOrigin(text, origine);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, "YOU WIN WELL PLAYED\n\n\n SEE YOU SOON...");
}

void print_ending(sfRenderWindow *window)
{
    static int init = 0;
    static sfText *text;
    static sfFont *font;

    if (init == 0) {
        text = sfText_create();
        font =  sfFont_createFromFile("res/9.TTF");
        init_text_end(window, text, font);
        init = 1;
    }
    sfRenderWindow_drawText(window, text, NULL);
    if (game_mode == -1) {
        sfText_destroy(text);
        sfFont_destroy(font);
    }
}

void core_end(sfRenderWindow *window)
{
    sfColor black;
    static int opacity = 0;

    black.r = opacity;
    black.g = opacity;
    black.b = opacity;
    sfRenderWindow_clear(window, black);
    if (opacity == 255) {
        print_ending(window);
    }else {
        ++opacity;
    }
}