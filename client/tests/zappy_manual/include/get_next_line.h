/*
** get_next_line.h for GNL in /home/CHIGRIA/CPE_2016_getnextline
**
** Made by Aziz CHIGRI
** Login   <CHIGRIA@epitech.net>
**
** Started on  Mon Jan  2 10:34:15 2017 Aziz CHIGRI
** Last update Sun May 21 16:28:23 2017 chadelaud benjamin
*/

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define	NO_LINE	(-1)

char	*get_next_line(const int fd);
char	*my_strcat(char *dest, char *src);
char	*my_split(char *line, char **save);
int	check_line(char *str);
int	my_strlen(char *str);
