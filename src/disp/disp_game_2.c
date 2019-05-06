/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp_game
*/

#include "../../include/header.h"

void disp_mob(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 1 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 6 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 2 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 3 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 126 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 22 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 58 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 12 && obj->eval != 0)
            final_disp(obj, window, 1);
        obj = obj->next;
    }
}

void final_disp_text(game *obj, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, obj->text, NULL);
}

void disp_text(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 't' && obj->eval == 3)
            final_disp_text(obj, window);
        if (obj->id == 'b' && obj->eval != 0)
            final_disp(obj, window, 0);
        if (obj->scene == scene && obj->id == 'u' && obj->eval == 1)
            final_disp(obj, window, 0);
        obj = obj->next;
    }
}

void disp_tree(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 'a' && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 'n' && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == '3' && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 'c' && obj->eval == 1)
            final_disp(obj, window, 0);
        obj = obj->next;
    }
}

void disp_inventory(game *obj, sfRenderWindow *window)
{
    game *tmp = obj;

    while (obj) {
        if (obj->id == 'i' && obj->eval != 0 && obj->mode != game_mode) {
            final_disp(obj, window, 0);
            while (tmp) {
                if (tmp->id == 'k' && tmp->eval != 0 && tmp->mode == 1)
                    final_disp(tmp, window, 0);
                tmp = tmp->next;
            }
        }
        obj = obj->next;
    }
}


