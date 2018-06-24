/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server function
*/

#include "server.h"

void free_server(t_server *server)
{
	free(server);
	server = NULL;
}

int launch_server(int ac, char **av)
{
	t_server *server = malloc(sizeof(t_server));
	if (server == NULL)
		return (84);
	if (get_options(ac, av, server) == 84) {
		fprintf(stderr, "Error, invalid parameters\n");
		exit(84);
	}
	init_server(server);
	manage_server(server);
	return (0);
}