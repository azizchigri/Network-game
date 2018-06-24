/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** ressources function
*/

#include "server.h"

void check_ressources(t_server *server)
{
	if (server->ressources <= 0) {
		server->ressources = RESSOURCES_TICK;
		init_ressources(server->game);
		if (server->graph != -1)
			mct(server->game, server->graph);
	}
	server->ressources -= 1;
}