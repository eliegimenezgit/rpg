##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## file of compilation
##

SRC = src/main.c                        \
      src/free_obj.c                    \
      src/load/load_obj.c               \
      src/load/load_sound.c               \
      src/load/load_map.c               \
      src/load/load_pnl.c               \
      src/load/load_mob.c               \
      src/loop.c                           \
      src/core_end.c                           \
      src/event/event.c                    \
      src/init_obj.c                       \
      src/menu/menu.c                      \
      src/menu/menu_features.c                      \
      src/new_obj/new_obj.c                \
      src/new_obj/alloc_anime.c            \
      src/new_obj/text_or_graphic.c        \
      src/new_obj/alloc_battle.c           \
      src/new_obj/alloc_other.c            \
      src/core/core_game.c                 \
      src/core/calcule_vector.c      \
      src/core/proj/proj.c           \
      src/core/proj/anime_death.c    \
      src/core/proj/rm_proj.c        \
      src/core/proj/col_proj_death.c        \
      src/core/proj/rotate_gun.c     \
      src/core/proj/push_to_player.c \
      src/core/background/anime_background.c     \
      src/core/inventory/inventory.c           \
      src/core/quest/quest.c                \
      src/core/mob/anime_mob.c           \
      src/core/background_sound.c           \
      src/core/mob/move_mob.c            \
      src/core/player/player.c           \
      src/core/player/pnl.c        \
      src/core/player/anime.c            \
      src/core/player/anime_gun.c        \
      src/core/player/col.c              \
      src/core/player/new_collision.c              \
      src/core/player/compute.c          \
      src/core/player/inventory.c        \
      src/core/player/move_key.c         \
      src/core/player/recolt.c           \
      src/core/player/scene.c            \
      src/core/player/tp.c               \
      src/core/viseur.c                    \
      src/disp/disp_game.c            \
      src/disp/disp_game_1.c            \
      src/disp/disp_game_2.c            \
      src/disp/disp_game_3.c            \
      ./lib/my_dup.c                  \
      ./lib/my_putchar.c              \
      ./lib/my_put_nbr.c              \
      ./lib/my_putstr.c               \
      ./lib/my_strlen.c               \
      ./lib/my_concat.c               \
	./src/ask_name/ask_name.c      \
	./src/ask_name/name_deal.c       \
	./src/ask_name/loop_features.c    \
	./src/ask_name/event.c        \
	./src/ask_name/underline.c        \
	./src/ask_name/deal_with_key.c    \
      ./lib/my_getnbr.c

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CFLAGS += -Wall -Wextra

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -I. -l m

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
