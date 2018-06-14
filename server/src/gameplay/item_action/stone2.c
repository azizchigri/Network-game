/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** function point to drop and take
*/

#include "game.h"

static int thystame(t_player_p *player, t_game_p *game, int value)
{
	if (value < 0) {
		if (player->thystame > 0) {
			player->thystame -= 1;
			game->map[player->x][player->y].thystame += 1;
		}
		else
			return (-1);
	}
	else if (game->map[player->x][player->y].thystame != 0) {
		player->thystame += 1;
		game->map[player->x][player->y].thystame -= 1;
	}
	else
		return (-1);
	return (0);
}

static int food(t_player_p *player, t_game_p *game, int value)
{
	if (value < 0) {
		if (player->food > 0) {
			player->food -= 1;
			game->map[player->x][player->y].food += 1;
		}
		else
			return (-1);
	}
	else if (game->map[player->x][player->y].food != 0) {
		player->food += 1;
		game->map[player->x][player->y].food -= 1;
	}
	else
		return (-1);
	return (0);
}
