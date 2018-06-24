/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return com graphival client
*/

#include "game.h"


Test(Drop_client, enought)
{
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 0, "poulet");
	player->linemate = 1;
	cr_assert_eq(strcmp(drop_r_client('1', player->id), "pdr 0 1"), 0);
}
