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

typedef struct	s_room
{
	char		*name;
	int			start;
	int			end;
	t_room_list	*adj;
	int			x;
	int			y;
}				t_room;

typedef struct	s_room_list
{
	struct s_room_list	*prev;
	struct s_room_list	*next;
	t_room				*room;
}				t_room_list;

//Main.c

//Parsing.c
void	parsing(void);
int		get_line_type(char *line, t_room_list **room_list);
int		full_digit(char *line);
int		check_int_range(char *nb);
int		check_int_max(char *nb);
int		is_room(char *line, t_room_list **room_list);
void	add_room(char **room, t_room_list **room_list);
int		is_pipe(char *line, t_room_list **room_list);
int		check_name(char *name, t_room_list **room_list);

//Utils.c
void	error(void);

//Free_ressources.c
void	free_room_list(t_room_list *room_list);

#endif
