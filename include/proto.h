/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_PROTO_
#define MY_PROTO_

/*
id : le character qui définit l'objet
scene : la map de l'objet
mode : chargement, menu, déplacement, pause, combat, dialogue
*/
void core_end(sfRenderWindow *window);
//basic function
char *my_concat(char *str1, char *str2);
int my_getnbr(char const *str);
void my_putchar(char const c);
void my_put_nbr(int nbr);
void my_putstr(char *str);
int my_strlen(char const *str);
char *my_dup(char *str);

//load and other
int col_proj_mob(game *proj, game *obj, game *tmp, sound *son);
int col_proj_decor(game *proj, game *obj, game *tmp, sound *son);
void new_death(game *proj, game *tmp, sound *son);
int name_leng(sfRenderWindow *window, char *name,
                sfText *my_text, player *data);
int wave(int number);
char *ask_name(sfRenderWindow *window);
void give_str(char c, sfVector2f *position, sfText *my_text);
void name_take(player *data, char **alpha, char *name);
void my_option(sfRenderWindow * window, sfText *my_text,
                player *data, char **option);
void my_alpha(sfRenderWindow * window, sfText *my_text,
                player *data, char **alpha);
void events_deal(sfEvent *event, player *data);
void print_underline(sfText *my_text, sfVector2i *tab
                    , player *data);
void deal_with_option(player *data);
void deal_with_key_press(player *data, char **alpha);
void free_obj(game*, sound*);
void load_obj(game*, sound*);
void load_maps(game*);
void load_pnl(game*);
void load_mob(game*);
void loop(sfRenderWindow *window, game *obj, sfEvent event, sound *son);
void poll_event(sfRenderWindow *window, sfEvent *event, game *obj);

/*
**core
*/
int upgrade_gun(game *obj, game *p);
void new_collision(game *p, game *o);
void disp_house(game *obj, sfRenderWindow *window);
// sound

void background_sound(sound *son);
void load_sound(sound *son);
int play_or_stop(int id, sound *son);
void play_that(int id, sound *son, int play);

// menu

void menu_music(sound *son);
void quit_game(game *player, game *obj, sfRenderWindow *window);
void start_game(game *player, game *obj, sfRenderWindow *window);
void anime_back(game *obj);
void pause_all(sound *son);
void disp_background(game *obj, sfRenderWindow *window);
void core_menu(game *obj, sfRenderWindow *window, sound *son);

void core_game(game *obj, sfRenderWindow *window, sound *son);

//player

void player_move(game *obj, sfRenderWindow *window);
void move_with_key(game*, int);
void collision(game* , game*);
void recolt(game*, game*);
void inventory(game*, game*);
void anime_player(game*, sfRenderWindow*);
void change_scene(game*);
void compute_player(game*, game*);
void tp(game*, game*);
int anime_gun(game*, game*);
int col_play(game*, game*, char, int);
int col_hous(game*, game*, char);
void local_pnl(game*, int);

//viseur

void viseur(game *obj, sfRenderWindow *window);

//mob

void anime_mob(game *obj);
void anime_4(game *, int, int);
void move_mob(game *obj);
sfVector2f c_v(sfVector2f *, sfVector2f *, float speed, sfVector2f AB);
float calcule_angle(sfVector2f *pos_1, sfVector2f *pos_2, sfVector2f AB);

//proj

void proj(game *obj, sfRenderWindow *window, sound *son);
void rotate_gun(game *gun, sfRenderWindow *window);
void push_to_player(game *p, game *tmp, game *gun, sfRenderWindow *window);
void rm_proj(game *obj, game *tmp, sound *son);

//background

void anime_background(game *obj);

//inventory

void move_inventory(game *obj);

// quest

void quest(game *obj);

// death

void anime_death(game *obj);

/*
**disp
*/

void disp_name(sfRenderWindow *window, game *obj);
void disp_menu(game *obj, sfRenderWindow *window);
void disp_gun(game *obj, sfRenderWindow *window);
void disp_other(game *obj, sfRenderWindow *window);
void disp_mob(game *obj, sfRenderWindow *window);
void final_disp_text(game *obj, sfRenderWindow *window);
void disp_text(game *obj, sfRenderWindow *window);
void disp_tree(game *obj, sfRenderWindow *window);
void disp_inventory(game *obj, sfRenderWindow *window);
void final_disp(game *obj, sfRenderWindow *window, int eval);
int return_pos(int c, char **id_content);
void disp_player(game *obj, sfRenderWindow *window);
void disp_vita_exp(game *obj, sfRenderWindow *window);
void disp_game(sfRenderWindow *window, game *obj);

//init
void init_obj(game*);

void new_obj(game *obj, int id, int eval, int pos);
void animation(game*);
void text_or_graphic(game *new, game *obj);
void battle(game *new);
void game_mod(game *new);
void mob_hp(game *new);
void ajust_pos(game *obj);

#endif /*MY_PROTO_*/
