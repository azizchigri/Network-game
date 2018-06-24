/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** end game for graphical client
*/

#include "game.h"

char *graphical_win(char *team)
{
	char *result;
	int size = 0;
	size += strlen(team);
	size += 4;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = add_str(result, "seg ");
	result = add_str(result, team);
	result[size] = 0;
	return (result);
}
