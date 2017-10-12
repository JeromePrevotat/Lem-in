/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef LEMIN_H
# define LEMIN_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

enum
{
	COM, CMD, ROOM, PIPE, ANT
};

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
}				t_room;

//Main.c

//Parsing.c
void	parsing(void);
int		get_line_type(char *line);
int		full_digit(char *line);
int		check_int_range(char *nb);
int		check_int_max(char *nb);
int		is_room(char *line);

//Utils.c
void	error(void);

#endif
