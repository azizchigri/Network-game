/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** all function for game info when ai ask for it
*/

#include "game.h"

char *nbr_player(t_game_p *game)
{
	char *respond;
	int tmp;
	int size = 1;
	for (tmp = game->slot; tmp != 0; tmp /= 10)
		size += 1;
	respond = malloc(sizeof(char) * (size + 2));
	sprintf(respond, "%d", game->slot);
	return (respond);
}
