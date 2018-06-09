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
	if (strcmp(msg_r[0], "Forward") == 0) {
		front(player, game);
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Right") == 0) {
		right(player);
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Left") == 0) {
		left(player);
		respond = "OK";
	}
	return (respond);
}
/*
char *personnal_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], "Look") == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Inventory") == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Broadcast") == 0) {
		respond = "OK";
	}
	return (respond);
}
*/
char *game_info(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], "Connect_nbr") == 0) {
		respond = nbr_player(game);
	}
	else if (strcmp(msg_r[0], "Fork") == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Eject") == 0) {
		respond = "OK";
	}
	write(1, player, 0);
	return (respond);
}
/*
char *item_action(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *respond = NULL;
	if (strcmp(msg_r[0], "Take object") == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Set object") == 0) {
		respond = "OK";
	}
	else if (strcmp(msg_r[0], "Incantation") == 0) {
		respond = "OK";
	}
	return (respond);
}
*/
char *gameplay(char **msg_r, t_player_p *player, t_game_p *game)
{
	char *msg_s = NULL;

	msg_s = move(msg_r, player, game);
	if (msg_s != NULL)
		return (msg_s);
	/*msg_s = personnal_action(msg_r, player, game);
	if (msg_s != NULL)
	return (msg_s);*/
	msg_s = game_info(msg_r, player, game);
	if (msg_s != NULL)
		return (msg_s);
/*	msg_s = item_action(msg_r, player, game);
	if (msg_s != NULL)
		return (msg_s);*/
	return ("KO");
}
