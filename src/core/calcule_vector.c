/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** calcule_vector
*/

#include "../../include/header.h"

sfVector2f c_v(sfVector2f *p1, sfVector2f *p2, float sd, sfVector2f AB)
{
    float angle = calcule_angle(p1, p2, AB);
    sfVector2f vector = {cos(angle) * sd, sin(angle) * sd};

    if (p1->y < p2->y)
        vector.y = vector.y * -1;
    return (vector);
}
