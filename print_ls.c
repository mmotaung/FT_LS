/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:31:36 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/02 13:27:35 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_ls(t_dir *list, t_options *o, char *path)
{
	t_dir	*tmp;

	if (o->t == 1)
		sort_list(&list, compare_time, 0);
	if (o->r == 1)
		rev_list(&list);
	if (o->cap_r == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (o->l == 1)
		print_l(list);
	else
	{
		tmp = list;
		while (tmp != NULL)
		{
			ft_putstr(tmp->dir);
			tmp = tmp->next;
			if (tmp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if (o->cap_r == 1)
		cap_r(list, o);
}

int		file_check(t_options *o)
{
	if ((o->dirp = opendir(".")) != NULL)
	{
		while ((o->dp = readdir(o->dirp)) != NULL)
		{
			lstat(o->dp->d_name, &o->sb);
			if (S_ISREG(o->sb.st_mode) && ft_strcmp(o->dp->d_name, o->list->dir) == 0)
			{
				ft_putendl(o->dp->d_name);
				return (1);
			}
			else if (!ft_strcmp(o->dp->d_name, o->list->dir))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(o->list->dir);
				ft_putendl(": Permission denied");
				return (-1);
			}
		}
		ft_putstr("ft_ls: ");
		ft_putstr(o->list->dir);
		ft_putendl(": Permission denied");
		return (-1);
	}
	return (0);
}
