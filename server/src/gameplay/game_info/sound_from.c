/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check where the sound came from
*/

#include "game.h"

char real_pos_sound(char tmp, t_player_p *player)
{
	char add = player->direction;
	char nb  = tmp;

	add = 0;
	return (nb + 48 + add);
}

char *is_right(char up_down, t_player_p *player)
{
	char tmp = 2;
	char *cell = malloc(sizeof(char) * 2);

	if (cell == NULL)
		return (NULL);
	if (up_down == 'x')
		tmp = 3;
	else if (up_down == 'd')
		tmp = 4;
	cell[0] = real_pos_sound(tmp, player);
	cell[1] = 0;
	return (cell);
}

char *is_left(char up_down, t_player_p *player)
{
	char tmp = 8;
	char *cell = malloc(sizeof(char) * 2);

	if (cell == NULL)
		return (NULL);
	if (up_down == 'x')
		tmp = 7;
	else if (up_down == 'd')
		tmp = 6;
	cell[0] = real_pos_sound(tmp, player);
	cell[1] = 0;
	return (cell);
}

char *is_center(char up_down, t_player_p *player)
{
	char tmp = 1;
	char *cell = malloc(sizeof(char) * 2);

	if (cell == NULL)
		return (NULL);
	if (up_down == 'x')
		tmp = 0;
	else if (up_down == 'd')
		tmp = 5;
	cell[0] = real_pos_sound(tmp, player);
	cell[1] = 0;
	return (cell);
}
