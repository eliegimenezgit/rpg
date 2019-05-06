/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** get nbr in string
*/

#include "../include/header.h"

int my_strisneg(char const *str)
{
    int i = 0;
    int signe = 1;

    while ((str[i] != '\0' && str[i] == '-') || str[i] == '+') {
        if (str[i] == '-') {
            signe = signe * (-1);
        }
        i = i + 1;
    }
    return (signe);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;

    while ((str[i] != '\0' && str[i] < '0') || str[i] > '9') {
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = (result * 10) + (str[i] - 48);
        i = i + 1;
    }
    return (result * my_strisneg(str));
}
