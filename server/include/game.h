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

	#define TAKE 1000
	#define DROP -1000

	typedef struct s_player_p t_player_p;
	struct s_player_p {
		int id;
		int alive;
		int lvl;
		char *team;
		int linemate;
		int deraumere;
		int sibur;
		int mendiane;
		int phiras;
		int thystame;
		int food;
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

//genearation
	//generate the map
	int create_map(t_game_p *game);
	//free the game and return the new game equal to NULL
	t_game_p *destroy_game(t_game_p *game);
	//place food and stone randomly on the map
	void init_ressources(t_game_p *game);
	//create the game, take width heigth and frequency
	t_game_p *game_init(int w, int h, int f);
	//init the player with an unique id as fd
	t_player_p *init_player(t_game_p *game, int fd);
	//free the player and return NULL
	t_player_p *destroy_player(t_player_p *player);

//gameplay
	//turn left the player
	void left(t_player_p *player);
	//turn right the player
	void right(t_player_p *player);
	//delete the actual position of the player
	int remove_place(t_player_p *player, t_game_p *game);
	//add the player on his new place
	int new_place(t_player_p *player, t_game_p *game);
	//go forward the direction of the player is imortant
	void front(t_player_p *player, t_game_p *game);
	//take the cmd of the AI and do the cmd. return the respond
	char *gameplay(char **msg_r, t_player_p *player, t_game_p *game);
	//return the number of free slot in the game as a respond (char *)
	char *nbr_player(t_game_p *game);
	// gice the inventory as str
	char *inventory(t_player_p *player);
	//free players on a cell
	t_player_p **free_player_cell(t_player_p **players);
	//copy player in cpy, return cpy
	t_player_p *cp_player(t_player_p *player);
	//add a player on a cell
	int new_place(t_player_p *player, t_game_p *game);
	//take an item, if not possible return KO
	char *take(t_player_p *player, t_game_p *game, char *obj);
	//drop an item, if not possible retrurn KO
	char *drop(t_player_p *player, t_game_p *game, char *obj);
	//take and drop stone
	int linemate(t_player_p *player, t_game_p *game, int value);
	int deraumere(t_player_p *player, t_game_p *game, int value);
	int mendiane(t_player_p *player, t_game_p *game, int value);
	int phiras(t_player_p *player, t_game_p *game, int value);
	int thystame(t_player_p *player, t_game_p *game, int value);
	int food(t_player_p *player, t_game_p *game, int value);
	int sibur(t_player_p *player, t_game_p *game, int value);
	//eject player
	char *eject(t_player_p *player, t_game_p *game);

#endif
