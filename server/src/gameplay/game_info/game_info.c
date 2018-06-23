/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** all function for game info when ai ask for it
*/

#include "game.h"

char *nbr_player(t_game_p *game, t_player_p *player)
{
	int i = 0;
	char *respond;
	int tmp;
	int size = 1;
	for (i = 0; strcmp(game->teams[i]->name, player->team) != 0; i += 1);
	for (tmp = game->teams[i]->slot; tmp != 0; tmp /= 10)
		size += 1;
	respond = malloc(sizeof(char) * (size + 1));
	if (respond == NULL)
		return ("KO");
	sprintf(respond, "%d", game->teams[i]->slot);
	return (respond);
}
