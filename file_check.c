/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 07:07:59 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/02 13:13:59 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		do_ls(char *dir, t_options *o)
{
	t_dir	*lst;
	t_dir	*tp;

	lst = NULL;
	if ((o->dirp = opendir(dir)) != NULL)
	{
		while ((o->dp = readdir(o->dirp)) != NULL)
		{
			if (o->dp->d_name[0] != '.' || o->a == 1)
			{
				tp = (t_dir *)malloc(sizeof(t_dir));
				tp->dir = o->dp->d_name;
				tp->full_path = ft_strjoin(ft_strjoin(dir, "/"), o->dp->d_name);
				lstat(tp->full_path, &o->sb);
				tp->time = o->sb.st_mtime;
				(S_ISDIR(o->sb.st_mode) == 1) ? tp->is_dir = 1 : 0;
				tp->next = lst;
				lst = tp;
			}
		}
		sort_list(&lst, compare_strings, 0);
		print_ls(lst, o, dir);
		return ;
	}
	file_check(o);
}

void		ft_ls(t_options *o)
{
	t_dir	*tp;
	tp = o->list;
	while (tp != NULL)
	{
		do_ls(tp->dir, o);
		tp = tp->next;
	}
}
