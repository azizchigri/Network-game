/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to destroy the game
*/

#include "game.h"

Test(free_map, is_it_free)
{
	t_game_p *game = game_init(10, 10, 100);
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	game = destroy_game(game);
	cr_assert_eq(game, NULL);
}
