/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** function point to drop and take
*/

#include "game.h"

int linemate(t_player_p *player, t_game_p *game, int value)
{
	if (player->linemate > 0 && value == DROP) {
		player->linemate -= 1;
		game->map[player->x][player->y].linemate += 1;
	}
	else if (game->map[player->x][player->y].linemate != 0
		&& value == TAKE) {
		player->linemate += 1;
		game->map[player->x][player->y].linemate -= 1;
	}
	else
		return (-1);
	return (0);
}

int deraumere(t_player_p *player, t_game_p *game, int value)
{
	if (player->deraumere > 0 && value == DROP) {
		player->deraumere -= 1;
		game->map[player->x][player->y].deraumere += 1;
	}
	else if (game->map[player->x][player->y].deraumere != 0
		&& value == TAKE) {
		player->deraumere += 1;
		game->map[player->x][player->y].deraumere -= 1;
	}
	else
		return (-1);
	return (0);
}

int sibur(t_player_p *player, t_game_p *game, int value)
{
	if (player->sibur > 0 && value == DROP) {
		player->sibur -= 1;
		game->map[player->x][player->y].sibur += 1;
	}
	else if (game->map[player->x][player->y].sibur != 0
		&& value == TAKE) {
		player->sibur += 1;
		game->map[player->x][player->y].sibur -= 1;
	}
	else
		return (-1);
	return (0);
}

int mendiane(t_player_p *player, t_game_p *game, int value)
{
	if (player->mendiane > 0 && value == DROP) {
		player->mendiane -= 1;
		game->map[player->x][player->y].mendiane += 1;
	}
	else if (game->map[player->x][player->y].mendiane != 0
		&& value == TAKE) {
		player->mendiane += 1;
		game->map[player->x][player->y].mendiane -= 1;
	}
	else
		return (-1);
	return (0);
}

int phiras(t_player_p *player, t_game_p *game, int value)
{
	if (player->phiras > 0 && value == DROP) {
		player->phiras -= 1;
		game->map[player->x][player->y].phiras += 1;
	}
	else if (game->map[player->x][player->y].phiras != 0
		&& value == TAKE) {
		player->phiras += 1;
		game->map[player->x][player->y].phiras -= 1;
	}
	else
		return (-1);
	return (0);
}
