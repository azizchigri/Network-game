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
	tmp += linemate(player, game, check + 1);
	check = strcmp(obj, "deraumere");
	tmp += deraumere(player, game, check + 1);
	check = strcmp(obj, "sibur");
	tmp += sibur(player, game, check + 1);
	check = strcmp(obj, "mendiane");
	tmp += mendiane(player, game, check + 1);
	check = strcmp(obj, "phiras");
	tmp += phiras(player, game, check + 1);
	check = strcmp(obj, "thystame");
	tmp += thystame(player, game, check + 1);
	check = strcmp(obj, "food");
	tmp += food(player, game, check + 1);
	if (tmp == -6)
		return ("OK");
	return ("KO");
}

char *drop(t_player_p *player, t_game_p *game, char *obj)
{
	int check = 0;
	int tmp = 0;
	check = strcmp(obj, "linemate");
	tmp += linemate(player, game, check - 1);
	check = strcmp(obj, "deraumere");
	tmp += deraumere(player, game, check - 1);
	check = strcmp(obj, "sibur");
	tmp += sibur(player, game, check - 1);
	check = strcmp(obj, "mendiane");
	tmp += mendiane(player, game, check - 1);
	check = strcmp(obj, "phiras");
	tmp += phiras(player, game, check - 1);
	check = strcmp(obj, "thystame");
	tmp += thystame(player, game, check - 1);
	check = strcmp(obj, "food");
	tmp += food(player, game, check - 1);
	if (tmp == -6)
		return ("OK");
	return ("KO");
}
