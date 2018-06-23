/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** error concerning client's program
*/

#include "client.h"

int return_error(int fd)
{
	if (close(fd) == -1) {
		perror("Socket error");
		return (84);
	}
	return (84);
}