/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_STRUCT_
#define MY_STRUCT_

typedef struct sound
{
    int id;
    sfMusic *music;
    struct sound *next;
} sound;

typedef struct game
{
    int id;
    int scene;
    char *path;
    int mode;
    int eval;
    int atk;
    int hp;
    int hp_max;
    int lvl;
    int timer;
    int timer_max;
    int z;
    int q;
    int s;
    int d;
    int f;
    int speed;
    sfVector2f *ex_pos;
    sfVector2f direction;
    sfVector2f *pos;
    int nb_rect;
    sfIntRect *rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfFont *font;
    struct game *next;
} game;

typedef struct
{
    sfClock *clock;
    int what;
    sfVector2i pos;
    sfVector2f pos_null;
    int press;
    char key;
    int size;
}player;
#endif /*MY_STRUCT_*/
