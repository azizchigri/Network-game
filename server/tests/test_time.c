/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return the time the action took
*/

#include "game.h"

Test(time, taking_no_time)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1);
	msg_r[0] = "poulet";
	msg_r[1] = NULL;
	cr_assert_eq(cooldown(game, player, msg_r), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}

Test(time, taking_good_time)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1);
	msg_r[0] = "Forward";
	msg_r[1] = NULL;
	cr_assert_eq(cooldown(game, player, msg_r), 7);
	game = destroy_game(game);
	player = destroy_player(player);
}
