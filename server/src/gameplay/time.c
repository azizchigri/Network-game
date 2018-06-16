/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** wait some time before doing any action
*/

#include "game.h"

void player_refresh(t_player_p **players, t_player_p *player)
{
	int i;
	if (players == NULL)
		return;
	for (i = 0; players[i] != NULL; i += 1) {
		if (players[i]->id == player->id) {
			player->x = players[i]->x;
			player->y = players[i]->y;
		}
	}
}

int cooldown(t_game_p *game, t_player_p *player)
{
	int i;
	int j;
	sleep(1/game->f);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < game->width; j += 1)
			player_refresh(game->map[i][j].players, player);
	}
	return (0);
}
