/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look function
*/

#include "game.h"

char **fct(t_game_p *game, t_player_p *player)
{
	int level = player->lvl;
	char **tab = malloc(sizeof(char *) * (level + 2));
	void (*see[4])(t_player_p *, int, t_game_p *, char **);

	if (tab == NULL)
		return (NULL);
	tab[0] = strdup(" player");
	if (tab[0] == NULL)
		return (NULL);
	see[0] = &see_north;
	see[1] = &see_east;
	see[2] = &see_south;
	see[3] = &see_west;
	for (int i = 0; i < 4; i += 1) {
		if (i == player->direction)
			(*see[i])(player, 1, game, tab);
	}
	return (tab);
}

char *look(t_game_p *game, t_player_p *player)
{
	char **response;

	if (!game || !player)
		return (NULL);
	response = fct(game, player);
	return (wordtab_to_str(response, ", "));
}
