/*
** EPITECH PROJECT, 2019
** main of my_rpg
** File description:
** main
*/

#include "../include/header.h"

int check_name(char *name)
{
    int incre = 0;
    char display[8] = "DISPLAY\0";

    while (display[incre] != '\0') {
        if (name[incre] != display[incre])
            return (0);
        ++incre;
    }
    if (name[incre + 2] == '\0')
        return (0);
    return (1);
}

int check_error(int argc, char **argv, char **envp)
{
    int incre = 0;
    (void) argc;
    (void) argv;

    game_mode = 2;
    scene = 40;
    if (envp == NULL)
        return (1);
    while (envp[incre] != NULL) {
        if (check_name(envp[incre]) == 1)
            return (0);
        ++incre;
    }
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    sfRenderWindow *window = NULL;
    sound *son;
    game *obj;
    sfEvent event;

    if (check_error(argc, argv, envp) == 1)
        return (84);
    obj = malloc(sizeof(game));
    son = malloc(sizeof(sound));
    if (obj == NULL || son == NULL)
        return (84);
    init_obj(obj);
    load_obj(obj, son);
    if (game_mode == -1) {
        free_obj(obj, son);
        return (84);
    }
    loop(window, obj, event, son);
    return (0);
}
