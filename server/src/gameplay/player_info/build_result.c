/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** build_result function
*/

#include "game.h"

char *build_players(t_cell map, int x, int y, char *res)
{
	int i = 0;

	while (map.players != NULL && map.players[i] != NULL) {
		res = realloc(res, strlen(res) + strlen("player") + 2);
		if (res == NULL)
			return (NULL);
		if (i != 0)
			res = strcat(res, " ");
		res = strcat(res, "player");
		i += 1;
	}
	return (res);
}

char *build_resource(int max, char *msg, char *res)
{
	int i = 0;

	if (res != NULL && strcmp(res, "") != 0 && i != max) {
		res = realloc(res, strlen(res) + 2);
		if (res == NULL)
			return (NULL);
		res = strcat(res, " ");
	}
	while (i < max) {
		res = realloc(res, strlen(res) + strlen(msg) + 2);
		if (res == NULL)
			return (NULL);
		if (i != 0)
			res = strcat(res, " ");
		res = strcat(res, msg);
		i += 1;
	}
	return (res);
}

char *build_result(int x, int y, t_game_p *game)
{
	t_cell map = game->map[x][y];
	char *res = strdup("");

	res = build_players(map, x, y, res);
	res = build_resource(map.deraumere, "deraumere", res);
	res = build_resource(map.linemate, "linemate", res);
	res = build_resource(map.food, "food", res);
	res = build_resource(map.mendiane, "mendiane", res);
	res = build_resource(map.sibur, "sibur", res);
	res = build_resource(map.phiras, "phiras", res);
	res = build_resource(map.thystame, "thystame", res);
	return (res);
}