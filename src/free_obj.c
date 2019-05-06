/*
** EPITECH PROJECT, 2019
** free_obj.c
** File description:
** free
*/

#include "../include/header.h"

void close_sound(sound *son)
{
    while (son != NULL) {
        if (son->music) {
            sfMusic_stop(son->music);
            sfMusic_destroy(son->music);
        }
        son = son->next;
    }
}

int free_last_obj(game *obj)
{
    if (obj->next == NULL) {
        free(obj);
        return (1);
    } else {
        while (obj->next->next) {
            obj = obj->next;
        }
        free(obj->next);
        obj->next = NULL;
    }
    return (0);
}

int free_last_sound(sound *son)
{
    if (son->next == NULL) {
        free(son);
        return (1);
    } else {
        while (son->next->next) {
            son = son->next;
        }
        free(son->next);
        son->next = NULL;
    }
    return (0);
}

void free_obj(game *obj, sound *son)
{
    while (free_last_obj(obj) == 0);
    close_sound(son);
    while (free_last_sound(son) == 0);
}
