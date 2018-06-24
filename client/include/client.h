/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's header program
*/

#ifndef CLIENT_H_
	#define CLIENT_H_

	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netdb.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <errno.h>
	#include <arpa/inet.h>
	#include <string.h>
	#include <getopt.h>

//communication
	//Management for "-help" argument
	int get_help(int argc, char **argv);
	//Print usage program when error or "-help" argument found
	void print_usage(void);
	//get arguments given on program's launch
	char **get_args(int argc, char **argv);
	//Check if necessary arguments are here
	int check_args(char **args);
	//initialize a file descriptor for socket
	int init_socket(void);
	//Connect the program on server
	int init_connection(char **av, int fd);
	//Management in case of error when socket is open
	int return_error(int fd);
	//Close the socket
	int stop_socket(int fd);

#endif /* !CLIENT_H_ */
