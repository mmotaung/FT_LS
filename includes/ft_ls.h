/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:28:29 by mmotaung          #+#    #+#             */
/*   Updated: 2019/09/03 06:32:13 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <grp.h>
# include <time.h>
# include <pwd.h>
# include <sys/ttycom.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>

typedef struct		s_dir
{
	char			*dir;
	time_t			time;
	int				is_dir;
	char			*full_path;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_options
{
	int				l;
	int				cap_r;
	int				r;
	int				a;
	int				t;
	struct stat		sb;
	struct dirent	*dp;
	DIR				*dirp;
	char			*path;
	t_dir			*list;
}					t_options;

void		ft_ls(t_options *o);
void		do_ls(char *dir, t_options *o);
int			compare_time(t_dir d1, t_dir d2);
int			compare_strings(t_dir d1, t_dir d2);
void		sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
void		do_list(t_options *o);
void		print_l(t_dir *list);
void		print_ls(t_dir *list, t_options *o, char *path);
int			file_check(t_options *o);
void		cap_r(t_dir *list, t_options *o);
void		rev_list(t_dir **head);
void		permissions(t_dir *tmp, struct stat fstat);
void		get_time(struct stat fstat, t_dir *tmp);
#endif



