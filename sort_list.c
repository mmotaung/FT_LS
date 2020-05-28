/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 06:30:30 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/03 13:01:29 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*tmp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		tmp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*tmp, *next) > 0)
			{
				tmp->next = next->next;
				next->next = tmp;
				*src = next;
				done = 0;
			}
			src = &tmp->next;
			tmp = next;
			next = next->next;
		}
	}
}
