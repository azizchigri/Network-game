/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_server function
*/

#include "server.h"

int init_server(t_server *server)
{
	FD_ZERO(&(server->readfds));

	srand(time(NULL));
	struct sockaddr_in s_addr;
	struct protoent *pe = getprotobyname("TCP");
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(server->options.port);
	s_addr.sin_addr.s_addr = INADDR_ANY;
	server->fds_len = 0;
	server->higher_fd = 0;
	server->game = game_init(server->options.width, server->options.height,
	server->options.frequence);
	int result = init_teams(server->game, server->options.nameX,
	server->options.nb_clients);
	if (server->game == NULL || result == -1)
		exit(ERROR);
	if (pe == 0)
		return (ERROR);
	server->fd_connection = socket(AF_INET, SOCK_STREAM, pe->p_proto);
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

size_t get_size_buff(char *str1, char *str2)
{
	if (str1 == NULL){
		if (str2 == NULL)
			return (0);
		else
			return (strlen(str2) + 1);
	} else if (str2 == NULL)
		return (strlen(str1) + 1);
	else
		return (strlen(str1) + strlen(str1) + 1);
}

void manage_buff(t_server *server, char *buff, int fd)
{
	int i;
	t_client *client = server->client;
	for (i = 0; client->fd != fd && client != NULL; i += 1) {
		client = client->next;
	}
	if (client != NULL) {
		size_t size = get_size_buff(client->buffer, buff);
		client->buffer = realloc(client->buffer,
		sizeof(char) * size);
		client->buffer[0] = '\0';
		strcat(client->buffer, buff);
		//buff[strlen(buff) - 1] = '\0';
		char *result;
		while (((result = strchr(client->buffer, '\n')) != NULL)) {
			char *new = strdup(result + 1);
			if (new == NULL)
				exit(84);
			*result = '\0';
			add_client_cmd(server, fd, client->buffer);
			free(client->buffer);
			client->buffer = new;
		}
	}
}

void read_fd(t_server *server, int fd)
{
	char buff[BUFF_SIZE];
	int result = recv(fd, buff, sizeof(buff), 0);
	if (result < 1) {
		printf("Round %d, and the data read size is: n=%d \n", fd,
		result);
	}
	buff[result] = 0;
	manage_buff(server, buff, fd);
	printf("message:%s, len:%ld\n", buff, strlen(buff));
}

int manage_fd(t_server *server, fd_set set)
{
	if (FD_ISSET(server->fd_connection, &set))
		add_connection(server);
	for (int i = 0; i < server->fds_len; i = i + 1) {
		if (FD_ISSET(server->fds[i], &set))
			read_fd(server, server->fds[i]);
	}
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
		result = select(server->higher_fd + 1, &set, NULL, NULL, &tv);
		if (result == -1)
			error = -1;
		else if (result)
			manage_fd(server, set);
		execute_commands(server);
	}
	return (0);
}