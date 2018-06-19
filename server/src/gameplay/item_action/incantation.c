/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to do the incantation
*/

#include "game.h"

int check_incantation(t_game_p *game, t_player_p *player)
{
	return (0);
}

char *incantation(t_game_p *game, t_player_p *player)
{
	if (check_incantation(game, player) == -1)
		return ("KO");
	return ("OK");
}
