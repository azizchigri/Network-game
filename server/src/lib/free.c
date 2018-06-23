/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** free function
*/

#include <unistd.h>
#include <stdlib.h>

void free_tab(char **tab)
{
	if (tab != NULL) {
		for (int i = 0; tab[i] != NULL; i += 1) {
			free(tab[i]);
		}
		free(tab);
	}
}