/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** delete stone for incantation
*/

#include "game.h"

int del_s6(t_game_p *game, t_player_p *player)
{
	if (player->lvl == 7)
		game->map[player->x][player->y].thystame -= 1;
	if (game->map[player->x][player->y].thystame < 0) {
		game->map[player->x][player->y].thystame = 0;
		return (-1);
	}
	return (0);
}
