/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** take and drop item
*/

#include "game.h"

int call_take_drop(t_player_p *player, t_game_p *game, int action, char *obj)
{
	int tmp = 0;
	int check = 0;
	check = strcmp(obj, "linemate");
	tmp += linemate(player, game, check + action);
	check = strcmp(obj, "deraumere");
	tmp += deraumere(player, game, check + action);
	check = strcmp(obj, "sibur");
	tmp += sibur(player, game, check + action);
	check = strcmp(obj, "mendiane");
	tmp += mendiane(player, game, check + action);
	check = strcmp(obj, "phiras");
	tmp += phiras(player, game, check + action);
	check = strcmp(obj, "thystame");
	tmp += thystame(player, game, check + action);
	check = strcmp(obj, "food");
	tmp += food(player, game, check + action);
	return (tmp);
}

char *graphical_take(char *obj, char **stone, t_player_p *player)
{
	int i;
	char *tmp = NULL;
	for (i = 0; i != 7; i += 1) {
		if (strcmp(obj, stone[i]) == 0)
			tmp = take_r_client(i + 48, player->id);
	}
	return (tmp);
}

t_respond take(t_player_p *player, t_game_p *game, char *obj)
{
	int tmp = 0;
	t_respond resp;
	char *stone[7] = {"food", "linemate", "deraumere",
			"sibur", "mendiane", "phiras", "thystame"};
	resp.respond = OK;
	resp.respond_g = graphical_take(obj, stone, player);
	tmp = call_take_drop(player, game, TAKE, obj);
	if (tmp == -6)
		return (resp);
	if (resp.respond_g != NULL) {
		free(resp.respond_g);
		resp.respond_g = NULL;
	}
	resp.respond = KO;
	return (resp);
}

char *graphical_drop(char *obj, char **stone, t_player_p *player)
{
	int i;
	char *tmp = NULL;
	for (i = 0; i != 7; i += 1) {
		if (strcmp(obj, stone[i]) == 0)
			tmp = drop_r_client(i + 48, player->id);
	}
	return (tmp);
}

t_respond drop(t_player_p *player, t_game_p *game, char *obj)
{
	int tmp = 0;
	t_respond resp;
	char *stone[7] = {"food", "linemate", "deraumere",
			"sibur", "mendiane", "phiras", "thystame"};
	resp.respond = OK;
	resp.respond_g = graphical_drop(obj, stone, player);
	tmp = call_take_drop(player, game, DROP, obj);
	if (tmp == -6)
		return (resp);
	if (resp.respond_g != NULL) {
		free(resp.respond_g);
		resp.respond_g = NULL;
	}
	resp.respond = KO;
	return (resp);
}
