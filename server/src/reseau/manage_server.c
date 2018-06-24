/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_server function
*/

#include "server.h"

void init_server_params(t_server *server)
{
	FD_ZERO(&(server->readfds));
	srand(time(NULL));
	server->fds_len = 0;
	server->higher_fd = 0;
	server->client = NULL;
	server->game = game_init(server->options.width, server->options.height,
	server->options.frequence);
	server->eat = SERVER_EAT;
	server->graph = -1;
}

int init_sockets(struct sockaddr_in s_addr, t_server *server)
{
	if (server->fd_connection == -1)
		return (ERROR);
	if (bind(server->fd_connection, (const struct sockaddr *) &s_addr,
	sizeof(s_addr)) == -1) {
		close(server->fd_connection);
		return (ERROR);
	}
	if (listen(server->fd_connection, server->options.nb_clients) == -1) {
		close(server->fd_connection);
		return (ERROR);
	}
	fcntl(server->fd_connection, F_SETFL, O_NONBLOCK);
	FD_SET(server->fd_connection, &(server->readfds));
	server->higher_fd = server->fd_connection;
	return (0);
}

int init_server(t_server *server)
{
	struct sockaddr_in s_addr;
	struct protoent *pe = getprotobyname("TCP");
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(server->options.port);
	s_addr.sin_addr.s_addr = INADDR_ANY;
	init_server_params(server);
	int result = init_teams(server->game, server->options.nameX,
	server->options.nb_clients);
	if (server->game == NULL || result == -1)
		exit(ERROR);
	if (pe == 0)
		return (ERROR);
	server->fd_connection = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	return (init_sockets(s_addr, server));
}

int add_connection(t_server *server)
{
	struct sockaddr_in addr_client;
	socklen_t addr_size;
	int fd_client;

	addr_size = sizeof(addr_client);
	fd_client = accept(server->fd_connection,
	(struct sockaddr *) &addr_client, &addr_size);
	manage_new_client(server, fd_client);
	return (0);
}

int manage_server(t_server *server)
{
	int error = 0;
	int result;
	fd_set set;
	struct timeval tv;
	tv.tv_usec = 0;
	while (!error) {
		tv.tv_sec = 1;
		set = server->readfds;
		printf("tick:%ld\n", tv.tv_sec);
		result = select(server->higher_fd + 1, &set, NULL, NULL, &tv);
		if (result == -1)
			error = -1;
		else if (result)
			manage_fd(server, set);
		execute_commands(server);
	}
	return (0);
}