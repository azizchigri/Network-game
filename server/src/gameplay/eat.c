/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eat when possible or die
*/

#include "game.h"

char *eat(t_player_p *player, t_game_p *game)
{
	char *result = "alive";

	player->food -= 1;
	if (player->food < 0) {
		player->alive  = 0;
		result = "dead";
		remove_place(player, game);
	}
	return (result);
}
