/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** functional test
*/

#include "game.h"

int main(int ac, char **tmp)
{
	if (ac > 3)
		return (1);
	int h = 5;
	int w = 10;
	int i = 0;
	int j = 0;
	t_game_p *game;
	t_player_p *player;
	t_player_p *player2;
	char *str[2] = {INCANTATION, "linemate"};
	t_respond res;
	srand(time(NULL));
	game = game_init(w, h, 100);
	init_teams(game, tmp, 2);
	player = init_player(game, 1, tmp[0]);
	player2 = init_player(game, 2, tmp[0]);
	player->linemate = 0;
	res = gameplay(str, player, game);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < w; j += 1)
			printf("%d", game->map[i][j].linemate);
		printf("\n");
	}
	game = destroy_game(game);
	player = destroy_player(player);
	player2 = destroy_player(player2);
	printf("%s", res.respond);
	if (strcmp(res.respond, "OK") != 0 && strcmp(res.respond, "KO") != 0)
		free(res.respond);
}
