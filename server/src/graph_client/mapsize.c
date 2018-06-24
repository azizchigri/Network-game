/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** return map size
*/

#include "game.h"

char *add_str(char *src, char *str)
{
	int i;
	int j;

	for (j = 0; src[j] != 0; j += 1);
	for (i = 0; str[i] != 0; i += 1) {
		src[j] = str[i];
		j += 1;
	}
	src[j] = 0;
	return (src);
}

char *add_int(char *str, int nb)
{
	char *in_t;
	int tmp;
	int size;
	for (tmp = nb; tmp != 0; tmp /= 10)
		size += 1;
	in_t = malloc(sizeof(char) * size + 1);
	if (in_t == NULL)
		return (NULL);
	sprintf(in_t, "%d", nb);
	str = add_str(str, in_t);
	free(in_t);
	return (str);
}

char *map_size(t_game_p *game)
{
	char *result;
	int x = game->width;
	int y = game->height;
	int tmp;
	int size = 1;
	for (tmp = x; tmp != 0; tmp /= 10)
		size += 1;
	for (tmp = y; tmp != 0; tmp /= 10)
		size += 1;
	result = malloc(sizeof(char) * (size + 6));
	if (result == NULL)
		return (NULL);
	result[0] = 0;
	result = add_str(result, "msz ");
	result = add_int(result, x);
	result = add_str(result, " ");
	result = add_int(result, x);
	result[size + 5] = 0;
	return (result);
}
