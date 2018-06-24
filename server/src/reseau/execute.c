/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017s
** execute function
*/

#include "server.h"

void clear_cmd(t_client *client)
{
	free_tab(client->buf[0].cmd);
	client->buf[0].time = -1;
	for (int i = 1; i < 10; i += 1) {
		client->buf[i - 1].cmd = client->buf[i].cmd;
		client->buf[i - 1].time = client->buf[i].time;
	}
	client->buf[9].cmd = NULL;
	client->buf[9].time = -1;
}

void eat_client(t_server *server)
{
	t_client *client = server->client;
	if (server->eat == 0) {
		while (client != NULL) {
			if (client->player != NULL) {
				char *str = eat(client->player);
				if (str != NULL && strcmp(str, "dead") == 0) {
					FD_CLR(client->fd, &(server->readfds));
					send(client->fd, "dead\n", 5, 0);
					destroy_client(server, client);
				}
			}
			if (client != NULL)
				client = client->next;
		}
		server->eat = SERVER_EAT;
	} else
		server->eat -= 1;
}

void check_client_win(t_server *server)
{
	char *status = check_win(server->game);
	if (strcmp(status, "ko") != 0) {
		t_client *client = server->client;
		printf("Le gagnant est:%s\n", status);
		for (; client != NULL; client = client->next) {
			destroy_client(server, client);
		}
		//free server
		exit(0);
	}
}

int execute_other_cmd(t_server *server, t_client *client, char **tab)
{
	if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
		connect_client(server, client, client->fd, tab);
		return (0);
	} else if (tab != NULL && strcmp(tab[0], "Graphical") == 0) {
		server->graph = client->fd;
		send(client->fd, "ok\n", 3, 0);
		clear_cmd(client);
		//msz et mct
		return (0);
	}
	if (tab != NULL && strcmp(tab[0], "Broadcast") == 0 &&
	    client->buf[0].time == 0) {
		t_client *tmp = server->client;
		char *msg;
		int size = 0;
		for (; tmp != NULL; tmp = tmp->next) {
			if (tmp != client) {
				msg = broadcast(server->game, client->player,
				tmp->player);
				size = strlen(msg);
				msg = realloc(msg, size + 2);
				strcat(msg, "\n\0");
				send(tmp->fd, msg, size, 0);
				free(msg);
			}
		}
		send(client->fd, "ok\n", 3, 0);
		clear_cmd(client);
	}
	return (-1);
}

int execute_commands(t_server *server)
{
	t_client *client = server->client;
	int result;
	while (client != NULL) {
		char **tab = client->buf[0].cmd;
		result = execute_other_cmd(server, client, tab);
		if (result == -1 && (client->buf[0].time != -1)) {
			manage_cmd(server, client);
		}
		client = client->next;
	}
	eat_client(server);
	check_client_win(server);
	return (0);
}