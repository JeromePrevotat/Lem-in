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
		i++;
	}
	while (check_end(ants_tab) == FALSE)
		move_ants(anthill, ants_tab);

}

void move_ants(t)anthill *anthill, char **ants_tab)
{
	/* code */
}

int		check_end(char **ants_tab)
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
