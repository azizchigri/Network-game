/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to move player
*/

#include "game.h"

Test(move_player, turn_left)
{
	t_game_p *game = game_init(10, 10, 1);
	t_player_p *player = init_player(game, 1);
	left(player);
	cr_assert_eq(player->direction, 4);
	destroy_game(game);
	free(player);
}

Test(move_player, turn_right)
{
	t_game_p *game = game_init(10, 10, 1);
	t_player_p *player = init_player(game, 1);
	right(player);
	cr_assert_eq(player->direction, 1);
	destroy_game(game);
	free(player);
}
