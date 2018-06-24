/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** refresh player and player in map
*/

#include "game.h"

void find_player(t_player_p *player, t_player_p **players)
{
	int i;
	if (players == NULL)
		return;
	for (i = 0; players[i] != NULL; i += 1) {
		if (players[i]->id == player->id) {
			player->x = players[i]->x;
			player->y = players[i]->y;
			player->lvl = players[i]->lvl;
		}
	}
}

void refresh_player(t_player_p *player, t_game_p *game)
{
	int x;
	int y;

	for (x = 0; game->map[x] != NULL; x += 1) {
		for (y = 0; y != game->height; y += 1)
			find_player(player, game->map[x][y].players);
	}
}

void refresh_map(t_player_p *player, t_game_p *game)
{
	int i;
	for (i = 0; game->map[player->x][player->y].players[i]->id !=
		    player->id; i += 1);
	game->map[player->x][player->y].players[i]->x = player->x;
	game->map[player->x][player->y].players[i]->y = player->y;
	game->map[player->x][player->y].players[i]->direction = player
	->direction;
	game->map[player->x][player->y].players[i]->linemate = player
	->linemate;
	game->map[player->x][player->y].players[i]->deraumere = player
	->deraumere;
	game->map[player->x][player->y].players[i]->sibur = player->sibur;
	game->map[player->x][player->y].players[i]->mendiane = player
	->mendiane;
	game->map[player->x][player->y].players[i]->phiras = player->phiras;
	game->map[player->x][player->y].players[i]->thystame = player
	->thystame;
	game->map[player->x][player->y].players[i]->food = player->food;
}
