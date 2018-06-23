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

	#define TAKE (1000)
	#define DROP (-1000)

	#define LEFT "Left"
	#define RIGHT "Right"
	#define FORWARD "Forward"
	#define LOOK "Look"
	#define INVENTORY "Inventory"
	#define BROADCAST "Broadcast"
	#define CONNECT_NBR "Connect_nbr"
	#define FORK "Fork"
	#define EJECT "Eject"
	#define TAKE_OBJ "Take"
	#define SET_OBJ "Set"
	#define INCANTATION "Incantation"

	typedef struct s_respond t_respond;
	struct s_respond {
		int time;
		char *respond;
		char *respond_g;
	};

	typedef struct s_teams t_teams;
	struct s_teams {
		char *name;
		int lvl6;
		int eggs;
		int slot;
	};

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
		t_teams **teams;
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
	t_player_p *init_player(t_game_p *game, int fd, char *team);
	//free the player and return NULL
	t_player_p *destroy_player(t_player_p *player);
	//init teams in the game
	int init_teams(t_game_p *game, char **teams_name, int slot);
	//free the game teams
	t_teams **free_teams(t_teams **teams);
	//free respond
	t_respond free_respond(t_respond respond);

//gameplay
	//turn left the player
	void left(t_player_p *player, t_game_p *game);
	//turn right the player
	void right(t_player_p *player, t_game_p *game);
	//delete the actual position of the player
	int remove_place(t_player_p *player, t_game_p *game);
	//add the player on his new place
	int new_place(t_player_p *player, t_game_p *game);
	//go forward the direction of the player is imortant
	void front(t_player_p *player, t_game_p *game);
	//take the cmd of the AI and do the cmd. return the respond and time
	t_respond gameplay(char **msg_r, t_player_p *player, t_game_p *game);
	//return the number of free slot in the game as a respond (char *)
	char *nbr_player(t_game_p *game, t_player_p *player);
	// gice the inventory as str
	char *inventory(t_player_p *player);
	//free players on a cell
	t_player_p **free_player_cell(t_player_p **players);
	//copy player in cpy, return cpy
	t_player_p *cp_player(t_player_p *player);
	//add a player on a cell
	int new_place(t_player_p *player, t_game_p *game);
	//take an item, if not possible return KO
	t_respond take(t_player_p *player, t_game_p *game, char *obj);
	//drop an item, if not possible retrurn KO
	t_respond drop(t_player_p *player, t_game_p *game, char *obj);
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
	//return time for each action
	int cooldown(t_game_p *game, t_player_p *player, char **cmd);
	//incantation to lvl up
	char *incantation(t_game_p *game, t_player_p *player);
	//delete stone to do incantation
	int del_s1(t_game_p *game, t_player_p *player);
	int del_s2(t_game_p *game, t_player_p *player);
	int del_s3(t_game_p *game, t_player_p *player);
	int del_s4(t_game_p *game, t_player_p *player);
	int del_s5(t_game_p *game, t_player_p *player);
	int del_s6(t_game_p *game, t_player_p *player);
	//find where the msg came from
	char *is_right(char up_down, t_player_p *player);
	char  *is_left(char up_down, t_player_p *player);
	char *is_center(char up_down, t_player_p *player);
	//return the cell where end player recieve msg
	char *broadcast(t_game_p *game, t_player_p *start, t_player_p *end);
	//refresh before and after action client and map
	void refresh_map(t_player_p *player, t_game_p *game);
	void refresh_player(t_player_p *player, t_game_p *game);
	// eat or die, if die return dead
	char *eat(t_player_p *player, t_game_p *game);
	//com with graphical client
	char *death(t_player_p *player);
	char *lvl_client(t_player_p *player);
	char *add_str(char *src, char *str);
	char *add_int(char *str, int nb);
	char *map_size(t_game_p *game);
	char *player_pos(t_player_p *player);
	char *player_inv(t_player_p *player);
	char *take_r_client(char ress, int nb);
	char *drop_r_client(char ress, int nb);
	//check if a team won the game, return ko or the team name;
	char *check_win(t_game_p *game);


#endif
