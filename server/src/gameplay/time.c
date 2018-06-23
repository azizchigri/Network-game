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

int other_time(char **cmd)
{
	int time = 0;
	if (strcmp(FORK, cmd[0]) == 0)
		time = 42;
	else if (strcmp(CONNECT_NBR, cmd[0]) == 0 ||
		strcmp("TEAM", cmd[0]) == 0)
		time = 0;
	else
		time = -1;
	return (time);
}

int check_time(char **cmd)
{
	int time = 0;
	if (strcmp(RIGHT, cmd[0]) == 0 || strcmp(LEFT, cmd[0]) == 0 ||
	strcmp(FORWARD, cmd[0]) == 0 || strcmp(LOOK, cmd[0]) == 0 ||
	strcmp(BROADCAST, cmd[0]) == 0 || strcmp(EJECT, cmd[0]) == 0 ||
	strcmp(TAKE_OBJ, cmd[0]) == 0 || strcmp(SET_OBJ, cmd[0]) == 0)
		time = 7;
	else if (strcmp(INCANTATION, cmd[0]) == 0)
		time = 300;
	else
		time = other_time(cmd);
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
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < game->width; j += 1)
			player_refresh(game->map[i][j].players, player);
	}
	return (time);
}
