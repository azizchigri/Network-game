/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** executes_cmd function
*/

#include "server.h"

void execute_incantation(t_server *server, t_client *client)
{
	incantation(server->game, client->player, 0);
}