/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** lvl up for g client
*/

#include "game.h"
#include "server.h"

char *lvl_client(t_player_p *player)
{
	char *result;
	asprintf(&result, "plv %d %d\n", player->id, player->lvl);
	return (result);
}
