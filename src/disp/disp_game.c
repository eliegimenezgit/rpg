/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp_game
*/

#include "../../include/header.h"

void disp_game(sfRenderWindow *window, game *obj)
{
    if (game_mode != 2) {
        disp_background(obj, window);
        disp_other(obj, window);
        disp_player(obj, window);
        disp_tree(obj, window);
        disp_mob(obj, window);
        disp_gun(obj, window);
        disp_house(obj, window);
        disp_vita_exp(obj, window);
        disp_inventory(obj, window);
        disp_text(obj, window);
        disp_name(window, obj);
    } else {
        disp_menu(obj, window);
    }
}
