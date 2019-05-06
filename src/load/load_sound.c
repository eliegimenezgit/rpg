/*
** EPITECH PROJECT, 2019
** load_sound
** File description:
** sound
*/

#include "../../include/header.h"

void new_sound(int id, sound *son, char *path)
{
    sound *new = malloc(sizeof(sound));

    if (new == NULL)  {
        game_mode = -1;
        return;
    }
    while (son->next)
        son = son->next;
    son->next = new;
    new->id = id;
    new->music = sfMusic_createFromFile(path);
    if (!new->music)  {
        game_mode = -1;
        return;
    }
    new->next = NULL;
}

void load_sound(sound *son)
{
    son->music = sfMusic_createFromFile("./sound/shot.ogg");
    son->next = NULL;
    new_sound('e', son, "./sound/boom.ogg");
    new_sound('t', son, "./sound/shot.ogg");
    new_sound('b', son, "./sound/boss.ogg");
    new_sound('d', son, "./sound/desert.ogg");
    new_sound('f', son, "./sound/main.ogg");
    new_sound('m', son, "./sound/menu.ogg");
    new_sound('s', son, "./sound/soussol.ogg");
    new_sound('n', son, "./sound/neige.ogg");
}
