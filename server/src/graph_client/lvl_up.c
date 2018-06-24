/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** lvl up for g client
*/

#include "game.h"
#include "server.h"

void lvl_client(t_player_p *player, int fd)
{
	char *result;
	asprintf(&result, "plv %d %d\n", player->id, player->lvl);
	if (result != NULL && fd != -1)
		send(fd, result, strlen(result), 0);
	if (result != NULL)
		free(result);
}
