/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of incantation
*/

#include "game.h"

Test(parsing_cmd, valide_incantation)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1, "poulet");
	msg_r[0] = INCANTATION;
	msg_r[1] = NULL;
	game->map[player->x][player->y].linemate = 1;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game).respond, "OK"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}

Test(parsing_cmd, valide_incantation_lvl)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1, "poulet");
	msg_r[0] = INCANTATION;
	msg_r[1] = NULL;
	game->map[player->x][player->y].linemate = 1;
	gameplay(msg_r, player, game);
	cr_assert_eq(player->lvl, 2);
	game = destroy_game(game);
	player = destroy_player(player);
}

Test(parsing_cmd, not_valide_incantation)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player = init_player(game, 1, "poulet");
	msg_r[0] = INCANTATION;
	msg_r[1] = NULL;
	game->map[player->x][player->y].linemate = 0;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game).respond, "KO"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}
