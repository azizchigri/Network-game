/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ressources droping and taking for client
*/

#include "game.h"

char *take_r_client(char *ress, int nb)
{
	char *result;
	int size = 0;
	for (tmp = player->id; tmp != 0; tmp /= 10)
		size += 1;
	result = malloc(sizeof(char) * size + 7);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = add_str(result, "pgt ");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result[size + 5] = ress;
	result[size + 6] = 0;
	return (result);
}

char *drop_r_client(char ress, t_player_p *player)
{
	char *result;
	int size = 0;
	for (tmp = player->id; tmp != 0; tmp /= 10)
		size += 1;
	result = malloc(sizeof(char) * size + 7);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = add_str(result, "pdr ");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result[size + 5] = ress;
	result[size + 6] = 0;
	return (result);
}
