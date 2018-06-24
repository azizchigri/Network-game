/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** branching cmd receive from ai
*/

#include "game.h"

t_respond move(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond resp;
	resp.respond = NULL;
	resp.respond_g = NULL;
	if (strcmp(msg_r[0], FORWARD) == 0) {
		front(player, game);
		resp.respond = OK;
		resp.respond_g = player_pos(player);
	}
	else if (strcmp(msg_r[0], RIGHT) == 0) {
		right(player, game);
		resp.respond = OK;
		resp.respond_g = player_pos(player);
	}
	else if (strcmp(msg_r[0], LEFT) == 0) {
		left(player, game);
		resp.respond = OK;
		resp.respond_g = player_pos(player);
	}
	refresh_map(player, game);
	return (resp);
}

t_respond personnal_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond resp;
	resp.respond = NULL;
	resp.respond_g = NULL;
	if (strcmp(msg_r[0], LOOK) == 0)
		resp.respond = look(game, player);
	else if (strcmp(msg_r[0], INVENTORY) == 0)
		resp.respond = inventory(player);
	refresh_map(player, game);
	return (resp);
}

t_respond game_info(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond resp;
	resp.respond = NULL;
	resp.respond_g = NULL;
	if (strcmp(msg_r[0], CONNECT_NBR) == 0)
		resp.respond = nbr_player(game, player);
	else if (strcmp(msg_r[0], EJECT) == 0)
		resp = eject(player, game);
	refresh_map(player, game);
	return (resp);
}

t_respond item_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond resp;
	resp.respond = NULL;
	resp.respond_g = NULL;
	if (strcmp(msg_r[0], TAKE_OBJ) == 0)
		resp = take(player, game, msg_r[1]);
	else if (strcmp(msg_r[0], SET_OBJ) == 0)
		resp = drop(player, game, msg_r[1]);
	refresh_map(player, game);
	return (resp);
}

t_respond gameplay(char **msg_r, t_player_p *player, t_game_p *game)
{
	t_respond msg_s;
	if (player->alive == 0) {
		msg_s.respond = "dead";
		return (msg_s);
	}
	refresh_player(player, game);
	msg_s = move(msg_r, player, game);
	if (msg_s.respond != NULL || msg_s.respond_g != NULL)
		return (msg_s);
	msg_s = personnal_action(msg_r, player, game);
	if (msg_s.respond != NULL || msg_s.respond_g != NULL)
		return (msg_s);
	msg_s = game_info(msg_r, player, game);
	if (msg_s.respond != NULL || msg_s.respond_g != NULL)
		return (msg_s);
	msg_s = item_action(msg_r, player, game);
	if (msg_s.respond != NULL || msg_s.respond_g != NULL)
		return (msg_s);
	msg_s.respond = KO;
	return (msg_s);
}
