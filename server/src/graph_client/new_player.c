/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inform graphical client of a new connexion
*/

#include "game.h"
#include "server.h"

int getsize_int_to_str(int nbr)
{
	int tmp;
	int size = 0;
	for (tmp = nbr; tmp != 0; tmp /= 10)
		size += 1;
	return (size);
}

void new_connection(t_player_p *player, int fd)
{
	char *result = NULL;

	if (player != NULL) {
		asprintf(&result, "pnw %d %d %d %d %d %s\n", player->id,
		player->x, player->y, (int) (player->direction + 1),
		player->lvl,
		player->team);
		if (fd != -1)
			send(fd, result, strlen(result), 0);
	}
	free(result);
}
