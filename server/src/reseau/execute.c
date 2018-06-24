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

int execute_commands(t_server *server)
{
	t_client *client = server->client;
	while (client != NULL) {
		char **tab = client->buf[0].cmd;
		if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
			connect_client(server, client, client->fd, tab);
		} else if (tab != NULL && strcmp(tab[0], "Graphical")) {
			server->graph = client->fd;
			send(client->fd, "ok\n", 3, 0);
			clear_cmd(client);
			printf("hey le client graphique est:%d\n",server->graph);
		} else if (client->buf[0].time != -1)
			manage_cmd(server, client);
		client = client->next;
	}
	eat_client(server);
	return (0);
}