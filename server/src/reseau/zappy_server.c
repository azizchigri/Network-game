/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server function
*/

#include "reseau.h"

int get_options(int ac __attribute__((unused)), char **av __attribute__((unused)), t_server *server)
{
	server->options.port = 5656;
	server->options.width = 20;
	server->options.height = 20;
	server->options.nameX = NULL;
	server->options.nb_authorized_client = 10;
	server->options.frequence = 10;
	server->fds_len = 0;
	server->higher_fd = 0;
	return (0);
}

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
	if (get_options(ac, av, server) == 84)
		return (84);
	init_server(server);
	manage_server(server);
	//free_server();
	return (0);
}

int main(int ac, char **av)
{

	printf("Port:5656\n");
	launch_server(ac, av);
	return (0);
}