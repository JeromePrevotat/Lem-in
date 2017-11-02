/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	to_lst_start(t_room_list **room_list)
{
	while ((*room_list)->prev != NULL)
		(*room_list) = (*room_list)->prev;
}

void	add_room(t_anthill *anthill, char **str_room, int *cmd)
{
	t_room		*room;
	t_room_list	*new_room;

	if (!(room = (t_room *)malloc(1 * sizeof(t_room))))
		return ;
	if (!(new_room = (t_room_list *)malloc(1 * sizeof(t_room_list))))
		return ;
	room->name = ft_strdup(str_room[0]);
	room->x = ft_atoi(str_room[1]);
	room->y = ft_atoi(str_room[2]);
	room->start = FALSE;
	room->end = FALSE;
	room->adj = NULL;
	room->dv = -1;
	room->full = FALSE;
	if (cmd[0] == 1)
	{
		room->start = TRUE;
		anthill->start = ft_strdup(room->name);
		cmd[0] = 0;
	}
	if (cmd[1] == 1)
	{
		room->end = TRUE;
		anthill->end = ft_strdup(room->name);
		cmd[1] = 0;
	}
	new_room->room = room;
	new_room->next = NULL;
	new_room->prev = NULL;
	if (anthill->rooms == NULL)
		anthill->rooms = new_room;
	else
	{
		while (anthill->rooms->next != NULL)
			anthill->rooms = anthill->rooms->next;
		anthill->rooms->next = new_room;
		new_room->prev = anthill->rooms;
	}
}
