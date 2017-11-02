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
	COM, CMD, ANT, ROOM, PIPE
};

typedef struct			s_anthill
{
	int					ants;
	struct s_room_list	*rooms;
	char				*start;
	char				*end;
}						t_anthill;

typedef struct			s_adj_list
{
	struct s_adj_list	*prev;
	struct s_adj_list	*next;
	char				*room;
}						t_adj_list;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	t_adj_list			*adj;
	int					x;
	int					y;
	int					dv;
	int					full;
}						t_room;

typedef struct			s_room_list
{
	struct s_room_list	*prev;
	struct s_room_list	*next;
	t_room				*room;
}						t_room_list;

/*
** Main.c
*/

/*
** Parsing.c
*/
void	parsing(t_anthill *anthill);
int		get_line_type(char *line, t_room_list **room_list);
int		full_digit(char *line);
int		add_to_anthill(t_anthill *anthill, char *line, int type);
int		get_cmd(char *line);


/*
** Scout.c
*/
int	send_scout(t_anthill *anthill);
int	scout_adj(t_anthill *anthill, t_adj_list *adj, int dv);

/*
** Room.c
*/
int		build_room(t_anthill *anthill, char *line, int *cmd);

/*
** Pipe.c
*/
int		is_pipe(char *line, t_room_list **room_list);
void	build_pipe(t_anthill *anthill, char *line);
void	add_pipe_to(t_anthill *anthill, char *dest);

/*
** Int_range.c
*/
int		check_int_range(char *nb);
int		check_int_max(char *nb);

/*
** Room_list.c
*/
void	to_lst_start(t_room_list **room_list);
void	add_room(t_anthill *anthill, char **room, int *cmd);
int		check_name(char *name, t_room_list **room_list);
int		is_room(char *line);

/*
** Utils.c
*/
void	error(void);

/*
** Free_ressources.c
*/
void	free_room(t_room **room);
void	free_room_list(t_room_list *room_list);
void	free_adj_list(t_adj_list **adj_list);
void	free_anthill(t_anthill **anthill);
int		free_split(char **split, int rv);

#endif
