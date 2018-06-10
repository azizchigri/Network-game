##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## client makefile
##

SRC	=

TESTS = tests.test_json_wrapper

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage

NAME    =

COVER1	=	*/*.pyc

COVER2	=	*/__pycache__

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	python3 -m unittest $(TESTS)

tests_clean:
	rm -rf $(COVER1)
	rm -rf $(COVER2)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all