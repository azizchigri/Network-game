/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** str_to_wordtab for parsing
*/

#include "server.h"

int get_size(int i, char *str)
{
	int size = 0;

	while (str[i] != ' ' && str[i] != '\0') {
		size += 1;
		i += 1;
	}
	return (size);
}

int cpy_intab(char *tab, char *str, int cpt, int size)
{
	int j = 0;

	while (j < size) {
		tab[j] = str[cpt];
		cpt += 1;
		j += 1;
	}
	tab[j] = '\0';
	return (cpt + 1);
}

char **fill_tab(char **tab, char *str, int end)
{
	int i;
	int cpt = 0;
	int size;

	for (i = 0; i != end; i += 1) {
		size = get_size(cpt, str);
		tab[i] = malloc(sizeof(char) * (size + 1));
		if (tab[i] == NULL)
			return (NULL);
		cpt = cpy_intab(tab[i], str, cpt, size);
	}
	return (tab);
}

char **str_to_wordtab(char *str)
{
	int i;
	int cpt = 1;
	char **tab;

	for (i = 0; str[i] != '\0'; i += 1) {
		if (str[i] == ' ')
			cpt += 1;
	}
	tab = malloc(sizeof(char *) * (cpt + 1));
	if (tab == NULL)
		return (NULL);
	tab[cpt] = NULL;
	tab = fill_tab(tab, str, cpt);
	return (tab);
}
