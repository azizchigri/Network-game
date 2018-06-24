/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** get_next_line
*/

#include "get_next_line.h"

char *get_next_line(const int fd)
{
	char *line = NULL;
	char buff[READ_SIZE + 1];
	static char *save = "\0";
	int rd;

	rd = 1;
	if (READ_SIZE <= 0 || READ_SIZE > 4294967295)
		return (NULL);
	while (check_line(save) == NO_LINE && rd != 0) {
		if ((rd = read(fd, buff, READ_SIZE)) < 0)
			return (NULL);
		buff[rd] = '\0';
		if ((save = my_strcat(save, buff)) == NULL)
			return (NULL);
	}
	if (rd != 0)
		line = my_split(line, &save);
	if (rd != 0)
		return (line);
	if (save[0] == '\0')
		return (NULL);
	line = save;
	save = "\0";
	return (line);
}

char *my_strcat(char *dest, char *src)
{
	char *cpy;
	int i;
	int j;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(char) *
		     strlen(dest) + strlen(src) + 1);
	if (cpy == NULL || (src == NULL && dest == NULL))
		return (NULL);
	while (dest != NULL && dest[i] != '\0') {
		cpy[i] = dest[i];
		i = i + 1;
	}
	while (src != NULL && src[j] != '\0') {
		cpy[i] = src[j];
		i = i + 1;
		j = j + 1;
	}
	cpy[i] = '\0';
	return (cpy);
}

char *my_split(char *line, char **save)
{
	int i;

	i = 0;
	line = malloc(sizeof(char) * (check_line(*save) + 1));
	if (line == NULL)
		return (NULL);
	while ((*save)[i] != '\n') {
		line[i] = (*save)[i];
		i = i + 1;
	}
	line[i] = '\0';
	(*save) = &((*save)[i + 1]);
	return (line);
}

int check_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (i);
		i = i + 1;
	}
	return (NO_LINE);
}
