/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** server function header
*/

#ifndef PSU_ZAPPY_2017_SERVER_H
#define PSU_ZAPPY_2017_SERVER_H

#define ERROR_PARAM (-84)

#include "reseau.h"
#include "game.h"

#define BUFF_SIZE (2048)

typedef struct s_buff t_buff;
struct s_buff {
	char **cmd;
	int time;
};

typedef struct s_client t_client;
struct s_client {
	int fd;
	t_player_p *player;
	t_buff buf[10];
	t_client *next;
	int buff_start;
};

typedef struct s_server t_server;
struct s_server {
	int fd_connection;
	int fds_len;
	int higher_fd;
	t_options options;
	fd_set readfds;
	t_game_p *game;
	t_client *client;
	int fds[];
};

int init_server(t_server *server);
int add_connection(t_server *server);
void read_fd(t_server *server, int fd);
int manage_fd(t_server *server, fd_set set);
int manage_server(t_server *server);
int get_options(int ac __attribute__((unused)), char **av __attribute__(
(unused)), t_server *server);
t_client *add_client(t_client *liste, t_client *client);
int manage_new_client(t_server *server, int fd);
char **str_to_wordtab(char *str);
int execute_commands(t_server *server);
void init_client_player(t_server *server, t_client *client, char **tab);
void add_client_cmd(t_server *server, int fd, char *buff);

#endif //PSU_ZAPPY_2017_SERVER_H
