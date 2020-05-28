/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:59:59 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/03 12:59:40 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_user(struct stat fstat)
{
	char			*str;
	struct	passwd 	*pw;
	struct	group  	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin(pw->pw_name, "  "), gr->gr_name);
	return (ft_strjoin(str, "  "));
}

void	permissions(t_dir *tmp, struct stat fstat)
{
	if (tmp->is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
} 

void	print_l(t_dir *list)
{
	t_dir		*tmp;
	struct stat	fstat;
	char		*bytes;
	int			len;
	int			i;

	tmp = list;
	while (tmp != NULL)
	{
		lstat(tmp->full_path, &fstat);
		permissions(tmp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(" ");
		ft_putstr(get_user(fstat));
		i = 5;
		bytes = ft_itoa(fstat.st_size);
		len = ft_strlen(bytes);
		while (i-- > len)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(bytes, " "));
		get_time(fstat, tmp);
		tmp = tmp->next;
		if (tmp != NULL)
			ft_putchar('\n');
	}
}
