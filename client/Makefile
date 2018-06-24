##
## EPITECH PROJECT, 2018
## zappy
## File description:
## zappy serveur makefile
##

SRC	=	lib/com_client/args_management.c	\
		lib/com_client/client_communication.c	\
		lib/com_client/error_client.c		\
		lib/com_client/get_next_line.c		\
		lib/com_client/init_communication.c

SRC1	=	lib/com_client/args_management.c	\
		lib/com_client/client_communication.c	\
		lib/com_client/error_client.c		\
		lib/com_client/get_next_line.c		\
		lib/com_client/init_communication.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude -fpic -shared

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage

NAME    =	libia.so

NAME1	=	test

COVER1	=	*.gcno

COVER2	=	*.gcda

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

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
