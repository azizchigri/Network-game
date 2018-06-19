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
	int nb_authorized_client;
	int frequence;
};

typedef struct s_server t_server;
struct s_server {
	int fd_connection;
	int fds_len;
	int higher_fd;
	t_options options;
	fd_set readfds;
	int fds[];
};

int init_server(t_server *server);
int add_connection(t_server *server);
void read_fd(int fd);
int manage_fd(t_server *server, fd_set set);
int manage_server(t_server *server);

#endif //PSU_ZAPPY_2017_RESEAU_H
