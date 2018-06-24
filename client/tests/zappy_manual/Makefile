##
## EPITECH PROJECT, 2018
## zappy
## File description:
## zappy_manual makefile
##

SRC	=	src/args_management.c		\
		src/client_communication.c	\
		src/error_client.c		\
		src/get_next_line.c		\
		src/init_communication.c	\
		src/main.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage

NAME    =	zappy_manual

NAME1	=	test

COVER1	=	*.gcno

COVER2	=	*.gcda

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

debug: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3

tests_run:
	gcc -o $(NAME1) $(SRC) $(CFLAGS1)
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
