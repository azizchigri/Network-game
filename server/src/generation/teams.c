/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init teams
*/

#include "game.h"

t_teams *cp_teams(t_teams *team, char *name)
{
	t_teams *cpy = malloc(sizeof(t_teams) * 1);
	if (cpy == NULL)
		return (NULL);
	if (name != NULL) {
		cpy->name = name;
		cpy->lvl6 = 0;
		cpy->eggs = 0;
	}
	else {
		cpy->name = team->name;
		cpy->lvl6 = team->lvl6;
		cpy->eggs = team->eggs;
	}
	return (cpy);
}

int add_team(t_game_p *game, char *team)
{
	int i = 0;
	t_teams **tmp;
	for (i = 0; game->teams[i] != NULL; i += 1) {
		if (strcmp(game->teams[i]->name, "team") == 0)
			return (0);
	}
	for (i = 0; game->teams[i] != NULL; i += 1);
	tmp = malloc(sizeof(t_teams *) * (i + 2));
	if (tmp == NULL)
		return (-1);
	for (i = 0; game->teams[i] != NULL; i += 1)
		tmp[i] = cp_teams(game->teams[i], NULL);
	tmp[i] = cp_teams(NULL, team);
	tmp[i + 1] = NULL;
	free_teams(game->teams);
	game->teams = tmp;
	return (0);
}

int gen_teams(t_game_p *game, char *team)
{
	if (game->teams == NULL) {
		game->teams = malloc(sizeof(t_teams *) * 2);
		if (game->teams == NULL)
			return (-1);
		game->teams[0] = cp_teams(NULL, team);
		game->teams[1] = NULL;
	}
	else {
		if (add_team(game, team) == -1)
			return (-1);
	}
	return (0);
}
