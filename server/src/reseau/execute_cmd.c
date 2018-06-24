/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** executes_cmd function
*/

#include "server.h"

void execute_incantation(t_server *server, t_client *client)
{
	t_respond rep = incantation(server->game, client->player, 0);
	if (strcmp(rep.respond, "ko") == 0)
		send(client->fd, "ko\n", 3, 0);
	else {
		for (int i = 0; rep.id[i] != -1; i += 1) {
			send(rep.id, rep.respond, strlen(rep.respond), 0);
		}
		if (rep.respond != NULL)
			free(rep.respond);
		if (rep.id != NULL)
			free(rep.id);
	}
	free_tab(client->buf[0].cmd);
	client->buf[0].time = 300.0 / server->options.frequence;
	client->buf[0].cmd = str_to_wordtab("Incantation2");
}

void execute_incantation_next(t_server *server, t_client *client)
{
	t_client *tmp = server->client;
	t_respond rep = incantation(server->game, client->player, 1);
	for (int i = 0; rep.id[i] != -1; i += 1) {
		send(rep.id, rep.respond, strlen(rep.respond), 0);
		for (tmp = server->client; tmp != NULL; tmp = tmp->next) {
			if (tmp->player != NULL &&
			    tmp->player->fd == rep.id[i])
				lvl_client(tmp->player, server->graph);
		}
	}
	if (strcmp(rep.respond, "ko") != 0 && rep.respond != NULL)
		free(rep.respond);
	if (rep.id != NULL)
		free(rep.id);
	clear_cmd(client);
}