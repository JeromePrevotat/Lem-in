/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int		is_pipe(char *line, t_room_list **room_list)
{
	char	**pipe;
	int		i;

	i = 0;
	pipe = ft_strsplit(line, '-');
	while (pipe[i] != NULL)
		i++;
	if (i != 2)
		return (FALSE);
	if (check_name(pipe[0], room_list) == FALSE
		|| check_name(pipe[1], room_list) == FALSE)
		return (free_split(pipe, 0));
	return (free_split(pipe, 1));
}

void	build_pipe(t_anthill *anthill, char *line)
{
	char	**pipe;

	pipe = ft_strsplit(line, '-');
	to_lst_start(&anthill->rooms);
	while (anthill->rooms->next != NULL)
	{
		if (ft_strcmp(anthill->rooms->room->name, pipe[0]) == 0)
			add_pipe_to(anthill, pipe[1]);
		if (ft_strcmp(anthill->rooms->room->name, pipe[1]) == 0)
			add_pipe_to(anthill, pipe[0]);
		anthill->rooms = anthill->rooms->next;
	}
	if (ft_strcmp(anthill->rooms->room->name, pipe[0]) == 0)
		add_pipe_to(anthill, pipe[1]);
	if (ft_strcmp(anthill->rooms->room->name, pipe[1]) == 0)
		add_pipe_to(anthill, pipe[0]);
	free_split(pipe, 0);
}

void	add_pipe_to(t_anthill *anthill, char *dest)
{
	t_adj_list	*adj_room;

	adj_room = NULL;
	if (!(adj_room = (t_adj_list *)malloc(1 * sizeof(t_adj_list))))
		return ;
	adj_room->room = ft_strdup(dest);
	adj_room->next = NULL;
	if (anthill->rooms->room->adj == NULL)
	{
		adj_room->prev = NULL;
		anthill->rooms->room->adj = adj_room;
	}
	else
	{
		while (anthill->rooms->room->adj->next != NULL)
			anthill->rooms->room->adj = anthill->rooms->room->adj->next;
		anthill->rooms->room->adj->next = adj_room;
		adj_room->prev = anthill->rooms->room->adj;
	}
}
