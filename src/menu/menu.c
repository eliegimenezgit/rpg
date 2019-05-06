/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** menu
*/

#include "../../include/header.h"

void core_menu(game *obj, sfRenderWindow *window, sound *son)
{
    game *tmp = obj;

    while (obj->id != 'p' || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    viseur(obj, window);
    start_game(obj, tmp, window);
    quit_game(obj, tmp, window);
    anime_back(tmp);
    menu_music(son);
}
