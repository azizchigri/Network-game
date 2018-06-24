/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init teams
*/

#include "game.h"

int init_teams(t_game_p *game, char **teams_name, int slot)
{
	int i;
	for (i = 0; teams_name[i] != NULL; i += 1);
	game->teams = malloc(sizeof(t_teams *) * (i + 1));
	if (game->teams == NULL)
		return (-1);
	for (i = 0; teams_name[i] != NULL; i += 1) {
		game->teams[i] = malloc(sizeof(t_teams) * 1);
		if (game->teams[i] == NULL)
			return (-1);
		game->teams[i]->name = teams_name[i];
		game->teams[i]->slot = slot;
		game->teams[i]->eggs = 0;
		game->teams[i]->lvl6 = 0;
	}
	game->teams[i] = NULL;
	return (0);
}
