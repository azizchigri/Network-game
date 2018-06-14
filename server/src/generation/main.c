/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** functional test
*/

#include "game.h"

int main()
{
	int h = 5;
	int w = 10;
	int i = 0;
	int j = 0;
	t_game_p *game;
	t_player_p *player;
	char *respond;
	char *str[2] = {"Set object", "linemate"};
	srand(time(NULL));
	game = game_init(w, h, 1);
	player = init_player(game, 1);
	player->linemate = 0;
	respond = gameplay(str, player, game);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < w; j += 1)
			printf("%d", game->map[i][j].linemate);
		printf("\n");
	}
	game = destroy_game(game);
	player = destroy_player(player);
	printf("%s", respond);
	if (strcmp(respond, "OK") != 0 && strcmp(respond, "KO") != 0)
		free(respond);
}
