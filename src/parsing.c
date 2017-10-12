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
	char	*line;
	while (get_next_line(0, &line) != 0)
	{
		printf("LINE : >%s<\n", line);
		if (get_line_type(line) == ERROR)
			return ;
		else if (get_line_type(line) == COM)
			printf("COM\n");
		else if (get_line_type(line) == CMD)
			printf("CMD\n");
		else if (get_line_type(line) == ANT)
			printf("ANT\n");
		else if (get_line_type(line) == ROOM)
			printf("ROOM\n");
		free(line);
	}
	free(line);
}

int		get_line_type(char *line)
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

int		is_room(char *line)
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
	return (TRUE);
}
