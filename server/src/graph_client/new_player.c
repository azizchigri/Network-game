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

char *write_new_connection(char *result, t_player_p *player)
{
	result = add_str(result, "pnw #");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result = add_int(result, player->x);
	result = add_str(result, " ");
	result = add_int(result, player->y);
	result = add_str(result, " ");
	result = add_int(result, player->direction);
	result = add_str(result, " ");
	result = add_int(result, player->direction);
	result = add_str(result, " ");
	result = add_int(result, player->lvl);
	result = add_str(result, " ");
	result = add_str(result, player->team);
	return (result);
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
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = write_new_connection(result, player);
	result[size] = 0;
	return (result);
}
