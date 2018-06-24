/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of eject
*/

#include "game.h"

Test(eject, eject_no_one)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	msg_r[0] = EJECT;
	msg_r[1] = NULL;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game).respond, KO), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}
