/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Socket and connection's initialisation for client
*/

#include "client.h"

int init_connection(char **av, int fd)
{
	int port;
	struct sockaddr_in addr;

	port = atoi(av[0]);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(av[2]);
	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		perror("Connection failed");
		return (return_error(fd));
	}
	return (0);
}

int init_socket(void)
{
	struct protoent *pe;
	int fd;

	pe = getprotobyname("TCP");
	if (!pe)
		return (84);
	if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) < 0)
		perror("Socket failed");
	return (fd);
}
