/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include "server.h"

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

char le_or_ri(t_game_p *game, t_player_p *start, t_player_p *end, int tmp)
{
	int x2 = end->x;
	int tmp2 = 0;
	char left_right = 'x';
	for (int x = start->x; x != x2; x += 1) {
		if (x == game->width)
			x = -1;
		else
			tmp += 1;
	}
	for (int x = start->x; x != x2; x -= 1) {
		if (x < 0)
			x = game->width;
		else
			tmp2 += 1;
	}
	if (tmp < tmp2)
		left_right = 'l';
	else if (tmp > tmp2)
		left_right = 'r';
	return (left_right);
}

char up_or_do(t_game_p *game, t_player_p *start, t_player_p *end, int tmp)
{
	int y2 = end->y;
	int tmp2 = 0;
	char up_down = 'x';
	for (int y = start->y; y != y2; y += 1) {
		if (y == game->height)
			y = -1;
		else
			tmp += 1;
	}
	for (int y = start->y; y != y2; y -= 1) {
		if (y < 0)
			y = game->height;
		else
			tmp2 += 1;
	}
	if (tmp < tmp2)
		up_down = 'd';
	else if (tmp > tmp2)
		up_down = 'u';
	return (up_down);
}

char *broadcast(t_game_p *game, t_player_p *start, t_player_p *end)
{
	char left_right = le_or_ri(game, start, end, 0);
	char up_down = up_or_do(game, start, end, 0);
	char *cell;

	if (left_right == 'r')
		cell = is_right(up_down, end);
	else if (left_right == 'l')
		cell = is_left(up_down, end);
	else
		cell = is_center(up_down, end);
	cell[0] = relativ_pos(end->direction, cell[0]);
	return (cell);
}

void execute_broadcast(t_server *server, t_client *client)
{
	t_client *tmp = server->client;
	char *msg;
	int size = 0;
	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp != client) {
			msg = broadcast(server->game, client->player,
			tmp->player);
			size = strlen(msg);
			msg = realloc(msg, size + 2);
			strcat(msg, "\n\0");
			send(tmp->fd, msg, size, 0);
			free(msg);
		}
	}
	send(client->fd, "ok\n", 3, 0);
	clear_cmd(client);
}