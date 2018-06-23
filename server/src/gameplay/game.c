/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check if a team win the game
*/

#include "game.h"

char *check_win(t_game_p *game)
{
	int i;
	char *respond = "KO";
	for (i = 0; game->teams[i] != NULL; i += 1) {
		if (game->teams[i]->lvl6 >= 6)
			respond = game->teams[i]->name;
	}
	return (respond);
}
