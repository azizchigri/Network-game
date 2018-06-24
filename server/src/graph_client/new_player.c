/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inform graphical client of a new connexion
*/

#include "game.h"

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
	int size = 0;

	size += getsize_int_to_str(player->x);
	size += getsize_int_to_str(player->y);
	size += getsize_int_to_str(player->direction);
	size += getsize_int_to_str(player->id);
	size += getsize_int_to_str(player->lvl);
	size += strlen(player->team);
	size += 11;
	return (result);
}
