/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_client function
*/

#include "server.h"
#include "game.h"

t_client *init_client(t_server *server, int fd)
{
	t_client *client = malloc(sizeof(t_client));
	if (client == NULL)
		exit(ERROR);
	client->fd = fd;
	client->player = init_player(server->game, fd, "teaam");
	if (client->player == NULL) {
		free(client);
		return (NULL);
	}
	return (client);
}

int connect_client(t_server *server, int fd, char **tab)
{
	int i = 0;

	char *str = NULL;
	char *str2 = NULL;
	t_game_p *game = server->game;
	for (i = 0; game->teams[i] != NULL &&
		    strcmp(game->teams[i]->name, tab[0]) == 0; i += 1) {
	}
	if (server->game->teams[i]->slot > 0) {
		server->client = add_client(server->client,
		init_client(server, fd));
		sprintf(str, "CLIENT-%d\n", game->teams[i]->slot);
		send(fd, str, strlen(str), 0);
		sprintf(str, "%d %d\n", server->options.width,
		server->options.height);
		send(fd, str2, strlen(str2), 0);

	} else {
		//delete fd from server->fds
		FD_CLR(fd, &(server->readfds));
	}
	return (0);
}

int manage_new_client(t_server *server, int fd)
{
	if (fd == -1) {
		return (ERROR);
	}
	server->fds[server->fds_len] = fd;
	server->fds_len += 1;
	server->higher_fd = server->higher_fd > fd ? server->higher_fd : fd;
	fcntl(fd, F_SETFL, O_NONBLOCK);
	FD_SET(fd, &(server->readfds));
	printf("New client connected\n");
	send(fd, "WELCOME\n", 8, 0);
	return (0);
}