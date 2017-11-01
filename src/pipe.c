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
	{
		free(pipe[0]);
		free(pipe[1]);
		free(pipe);
		return (FALSE);
	}
	free(pipe[0]);
	free(pipe[1]);
	free(pipe);
	return (TRUE);
}

void	build_pipe(t_anthill *anthill, char *line)
{
	char	**pipe;
	int		i;

	i = 0;
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
	free(pipe[0]);
	free(pipe[1]);
	free(pipe);
}

void	add_pipe_to(t_anthill *anthill, char *dest)
{
	t_room_list	*new_room;
	t_room_list	*tmp;

	new_room = NULL;
	tmp = anthill->rooms;
	to_lst_start(&tmp);
	while (tmp->next != NULL && ft_strcmp(tmp->room->name, dest) != 0)
		tmp = tmp->next;
	if (!(new_room = (t_room_list *)malloc(1 * sizeof(t_room_list))))
		return ;
	new_room->room = room_cpy(tmp->room);
	if (anthill->rooms->room->adj == NULL)
	{
		new_room->prev = NULL;
		new_room->next = NULL;
		anthill->rooms->room->adj = new_room;
	}
	else
	{
		new_room->prev = anthill->rooms->room->adj;
		new_room->next = NULL;
		anthill->rooms->room->adj->next = new_room;
	}
}

t_room	*room_cpy(t_room *src)
{
	t_room	*cpy;

	if ((!src) || (!(cpy = (t_room *)malloc(1 * sizeof(t_room)))))
		return (NULL);
	cpy->name = ft_strdup(src->name);
	cpy->start = src->start;
	cpy->end = src->end;
	cpy->adj = src->adj;
	cpy->x = src->x;
	cpy->y = src->y;
	return (cpy);
}
