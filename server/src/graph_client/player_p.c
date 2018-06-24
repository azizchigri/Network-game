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

char *player_pos(t_player_p *player)
{
	char *result;
	int size = 0;
	size += getsize_int_to_str(player->id);
	size += getsize_int_to_str(player->x);
	size += getsize_int_to_str(player->y);
	size += getsize_int_to_str(player->direction);
	size += 7;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = write_ppo(result, player);
	result[size] = 0;
	return (result);
}

int size_pin(t_player_p *player)
{
	int size = 0;
	size += getsize_int_to_str(player->id);
	size += getsize_int_to_str(player->x);
	size += getsize_int_to_str(player->y);
	size += getsize_int_to_str(player->food);
	size += getsize_int_to_str(player->linemate);
	size += getsize_int_to_str(player->deraumere);
	size += getsize_int_to_str(player->sibur);
	size += getsize_int_to_str(player->mendiane);
	size += getsize_int_to_str(player->phiras);
	size += getsize_int_to_str(player->thystame);
	return (size);
}

char *write_pin(char *result, t_player_p *player)
{
	result = add_str(result, "pin ");
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

char *player_inv(t_player_p *player)
{
	char *result;
	int size = size_pin(player);
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
