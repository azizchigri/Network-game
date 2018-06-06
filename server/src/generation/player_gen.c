/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to generate the map (serveur side)
*/

#include "game.h"

int place_player(t_game_p *game, t_player_p *player)
{
	if (game->map[player->x][player->y].players != NULL)
		return (-1);
	game->map[player->x][player->y].players =
		malloc(sizeof(t_player_p *) * 2);
	if (game->map[player->x][player->y].players == NULL)
		return (-1);
	game->map[player->x][player->y].players[0] = player;
	game->map[player->x][player->y].players[1] = NULL;
	return (0);
}

void init_player(t_game_p *game, t_player_p *player, int fd)
{
	int pos = 0;
	player->id = fd;
	player->alive = 1;
	player->inventory = NULL;
	while (pos == 0) {
		player->y = rand() % (game->width + 1) - 1;
		player->x = rand() % (game->height + 1) - 1;
		pos = place_player(game, player);
	}
	player->lvl = 0;
	player->direction = 0;
}
