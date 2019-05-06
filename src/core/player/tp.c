/*
** EPITECH PROJECT, 2019
** tp
** File description:
** tp
*/

#include "../../../include/header.h"

void foret(game *play)
{
    if (scene == 35) {
        play->pos->x = 900;
        play->pos->y = 600;
        scene = 29;
    } else if (scene == 29) {
        play->pos->x = 1350;
        play->pos->y = 780;
        scene = 35;
    }
    if (scene == 43 && play->pos->x < 1000) {
        play->pos->x = 900;
        play->pos->y = 600;
        scene = 30;
    } else if (scene == 30) {
        play->pos->x = 440;
        play->pos->y = 580;
        scene = 43;
    }
}

void desert(game *play)
{
    if (scene == 2) {
        play->pos->x = 900;
        play->pos->y = 600;
        scene = 31;
    } else if (scene == 31) {
        play->pos->x = 1160;
        play->pos->y = 600;
        scene = 2;
    }
}

void neige(game *play)
{
    if (scene == 71) {
        play->pos->x = 832;
        play->pos->y = 360;
        scene = 79;
    } else if (scene == 79) {
        play->pos->x = 832;
        play->pos->y = 360;
        scene = 71;
    }
}

void passage_secret(game *play, game *obj)
{
    while (obj->id != 'k' || obj->eval == 0 || obj->mode != 1) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    if (scene == 43 && play->pos->x > 1000) {
        play->pos->x = 200;
        play->pos->y = 200;
        scene = 52;
    } else if (scene == 52) {
        play->pos->x = 1350;
        play->pos->y = 750;
        scene = 43;
    }
}

void tp(game *play, game *obj)
{
    if (col_play(play, obj, 'q', 0) == 1) {
        foret(play);
        desert(play);
        passage_secret(play, obj);
        neige(play);
    }
}
