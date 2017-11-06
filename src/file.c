/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_file	*new_file(char *name)
{
	t_file	*new_file;

	if (!(new_file = (t_file *)malloc(1 * sizeof(t_file))))
		return (NULL);
	new_file->prev = NULL;
	new_file->next = NULL;
	new_file->name = ft_strdup(name);
	return (new_file);
}

void	add_to_file(t_file **file, char *name)
{
	if ((*file) == NULL)
	{
		(*file) = new_file(name);
		return ;
	}
	while ((*file)->next != NULL)
		(*file) = (*file)->next;
	(*file)->next = new_file(name);
	(*file)->next->prev = (*file);
}

void	file_rm_first(t_file **file)
{
	if ((*file) == NULL)
		return ;
	while ((*file)->prev != NULL)
		(*file) = (*file)->prev;
	if ((*file)->name != NULL)
	{
		free((*file)->name);
		(*file)->name = NULL;
	}
	if ((*file)->next != NULL)
	{
		(*file) = (*file)->next;
		free((*file)->prev);
		(*file)->prev = NULL;
	}
	else
	{
		free((*file));
		(*file) = NULL;
	}
}

char	*file_get_next(t_file **file)
{
	if ((*file) == NULL)
		return (NULL);
	while ((*file)->prev != NULL)
		(*file) = (*file)->prev;
	return ((*file)->name);
}

int		file_size(t_file **file)
{
	t_file	*f_tmp;
	int		size;

	size = 0;
	if ((*file) == NULL)
		return (0);
	while ((*file)->prev != NULL)
		(*file) = (*file)->prev;
	f_tmp = (*file);
	while (f_tmp != NULL)
	{
		f_tmp = f_tmp->next;
		size++;
	}
	return (size);
}

void	print_file(t_file **file)
{
	if ((*file) == NULL)
	{
		printf("FILE VIDE\n");
		return ;
	}
	while ((*file)->prev != NULL)
		(*file) = (*file)->prev;
	printf("FILE :\n");
	while ((*file)->next != NULL)
	{
		printf("%s\n", (*file)->name);
		(*file) = (*file)->next;
	}
	printf("%s\n", (*file)->name);
}
