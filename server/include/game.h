/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** include file to creating game for zappy's project
*/

#ifndef GAME_H_
	# define GAME_H_

	#include <fcntl.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#include <time.h>
	#include <criterion/criterion.h>

	typedef struct s_player_p t_player_p;
	struct s_player_p {
		int id;
		int alive;
		int lvl;
		char *teams_name;
		int *inventory;
		int x;
		int y;
		char direction;
	};

	typedef struct s_cell t_cell;
	struct s_cell {
		t_player_p **players;
		int linemate;
		int deraumere;
		int sibur;
		int mendiane;
		int phiras;
		int thystame;
		int food;
	};

	typedef struct s_game_p t_game_p;
	struct s_game_p {
		int height;
		int width;
		int slot;
		int nb_player;
		t_cell **map;
		int f;
	};

	int create_map(t_game_p *game);
	t_game_p *destroy_game(t_game_p *game);
	void init_ressources(t_game_p *game);
	t_game_p *game_init(int w, int h, int f);
	void left(t_player_p *player);
	void right(t_player_p *player);
	t_player_p *init_player(t_game_p *game, int fd);
	int remove_place(t_player_p *player, t_game_p *game);
	int new_place(t_player_p *player, t_game_p *game);
	t_player_p *destroy_player(t_player_p *player);

#endif
