/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** death of a client for g client
*/

#include "game.h"
#include "server.h"

void death(t_player_p *player, int fd)
{
	char *result;
	asprintf(&result, "pdi %d\n", player->id);
	if (fd != -1)
		send(fd, result, strlen(result), 0);
	if (result!= NULL)
		free(result);
	result = NULL;
}
