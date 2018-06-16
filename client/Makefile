##
## EPITECH PROJECT, 2018
## zappy
## File description:
## client makefile
##

SRC	=	src/communication/main.c			\
		src/communication/args_management.c		\
		src/communication/error_client.c		\
		src/communication/client_communication.c	\
		src/communication/init_communication.c		\
		src/communication/get_next_line.c

SRC1	=	src/communication/main.c			\
		src/communication/args_management.c		\
		src/communication/error_client.c		\
		src/communication/client_communication.c	\
		src/communication/init_communication.c		\

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude

CFLAGS1	+=	-Wall -Wextra -Werror -Iinclude -lcriterion --coverage

NAME    =	client_ai

NAME1	=	test

COVER1	=	*.gcno

COVER2	=	*.gcda

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_clean:
	rm -f $(COVER1)
	rm -f $(COVER2)
	rm -f $(NAME1)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
