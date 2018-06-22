/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** Criterions tests for get_options
*/

#include <criterion/criterion.h>
#include "server.h"

Test(good_parameters, get_options)
{
	t_server *server = malloc(sizeof(t_server));
	char *av[15];
	av[0] = "zappy_server";
	av[1] = "-p";
	av[2] = "4242";
	av[3] = "-x";
	av[4] = "45";
	av[5] = "-y";
	av[6] = "486";
	av[7] = "-n";
	av[8] = "teamA";
	av[9] = "teamB";
	av[10] = "-c";
	av[11] = "10";
	av[12] = "-f";
	av[13] = "45";
	av[14] = NULL;
	if (server != NULL)
		cr_assert_eq(0, get_options(14, av, server));
}

Test(no_parameters, get_options)
{
	t_server *server = malloc(sizeof(t_server));
	char *av[2];
	av[0] = "zappy_server";
	av[1] = NULL;
	if (server != NULL){
		cr_assert_eq(84, get_options(1, av, server));
	}
}


Test(bad_parameters, get_options)
{
	t_server *server = malloc(sizeof(t_server));
	char *av[15];
	av[0] = "zappy_server";
	av[1] = "-p";
	av[2] = "zae42";
	av[3] = "-x";
	av[4] = "45";
	av[5] = "-y";
	av[6] = "486";
	av[7] = "-n";
	av[8] = "teamA";
	av[9] = "teamB";
	av[10] = "-c";
	av[11] = "10";
	av[12] = "-f";
	av[13] = "45";
	av[14] = NULL;
	if (server != NULL)
		cr_assert_eq(84, get_options(14, av, server));
}

Test(missing_one_arg_parameters, get_options)
{
	t_server *server = malloc(sizeof(t_server));
	char *av[15];
	av[0] = "zappy_server";
	av[1] = "-p";
	av[2] = "zae42";
	av[3] = "-x";
	av[4] = "45";
	av[5] = "-y";
	av[6] = "486";
	av[7] = "-n";
	av[8] = "teamA";
	av[9] = "teamB";
	av[10] = "-c";
	av[11] = "10";
	av[12] = "-f";
	av[13] = NULL;
	if (server != NULL)
		cr_assert_eq(84, get_options(13, av, server));
}