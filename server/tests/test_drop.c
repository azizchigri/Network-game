/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of drop
*/

#include "game.h"

Test(Drop, not_enought)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	msg_r[0] = SET_OBJ;
	msg_r[1] = "linemate";
	player->linemate = 0;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game).respond, "KO"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}

Test(Drop, enought)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	msg_r[0] = SET_OBJ;
	msg_r[1] = "linemate";
	player->linemate = 1;
	cr_assert_eq(strcmp(gameplay(msg_r, player, game).respond, "OK"), 0);
	game = destroy_game(game);
	player = destroy_player(player);
}

Test(Drop, enought_inventary)
{
	char *msg_r[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	msg_r[0] = SET_OBJ;
	msg_r[1] = "linemate";
	player->linemate = 1;
	gameplay(msg_r, player, game);
	cr_assert_eq(player->linemate, 0);
	game = destroy_game(game);
	player = destroy_player(player);
}
