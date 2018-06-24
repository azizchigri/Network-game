/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ressources droping and taking for client
*/

#include "game.h"
#include "server.h"

char *take_r_client(char ress, int nb)
{
	char *result;
	asprintf(&result, "pgt %d %c\n", nb, ress);
	return (result);
}

char *drop_r_client(char ress, int nb)
{
	char *result;
	asprintf(&result, "pdr %d %c\n", nb, ress);
	return (result);
}
