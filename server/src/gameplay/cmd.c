/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** branching cmd receive from ai
*/

#include "game.h"

char *move(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], FORWARD) == 0) {
		front(player, game);
		respond = "OK";
	}
	else if (strcmp(msg_r[0], RIGHT) == 0) {
		right(player);
		respond = "OK";
	}
	else if (strcmp(msg_r[0], LEFT) == 0) {
		left(player);
		respond = "OK";
	}
	return (respond);
}

char *personnal_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], LOOK) == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], INVENTORY) == 0) {
		respond = inventory(player);
	}
	else if (strcmp(msg_r[0], BROADCAST) == 0) {
		respond = "OK";
	}
	write(1, game, 0);
	return (respond);
}

char *game_info(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], CONNECT_NBR) == 0) {
		respond = nbr_player(game);
	}
	else if (strcmp(msg_r[0], FORK) == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], EJECT) == 0) {
		respond = eject(player, game);
	}
	write(1, player, 0);
	return (respond);
}

char *item_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], TAKE_OBJ) == 0) {
		respond = take(player, game, msg_r[1]);
	}
	else if (strcmp(msg_r[0], SET_OBJ) == 0) {
		respond = drop(player, game, msg_r[1]);
	}
	else if (strcmp(msg_r[0], INCANTATION) == 0) {
		respond = incantation(game, player);
	}
	return (respond);
}

t_respond gameplay(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond msg_s;
	if (player->alive == 0) {
		msg_s.respond = "dead";
		return (msg_s);
	}
	msg_s.time = cooldown(game, player, msg_r);
	msg_s.respond = move(msg_r, player, game);
	if (msg_s.respond != NULL)
		return (msg_s);
	msg_s.respond = personnal_action(msg_r, player, game);
	if (msg_s.respond != NULL)
		return (msg_s);
	msg_s.respond = game_info(msg_r, player, game);
	if (msg_s.respond != NULL)
		return (msg_s);
	msg_s.respond = item_action(msg_r, player, game);
	if (msg_s.respond != NULL)
		return (msg_s);
	msg_s.respond = "KO";
	return (msg_s);
}
