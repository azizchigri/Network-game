/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to do the incantation
*/

#include "game.h"

int check_nbr_player2(int lvl, int tmp)
{
	if (lvl == 1)
		return (1);
	else if ((lvl == 2 || lvl == 3) && tmp >= 2)
		return (2);
	else
		return (-1);
}

int check_nbr_player(int lvl, int tmp)
{
	int ret = check_nbr_player2(lvl, tmp);
	if ((lvl == 4 || lvl == 5) && tmp >= 4)
		ret = 4;
	else if ((lvl == 6 || lvl == 7) && tmp >= 6)
		ret = 6;
	return (ret);
}

int check_incantation(t_game_p *game, t_player_p *player)
{
	int i;
	int tmp = 0;
	int x = player->x;
	int y = player->y;
	if (player->lvl == 8)
		return (-1);
	for (i = 0; game->map[x][y].players[i] != NULL; i += 1) {
		if (game->map[x][y].players[i]->lvl == player->lvl)
			tmp += 1;
	}
	return (check_nbr_player(player->lvl, tmp));
}

void lvl_up(t_game_p *game, t_player_p *player, int tmp)
{
	int x = player->x;
	int y = player->y;
	int i = 0;
	for (i = 0; game->map[x][y].players[i] != NULL; i += 1) {
		if (game->map[x][y].players[i]->id == player->id)
			game->map[x][y].players[i]->lvl += 1;
	}
	tmp -= 1;
	for (i = 0; game->map[x][y].players[i] != NULL; i += 1) {
		if (game->map[x][y].players[i]->lvl == player->lvl
		&& game->map[x][y].players[i]->id != player->id
		&& tmp != 0) {
			game->map[x][y].players[i]->lvl += 1;
			tmp -= 1;
		}
	}
	for (i = 0; strcmp(game->teams[i]->name, player->team) != 0; i += 1);
	if (player->lvl == 5)
		game->teams[i]->lvl6 += 1;
	player->lvl += 1;
}

t_respond incantation(t_game_p *game, t_player_p *player, int begin)
{
	int tmp = check_incantation(game, player);
	int error = 0;
	t_respond resp;
	if (begin == 0)
		return (get_player_incant(game, player, tmp));
	error += del_s1(game, player);
	error += del_s2(game, player);
	error += del_s3(game, player);
	error += del_s4(game, player);
	error += del_s5(game, player);
	error += del_s6(game, player);
	if (error == 0 || tmp != -1)
		lvl_up(game, player, tmp);
	resp = get_player_had_incant(game, player, tmp);
	return (resp);
}
