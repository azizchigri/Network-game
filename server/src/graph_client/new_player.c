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

char *new_connection(t_player_p *player)
{
	char *result = NULL;

	asprintf(&result, "pnw #%d %d %d %c %d %s\n",
		player->id, player->x, player->y,
		player->direction, player->lvl, player->team);
	return (result);
}
