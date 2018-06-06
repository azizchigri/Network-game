/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to generate the map (serveur side)
*/

#include "game.h"

void init_ressources(t_game_p *game)
{
	int i;
	int j;

	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < game->width; j += 1) {
			game->map[i][j].linemate = rand() % 2;
			game->map[i][j].deraumere = rand() % 2;
			game->map[i][j].sibur = rand() % 2;
			game->map[i][j].mendiane = rand() % 2;
			game->map[i][j].phiras = rand() % 2;
			game->map[i][j].thystame = rand() % 2;
			game->map[i][j].food = rand() % 2;
		}
	}
}

void init_cell(t_game_p *game, int i, int j)
{
	game->map[i][j].players = NULL;
	game->map[i][j].linemate = 0;
	game->map[i][j].deraumere = 0;
	game->map[i][j].sibur = 0;
	game->map[i][j].mendiane = 0;
	game->map[i][j].phiras = 0;
	game->map[i][j].thystame = 0;
	game->map[i][j].food = 0;
}

int create_map(t_game_p *game)
{
	int i = 0;
	int j = 0;
	game->map = malloc(sizeof(t_cell *) * (game->height + 1));
	if (game->map == NULL)
		return (-1);
	game->map[game->height] = NULL;
	for (i = 0; i != game->height; i += 1) {
		game->map[i] = malloc(sizeof(t_cell) * (game->width + 1));
		if (game->map[i] == NULL)
			return (-1);
		for (j = 0; j <= game->width; j += 1)
			init_cell(game, i, j);
	}
	init_ressources(game);
	return (0);
}
