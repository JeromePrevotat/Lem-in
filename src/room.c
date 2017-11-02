/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		check_name(char *name, t_room_list **room_list)
{
	to_lst_start(room_list);
	while ((*room_list)->next != NULL)
	{
		if (ft_strcmp(name, (*room_list)->room->name) == 0)
			return (TRUE);
		(*room_list) = (*room_list)->next;
	}
	if (ft_strcmp(name, (*room_list)->room->name) == 0)
		return (TRUE);
	return (FALSE);
}

int		is_room(char *line)
{
	char **room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (room[i] != NULL)
		i++;
	if (i != 3)
		return (free_split(room, 0));
	if (room[0][0] == '#' || room[0][0] == 'L')
		return (free_split(room, 0));
	if (full_digit(room[1]) == FALSE || check_int_range(room[1]) == FALSE)
		return (free_split(room, 0));
	if (full_digit(room[2]) == FALSE || check_int_range(room[2]) == FALSE)
		return (free_split(room, 0));
	return (free_split(room, 1));
}

int		build_room(t_anthill *anthill, char *line, int *cmd)
{
	char **room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (room[i] != NULL)
		i++;
	if (i != 3)
		return (free_split(room, 0));
	add_room(anthill, room, cmd);
	return (free_split(room, 1));
}
