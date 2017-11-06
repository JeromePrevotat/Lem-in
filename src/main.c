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
	check_error(anthill);
	send_scout(anthill);
	print_adj(anthill);
	check_no_path(anthill);
	ants_attack(anthill);
	free_anthill(&anthill);
	return (0);
}

void print_adj(t_anthill *anthill)
{
	t_room_list *rtmp;
	t_adj_list	*adjtmp;

	to_lst_start(&anthill->rooms);
	rtmp = anthill->rooms;

	while (rtmp != NULL)
	{
		while (rtmp->room->adj->prev != NULL)
			rtmp->room->adj = rtmp->room->adj->prev;
		adjtmp = rtmp->room->adj;
		printf("FROM >%s< TO :\n", rtmp->room->name);
		while (adjtmp != NULL)
		{
			printf("\t>%s< || ", adjtmp->room);
			print_dv(anthill, adjtmp->room);
			adjtmp = adjtmp->next;
		}
		rtmp = rtmp->next;
	}
}

void print_dv(t_anthill *anthill, char *room)
{
	t_room_list *rtmp;

	to_lst_start(&anthill->rooms);
	rtmp = anthill->rooms;

	while (rtmp != NULL && ft_strcmp(rtmp->room->name, room) != 0)
		rtmp = rtmp->next;
	if (rtmp != NULL)
		printf("DV : %d\n", rtmp->room->dv);
	else
		printf("ERROR NO ROOM FIND\n");
}
