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
	to_lst_start(anthill->rooms);
	while (anthill->rooms->next != NULL)
	{
		if (anthill->rooms->room->name == pipe[0])
		{
			
		}
		if (anthill->rooms->room->name == pipe[1])
		{

		}
		anthill->rooms = anthill->rooms->next;
	}
}
