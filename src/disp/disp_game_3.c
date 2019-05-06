/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp_game
*/

#include "../../include/header.h"

void disp_house(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 'h' && obj->eval != 0) {
                final_disp(obj, window, 0);
        }
        if (obj->scene == scene && obj->id == 'j' && obj->eval != 0) {
                final_disp(obj, window, 0);
        }
        if (obj->scene == scene && obj->id == 'o' && obj->eval != 0) {
                final_disp(obj, window, 0);
        }
        obj = obj->next;
    }
}

void disp_other(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 'k' && obj->eval != 0) {
            if (obj->mode == 0)
                final_disp(obj, window, 0);
        }
        if (obj->scene == scene && obj->id == 'q' && obj->eval != 0)
            final_disp(obj, window, 0);
        if (obj->scene == scene && obj->id == '#' && obj->eval != 0)
            final_disp(obj, window, 0);
        if (obj->scene == scene && obj->id == 7 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 8 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 9 && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 10 && obj->eval != 0)
            final_disp(obj, window, 1);
        obj = obj->next;
    }
}

void disp_gun(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->scene == scene && obj->id == 'g' && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 's' && obj->eval == 2)
            final_disp(obj, window, 1);
        if (obj->scene == scene && obj->id == 'd' && obj->eval == 2)
            final_disp(obj, window, 1);
        obj = obj->next;
    }
}

void disp_menu(game *obj, sfRenderWindow *window)
{
    sfVector2f scale = {4.2, 4.5};
    game *tmp = obj;

    while (obj) {
        if (obj->id > 58 && obj->id < 62 && obj->eval != 0)
            final_disp(obj, window, 0);
        if (obj->id == 'z' && obj->eval != 0)
            final_disp(obj, window, 0);
        if (obj->id == 123 && obj->eval != 0) {
            sfSprite_setScale(obj->sprite, scale);
            final_disp(obj, window, 0);
        }
        obj = obj->next;
    } while (tmp) {
        if (tmp->id == 'b' && tmp->eval != 0)
            final_disp(tmp, window, 0);
        tmp = tmp->next;
    }
}

void disp_name(sfRenderWindow *window, game *obj)
{
    game *tmp = obj;
    sfVector2f pos = {0, 0};

    while (tmp->id != 'p' || tmp->eval == 0) {
        tmp = tmp->next;
        if (tmp == NULL)
            return;
    }
    while (obj->id != 200 || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    pos.x = tmp->pos->x + 30 - (obj->eval * 5);
    pos.y = tmp->pos->y - 40;
    sfText_setPosition(obj->text, pos);
    final_disp_text(obj, window);
}
