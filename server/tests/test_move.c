/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to move player
*/

#include "game.h"

Test(move_player, turn_left)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *tmp[2];
	tmp[0] = "poulet";
	tmp[1] = NULL;
	init_teams(game, tmp, 2);
	player = init_player(game, 1, "poulet");
	left(player, game);
	cr_assert_eq(player->direction, 3);
	destroy_game(game);
	free(player);
}

Test(move_player, turn_right)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *tmp[2];
	tmp[0] = "poulet";
	tmp[1] = NULL;
	init_teams(game, tmp, 2);
	player = init_player(game, 1, "poulet");
	right(player, game);
	cr_assert_eq(player->direction, 1);
	destroy_game(game);
	free(player);
}

Test(move_player, right_left_frompars)
{
	char *str[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *tmp[2];
	tmp[0] = "poulet";
	tmp[1] = NULL;
	init_teams(game, tmp, 2);
	player = init_player(game, 1, "poulet");
	str[0] = LEFT;
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game).respond, "OK"), 0);
	cr_assert_eq(player->direction, 3);
	str[0] = RIGHT;
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game).respond, "OK"), 0);
	cr_assert_eq(player->direction, 0);
	destroy_game(game);
	free(player);
}

Test(move_player, move_forward)
{
	char *str[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *tmp[2];
	tmp[0] = "poulet";
	tmp[1] = NULL;
	init_teams(game, tmp, 2);
	player = init_player(game, 1, "poulet");
	str[0] = FORWARD;
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game).respond, "OK"), 0);
}


Test(move_player, move_forward_and_delete)
{
	char *str[2];
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *tmp[2];
	tmp[0] = "poulet";
	tmp[1] = NULL;
	init_teams(game, tmp, 2);
	player = init_player(game, 1, "poulet");
	int x = player->x;
	int y = player->y;
	str[0] = FORWARD;
	str[1] = NULL;
	cr_assert_eq(strcmp(gameplay(str, player, game).respond, "OK"), 0);
	cr_assert_eq(game->map[x][y].players, NULL);
	cr_assert_eq(game->map[player->x][player->y].players[0]->id,
		player->id);
}
