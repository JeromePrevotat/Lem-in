/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	ants_attack(t_anthill *anthill)
{
	char	**ants_tab;
	int		i;

	if (!(ants_tab = (char **)malloc(anthill->ants * sizeof(char *))))
		return ;
	i = 0;
	while (i < anthill->ants)
	{
		ants_tab[i] = ft_strdup(anthill->start);
		print_pos(ants_tab, i);
		i++;
	}
	printf("\n");
	while (check_end(anthill, ants_tab) == FALSE)
	{
		i = 0;
		while (i < anthill->ants)
		{
			if (move_ants(anthill, ants_tab, i) == TRUE)
				print_pos(ants_tab, i);
			i++;
		}
		printf("\n");
	}
	i = 0;
	while (i < anthill->ants)
	{
		free(ants_tab[i]);
		i++;
	}
	free(ants_tab);
}

int		move_ants(t_anthill *anthill, char **ants_tab, int ant)
{
	char	*next;
	char	*cur_room;

	if (ft_strcmp(ants_tab[ant], anthill->end) != 0)
	{
		cur_room = ft_strdup(ants_tab[ant]);
		next = get_next_room(anthill, ants_tab[ant]);
		if (ft_strcmp(cur_room, next) == 0)
			return (FALSE);
		to_lst_start(&anthill->rooms);
		while (ft_strcmp(anthill->rooms->room->name, ants_tab[ant]) != 0)
			anthill->rooms = anthill->rooms->next;
		anthill->rooms->room->full = FALSE;
		if (ants_tab[ant] != NULL)
		{
			free(ants_tab[ant]);
			ants_tab[ant] = next;
			to_lst_start(&anthill->rooms);
			while (anthill->rooms->next != NULL
				&& ft_strcmp(anthill->rooms->room->name, ants_tab[ant]) != 0)
				anthill->rooms = anthill->rooms->next;
			if (ft_strcmp(anthill->rooms->room->name, anthill->start) != 0
				&& ft_strcmp(anthill->rooms->room->name, anthill->end) != 0)
				anthill->rooms->room->full = TRUE;
		}
		return (TRUE);
	}
	return (FALSE);
}

char	*get_next_room(t_anthill *anthill, char *cur_room)
{
	t_room_list	*tmp;
	t_adj_list	*tmp2;
	int			range;
	char		*next;

	next = ft_strdup(cur_room);
	to_lst_start(&anthill->rooms);
	tmp = anthill->rooms;
	while (tmp != NULL && ft_strcmp(tmp->room->name, cur_room) != 0)
		tmp = tmp->next;
	range = tmp->room->dv;
	while (tmp->room->adj->prev != NULL)
		tmp->room->adj = tmp->room->adj->prev;
	tmp2 = tmp->room->adj;
	while (tmp2 != NULL)
	{
		if ((tmp = get_room_prop(anthill, tmp2->room)) != NULL
			&& tmp->room->dv <= range && tmp->room->full == FALSE)
		{
			range = tmp->room->dv;
			if (next != NULL)
			{
				free(next);
				next = NULL;
			}
			next = ft_strdup(tmp->room->name);
		}
		tmp2 = tmp2->next;
	}
	return (next);
}

int		check_end(t_anthill *anthill, char **ants_tab)
{
	int	i;

	i = 0;
	while (i < anthill->ants)
	{
		if (ft_strcmp(ants_tab[i], anthill->end) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
