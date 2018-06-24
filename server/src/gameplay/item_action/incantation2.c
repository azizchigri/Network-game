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
	for (i = 0; game->map[x][y].player[i] != NULL; i += 1) {
		if (game->map[x][y].player[i].id != player.id) {
			id[j] = game->map[x][y].player[i].id;
			tmp -= 1;
			j += 1;
		}
	}
}

t_respond get_player_incant(t_game_p *game, t_player_p *player, int tmp)
{
        int resp;
        resp.respond = "OK";
        resp.id = malloc(sizeof(int) * (tmp + 1));
        if (resp.id == NULL)
                return (NULL);
	resp.id = get_id_lvlup(game, player, tmp, resp.id);
        return (resp);
}
