/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** delete old position and go to the next one
*/

#include "game.h"

int remove_place(t_player_p *player, t_game_p *game)
{
	t_player_p **tmp;
	int size = 0;
	while (game->map[player->x][player->y].players[size] != NULL)
		size += 1;
	tmp = malloc(sizeof(t_player_p *) * (size - 1));
	if (tmp == NULL)
		return (-1);
	size = 0;
	while (game->map[player->x][player->y].players[size] != NULL) {
		if (game->map[player->x][player->y].players[size] != player)
			tmp[size] = game->map[player->x][player->y].players[size];
		size += 1;
	}
	tmp[size - 1] = NULL;
	free(game->map[player->x][player->y].players);
	game->map[player->x][player->y].players = tmp;
	return (0);
}

int new_place(t_player_p *player, t_game_p *game)
{
	t_player_p **tmp;
	int size = 0;
	if (game->map[player->x][player->y].players != NULL) {
		while (game->map[player->x][player->y].players[size] != NULL)
			size += 1;
	}
	tmp = malloc(sizeof(t_player_p *) * size + 2);
	if (tmp == NULL)
		return (-1);
	size = 0;
	if (game->map[player->x][player->y].players != NULL) {
		while (game->map[player->x][player->y].players[size] != NULL) {
			tmp[size] = game->map[player->x][player->y].players[size];
			size += 1;
		}
	}
	tmp[size] = player;
	tmp[size + 1] = NULL;
	free(game->map[player->x][player->y].players);
	game->map[player->x][player->y].players = tmp;
	return (0);
}
