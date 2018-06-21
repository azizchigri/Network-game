/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion to check ressources
*/

#include "game.h"

Test(map, is_the_map_NULL)
{
	int height = 10;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	cr_assert_neq(game->map, NULL);
}

Test(map, is_random_working)
{
	int height = 10;
	int width = 10;
	int freq = 100;
	t_game_p *game = game_init(width, height, freq);
	t_game_p *game2 = game_init(width, height, freq);
	cr_assert_neq(game->map, game2->map);
}

int check_random(t_cell cell, t_cell cell2)
{
	if (cell.linemate == cell2.linemate
	&& cell.deraumere == cell2.deraumere
	&& cell.sibur == cell2.sibur
	&& cell.mendiane == cell2.mendiane
	&& cell.phiras == cell2.phiras
	&& cell.thystame == cell2.thystame
	&& cell.food == cell2.food)
		return (1);
	return (0);
}

Test(map, is_random_working3)
{
	int cpt = 0;
	int i;
	int j;
	t_game_p *game;
	t_game_p *game2;
	srand(time(NULL));
	game = game_init(10, 10, 100);
	game2 = game_init(10, 10, 100);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < 10; j += 1)
			cpt += check_random(game->map[i][j],
					game2->map[i][j]);
	}
	cr_assert(cpt < 100);
}

Test(map, is_the_map_have_ressources)
{
	int cpt = 0;
	int i, j;
	int linemate, deraumere, sibur, mendiane, phiras, thystame, food = 0;
	t_game_p *game = game_init(10, 10, 100);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < 10; j += 1) {
			linemate += game->map[i][j].linemate;
			deraumere += game->map[i][j].deraumere;
			sibur += game->map[i][j].sibur;
			mendiane += game->map[i][j].mendiane;
			phiras += game->map[i][j].phiras;
			thystame += game->map[i][j].thystame;
			food += game->map[i][j].food;
		}
	}
	if (linemate == 0 && deraumere == 0 && sibur == 0
	&& mendiane == 0 && phiras == 0 && thystame == 0 && food == 0)
		cpt = -1;
	cr_assert(cpt != -1);
}
