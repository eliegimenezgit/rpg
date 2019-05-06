/*
** EPITECH PROJECT, 2019
** load_pnl
** File description:
** load
*/

#include "../../include/header.h"

void edit_text(game *obj, char *str, int size)
{
    while (obj->id != 't' || obj->eval != 1) {
        obj = obj->next;
        if (obj == NULL)
            return;
    }
    sfText_setFont(obj->text, obj->font);
    sfText_setCharacterSize(obj->text, size);
    sfText_setString(obj->text, str);
    sfText_setPosition(obj->text , *(obj->pos));
    obj->eval = 2;
}

void load_npc2(game *obj)
{
    new_obj(obj, 7, 4, 380);
    new_obj(obj, 't', 4, 350);
    edit_text(obj, " Il faudrait un bateau\n   pour aller la bas", 25);
    new_obj(obj, 9, 52, 389);
    new_obj(obj, 't', 52, 356);
    edit_text(obj, "Il y a des vers bizarres\n    fait attention", 25);
    new_obj(obj, 10, 79, 84);
    new_obj(obj, 't', 79, 52);
    edit_text(obj, "mon upgrade dans le labyrinthe cache...\n\
    quoi! tu m'ecoutais ?", 23);
}

void load_npc(game *obj)
{
    new_obj(obj, 7, 41, 320);
    new_obj(obj, 't', 41, 287);
    edit_text(obj, "Il faudrait une arme pour\n  tuer ces plantes", 25);
    new_obj(obj, 8, 30, 295);
    new_obj(obj, 't', 30, 261);
    edit_text(obj, " Colle toi aux statues pour \n    te sentir mieux", 25);
    new_obj(obj, 9, 29, 295);
    new_obj(obj, 't', 29, 262);
    edit_text(obj, "Il faut une clef pour ouvrir\n   la maison au sud", 25);
    new_obj(obj, 9, 35, 290);
    new_obj(obj, 't', 35, 256);
    edit_text(obj, "  La foret Nabi cache des choses...", 25);
    new_obj(obj, 7, 27, 284);
    new_obj(obj, 't', 27, 252);
    edit_text(obj, "Woaw quel combattant !\n\
    j'espere que tu as pris l'upgrade dans la fo..\n", 25);
    new_obj(obj, 8, 31, 290);
    new_obj(obj, 't', 31, 259);
    edit_text(obj, "J'ai perdu mon scorpion\nquand j'etais petit...", 25);
    load_npc2(obj);
}

void load_pnl(game *obj)
{
    load_npc(obj);
    new_obj(obj, '#', 34, 202);
    new_obj(obj, 't', 34, 169);
    edit_text(obj, "      FORET : Nabi", 25);
    new_obj(obj, '#', 40, 300);
    new_obj(obj, 't', 40, 267);
    edit_text(obj, "       Bienvenue !\n  Il faut lire les panneaux", 25);
    new_obj(obj, '#', 43, 283);
    new_obj(obj, 't', 43, 251);
    edit_text(obj, "    VILLAGE :\n     Basho", 25);
    new_obj(obj, '#', 19, 205);
    new_obj(obj, 't', 19, 172);
    edit_text(obj, "    DESERT : Samag", 25);
    new_obj(obj, '#', 33, 265);
    new_obj(obj, 't', 33, 232);
    edit_text(obj, "     Prends l'arme\net montre ce que tu vaux", 25);
}
