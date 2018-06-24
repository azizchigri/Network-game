/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** return map size
*/

#include "game.h"
#include "server.h"

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
	int size = 1;
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
	asprintf(&result, "msz %d %d\n", game->width, game->height);
	return (result);
}
