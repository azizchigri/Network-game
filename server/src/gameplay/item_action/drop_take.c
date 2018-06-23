/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** take and drop item
*/

#include "game.h"

char *take(t_player_p *player, t_game_p *game, char *obj)
{
	int check = 0;
	int tmp = 0;
	check = strcmp(obj, "linemate");
	tmp += linemate(player, game, check + TAKE);
	check = strcmp(obj, "deraumere");
	tmp += deraumere(player, game, check + TAKE);
	check = strcmp(obj, "sibur");
	tmp += sibur(player, game, check + TAKE);
	check = strcmp(obj, "mendiane");
	tmp += mendiane(player, game, check + TAKE);
	check = strcmp(obj, "phiras");
	tmp += phiras(player, game, check + TAKE);
	check = strcmp(obj, "thystame");
	tmp += thystame(player, game, check + TAKE);
	check = strcmp(obj, "food");
	tmp += food(player, game, check + TAKE);
	if (tmp == -6)
		return ("OK\n");
	return ("KO\n");
}

char *drop(t_player_p *player, t_game_p *game, char *obj)
{
	int check = 0;
	int tmp = 0;
	check = strcmp(obj, "linemate");
	tmp += linemate(player, game, check + DROP);
	check = strcmp(obj, "deraumere");
	tmp += deraumere(player, game, check + DROP);
	check = strcmp(obj, "sibur");
	tmp += sibur(player, game, check + DROP);
	check = strcmp(obj, "mendiane");
	tmp += mendiane(player, game, check + DROP);
	check = strcmp(obj, "phiras");
	tmp += phiras(player, game, check + DROP);
	check = strcmp(obj, "thystame");
	tmp += thystame(player, game, check + DROP);
	check = strcmp(obj, "food");
	tmp += food(player, game, check + DROP);
	if (tmp == -6)
		return ("OK\n");
	return ("KO\n");
}
