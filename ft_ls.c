/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:24:47 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/02 12:45:37 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		rev_list(t_dir **head)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void		cap_r(t_dir *list, t_options *o)
{
	t_dir	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->is_dir == 1 && tmp->dir[0] != '.')
			do_ls(tmp->full_path, o);
		tmp = tmp->next;
	}
}
