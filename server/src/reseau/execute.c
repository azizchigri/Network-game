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

void manage_cmd(t_server *server, t_client *client)
{
	if (client->player == NULL) {
		send(client->fd, "ko\n", strlen("ko\n"), 0);
		clear_cmd(client);
		return;
	}
	while (client->buf[0].time == 0) {
		char **cmd = client->buf[0].cmd;
		printf("cmd :%s", client->buf[0].cmd[0]);
		t_respond rep = gameplay(cmd, client->player, server->game);
		printf("retour = %s\n", rep.respond);
		send(client->fd, rep.respond, strlen(rep.respond), 0);
		clear_cmd(client);
		// free_respond();
	}
	client->buf[0].time -= 1;
}

int execute_commands(t_server *server)
{
	t_client *client = server->client;
	while (client != NULL) {
		char **tab = client->buf[0].cmd;
		if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
			connect_client(server, client, client->fd, tab);
		} else if (client->buf[0].time != -1)
			manage_cmd(server, client);
		client = client->next;
	}
	return (0);
}