/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	parsing(t_anthill *anthill)
{
	t_room_list	*room_list;
	char		*line;
	int			type;
	int			cmd;

	room_list = NULL;
	anthill->rooms = room_list;
	cmd = 0;
	while (get_next_line(0, &line) != 0)
	{
		if ((type = get_line_type(line, &anthill->rooms)) == ERROR)
			error();
		cmd = add_to_anthill(anthill, line, type);
		if (cmd == ERROR)
			error();
		free(line);
	}
	free(line);
	printf("PIPES LIST :\n");
	to_lst_start(&anthill->rooms);
	while (anthill->rooms->next != NULL)
	{
		to_lst_start(&anthill->rooms->room->adj);
		while (anthill->rooms->room->adj->next != NULL)
		{
			printf(">%s< -> >%s<\n", anthill->rooms->room->name, anthill->rooms->room->adj->room->name);
			anthill->rooms->room->adj = anthill->rooms->room->adj->next;
		}
		printf(">%s< -> >%s<\n", anthill->rooms->room->name, anthill->rooms->room->adj->room->name);
		anthill->rooms = anthill->rooms->next;
	}
	free_room_list(anthill->rooms);
}

int		add_to_anthill(t_anthill *anthill, char *line, int type)
{
	static int	cmd_list[2] = {0};
	int			c;

	ft_putendl(line);
	if (type == CMD)
	{
		c = get_cmd(line);
		if (c == 1 && cmd_list[0] == 0)
			cmd_list[0] = 1;
		if (c == 2 && cmd_list[1] == 0)
			cmd_list[1] = 1;
		return (c);
	}
	if (type == ANT)
		anthill->ants = ft_atoi(line);
	if (type == ROOM)
		build_room(anthill, line, cmd_list);
	if (type == PIPE)
		build_pipe(anthill, line);
	return (0);
}

int		get_cmd(char *line)
{
	static int	start = 0;
	static int	end = 0;

	if (ft_strcmp(line + 2, "start") == 0)
	{
		if (start == 1)
			return (ERROR);
		start = 1;
		return (1);
	}
	if (ft_strcmp(line + 2, "end") == 0)
	{
		if (end == 1)
			return (ERROR);
		end = 1;
		return (2);
	}
	return (0);
}

int		get_line_type(char *line, t_room_list **room_list)
{
	if (ft_strcmp(line, "") == 0)
		return (ERROR);
	else if (line[0] == '#' && line[1] != '#')
		return (COM);
	else if (line[0] == '#' && line[1] == '#')
		return (CMD);
	else if (full_digit(line) == TRUE && check_int_range(line) == TRUE)
		return (ANT);
	else if (is_room(line) == TRUE)
		return (ROOM);
	else if (is_pipe(line, room_list) == TRUE)
		return (PIPE);
	return (ERROR);
}

int		full_digit(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
