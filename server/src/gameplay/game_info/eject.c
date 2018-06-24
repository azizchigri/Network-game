/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject cmd
*/

#include "game.h"

int find_player_map(t_player_p *player, t_game_p *game)
{
	int i;
	if (game->map[player->x][player->y].players == NULL
	|| game->map[player->x][player->y].players[1] == NULL)
		return (-1);
	for (i = 0;
	game->map[player->x][player->y].players[i]->id == player->id;
	i += 1);
	return (i);
}

char *do_eject(t_player_p *player, t_game_p *game, int i)
{
	t_player_p *player_pushed;
	int tmp;
	char *graph;
	tmp = game->map[player->x][player->y].players[i]->direction;
	player_pushed = cp_player(game->map[player->x][player->y].players[i]);
	player_pushed->direction = player->direction;
	graph = player_pos(player_pushed);
	front(player_pushed, game);
	for (i = 0;
	game->map[player_pushed->x][player_pushed->y].players[i]->id
		== player->id;
	i += 1);
	game->map[player_pushed->x][player_pushed->y].players[i]->direction
		= tmp;
	free(player_pushed);
	return (graph);
}

t_respond eject(t_player_p *player, t_game_p *game)
{
	t_respond resp;
	int i = find_player_map(player, game);
	resp.respond = "KO";
	resp.respond_g = NULL;
	if (i == -1)
		return (resp);
	resp.respond_g = do_eject(player, game, i);
	return (resp);
}
