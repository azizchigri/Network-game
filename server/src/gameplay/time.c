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

int check_time(char **cmd)
{
	int time = 0;
	if (strcmp("Right", cmd[0]) == 0 || strcmp("Left", cmd[0]) == 0
	|| strcmp("Forward", cmd[0]) == 0
	|| strcmp("Look", cmd[0]) == 0 || strcmp("Broadcast", cmd[0]) == 0
	|| strcmp("Eject", cmd[0]) == 0
	|| strcmp("Take object", cmd[0]) == 0
	|| strcmp("Set Object", cmd[0]) == 0)
		time = 7;
	else if (strcmp("Incantation", cmd[0]) == 0)
		time = 300;
	else if (strcmp("Fork", cmd[0]) == 0)
		time = 42;
	return (time);
}

int cooldown(t_game_p *game, t_player_p *player, char **cmd)
{
	int i;
	int j;
	int time = 0;
	if (strcmp("Inventory", cmd[0]) == 0)
		time = 1;
	else
		time = check_time(cmd);
	sleep(time/game->f);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < game->width; j += 1)
			player_refresh(game->map[i][j].players, player);
	}
	return (0);
}
