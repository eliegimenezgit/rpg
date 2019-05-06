/*
** EPITECH PROJECT, 2019
** sound_background.c
** File description:
** son
*/

#include "../../include/header.h"

void play_that(int id, sound *son, int play)
{
    while (son->id != id) {
        son = son->next;
        if (son == NULL)
            return;
    }
    if (play == 1)
        sfMusic_play(son->music);
    else
        sfMusic_stop(son->music);
}

int play_or_stop(int id, sound *son)
{
    while (son->id != id) {
        son = son->next;
        if (son == NULL)
            return (0);
    }
    if (sfMusic_getStatus(son->music) == sfStopped)
        return (0);
    if (sfMusic_getStatus(son->music) == sfPlaying)
        return (1);
    return (-1);
}

void other_music2(sound *son, int b)
{
    if ((scene > 75 && scene < 90) || (scene == 66 && b != 1)) {
        if (play_or_stop('n', son) == 0) {
            play_that('n', son, 1);
        }
    } else if (play_or_stop('n', son) == 1) {
        play_that('n', son, 0);
    }
}

void other_music1(sound *son)
{
    if (scene < 20 && scene != 1) {
        if (play_or_stop('d', son) == 0) {
            play_that('d', son, 1);
        }
    } else if (play_or_stop('d', son) == 1) {
        play_that('d', son, 0);
    } if ((scene > 51 && scene < 63) || scene == 70 || scene == 71) {
        if (play_or_stop('s', son) == 0) {
            play_that('s', son, 1);
        }
    } else if (play_or_stop('s', son) == 1) {
        play_that('s', son, 0);
    }
}

void background_sound(sound *son)
{
    int b = 0;

    if (scene == 26 || scene == 1 || scene == 68) {
        if (play_or_stop('b', son) == 0) {
            play_that('b', son, 1);
            b = 1;
        }
    } else if (play_or_stop('b', son) == 1) {
        play_that('b', son, 0);
    } if (scene > 20 && scene < 51 && b != 1) {
        if (play_or_stop('f', son) == 0 && scene != 26 && game_mode != 2) {
            play_that('f', son, 1);
        }
    } else if (play_or_stop('f', son) == 1) {
        play_that('f', son, 0);
    }
    other_music1(son);
    other_music2(son, b);
}
