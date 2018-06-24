/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** add and delete client
*/

#include "server.h"

t_client *add_client(t_client *liste, t_client *client)
{
	t_client *tmp;

	if (client == NULL)
		return (liste);
	if (liste == NULL) {
		client->next = NULL;
		return (client);
	}
	tmp = liste;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = client;
	tmp->next->next = NULL;
	return (liste);
}

t_client *delete_client(t_client *liste, t_client *delete)
{
	t_client *tmp = liste;
	t_client *tmp2;
	t_client *tmp3;

	if (tmp == delete) {
		tmp = liste->next;
		free(liste);
		return (tmp);
	}
	while (tmp->next != delete)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	tmp->next = tmp3;
	free(tmp2);
	return (liste);
}
