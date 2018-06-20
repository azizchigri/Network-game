/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** reseau function header
*/

#ifndef PSU_ZAPPY_2017_RESEAU_H
#define PSU_ZAPPY_2017_RESEAU_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR (84)

typedef struct s_options t_options;
struct s_options {
	int port;
	int width;
	int height;
	char **nameX;
	int nb_clients;
	int frequence;
};

#endif //PSU_ZAPPY_2017_RESEAU_H
