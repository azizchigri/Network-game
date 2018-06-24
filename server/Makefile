##
## EPITECH PROJECT, 2018
## zappy
## File description:
## zappy serveur makefile
##

SRC	=	src/generation/map_gen.c				\
		src/generation/teams.c					\
		src/generation/player_gen.c				\
		src/generation/destroy_game.c				\
		src/generation/game.c					\
		src/gameplay/move/go.c					\
		src/gameplay/move/move.c				\
		src/gameplay/cmd.c					\
		src/gameplay/game_info/game_info.c			\
		src/gameplay/game_info/eject.c				\
		src/gameplay/player_info/inventory.c			\
		src/gameplay/item_action/stone.c			\
		src/gameplay/item_action/stone2.c			\
		src/gameplay/item_action/drop_take.c			\
		src/gameplay/time.c					\
		src/gameplay/item_action/incantation.c			\
		src/gameplay/item_action/incantation2.c			\
		src/gameplay/item_action/del_s.c			\
		src/gameplay/item_action/del_s2.c   			\
		src/gameplay/game_info/sound_from.c			\
		src/gameplay/game_info/broadcast.c			\
		src/gameplay/refresh.c					\
		src/gameplay/eat.c					\
		src/gameplay/player_info/build_result.c			\
		src/gameplay/player_info/wordtab_to_str.c		\
		src/gameplay/player_info/look_orientation/look.c	\
		src/gameplay/player_info/look_orientation/look_east.c	\
		src/gameplay/player_info/look_orientation/look_north.c	\
		src/gameplay/player_info/look_orientation/look_south.c	\
		src/gameplay/player_info/look_orientation/look_west.c	\
		src/graph_client/death.c				\
		src/graph_client/lvl_up.c				\
		src/graph_client/mapsize.c				\
		src/graph_client/player_p.c				\
		src/graph_client/res_drop_take.c			\
		src/graph_client/mct_function.c			\
		src/gameplay/game.c					\
		src/graph_client/end_game.c				\
		src/graph_client/new_player.c				\
		src/reseau/manage_server.c	\
        	src/reseau/zappy_server.c	\
		src/lib/str_to_wordtab.c	\
		src/lib/free.c	\
		src/reseau/client.c	\
        	src/parameters.c        \
        src/reseau/manage_client.c  \
        src/reseau/execute.c        \
        src/manage_cmd.c            \
        src/manage_fd.c             \
        src/gameplay/fork.c         \
        src/ressources.c

SRC1	=	src/generation/map_gen.c				\
		src/generation/teams.c					\
		src/generation/player_gen.c				\
		src/generation/destroy_game.c				\
		src/generation/game.c					\
		src/gameplay/move/go.c					\
		src/gameplay/move/move.c				\
		src/gameplay/cmd.c					\
		src/gameplay/game_info/game_info.c			\
		src/gameplay/game_info/eject.c				\
		src/gameplay/player_info/inventory.c			\
		src/gameplay/item_action/stone.c			\
		src/gameplay/item_action/stone2.c			\
		src/gameplay/item_action/drop_take.c			\
		src/gameplay/time.c					\
		src/gameplay/item_action/incantation.c			\
		src/gameplay/item_action/incantation2.c			\
		src/gameplay/item_action/del_s.c			\
		src/gameplay/item_action/del_s2.c   			\
		src/gameplay/game_info/sound_from.c			\
		src/gameplay/refresh.c					\
		src/gameplay/eat.c					\
		src/gameplay/player_info/build_result.c			\
		src/gameplay/player_info/wordtab_to_str.c		\
		src/gameplay/player_info/look_orientation/look.c	\
		src/gameplay/player_info/look_orientation/look_east.c	\
		src/gameplay/player_info/look_orientation/look_north.c	\
		src/gameplay/player_info/look_orientation/look_south.c	\
		src/gameplay/player_info/look_orientation/look_west.c	\
		src/gameplay/fork.c                                     \
		src/graph_client/death.c				\
		src/graph_client/lvl_up.c				\
		src/graph_client/mapsize.c				\
		src/graph_client/player_p.c				\
		src/graph_client/res_drop_take.c			\
		src/gameplay/game.c					\
		src/graph_client/end_game.c				\
		src/graph_client/new_player.c				\
		src/graph_client/mct_function.c			\
		src/lib/str_to_wordtab.c	\
		src/ressources.c            \
		tests/test_take.c					\
		tests/test_drop.c					\
		tests/test_destroy.c					\
		tests/test_map.c					\
		tests/test_ressources.c					\
		tests/test_move.c					\
		tests/test_player.c					\
		tests/test_game_info.c					\
		tests/test_cmd.c					\
		tests/test_eject.c					\
		tests/test_cmd_g.c					\
		tests/test_time.c					\
		tests/test_incantation.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude -D _GNU_SOURCE

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage -D _GNU_SOURCE

NAME    =	zappy_server

NAME1	=	test

COVER1	=	*.gcno

COVER2	=	*.gcda

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3

tests_run:
	gcc -o $(NAME1) $(SRC1) $(CFLAGS1)
	./$(NAME1)

tests_clean:
	rm -f $(COVER1)
	rm -f $(COVER2)
	rm -f $(NAME1)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
