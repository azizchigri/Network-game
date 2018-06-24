/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to check the map
*/

#include "game.h"

Test(map, height)
{
	int height = 10;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->height, height);
}

Test(map, width)
{
	int height = 10;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->width, width);
}

Test(map, freq)
{
	int height = 10;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->f, freq);
}

Test(map, error_map)
{
	int height = -1;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game, NULL);
}
