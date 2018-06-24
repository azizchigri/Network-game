/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fork function
*/

#include "server.h"

t_egg *add_egg(t_server *server, t_egg *start, char *team)
{
	t_egg *elem = malloc(sizeof(t_egg));
	if (elem == NULL)
		exit(84);
	elem->next = NULL;
	elem->team = strdup(team);
	elem->time = 600.0 / server->options.frequence;
}

t_egg *delete_egg(t_egg *list, t_egg *delete)
{
	t_egg *tmp = list;
	t_egg *tmp2;
	t_egg *tmp3;

	if (tmp == delete) {
		tmp = list->next;
		free(list);
		delete = NULL;
		return (tmp);
	}
	while (tmp != NULL && tmp->next != delete)
		tmp = tmp->next;
	if (tmp != NULL) {
		tmp2 = tmp->next;
		tmp3 = tmp2->next;
		tmp->next = tmp3;
		free(tmp2);
	}
	delete = NULL;
	return (list);
}

void check_egg(t_server *server, t_egg *start)
{
	t_egg *tmp = start;
	int i;
	while (tmp != NULL) {
		if (tmp->time <= 0) {
			for (i = 0; server->game->teams[i] != NULL && strcmp
			(server->game->teams[i], tmp->team) == 0; i +=	1);
			if (server->game->teams[i] != NULL)
				server->game->teams[i]->slot += 1;
			start = delete_egg(start, tmp);
		}
		tmp->time -= 1;
	}
}