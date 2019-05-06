/*
** EPITECH PROJECT, 2019
** load_map
** File description:
** load_map
*/

#include "../../include/header.h"

void map_to_obj(game *obj, char *map, char *map_name)
{
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] != '\n' && map[i] != 'x' && map[i] != 3) {
            new_obj(obj, map[i], my_getnbr(map_name), i);
        }
        i = i + 1;
    }
}

void open_map(game *obj, char *map_name)
{
    char *path = my_concat("map/", map_name);
    int fd = 0;
    char *map =  malloc(sizeof(char) * READ_SIZE + 1);

    if (map == NULL)  {
        game_mode = -1;
        return;
    }
    if ((fd = open(path, O_RDONLY)) != -1) {
        read(fd, map, READ_SIZE);
        map[READ_SIZE] = '\0';
        map_to_obj(obj, map, map_name);
    }
    close(fd);
}

void load_maps(game *obj)
{
    DIR *fdir = NULL;
    struct dirent *c_dir = NULL;

    if ((fdir = opendir("map/")) != NULL) {
        while ((c_dir = readdir(fdir)) != NULL) {
            if (c_dir->d_name[0] != '.')
                open_map(obj, c_dir->d_name);
        }
    }
}
