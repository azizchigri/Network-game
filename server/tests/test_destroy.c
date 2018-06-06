/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to destroy the game
*/

#include "game.h"

Test(free_map, is_it_free)
{
	t_game_p *game = game_init(10, 10, 1);
	game = destroy_game(game);
	cr_assert_eq(game, NULL);
}

Test(free_map, double_free_corruption)
{
	t_game_p *game = game_init(-1, 10, 1);
	game = destroy_game(game);
	cr_assert_eq(game, NULL);
}
