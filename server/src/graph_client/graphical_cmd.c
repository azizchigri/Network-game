/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** graphical_cmd function
*/

#include "server.h"

void init_client_graph(t_server *server, t_client *client)
{
	t_client *tmp = server->client;
	server->graph = client->fd;
	send(client->fd, "ok\n", 3, 0);
	clear_cmd(client);
	map_size(server->game, server->graph);
	mct(server->game, server->graph);
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->player != NULL && server->graph != -1) {
			new_connection(tmp->player, server->graph);
			player_inv(tmp->player, server->graph);
		}
	}
}