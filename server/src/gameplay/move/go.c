/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** delete old position and go to the next one
*/

#include "game.h"

int remove_place(t_player_p *player, t_game_p *game)
{
	t_player_p **tmp;
	int size = 0;
	while (game->map[player->x][player->y].players[size] != NULL)
		size += 1;
	tmp = malloc(sizeof(t_player_p *) * (size - 1));
	if (tmp == NULL)
		return (-1);
	size = 0;
	while (game->map[player->x][player->y].players[size] != NULL) {
		if (game->map[player->x][player->y].players[size]->id != player->id)
			tmp[size] = cp_player(game->map[player->x][player->y].players[size]);
		size += 1;
	}
	game->map[player->x][player->y].players = free_player_cell(game->map[player->x][player->y].players);
	if (size == 1) {
		game->map[player->x][player->y].players = NULL;
		free(tmp);
	}
	else {
		tmp[size - 1] = NULL;
		game->map[player->x][player->y].players = tmp;
	}
	return (0);
}

t_player_p *cp_player(t_player_p *player)
{
	t_player_p *cpy = malloc(sizeof(t_player_p) * 1);
	if (cpy == NULL)
		return (NULL);
	cpy->id = player->id;
	cpy->alive = player->alive;
	cpy->lvl = player->lvl;
	cpy->team = player->team;
	cpy->linemate = player->linemate;
	cpy->deraumere = player->deraumere;
	cpy->sibur = player->sibur;
	cpy->mendiane = player->mendiane;
	cpy->phiras = player->phiras;
	cpy->thystame = player->thystame;
	cpy->food = player->food;
	cpy->x = player->x;
	cpy->y = player->y;
	cpy->direction = player->direction;
	return (cpy);
}

int new_place(t_player_p *player, t_game_p *game)
{
	t_player_p **tmp;
	int size = 0;
	if (game->map[player->x][player->y].players != NULL) {
		while (game->map[player->x][player->y].players[size] != NULL)
			size += 1;
	}
	tmp = malloc(sizeof(t_player_p *) * (size + 2));
	if (tmp == NULL)
		return (-1);
	size = 0;
	if (game->map[player->x][player->y].players != NULL) {
		while (game->map[player->x][player->y].players[size] != NULL) {
			tmp[size] = cp_player(game->map[player->x][player->y].players[size]);
			size += 1;
		}
	}
	tmp[size] = cp_player(player);
	tmp[size + 1] = NULL;
	game->map[player->x][player->y].players = free_player_cell(game->map[player->x][player->y].players);
	game->map[player->x][player->y].players = tmp;
	return (0);
}
