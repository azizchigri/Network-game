/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017s
** execute function
*/

#include "server.h"

int execute_commands(t_server *server)
{
	t_client *client = server->client;
	while (client != NULL) {
		char **tab  = client->buf[0].cmd;
		if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
			connect_client(server, client, client->fd, tab);
		} else if (client->player != NULL)
			if (client->buf[0].time != -1) {
				char **cmd = client->buf[0].cmd;
				printf("cmd :%s", client->buf[0].cmd[0]);
				t_respond rep = gameplay(cmd, client->player,
				server->game);
				printf("retour = %s\n", rep.respond);
				send(client->fd, rep.respond, strlen(rep.respond), 0);
				client->buf[0]
				.cmd = NULL; // tempo a degager ->free
				// redécaller de tableau a gauche
				client->buf[0].time = -1;
				// free_respond();
			}
		client = client->next;
		//free(tab);
	}
	return (0);
}