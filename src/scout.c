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

	to_lst_start(&anthill->rooms);
	tmp = anthill->rooms;
	while (tmp != NULL && ft_strcmp(tmp->room->name, anthill->end) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (ERROR);
	tmp->room->dv = 0;
		scout_adj(anthill, tmp->room->adj, tmp->room->dv + 1);
	return (0);
}

int	scout_adj(t_anthill *anthill, t_adj_list *adj, int dv)
{
	t_room_list	*r_tmp;
	t_adj_list	*adj_tmp;

	if (!adj)
		return (0);
	to_lst_start(&anthill->rooms);
	while (adj->prev != NULL)
		adj = adj->prev;
	adj_tmp = adj;
	//MODIF DV
	while (adj_tmp != NULL)
	{
		r_tmp = anthill->rooms;
		while (r_tmp != NULL)
		{
			if (ft_strcmp(r_tmp->room->name, adj_tmp->room) == 0
				&& r_tmp->room->dv == -1)
				r_tmp->room->dv = dv;
			r_tmp = r_tmp->next;
		}
		adj_tmp = adj_tmp->next;
	}
	//SCOUT next
	adj_tmp = adj;
	while (adj_tmp != NULL)
	{
		r_tmp = anthill->rooms;
		while (r_tmp != NULL)
		{
			if (ft_strcmp(r_tmp->room->name, adj_tmp->room) == 0
				&& r_tmp->room->dv == dv)
				scout_adj(anthill, r_tmp->room->adj, dv + 1);
			r_tmp = r_tmp->next;
		}
		adj_tmp = adj_tmp->next;
	}
	return (0);
}
