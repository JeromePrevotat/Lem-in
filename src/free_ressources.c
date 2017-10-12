/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	free_room_list(t_room_list *room_list)
{
	while (room_list->prev != NULL)
		room_list = room_list->prev;
	while (room_list->next != NULL)
	{
		if (room_list->room != NULL)
			free(room_list->room);
		room_list = room_list->next;
		if (room_list->prev != NULL)
			free(room_list->prev);
	}
	if (room_list->room != NULL)
		free(room_list->room);
	if (room_list != NULL)
		free(room_list);
}
