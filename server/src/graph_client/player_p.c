/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player position for g client
*/

#include "game.h"
#include "server.h"

char *player_pos(t_player_p *player)
{
	char *result;

	asprintf(&result, "ppo %d %d %d %d\n", player->id,
		player->x, player->y, (int) (player->direction + 1));
	return (result);
}

void player_inv(t_player_p *player, int fd)
{
	char *result;

	asprintf(&result,
		"pin %d %d %d %d %d %d %d %d %d %d\n",
		player->id, player->x, player->y,
		player->food, player->linemate,
		player->deraumere, player->sibur,
		player->mendiane, player->phiras, player->thystame);
	if (fd != -1)
		send(fd, result, strlen(result), 0);
	if (result != NULL)
		free(result);
	result = NULL;
}
