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
	int tmp;
	if (game->map[player->x][player->y].players[1] == NULL)
		return ("KO\n");
	for (i = 0;
	game->map[player->x][player->y].players[i]->id == player->id;
	i += 1);
	tmp = game->map[player->x][player->y].players[i]->direction;
	player_pushed = cp_player(game->map[player->x][player->y].players[i]);
	player_pushed->direction = player->direction;
	front(player_pushed, game);
	for (i = 0;
	game->map[player_pushed->x][player_pushed->y].players[i]->id
		== player->id;
	i += 1);
	game->map[player_pushed->x][player_pushed->y].players[i]->direction
		= tmp;
	free(player_pushed);
	return ("OK\n");
}
