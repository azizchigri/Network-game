/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** communication management for client
*/

#include "client.h"

int client_actions(int fd, char *name)
{
	char buff[4096];
	char *command = NULL;
	int nb_read;

	read(fd, &buff, 4096);
	dprintf(fd, "%s\n", name);
	nb_read = read(fd, &buff, 4096);
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
		while (nb_read == 0 || (strncmp(buff, "ok\n", 3) && strncmp(buff, "ko\n", 3) && strncmp(buff, "[", 1))) {
			nb_read = read(fd, &buff, 4096);
			if (nb_read == -1) {
				perror("read failed");
				return (return_error(fd));
			}
			dprintf(1, "%.*s", nb_read, buff);
			if (!strncmp(buff, "dead\n", 5))
				return (0);
		}
	}
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

