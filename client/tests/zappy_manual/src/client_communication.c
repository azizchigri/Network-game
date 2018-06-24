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

int client_receive_manual(int fd, char *message)
{
	int nb_read = 0;
	int len = strlen(message);
	int digit = 1;
	while (nb_read == 0 || (strncmp(message, "ok\n", 3) &&
				strncmp(message, "ko\n", 3) &&
				strncmp(message, "[", 1) &&
				digit != 0)) {
		nb_read = read(fd, message, 4096);
		if (nb_read == -1) {
			perror("read failed");
			return (return_error(fd));
		}
		if (dprintf(1, "%.*s", nb_read, message) < 0)
			return (return_error(fd));
		if (!strncmp(message, "dead\n", 5))
			return (-1);
		for (int i = 0; (i < len) && (digit != 0); i++)
			digit = isdigit(message[i]);
	}
	return (0);
}

int client_actions(int fd, char *name)
{
	char *buff;
	char *command = NULL;
	int nb_read;

	if ((buff = malloc(sizeof(*buff) * 4097)) == NULL)
		return (return_error(fd));
	read(fd, buff, 4096);
	dprintf(fd, "%s\n", name);
	nb_read = read(fd, buff, 4096);
	if (!strncmp(buff, "ko\n", 3)) {
		printf("Not connected: Slots already in use.\n");
		return (0);
	}
	printf("%.*s", nb_read, buff);
	printf("Connected. You can perform actions.\n");
	while (1) {
		nb_read = 0;
		printf("$> ");
		command = get_next_line(0);
		if (command != NULL) {
			dprintf(fd, "%s\n", command);
		}
		client_receive_manual(fd, buff);
	}
	free(buff);
	return (84);
}

int	stop_socket(int fd)
{
	if (close(fd) == -1) {
		perror("Socket error");
		return (84);

	}
	return (0);
}

int launch_client(char **args)
{
	int fd;

	if ((fd = init_socket()) < 0)
		return (84);
	if (init_connection(args, fd) == 84)
		return (84);
	if (client_actions(fd, args[1]) == 84)
		return (84);
	return (stop_socket(fd));
}

