/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include "game.h"

char relativ_pos(int or, char cell)
{
        int tmp = 0;
        int sum = 2 * or;
        if (cell == '0')
                return (cell);
        for (tmp = 0; tmp != sum; tmp += 1) {
                if (cell == 0)
                        cell = 8;
                cell -= 1;
        }
        return (cell);
}


char le_or_ri(t_game_p *game, t_player_p *start, t_player_p *end)
{
	int x = start->x;
	int x2 = end->x;
	int tmp = 0;
	int tmp2 = 0;
	char l_r = 'x';
	for (x = start->x; x != x2; x += 1) {
		if (x == game->width)
			x = -1;
		else
			tmp += 1;
	}
	for (x = start->x; x != x2; x -= 1) {
		if (x < 0)
			x = game->width;
		else
			tmp2 += 1;
	}
	if (tmp < tmp2)
		l_r = 'l';
	else if(tmp > tmp2)
		l_r = 'r';
	return (l_r);
}

char up_or_do(t_game_p *game, t_player_p *start, t_player_p *end)
{
	int y = start->y;
	int y2 = end->y;
	int tmp = 0;
	int tmp2 = 0;
	char u_d = 'x';
	for (y = start->y; y != y2; y += 1) {
		if (y == game->height)
			y = -1;
		else
			tmp += 1;
	}
	for (y = start->y; y != y2; y -= 1) {
		if (y < 0)
			y = game->height;
		else
			tmp2 += 1;
	}
	if (tmp < tmp2)
		u_d = 'd';
	else if(tmp > tmp2)
		u_d = 'u';
	return (u_d);
}

char *broadcast(t_game_p *game, t_player_p *start, t_player_p *end)
{
	char  l_r = le_or_ri(game, start, end);
	char u_d = up_or_do(game, start, end);
	char *cell;

	if (l_r == 'r')
		cell = is_right(u_d, end);
	else if (l_r == 'l')
		cell = is_left(u_d, end);
	else
		cell = is_center(u_d, end);
	cell[0] = relativ_pos(end->direction, cell[0]);
	return (cell);
		
}
