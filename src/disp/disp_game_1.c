/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp_game
*/

#include "../../include/header.h"

void final_disp(game *obj, sfRenderWindow *window, int eval)
{
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    if (eval == 1)
        sfSprite_setTextureRect(obj->sprite, *(obj->rect));
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

int return_pos(int c, char **id_content)
{
    int i_1 = 0;
    int i_2 = 0;

    while (id_content[i_1] != NULL) {
        if (c == id_content[i_1][i_2])
            return (i_1);
        if (id_content[i_1][i_2] == '\0') {
            ++i_1;
            i_2 = 0;
        } else {
            ++i_2;
        }
    }
    return (-1);
}

void disp_background(game *obj, sfRenderWindow *window)
{
    char *id_content[3] = {"0mrewy25\0", "14f\0", NULL};
    int animated_or_not = -1;

    while (obj) {
        if (obj->scene == scene && obj->eval != 0) {
            animated_or_not = return_pos(obj->id, id_content);
            if (animated_or_not != -1)
                final_disp(obj, window, animated_or_not);
        }
        obj = obj->next;
    }
}

void disp_vita_exp(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->id == 'v' && obj->eval != 0)
            final_disp(obj, window, 1);
        if (obj->id == 'x' && obj->eval != 0)
            final_disp(obj, window, 1);
        obj = obj->next;
    }
}

void disp_player(game *obj, sfRenderWindow *window)
{
    while (obj) {
        if (obj->id == 'p' && obj->eval != 0)
            final_disp(obj, window, 1);
        obj = obj->next;
    }
}