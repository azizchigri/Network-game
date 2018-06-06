/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** delete old position and go to the next one
*/

#include "game.h"

int remove_place(t_player_p *player, t_game_p *game)
{
	int *tmp;
	int size = 0;
	while (game->map[player->x][player->y].players[size] != 0)
		size += 1;
	tmp = malloc(sizeof(int) * (size - 1));
	if (tmp == NULL)
		return (-1);
	size = 0;
	while (game->map[player->x][player->y].players[size] != 0) {
		if (game->map[player->x][player->y].players[size] != player->id)
			tmp[size] = game->map[player->x][player->y].players[size];
		size += 1;
	}
	tmp[size - 1] = 0;
	free(game->map[player->x][player->y].players);
	game->map[player->x][player->y].players = tmp;
	return (0);
}

int new_place(t_player_p *player, t_game_p *game)
{
	int *tmp;
	int size = 0;
	while (game->map[player->x][player->y].players[size] != 0)
		size += 1;
	tmp = malloc(sizeof(int) * size + 2);
	if (tmp == NULL)
		return (-1);
	size = 0;
	while (game->map[player->x][player->y].players[size] != 0) {
		tmp[size] = game->map[player->x][player->y].players[size];
		size += 1;
	}
	tmp[size + 1] = player->id;
	tmp[size + 2] = 0;
	free(game->map[player->x][player->y].players);
	game->map[player->x][player->y].players = tmp;
	return (0);
}
