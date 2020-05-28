/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 06:15:55 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/03 09:22:35 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flags(t_options *o, char *flag)
{
	int		i;

	i = 1;
	while (flag[i] != '\0')
	{
		if (flag[i] == 'l')
			o->l = 1;
		else if (flag[i] == 'a')
			o->a = 1;
		else if (flag[i] == 'r')
			o->r = 1;
		else if (flag[i] == 't')
			o->t = 1;
		else if (flag[i] == 'R')
			o->cap_r = 1;
		else
		{
			ft_putstr(flag);
			ft_putendl(": illegal option ");
			ft_putendl("usage: ls [-alrRt] ");
			return (0);
		}
		i++;
	}
	return (1);
}

int		compare_strings(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int		compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int			i;
	t_options	o;
	t_dir		*tmp;

	i = 1;
	o.list = NULL;
	while (i < argc)
	{
		if (argv[i][0] != '-' && (tmp = (t_dir *)malloc(sizeof(t_dir))))
		{
			tmp->dir = argv[i];
			tmp->next = o.list;
			o.list = tmp;
		}
		else if (flags(&o, argv[i]) == 0)
			return (0);
		i++;
	}
	if (o.list == NULL)
		do_list(&o);
	ft_ls(&o);
}
