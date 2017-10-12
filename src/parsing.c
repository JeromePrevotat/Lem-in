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

void	parsing(void)
{
	char		*line;
	t_room_list	*room_list;

	room_list = NULL;
	while (get_next_line(0, &line) != 0)
	{
		get_line_type(line, &room_list);
		free(line);
	}
	free(line);
	while (room_list->prev != NULL)
		room_list = room_list->prev;
	while (room_list != NULL)
	{
		printf("Room : >%s<\n", room_list->room->name);
		room_list = room_list->next;
	}
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
	else if (is_room(line, room_list) == TRUE)
		return (ROOM);
	else if (is_pipe(line, room_list) == TRUE)
		return (PIPE);
	return (-2);
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

int		check_int_range(char *nb)
{
	if (ft_strlen(nb) < 10)
		return (TRUE);
	if (ft_strlen(nb) > 10)
		return (FALSE);
	if (ft_strlen(nb) == 10)
		return (check_int_max(nb));
	return (FALSE);
}

int		check_int_max(char *nb)
{
	int		part1;
	int		part2;
	char	c;

	c = nb[0];
	part1 = ft_atoi(&c);
	part2 = ft_atoi(nb + 1);
	if (part2 <= 147483647 && part1 <= 2)
		return (TRUE);
	else if (part2 <= 147483647 && part1 > 2)
		return (FALSE);
	else if (part2 > 147483647 && part1 < 2)
		return (TRUE);
	else if (part2 > 147483647 && part1 >= 2)
		return (FALSE);
	return (ERROR);
}

int		is_room(char *line, t_room_list **room_list)
{
	char **room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (room[i] != NULL)
		i++;
	if (i != 3)
		return (FALSE);
	if (room[0][0] == '#' || room[0][0] == 'L')
		return (FALSE);
	if (full_digit(room[1]) == FALSE || check_int_range(room[1]) == FALSE)
		return (FALSE);
	if (full_digit(room[2]) == FALSE || check_int_range(room[2]) == FALSE)
		return (FALSE);
	add_room(room, room_list);
	free(room);
	return (TRUE);
}

void	add_room(char **str_room, t_room_list **room_list)
{
	t_room		*room;
	t_room_list	*new_room;

	if (!(room = (t_room *)malloc(1 * sizeof(t_room))))
		return ;
	if (!(new_room = (t_room_list *)malloc(1 * sizeof(t_room_list))))
		return ;
	room->name = str_room[0];
	room->x = ft_atoi(str_room[1]);
	room->y = ft_atoi(str_room[2]);
	new_room->room = room;
	new_room->next = NULL;
	new_room->prev = NULL;
	if ((*room_list) == NULL)
		(*room_list) = new_room;
	else
	{
		while ((*room_list)->next != NULL)
			(*room_list) = (*room_list)->next;
		(*room_list)->next = new_room;
		new_room->prev = (*room_list);
	}
}

int		is_pipe(char *line, t_room_list **room_list)
{
	char	**pipe;
	int		i;

	(void)room_list;
	i = 0;
	pipe = ft_strsplit(line, '-');
	while (pipe[i] != NULL)
		i++;
	if (i != 2)
		return (FALSE);
	if (check_name(pipe[0], room_list) == FALSE || check_name(pipe[1], room_list) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		check_name(char *name, t_room_list **room_list)
{
	while ((*room_list)->prev != NULL)
		(*room_list) = (*room_list)->prev;
	while ((*room_list)->next != NULL)
	{
		if (ft_strcmp(name, (*room_list)->room->name) == 0)
			return (TRUE);
		(*room_list) = (*room_list)->next;
	}
	if (ft_strcmp(name, (*room_list)->room->name) == 0)
		return (TRUE);
	return (FALSE);
}
