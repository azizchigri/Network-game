/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** death of a client for g client
*/

#include "game.h"
#include "server.h"

char *death(t_player_p *player)
{
	char *result;
	asprintf(&result, "pdi %d\n", player->id);
	return (result);
}
