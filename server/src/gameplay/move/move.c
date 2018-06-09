/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** functions to move ai
*/

#include "game.h"

void right(t_player_p *player)
{
	player->direction += 1;
	if (player->direction == 4)
		player->direction = 0;
}

void left(t_player_p *player)
{
	player->direction -= 1;
	if (player->direction == -1)
		player->direction = 4;
}

void up_down(t_player_p *player, t_game_p *game)
{
	if (player->direction == 0) {
		if (remove_place(player, game) == -1)
			return;
		player->y += 1;
		if (new_place(player, game) == -1)
			return;
	}
	else {
		if (remove_place(player, game) == -1)
			return;
		player->y -= 1;
		if (new_place(player, game) == -1)
			return;
	}
}

void left_right(t_player_p *player, t_game_p *game)
{
	if (player->direction == 0) {
		if (remove_place(player, game) == -1)
			return;
		player->x += 1;
		if (new_place(player, game) == -1)
			return;
	}
	else {
		if (remove_place(player, game) == -1)
			return;
		player->x -= 1;
		if (new_place(player, game) == -1)
			return;
	}
}

void front(t_player_p *player, t_game_p *game)
{
	if (player->direction == 0 || player->direction == 2)
		up_down(player, game);
	else
		left_right(player, game);
}
