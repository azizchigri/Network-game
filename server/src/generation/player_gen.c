/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to generate the map (serveur side)
*/

#include "game.h"

t_player_p *destroy_player(t_player_p *player)
{
	if (player != NULL)
		free(player);
	player = NULL;
	return (player);
}

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

void init_inventory(t_player_p *player)
{
	player->linemate = 0;
	player->deraumere = 0;
	player->sibur = 0;
	player->mendiane = 0;
	player->phiras = 0;
	player->thystame = 0;
	player->food = 0;
}

t_player_p *init_player(t_game_p *game, int fd)
{
	int pos = -1;
	t_player_p *player = malloc(sizeof(t_player_p) * 1);
	if (player == NULL)
		return (NULL);
	player->id = fd;
	player->alive = 1;
	init_inventory(player);
	while (pos == -1) {
		player->y = rand() % (game->width);
		player->x = rand() % (game->height);
		pos = place_player(game, player);
	}
	player->lvl = 0;
	player->direction = 0;
	return (player);
}
