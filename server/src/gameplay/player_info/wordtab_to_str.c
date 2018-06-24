/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** wordtab_to_str function
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int tablen(char **tab, char *separator)
{
	int i = 0;
	int count = 0;

	while (tab[i] != NULL) {
		count += strlen(tab[i]);
		i += 1;
	}
	return (count + (i + 1) * strlen(separator));
}

void free_input_tab(char **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i += 1;
	i -= 1;
	while (i >= 0) {
		free(tab[i]);
		tab[i] = NULL;
		i -= 1;
	}
	free(tab);
	tab = NULL;
}

char *wordtab_to_str(char **tab, char *separator)
{
	int i = 0;
	char *result;

	if (tab == NULL || tab[0] == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (tablen(tab, separator) + 3));
	if (result == NULL)
		return (NULL);
	result[0] = '[';
	result[1] = '\0';
	while (tab[i] != NULL) {
		if (i != 0)
			result = strcat(result, separator);
		result = strcat(result, tab[i]);
		i += 1;
	}
	free_input_tab(tab);
	return (strcat(result, "]"));
}