/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:36:18 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/02 13:10:19 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_time(struct stat fstat, t_dir *tmp)
{
	char	buff[13];
	char	*str;
	char	buf[64];
	size_t	len;

	(void)fstat;
	str = ctime(&tmp->time);
	ft_memcpy(buff, &str[4], 12);
	buff[12] = '\0';
	ft_putstr(buff);
	ft_putstr(" ");
	ft_putstr(tmp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		len = readlink(tmp->full_path, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}

void	do_list(t_options *o)
{
	o->list = (t_dir *)malloc(sizeof(t_dir));
	o->list->dir = ".";
	o->list->next = NULL;
}
