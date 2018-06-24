/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** mct_function function
*/

#define _GNU_SOURCE
#define CURRENT_LINE "bct %d %d %d %d %d %d %d %d %d\n"
#include "game.h"
#include "server.h"

void mct(t_game_p *game, int fd)
{
	char *tmp;

	for (int i = 0; i < game->width; i += 1) {
		for (int j = 0; j < game->height; j += 1) {
			t_cell map = game->map[i][j];
			int err = asprintf(&tmp, CURRENT_LINE,
			i, j, map.food, map.linemate, map.deraumere,
			map.sibur, map.mendiane, map.phiras, map.thystame);
			if (err == -1)
				return;
			send(fd, tmp, strlen(tmp), 0);
			free(tmp);
			tmp = NULL;
		}
	}
}
