/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Manual Client
*/

#include "client.h"

int main(int argc, char **argv)
{
	char **args;

	setvbuf(stdout, NULL, _IONBF, 0);
	if (!get_help(argc, argv))
		return (0);
	if ((args = get_args(argc, argv)) == NULL)
		return (84);
	if (check_args(args) == 84)
		return (84);
	if (launch_client(args) == 84)
		return (84);
	return (0);
}
