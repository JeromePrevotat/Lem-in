/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

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
