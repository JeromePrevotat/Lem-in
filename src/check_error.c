/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	check_error(t_anthill *anthill)
{
	if (anthill->ants < 1)
	{
		printf("ANTS ");
		error();
	}
	if (anthill->rooms == NULL)
	{
		printf("ROOMS ");
		error();
	}
	if (anthill->start == NULL)
	{
		printf("NO START ");
		error();
	}
	if (anthill->end == NULL)
	{
		printf("NO END ");
		error();
	}
	if (no_pipes(anthill) == TRUE)
	{
		printf("NO PIPES ");
		error();
	}
	return (1);
}

int	no_pipes(t_anthill *anthill)
{
	t_room_list	*r_tmp;

	to_lst_start(&anthill->rooms);
	r_tmp = anthill->rooms;
	while (r_tmp != NULL)
	{
		if (r_tmp->room->adj != NULL)
			return (FALSE);
		r_tmp = r_tmp->next;
	}
	return (TRUE);
}

int	check_no_path(t_anthill *anthill)
{
	t_room_list	*tmp;

	to_lst_start(&anthill->rooms);
	tmp = anthill->rooms;
	while (tmp != NULL && ft_strcmp(tmp->room->name, anthill->start) != 0)
		tmp = tmp->next;
	if (tmp->room->dv == -1)
	{
		printf("DV START -1 ");
		error();
	}
	return (1);
}
