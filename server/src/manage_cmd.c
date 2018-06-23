/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** manage_cmd function
*/

#include "server.h"

char **get_cmd(char *buff)
{
	if (buff != NULL) {
		char *caract = strrchr(buff, '-');
		if (caract != NULL && buff[0] == 'T')
			*caract = ' ';
	}
	return (str_to_wordtab(buff));
}

void add_client_cmd(t_server *server, int fd, char *buff)
{
	t_client *client = server->client;
	int i = 0;
	int i2 = 0;
	char **tab = get_cmd(buff);
	if (tab != NULL && client != NULL) {
		int time = cooldown(server->game, client->player, tab);
		if (time == -1) {
			time = -2;
		}
		for (i = 0; client->fd != fd && client != NULL; i += 1) {
			client = client->next;
		}
		for (i2 = 0; client->buf[i2].cmd != NULL && i2 < 10; i2 += 1);
		//appller destroy client
		client->buf[i2].cmd = tab;
		client->buf[i2].time = time;
	}
}

size_t get_size_buff(char *str1, char *str2)
{
	if (str1 == NULL) {
		if (str2 == NULL)
			return (0);
		else
			return (strlen(str2) + 2);
	} else if (str2 == NULL)
		return (strlen(str1) + 1);
	else
		return (strlen(str1) + strlen(str2) + 2);
}

void manage_buff(t_server *server, char *buff, int fd)
{
	t_client *client = server->client;
	for (int i = 0; client->fd != fd && client != NULL; i += 1) {
		client = client->next;
	}
	if (client != NULL) {
		size_t size = get_size_buff(client->buffer, buff);
		client->buffer = realloc(client->buffer, sizeof(char) * size);
		client->buffer[0] = '\0';
		strcat(client->buffer, buff);
		client->buffer[size - 2] = '\0';
		char *result;
		while (((result = strchr(client->buffer, '\n')) != NULL)) {
			char *new = strdup(result + 1);
			*result = '\0';
			add_client_cmd(server, fd, client->buffer);
			free(client->buffer);
			client->buffer = new;
		}
	}
}

void manage_cmd(t_server *server, t_client *client)
{
	if (client->player == NULL || client->buf[0].time == -2) {
		send(client->fd, "ko\n", strlen("ko\n"), 0);
		clear_cmd(client);
		return;
	}
	while (client->buf[0].time == 0) {
		char **cmd = client->buf[0].cmd;
		printf("cmd :%s", client->buf[0].cmd[0]);
		t_respond rep = gameplay(cmd, client->player, server->game);
		printf("retour = %s\n", rep.respond);
		send(client->fd, rep.respond, strlen(rep.respond), 0);
		clear_cmd(client);
		// free_respond();
	}
	client->buf[0].time -= 1;
}