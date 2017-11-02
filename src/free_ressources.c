/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	free_room(t_room **room)
{
	if ((*room) != NULL)
	{
		if ((*room)->name != NULL)
		{
			free((*room)->name);
			(*room)->name = NULL;
		}
		if ((*room)->adj != NULL)
		{
			free_adj_list(&(*room)->adj);
			(*room)->adj = NULL;
		}
		free((*room));
	}
}

void	free_adj_list(t_adj_list **adj_list)
{
	if ((*adj_list) != NULL)
	{
		while ((*adj_list)->prev != NULL)
			(*adj_list) = (*adj_list)->prev;
		while ((*adj_list)->next != NULL)
		{
			free((*adj_list)->room);
			(*adj_list)->room = NULL;
			(*adj_list) = (*adj_list)->next;
			if ((*adj_list)->prev != NULL)
			{
				free((*adj_list)->prev);
				(*adj_list)->prev = NULL;
			}
		}
		free((*adj_list)->room);
		(*adj_list)->room = NULL;
		free((*adj_list)->prev);
		(*adj_list)->prev = NULL;
		free((*adj_list));
		(*adj_list) = NULL;
	}
}

void	free_room_list(t_room_list *room_list)
{
	to_lst_start(&room_list);
	while (room_list->next != NULL)
	{
		free_room(&room_list->room);
		room_list = room_list->next;
		if (room_list->prev != NULL)
		{
			free(room_list->prev);
			room_list->prev = NULL;
		}
	}
	free_room(&room_list->room);
	if (room_list != NULL)
		free(room_list);
}

void	free_anthill(t_anthill **anthill)
{
	if (*anthill != NULL)
	{
		if ((*anthill)->start != NULL)
			free((*anthill)->start);
		if ((*anthill)->end != NULL)
			free((*anthill)->end);
		if ((*anthill)->rooms != NULL)
			free_room_list((*anthill)->rooms);
		free(*anthill);
	}
}

int		free_split(char **split, int rv)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (rv);
}
