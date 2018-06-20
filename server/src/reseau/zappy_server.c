/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server function
*/

#include "server.h"

void free_server(t_server *server)
{
	//free server->name free le tab complet;
	free(server);
	server = NULL;
}

int launch_server(int ac, char **av)
{
	t_server *server = malloc(sizeof(t_server));
	if (server == NULL)
		return (84);
	if (get_options(ac, av, server) == 84)
		return (84);
	init_server(server);
	manage_server(server);
	//free_server();
	return (0);
}

int main(int ac, char **av)
{
	launch_server(ac, av);
	return (0);
}