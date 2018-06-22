/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** destroy game
*/

#include "game.h"

t_respond free_respond(t_respond respond)
{
	if (strcmp(respond.respond, "KO") != 0
	&& strcmp(respond.respond, "OK") != 0
	&& respond.respond != NULL)
		free(respond.respond);
	respond.respond = NULL;
	return (respond);
}

t_player_p **free_player_cell(t_player_p **players)
{
	int i = 0;
	if (players != NULL) {
		for (i = 0; players[i] != NULL; i += 1)
			free(players[i]);
	}
	if (players != NULL)
		free(players);
	players = NULL;
	return (players);
}

t_teams **free_teams(t_teams **teams)
{
	int i = 0;

	if (teams == NULL)
		return (NULL);
	for (i = 0; teams[i] != NULL; i += 1) {
		if (teams[i] != NULL)
		free(teams[i]);
	}
	free(teams);
	return (NULL);
}

t_game_p *destroy_game(t_game_p *game)
{
	int i = 0;
	int j = 0;
	if (game == NULL)
		return (NULL);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < game->width; j += 1)
			game->map[i][j].players =
				free_player_cell(game->map[i][j].players);
		free(game->map[i]);
	}
	game->teams = free_teams(game->teams);
	if (game->map != NULL)
		free(game->map);
	game->map = NULL;
	free(game);
	game = NULL;
	return (game);
}
