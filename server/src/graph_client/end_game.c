/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** end game for graphical client
*/

#include "game.h"
#include "server.h"

char *graphical_win(char *team)
{
	char *result;
	asprintf(&result, "seg %s\n", team);
	return (result);
}
