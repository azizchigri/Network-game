/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** arguments management for client
*/

#include "client.h"

int check_args(char **args)
{
	if (args[0] == NULL || args[1] == NULL) {
		printf("Missing parameters! \n\n");
		print_usage();
		return (84);
	}
	return (0);
}

int get_help(int argc, char **argv)
{
	for (int i = 2; i < argc; i = i + 2) {
		if (!strcmp(argv[1], "-help")) {
			print_usage();
			return (0);
		}
	}
	return (84);
}

void print_usage()
{
	printf("USAGE: ./zappy_ai -p port -n name -h machine\n");
	printf("\tport\tis the port number\n");
	printf("\tname\tis the name of the team\n");
	printf("\tmachine\tis the name of the machine; localhost by default\n");
}

char **get_args(int argc, char **argv)
{
	int opt;
	char **args = malloc(sizeof(args) * 3);
	args[2] = "127.0.0.1";
	while ((opt = getopt(argc, argv, "p:n:h:")) != -1) {
		switch (opt) {
			case 'p':
				args[0] = optarg;
				break;
			case 'n':
				args[1] = optarg;
				break;
			case 'h':
				args[2] = optarg;
				break;
			default:
				print_usage();
				return (NULL);
		}
	}
	return (args);
}

