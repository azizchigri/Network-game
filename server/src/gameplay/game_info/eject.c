/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject cmd
*/

#include "game.h"

char *eject(t_player_p *player, t_game_p *game)
{
	int i;
	t_player_p *player_pushed;
	if (game->map[player->x][player->y].players[1] == NULL)
		return ("KO");
	for (i = 0;
	game->map[player->x][player->y].players[i]->id == player->id; i +=1);
	player_pushed = cp_player(game->map[player->x][player->y].players[i]);
	player_pushed->direction = player->direction;
	front(player_pushed, game);
	return ("OK");
}
