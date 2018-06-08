##
## EPITECH PROJECT, 2018
## malloc
## File description:
## malloc makefile
##

SRC	=	src/generation/map_gen.c	\
		src/generation/player_gen.c	\
		src/generation/destroy_game.c	\
		src/generation/game.c		\
		src/generation/main.c
#src/gameplay/cmd.c

SRC1	=	src/generation/map_gen.c	\
		src/generation/player_gen.c	\
		src/generation/destroy_game.c	\
		src/generation/game.c		\
		tests/test_destroy.c		\
		tests/test_map.c		\
		tests/test_ressources.c

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
