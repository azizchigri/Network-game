/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of game_info cmd
*/

#include "game.h"

Test(parsing_cmd, Connect_nbr)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1, "poulet");
	msg_r[0] = CONNECT_NBR;
	msg_r[1] = NULL;
	cr_assert_eq(atoi(gameplay(msg_r, player, game).respond), game->slot);
	game = destroy_game(game);
	player = destroy_player(player);
}
