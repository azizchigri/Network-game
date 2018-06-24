/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eat when possible or die
*/

#include "server.h"

char *eat(t_player_p *player, t_server *server)
{
	char *result = "alive";

	player->food -= 1;
	if (player->food < 0) {
		player->alive  = 0;
		result = "dead";
		death(player, server->graph);
	}
	return (result);
}
