/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** execute function
*/

#include "server.h"

int execute_commandes(t_server *server)
{
	t_client *client = server->client;
	while (client != NULL) {
		char **tab = str_to_wordtab(client->buf->cmd);
		if (tab != NULL && strcmp(tab[0], "TEAM") == 0) {
			client->player = init_player(server->game, client->fd,
			tab[1]);
			if (client->player == NULL) {
				free(client);
				exit (ERROR);
			}
		}
		if (client->player != NULL)
			cooldown(server->game, server->client->player, tab);
		for (int i = 0; i < 10; i += 1) {
			if (client->buf[i].time != -1) {
				char **cmd = str_to_wordtab(client->buf[i]
				.cmd);
				printf("cmd :%s", client->buf[i].cmd);
				t_respond rep = gameplay(cmd, client->player,
				server->game);
				printf("retour = %s\n", rep.respond);
				client->buf[i].cmd= NULL; // tempo a degager ->free
				client->buf[i].time = -1;
			}
		}
		client = client->next;
	}
	printf("execute\n");
	printf("client:%p\n", server->client);
	return (0);
}