/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_client function
*/

#include "server.h"
#include "game.h"

void init_client_player(t_server *server, t_client *client, char **tab)
{
	if (tab != NULL && tab[1] != NULL) {
		client->player = init_player(server->game, client->fd, tab[1]);
		if (client->player == NULL) {
			free(client);
			exit(ERROR);
		}
	}
}

void destroy_client(t_server *server, t_client *client)
{
	int i;
	int cpt;
	if (client != NULL && client->player) {
		for (i = 0; strcmp(client->player->team,
		server->game->teams[i]->name) != 0; i += 1);
		server->game->teams[i]->slot += 1;
		remove_place(client->player, server->game);
		destroy_player(client->player);
	}
	for (cpt = 0; server->fds[cpt] < server->fds_len &&
		      server->fds[cpt] != client->fd; cpt += 1);
	server->fds[cpt] = -1;
	if (client->buffer != NULL)
		free(client->buffer);
	for (i = 0; i < 10; i += 1) {
		if (client->buf[i].cmd != NULL)
			free(client->buf[i].cmd);
	}
	server->client = delete_client(server->client, client);
	client = NULL;
}

t_client *init_client(t_server *server __attribute__((unused)), int fd)
{
	t_client *client = malloc(sizeof(t_client));
	if (client == NULL)
		exit(ERROR);
	client->fd = fd;
	client->player = NULL;
	client->buffer = NULL;
	for (int i = 0; i < 10; i += 1) {
		client->buf[i].cmd = NULL;
		client->buf[i].time = -1;
	}
	return (client);
}

int connect_client(t_server *server, t_client *client, int fd, char **tab)
{
	int i = 0;
	char str[2048];
	char str2[2048];
	t_game_p *game = server->game;
	for (i = 0; tab[1] != NULL && game->teams[i] != NULL &&
		    strcmp(game->teams[i]->name, tab[1]) != 0; i += 1) {
	}
	if (game->teams[i] != NULL && server->game->teams[i]->slot > 0 &&
	    client->player == NULL) {
		init_client_player(server, client, tab);
		t_game_p *game = server->game;
		sprintf(str, "CLIENT-%d\n", game->teams[i]->slot);
		send(fd, str, strlen(str), 0);
		sprintf(str2, "%d %d\n", server->options.width,
		server->options.height);
		send(fd, str2, strlen(str2), 0);
	} else {
		send(fd, "ko\n", strlen("ko\n"), 0);
	}
	clear_cmd(client);
	// free_respond();
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
	server->client = add_client(server->client, init_client(server, fd));
	return (0);
                                                                                                                       }
