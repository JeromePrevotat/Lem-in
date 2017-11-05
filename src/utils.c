/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_room_list	*get_room_prop(t_anthill *anthill, char *name)
{
	t_room_list	*tmp;

	to_lst_start(&anthill->rooms);
	tmp = anthill->rooms;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->room->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void print_pos(t_anthill *anthill, char **ants_tab)
{
	int	i;

	i = 0;
	while (i < anthill->ants)
	{
		printf("ANTS : %d // POS : %s\n", i, ants_tab[i]);
		i++;
	}
	printf("\n");
}

void error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
