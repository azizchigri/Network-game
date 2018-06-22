/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look function
*/

#include "game.h"

char **get_cell(t_game_p *game, int x, int y)
{
	int i;
	char **cell;
	int size

	cell = malloc(sizeof(char *) * size);
	for (i = 0; game->map[x][y]->players[i] != NULL; i += 1) {
		cell[i] = "player"
	}
	return (cell);
}

char **look(t_game_p *game, t_player_p *player)
{
	char ***respond = "KO";

	return (respond);

}
