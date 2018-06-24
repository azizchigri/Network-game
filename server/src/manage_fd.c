/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_fd function
*/

#include "server.h"

void read_fd(t_server *server, int fd)
{
	t_client *client = server->client;
	char buff[BUFF_SIZE];
	int result = recv(fd, buff, sizeof(buff), 0);
	if (result < 1) {
		FD_CLR(fd, &(server->readfds));
		for (int i = 0; client->fd != fd && client != NULL; i += 1) {
			client = client->next;
		}
		destroy_client(server, client);
		close(fd);
	} else {
		buff[result] = '\0';
		manage_buff(server, buff, fd);
	}
}

int manage_fd(t_server *server, fd_set set)
{
	if (FD_ISSET(server->fd_connection, &set))
		add_connection(server);
	for (int i = 0; i < server->fds_len; i = i + 1) {
		if (server->fds[i] != -1 && server->client != NULL && FD_ISSET
		(server->fds[i], &set))
			read_fd(server, server->fds[i]);
	}
	return (0);
}
