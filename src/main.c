/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	main(void)
{
	t_anthill	*anthill;

	if (!(anthill = (t_anthill *)malloc(1 * sizeof(t_anthill))))
		return (ERROR);
	anthill->start = NULL;
	anthill->end = NULL;
	parsing(anthill);
	printf("\n");
	send_scout(anthill);
	to_lst_start(&anthill->rooms);
	while (anthill->rooms->next != NULL)
	{
		printf("ROOM DV : %s || %d\n", anthill->rooms->room->name, anthill->rooms->room->dv);
		anthill->rooms = anthill->rooms->next;
	}
	printf("ROOM DV : %s || %d\n", anthill->rooms->room->name, anthill->rooms->room->dv);
	free_anthill(&anthill);
	return (0);
}
