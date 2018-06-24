/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to move player
*/

#include "game.h"

Test(player, create_player)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	cr_assert_eq(player->direction, 0);
	destroy_game(game);
	free(player);
}

Test(player, destroy_player)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	player = destroy_player(player);
	cr_assert_eq(player, NULL);
	destroy_game(game);
}

Test(player, player_coherance)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	cr_assert(player->x < game->width);
	cr_assert(player->y < game->height);
	cr_assert(player->x >= 0);
	cr_assert(player->y >= 0);
	destroy_game(game);
}
