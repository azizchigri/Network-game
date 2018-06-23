/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player position for g client
*/

#include "game.h"

char *write_ppo(char *result, t_player_p *player)
{
	result = add_str(result, "ppo ");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result = add_int(result, player->x);
	result = add_str(result, " ");
	result = add_int(result, player->y);
	result = add_str(result, " ");
	result = add_int(result, player->direction);
	return (result);
}

char *ppo(t_player_p *player)
{
	char *result;
	int size = 0;
	for (tmp = player->id; tmp != 0; tmp /= 10)
		size += 1;
	for (tmp = player->x; tmp != 0; tmp /= 10)
		size += 1;
	for (tmp = player->y; tmp != 0; tmp /= 10)
		size += 1;
	for (tmp = player->direction; tmp != 0; tmp /= 10)
		size += 1;
	size += 7;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = write_ppo(result, player);
	result[size] = 0;
	return (result);
}

int size_pin(t_player_p *player, int *size)
{
	for (tmp = player->id; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->x; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->y; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->food; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->linemate; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->deraumere; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->sibur; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->mendiane; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->phiras; tmp != 0; tmp /= 10)
		*size += 1;
	for (tmp = player->thystame; tmp != 0; tmp /= 10)
		*size += 1;
}

char *write_ppo(char *result, t_player_p *player)
{
	result = add_str(result, "ppo ");
	result = add_int(result, player->id);
	result = add_str(result, " ");
	result = add_int(result, player->x);
	result = add_str(result, " ");
	result = add_int(result, player->y);
	result = add_str(result, " ");
	result = add_int(result, player->food);
	result = add_str(result, " ");
	result = add_int(result, player->linemate);
	result = add_str(result, " ");
	result = add_int(result, player->deraumere);
	result = add_str(result, " ");
	result = add_int(result, player->sibur);
	result = add_str(result, " ");
	result = add_int(result, player->mendiane);
	result = add_str(result, " ");
	result = add_int(result, player->phiras);
	return (result);
}

char *pin(t_player_p *player)
{
	char *result;
	int size = 0;
	size_pin(player, &size);
	size += 13;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = write_pin(result, player);
	result = add_str(result, " ");
	result = add_int(result, player->thystame);
	result[size] = 0;
	return (result);
}
