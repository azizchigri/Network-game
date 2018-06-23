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
		char **tab = client->buf->cmd;
		if (tab != NULL && strcmp(tab[0], "TEAM") == 0)
			init_client_player(server, client, tab);
		if (client->player != NULL)

			for (int i = 0; i < 10; i += 1) {
				if (client->buf[i].time != -1) {
					char **cmd = client->buf[i].cmd;
					printf("cmd :%s",
					client->buf[i].cmd[0]);
					t_respond rep = gameplay(cmd,
					client->player, server->game);
					printf("retour = %s\n", rep.respond);
					client->buf[i]
					.cmd = NULL; // tempo a degager ->free
					client->buf[i].time = -1;
					// free_respond();
				}
			}
		client = client->next;
		//free(tab);
	}
	printf("execute\n");
	printf("client:%p\n", server->client);
	return (0);
}