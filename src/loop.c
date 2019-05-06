/*
** EPITECH PROJECT, 2019
** loop.c
** File description:
** loop of the game
*/

#include "../include/header.h"

int get_frame(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.033) {
        sfClock_restart(clock);
        return (1);
    } else
        return (0);
}

void gamemode(game *obj, sfRenderWindow *window, sound *son)
{
    if (game_mode == 2)
        core_menu(obj, window, son);
    else if (game_mode == 3){
        core_end(window);
    }else {
        core_game(obj, window, son);
    }
}

void edit_name(game *obj, char *name)
{
    while (obj->id != 200 || obj->eval == 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    sfText_setFont(obj->text, obj->font);
    sfText_setCharacterSize(obj->text, 18);
    sfText_setString(obj->text, name);
    obj->eval = my_strlen(name);
}

void loop(sfRenderWindow *window, game *obj, sfEvent event, sound *son)
{
    sfClock *clock = sfClock_create();
    sfVideoMode mode = {30*64, 16*64, 32};

    window = sfRenderWindow_create(mode, "my_rpg", sfClose , NULL);
    edit_name(obj, ask_name(window));
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    while (sfRenderWindow_isOpen(window) && game_mode != -1) {
        if (get_frame(clock) == 1) {
            sfRenderWindow_clear(window, sfBlack);
            poll_event(window, &event, obj);
            disp_game(window, obj);
            gamemode(obj, window, son);
            sfRenderWindow_display(window);
        }
    }
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    free_obj(obj, son);
}
