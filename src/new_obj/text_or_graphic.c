/*
** EPITECH PROJECT, 2019
** text_graph
** File description:
** text_graph
*/

#include "../../include/header.h"

void alloc_text(game *new, game *obj)
{
    while (obj->id != 't' || obj->eval != 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    new->text = sfText_create();
    if (!new->text) {
        game_mode = -1;
        return;
    }
    new->font = sfFont_createFromFile(obj->path);
    if (!new->font) {
        game_mode = -1;
        return;
    }
}

void alloc_graphic(game *new, game *obj)
{
    while (obj->id != new->id || obj->eval != 0) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    new->texture = sfTexture_createFromFile(obj->path, NULL);
    if (!new->texture) {
        game_mode = -1;
        return;
    }
    new->sprite = sfSprite_create();
    sfSprite_setPosition(new->sprite, *(new->pos));
}

void text_or_graphic(game *new, game *obj)
{
    if (new->id == 't' || new->id == 200)
        alloc_text(new, obj);
    else
        alloc_graphic(new, obj);
}
