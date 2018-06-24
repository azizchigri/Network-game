/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parse and manage parameters
*/

#include "server.h"

int manage_parameters_cases(int ac, char **av, int c, t_server *server)
{
	switch (c) {
	case 'n':
		get_n_parameter(ac, av, optind, server);
		break;
	case 'c':
		server->options.nb_clients = get_int_parameter(optarg);
		break;
	case 'f':
		server->options.frequence = get_int_parameter(optarg);
		break;
	default:
		return (ERROR);
	}
	return (0);
}
