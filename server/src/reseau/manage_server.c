/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_server function
*/


#include "reseau.h"


int init_server(t_server *server)
{
	FD_ZERO(&(server->readfds));

	struct sockaddr_in s_addr;
	struct protoent *pe = getprotobyname("TCP");
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(server->options.port);
	s_addr.sin_addr.s_addr = INADDR_ANY;
	if (pe == 0)
		return (ERROR);
	server->fd_connection = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (server->fd_connection == -1)
		return (ERROR);
	if (bind(server->fd_connection, (const struct sockaddr *) &s_addr, sizeof(s_addr)) == -1) {
		close(server->fd_connection);
		return (ERROR);
	}
	if (listen(server->fd_connection, server->options
	.nb_authorized_client) == -1) {
		close(server->fd_connection);
		return (ERROR);
	}
	fcntl(server->fd_connection, F_SETFL, O_NONBLOCK);
	FD_SET(server->fd_connection, &(server->readfds));
	server->higher_fd = server->fd_connection;
	return (0);
}


int add_connection(t_server *server)
{
	struct sockaddr_in addr_client;
	socklen_t addr_size;
	int fd_client;

	addr_size = sizeof(addr_client);
	fd_client = accept(server->fd_connection,
	(struct sockaddr *) &addr_client, &addr_size);
	if (fd_client != -1) {
		server->fds[server->fds_len] = fd_client;
		server->fds_len += 1;
		server->higher_fd =
		server->higher_fd > fd_client ? server->higher_fd : fd_client;
		fcntl(fd_client, F_SETFL, O_NONBLOCK);
		FD_SET(fd_client, &(server->readfds));
		printf("New client connected\n");
		send(fd_client, "WELCOME\n", 8, 0);
	}
	return (0);
}

void read_fd(int fd)
{
	char buff[1024];
	int result = recv(fd, buff, sizeof(buff), 0);
	if (result < 1){
		printf("Round %d, and the data read size is: n=%d \n",fd,
		result);
	}
	buff[result] = 0;
	printf("message:%s\n", buff);
}

int manage_fd(t_server *server, fd_set set)
{
	if (FD_ISSET(server->fd_connection, &set))
		add_connection(server);
	for (int i = 0; i < server->fds_len; i++)
	{
		if (FD_ISSET(server->fds[i], &set))
			read_fd(server->fds[i]);
	}
	return(0);
}

int manage_server(t_server *server)
{
	int error = 0;
	int result;
	fd_set set;
	struct timeval tv;
	tv.tv_usec = 0;
	while (!error)
	{
		tv.tv_sec = 1;
		set = server->readfds;
		result = select(server->higher_fd + 1, &set, NULL, NULL, &tv);
		if (result == -1)
			error = -1;
		else if (result)
			manage_fd(server, set);
	}
	return (0);
}