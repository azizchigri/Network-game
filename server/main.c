/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** test criterion return of eject
*/

#include "game.h"

int main()
{
	srand(time(NULL));
	t_game_p *game = game_init(10, 10, 100);
	t_player_p *player;
	t_player_p *player2;
	char *str[2];
	str[0] = "poulet";
	str[1] = NULL;
	init_teams(game, str, 2);
	player = init_player(game, 1, "poulet");
	player2 = init_player(game, 2, "poulet");
	char c = player->x + 48;
	write(1, &c , 1);
	c = player2->x + 48;
	write(1, &c , 1);
	c = player->y + 48;
	write(1, &c , 1);
	c = player2->y + 48;
	write(1, &c , 1);
	write(1, "   ", 3);
	char *tmp = broadcast(game, player, player2);
	printf("x1:%d y1:%d x2:%d y2:%d -> %s\n", player->x, player->y, player2->x, player2->y, tmp);
	return (0);
}
