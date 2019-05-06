/*
** EPITECH PROJECT, 2019
** my_concat.c
** File description:
** concaten
*/

#include "../include/header.h"

char *my_concat(char *str1, char *str2)
{
    int size = (my_strlen(str1) + my_strlen(str2));
    char *dest = malloc(sizeof(char)*size + 1);
    int i = 0;
    int j = 0;

    while (str1[i] != '\0') {
        dest[i] = str1[i];
        i = i + 1;
    }
    while (str2[j] != '\0') {
        dest[i] = str2[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
