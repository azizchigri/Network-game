/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject cmd
*/

#include "game.h"

char *eject(t_player_p *player, t_game_p *game)
{
	if (game->map[player->x][player->y].players[1] == NULL)
		return ("KO");
	return ("OK");
}
