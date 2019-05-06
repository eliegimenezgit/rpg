/*
** EPITECH PROJECT, 2019
** new_obj.c
** File description:
** create obj with id pos scene
*/

#include "../include/header.h"

char *dup_car(char car)
{
    char *car_malloc = malloc(sizeof(char *));

    if (car_malloc == NULL) {
        game_mode = -1;
        return (NULL);
    }
    *car_malloc = car;
    return (car_malloc);
}

int *dup_nb(int nb)
{
    int *nb_malloc = malloc(sizeof(int *));

    if (nb_malloc == NULL) {
        game_mode = -1;
        return (NULL);
    }
    *nb_malloc = nb;
    return (nb_malloc);
}

char *my_dup(char *str)
{
    int i = 0;
    char *dest = NULL;

    while (str[i] != '\0')
        i = i + 1;
    dest = malloc(sizeof(char)*i+1);
    if (dest == NULL) {
        game_mode = -1;
        return (NULL);
    }
    i = 0;
    while (str[i] != '\0') {
        dest[i] = str[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
