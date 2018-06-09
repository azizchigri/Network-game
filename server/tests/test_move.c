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
	cr_assert_eq(player->direction, 3);
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

Test(move_player, right_left_frompars)
{
	char *str[2];
	t_game_p *game = game_init(10, 10, 1);
	t_player_p *player = init_player(game, 1);
	str[0] = "Left";
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game), "OK"), 0);
	cr_assert_eq(player->direction, 3);
	str[0] = "Right";
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game), "OK"), 0);
	cr_assert_eq(player->direction, 0);
	destroy_game(game);
	free(player);
}
