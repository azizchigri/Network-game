/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** take and drop item
*/

#include "game.h"

char *take(t_player_p *player, t_game_p *game, char *obj)
{
	char *respond = "OK";
	int check = 0;

	check = strcmp(obj, "linemate");
	linemate(player, game, check - 1);
	check = strcmp(obj, "deraumere");
	deraumere(player, game, check - 1);
	check = strcmp(obj, "sibur");
	sibur(player, game, check - 1);
	check = strcmp(obj, "mendiane");
	mendiane(player, game, check - 1);
	check = strcmp(obj, "phiras");
	phiras(player, game, check - 1);
	check = strcmp(obj, "thystame");
	thystame(player, game, check - 1);
	check = strcmp(obj, "food");
	food(player, game, check - 1);
	return (respond);
}

char *drop(t_player_p *player, t_game_p *game, char *obj)
{
	char *respond = "OK";
	int check = 0;

	check = strcmp(obj, "linemate");
	linemate(player, game, check + 1);
	check = strcmp(obj, "deraumere");
	deraumere(player, game, check + 1);
	check = strcmp(obj, "sibur");
	sibur(player, game, check + 1);
	check = strcmp(obj, "mendiane");
	mendiane(player, game, check + 1);
	check = strcmp(obj, "phiras");
	phiras(player, game, check + 1);
	check = strcmp(obj, "thystame");
	thystame(player, game, check + 1);
	check = strcmp(obj, "food");
	food(player, game, check + 1);
	return (respond);
}
