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
	for (int i = 0; rep.id != -1; i += 1) {
		send();
	}
}