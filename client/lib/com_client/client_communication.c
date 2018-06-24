/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** communication management for client
*/

#include "client.h"
#include <ctype.h>

int client_send(int fd, char *message)
{
	if (dprintf(fd, "%s\n", message) < 0)
		return (return_error(fd));
	return (0);
}

int client_receive(int fd, char *message)
{
	int nb_read = 0;
	while (nb_read == 0) {
		nb_read = read(fd, message, 4096);
		if (nb_read == -1) {
			perror("read failed");
			return (return_error(fd));
		}
	}
	return (0);
}

int	stop_socket(int fd)
{
	if (close(fd) == -1) {
		perror("Socket error");
		return (84);
	}
	return (0);
}
