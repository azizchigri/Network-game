#include "game.h"

int main()
{
	int h = 5;
	int w = 10;
	int f = 1;
	int i = 0;
	int j = 0;
	t_game_p *game;

	srand(time(NULL));
	game = game_init(w, h, f);
	for (i = 0; game->map[i] != NULL; i += 1) {
		for (j = 0; j < w; j += 1)
			printf("%d", game->map[i][j].linemate);
		printf("\n");
	}
	game = destroy_game(game);
}
