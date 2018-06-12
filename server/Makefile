##
## EPITECH PROJECT, 2018
## zappy
## File description:
## zappy serveur makefile
##

SRC	=	src/generation/map_gen.c		\
		src/generation/player_gen.c		\
		src/generation/destroy_game.c		\
		src/generation/game.c			\
		src/gameplay/move/go.c			\
		src/gameplay/move/move.c		\
		src/gameplay/cmd.c			\
		src/gameplay/game_info/game_info.c	\
		src/gameplay/player_info/inventory.c	\
		src/generation/main.c

SRC1	=	src/generation/map_gen.c		\
		src/generation/player_gen.c		\
		src/generation/destroy_game.c		\
		src/generation/game.c			\
		src/gameplay/move/go.c			\
		src/gameplay/move/move.c		\
		src/gameplay/cmd.c			\
		src/gameplay/game_info/game_info.c	\
		src/gameplay/player_info/inventory.c	\
		tests/test_destroy.c			\
		tests/test_map.c			\
		tests/test_ressources.c			\
		tests/test_move.c			\
		tests/test_player.c			\
		tests/test_game_info.c			\
		tests/test_cmd.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage

NAME    =	map

NAME1	=	test

COVER1	=	*.gcno

COVER2	=	*.gcda

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

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
