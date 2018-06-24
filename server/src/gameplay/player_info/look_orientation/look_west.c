/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look_west function
*/

#include "game.h"

char *west_finder(int y_min, int y_max, int x, t_game_p *game)
{
	char *result = strdup("");
	char *tmp;

	while (y_min != y_max || y_min == y_max) {
		if (y_min >= game->height)
			y_min -= game->height;
		tmp = build_result(x, y_min, game);
		if (tmp == NULL)
			break;
		result = realloc(result, strlen(result) + strlen(tmp) + 2);
		result = strcat(result, tmp);
		result = strcat(result, ",");
		if (y_min == y_max)
			break;
		y_min += 1;
	}
	return (result);
}

void see_west(t_player_p *player, int level, t_game_p *game, char **tab)
{
	int y_min = player->y - level;
	int y_max = player->y + level;
	int x = player->x - level;

	if (y_max >= game->height)
		y_max -= game->height;
	if (y_min < 0)
		y_min += game->width;
	if (x < 0)
		x += game->width;
	tab[level] = west_finder(y_min, y_max, x, game);
	tab[level + 1] = NULL;
	if (level != player->lvl)
		see_west(player, level + 1, game, tab);
}