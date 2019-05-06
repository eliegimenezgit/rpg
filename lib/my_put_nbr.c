/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** disp a int
*/

#include "../include/header.h"

void my_put_nbr(int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9) {
        my_put_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + 48);
}
