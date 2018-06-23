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

//ajouter fct detroy-client

char **get_cmd(char *buff)
{
	if (buff != NULL)
	{
		char *caract = strrchr(buff, '-');
		if (caract != NULL && buff[0] == 'T')
			*caract = ' ';
	}
	return (str_to_wordtab(buff));
}


void add_client_cmd(t_server *server, int fd, char *buff)
{
	t_client *client = server->client;
	int i = 0;
	int i2 = 0;
	char **tab = get_cmd(buff);
	if (tab != NULL && client != NULL) {
		int time = cooldown(server->game, client->player, tab);
		if (time == -1 ||
		    (client->player == NULL && strcmp(tab[0], "TEAM") != 0)) {
			send(fd, "ko\n", strlen("ko\n"), 0);
			return;
		}
		for (i = 0; client->fd != fd && client != NULL; i += 1) {
			client = client->next;
		}
		for (i2 = 0; client->buf[i2].cmd != NULL && i2 < 10; i2 += 1);
		//appller destroy client
		client->buf[i2].cmd = tab;
		client->buf[i2].time = time;
	}
}

t_client *init_client(t_server *server __attribute__((unused)), int fd)
{
	t_client *client = malloc(sizeof(t_client));
	if (client == NULL)
		exit(ERROR);
	client->fd = fd;
	client->player = NULL;
	for (int i = 0; i < 10; i += 1) {
		client->buf[i].cmd = NULL;
		client->buf[i].time = -1;
	}
	return (client);
}

int connect_client(t_server *server, t_client *client, int fd, char **tab)
{
	int i = 0;
	//int cpt = 0;
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
		/*for (cpt = 0; cpt < server->higher_fd &&
			      server->fds[cpt] != fd; cpt += 1);
		server->fds[cpt] = -1;
		FD_CLR(fd, &(server->readfds)); */
		send(fd, "ko\n", strlen("ko\n"), 0);
	}
	client->buf[0].cmd = NULL; // tempo a degager ->free
	// redécaller de tableau a gauche
	client->buf[0].time = -1;
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