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
		for (int i = 0; rep.id[i] != -1; i += 1) {
			send(rep.id[i], rep.respond, strlen(rep.respond), 0);
			send(rep.id[i], "\n", strlen("\n"), 0);

		}
		if (rep.respond != NULL)
			free(rep.respond);
		if (rep.id != NULL)
			free(rep.id);
	}
	client->buf[0].time = 300.0 / server->options.frequence;
	client->buf[0].cmd = str_to_wordtab("Incantation2");
}

void execute_incantation_next(t_server *server, t_client *client)
{
	t_client *tmp = server->client;
	t_respond rep = incantation(server->game, client->player, 1);
	for (int i = 0; rep.id[i] != -1; i += 1) {
		send(rep.id[i], rep.respond, strlen(rep.respond), 0);
		send(rep.id[i], "\n", strlen("\n"), 0);
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

int execute_other_md_next(t_server *server, t_client *client, char **tab)
{
	if (tab != NULL && strcmp(tab[0], "Fork") == 0 &&
		client->buf[0].time == 0) {
		if (client->player != NULL)
			server->egg = add_egg(server, server->egg,
			client->player->team);
		send(client->fd, "ok\n", 3, 0);
		clear_cmd(client);
		return (0);
	} else if (tab != NULL && strcmp(tab[0], "Incantation") == 0 &&
	    client->buf[0].time == 0) {
		if (client->player != NULL)
			execute_incantation(server, client);
		return (0);
	} else if (tab != NULL && strcmp(tab[0], "Incantation2") == 0 &&
	    client->buf[0].time == 0) {
		if (client->player != NULL)
			execute_incantation_next(server, client);
		return (0);
	}
	return (-1);
}