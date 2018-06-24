/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look_south function
*/

#include "game.h"

char *south_finder(int x_min, int x_max, int y, t_game_p *game)
{
	char *result = strdup("");
	char *tmp;

	while (x_min != x_max || x_min == x_max) {
		if (x_min < 0)
			x_min += game->width;
		tmp = build_result(x_min, y, game);
		if (tmp == NULL)
			break;
		result = realloc(result, strlen(result) + strlen(tmp) + 2);
		result = strcat(result, tmp);
		result = strcat(result, ",");
		if (x_min == x_max)
			break;
		x_min -= 1;
	}
	return (result);
}

void see_south(t_player_p *player, int level, t_game_p *game, char **tab)
{
	int x_min = player->x + level;
	int x_max = player->x - level;
	int y = player->y - level;

	if (x_min >= game->width)
		x_min -= game->width;
	if (x_max < 0)
		x_max += game->width;
	if (y < 0)
		y += game->height;
	tab[level] = south_finder(x_min, x_max, y, game);
	tab[level + 1] = NULL;
	if (level != player->lvl)
		see_south(player, level + 1, game, tab);
}
