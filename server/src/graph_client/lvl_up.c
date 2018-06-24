/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** lvl up for g client
*/

#include "game.h"

char *lvl_client(t_player_p *player)
{
	char *result;
	int size = 0;
	size += getsize_int_to_str(player->lvl);
	size += getsize_int_to_str(player->id);
	size += 5;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = add_str(result, "plv ");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result = add_int(result, player->lvl);
	result[size] = 0;
	return (result);
}
