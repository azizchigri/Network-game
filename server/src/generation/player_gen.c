/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** file to generate the map (serveur side)
*/

#include "game.h"

t_player_p *destroy_player(t_player_p *player)
{
	if (player != NULL)
		free(player);
	player = NULL;
	return (player);
}

void init_inventory(t_player_p *player)
{
	player->lvl = 1;
	player->linemate = 0;
	player->deraumere = 0;
	player->sibur = 0;
	player->mendiane = 0;
	player->phiras = 0;
	player->thystame = 0;
	player->food = 9;
	player->alive = 1;
}

int fill_team(t_game_p *game, char *name)
{
	int i = 0;
	int tmp = -1;
	for (i = 0; game->teams[i] != NULL; i += 1) {
		if (strcmp(name, game->teams[i]->name) == 0) {
			game->teams[i]->slot -= 1;
			tmp = i;
		}
	}
	if (tmp == -1)
		return (-1);
	if (game->teams[tmp]->slot < 0) {
		game->teams[tmp]->slot = 0;
		return (-1);
	}
	return (0);
}

t_player_p *init_player(t_game_p *game,
			int fd, char *team)
{
	static int id = 0;
	int pos = -1;
	t_player_p *player;
	if (fill_team(game, team) == -1)
		return (NULL);
	player = malloc(sizeof(t_player_p) * 1);
	if (player == NULL)
		return (NULL);
	player->id = id;
	player->fd = fd;
	id += 1;
	init_inventory(player);
	player->direction = 0;
	player->team = team;
	while (pos == -1) {
		player->y = rand() % (game->width);
		player->x = rand() % (game->height);
		pos = new_place(player, game);
	}
	return (player);
}
