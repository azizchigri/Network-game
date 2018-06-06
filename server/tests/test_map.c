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
	int freq = 1;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->height, height);
	destroy_game(game);
}

Test(map, width)
{
	int height = 10;
	int width = 10;
	int freq = 1;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->width, width);
	destroy_game(game);
}

Test(map, freq)
{
	int height = 10;
	int width = 10;
	int freq = 1;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game->f, freq);
	destroy_game(game);
}

Test(map, error_map)
{
	int height = -1;
	int width = 10;
	int freq = 1;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_eq(game, NULL);
}
