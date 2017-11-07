/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	send_scout(t_anthill *anthill)
{
	t_room_list	*tmp;
	t_file		*file;

	to_lst_start(&anthill->rooms);
	tmp = anthill->rooms;
	while (tmp != NULL && ft_strcmp(tmp->room->name, anthill->end) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (ERROR);
	file = new_file(tmp->room->name);
	scout_adj(anthill, &file, 1, 0);
	return (0);
}

int	scout_adj(t_anthill *anthill, t_file **file, int size, int dv)
{
	t_room_list	*r_tmp;

	if (file_size(file) == 0)
		return (0);
	to_lst_start(&anthill->rooms);
	r_tmp = anthill->rooms;
	while (r_tmp != NULL && ft_strcmp(r_tmp->room->name, (*file)->name) != 0)
		r_tmp = r_tmp->next;
	if (r_tmp == NULL)
		return (ERROR);
	modif_dv(anthill, file, dv);
	update_file(anthill, file, size);
	scout_adj(anthill, file, file_size(file), dv + 1);
	return (1);
}

void	add_adj_file(t_anthill *anthill, t_file **file, int size)
{
	t_room_list	*r_tmp;
	t_file		*f_tmp;
	t_adj_list	*a_tmp;
	int			s;

	to_lst_start(&anthill->rooms);
	while ((*file)->prev != NULL)
		(*file) = (*file)->prev;
	s = size;
	while (size != 0)
	{
		f_tmp = (*file);
		r_tmp = anthill->rooms;
		while (r_tmp != NULL && ft_strcmp(r_tmp->room->name, f_tmp->name) != 0)
			r_tmp = r_tmp->next;
		if (r_tmp == NULL)
			return ;
		a_tmp = r_tmp->room->adj;
		if (a_tmp != NULL)
		{
			while (a_tmp->prev != NULL)
			a_tmp = a_tmp->prev;
			while (a_tmp != NULL)
			{
				if (check_dv(anthill, a_tmp->room) == TRUE)
				add_to_file(file, a_tmp->room);
				a_tmp = a_tmp->next;
			}
		}
		file_rm_first(file);
		size--;
	}
}

void	rm_modified(t_file **file, int size)
{
	while (size != 0)
	{
		file_rm_first(file);
		size--;
	}
}

int		check_dv(t_anthill *anthill, char *room)
{
	t_room_list	*r_tmp;

	to_lst_start(&anthill->rooms);
	r_tmp = anthill->rooms;
	while (r_tmp != NULL && ft_strcmp(r_tmp->room->name, room) != 0)
		r_tmp = r_tmp->next;
	if (r_tmp == NULL)
		return (ERROR);
	if (r_tmp->room->dv == -1)
		return (TRUE);
	return (FALSE);
}

void	update_file(t_anthill *anthill, t_file **file, int size)
{
	printf("FILE UPDATE\n");
	print_file(file);
	add_adj_file(anthill, file, size);
	printf("ADJ ADDED\n");
	print_file(file);
	//rm_modified(file, size);
	printf("OLD REMOVED\n");
	print_file(file);
	printf("\n");
}

void	modif_dv(t_anthill *anthill, t_file **file, int dv)
{
	t_room_list	*r_tmp;
	t_file		*f_tmp;

	f_tmp = (*file);
	to_lst_start(&anthill->rooms);
	while (f_tmp != NULL)
	{
		r_tmp = anthill->rooms;
		while (r_tmp != NULL && ft_strcmp(r_tmp->room->name, f_tmp->name) != 0)
			r_tmp = r_tmp->next;
		if (r_tmp == NULL)
			return ;
		r_tmp->room->dv = dv;
		f_tmp = f_tmp->next;
	}
}
