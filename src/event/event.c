/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include "../../include/header.h"

int key_is_press(sfEvent *event, int val, int key)
{
    if (event->type == sfEvtKeyReleased && val == 1) {
        if (event->key.code == key) {
            return (0);
        }
        else
            return (1);
    }
    if (event->type == sfEvtKeyPressed && val == 0) {
        if (event->key.code == key) {
            return (1);
        }
        else
            return (0);
    }
    return (val);
}

void get_player_move(game *obj, sfEvent *event)
{
    while (obj->id != 'p' || obj->eval == 0) {
        if (obj == NULL)
            return;
        obj = obj->next;
    }
    obj->z = key_is_press(event, obj->z, sfKeyZ);
    obj->q = key_is_press(event, obj->q, sfKeyQ);
    obj->s = key_is_press(event, obj->s, sfKeyS);
    obj->d = key_is_press(event, obj->d, sfKeyD);
    if (event->type == sfEvtMouseButtonPressed)
        obj->f = 1;
    else if (event->type == sfEvtMouseButtonReleased)
        obj->f = 0;
    game_mode = key_is_press(event, game_mode, sfKeyTab);
}

void poll_event(sfRenderWindow *window, sfEvent *event, game *obj)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        get_player_move(obj, event);
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game_mode = 2;
    }
}
