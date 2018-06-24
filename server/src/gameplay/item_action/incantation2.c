/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incantation2 return all id who lvl up
*/

#include "game.h"

int *get_id_lvlup(t_game_p *game, t_player_p *player, int tmp, int *id)
{
	int i;
	int x = player->x;
	int y = player->y;
	int j;
	for (i = 0; game->map[x][y].players[i] != NULL; i += 1) {
		if (game->map[x][y].players[i]->id != player->id
		&& tmp != 1) {
			id[j] = game->map[x][y].players[i]->id;
			tmp -= 1;
			j += 1;
		}
	}
	id[j] = player->id;
	id[j + 1] = -1;
	return (id);
}

char *put_lvl_inrespond(char *str, int lvl)
{
	int i;
	int size = strlen(str);
	char *lvl_up = malloc(sizeof(char) * size  + 1);
	if (lvl_up == NULL)
		return (NULL);
	for (i = 0; str[i] != 0; i += 1)
		lvl_up[i] = str[i];
	lvl_up[i] = 0;
	lvl_up[i -1] = lvl + 48;
	return (lvl_up);
}

t_respond get_player_incant(t_game_p *game,
			t_player_p *player, int tmp)
{
	t_respond resp;
	char *str;
	str = "Elevation underway Current level: k";
	resp.respond = put_lvl_inrespond(str, player->lvl);
	resp.id = malloc(sizeof(int) * (tmp + 1));
	if (resp.id == NULL)
		return (resp);
	resp.id = get_id_lvlup(game, player, tmp, resp.id);
	return (resp);
}
