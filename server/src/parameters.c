/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** parameters function
*/

#include "server.h"

void get_n_parameter(int ac __attribute__((unused)),
char **av __attribute__((unused)), int index __attribute__((unused)),
t_server *server)
{
	index = index - 1;
	int i = 0;
	for (i = 0; index + i < ac && *av[index + i] != '-'; i += 1);
	server->options.nameX = malloc(sizeof(char *) * (i + 1));
	if (server->options.nameX == NULL)
		exit(ERROR);
	for (int cpt = 0; index + cpt < index + i; cpt += 1) {
		server->options.nameX[cpt] = strdup(av[index + cpt]);
	}
	server->options.nameX[i] = NULL;
}

int get_int_parameter(char *param)
{
	int nb = -1;
	nb = atoi(param);
	if (nb <= 0) {
		return (ERROR_PARAM);
	}
	return (nb);
}

int manage_parameters(int ac, char **av, int c, t_server *server)
{
	switch (c) {
	case 'p':
		server->options.port = get_int_parameter(optarg);
		break;
	case 'x':
		server->options.width = get_int_parameter(optarg);
		break;
	case 'y':
		server->options.height = get_int_parameter(optarg);
		break;
	default:
		return (manage_parameters_cases(ac, av, c, server));
	}
	return (0);
}


int check_options(t_server *server)
{
	t_options opt = server->options;
	if (opt.port <= 0 || opt.width <= 0 || opt.height <= 0 ||
	    opt.nameX == NULL || opt.nb_clients <= 0) {
		return (ERROR);
	}
	if (opt.frequence <= 0)
		opt.frequence = 100;
	return (0);
}

int
get_options(int ac __attribute__((unused)), char **av __attribute__((unused)),
t_server *server)
{
	server->options.port = 0;
	server->options.width = 0;
	server->options.height = 0;
	server->options.nameX = NULL;
	server->options.nb_clients = 0;
	server->options.frequence = 0;

	int c;
	while ((c = getopt(ac, av, "p:x:y:n:c:f:")) != -1) {
		if (manage_parameters(ac, av, c, server) == ERROR)
			return (ERROR);
	}
	return (check_options(server));
}
