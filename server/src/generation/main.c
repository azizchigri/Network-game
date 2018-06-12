#include "game.h"

int main()
{
	int h = 5;
	int w = 10;
	int f = 1;
	int i = 0;
	int j = 0;
	t_game_p *game;
	t_player_p *player;
	char *str[2];
	char *respond;

        str[0] = "Inventory";
	str[1] = NULL;
	srand(time(NULL));
	game = game_init(w, h, f);
	player = init_player(game, 1);
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
