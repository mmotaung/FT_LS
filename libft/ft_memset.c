/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 06:59:08 by mmotaung          #+#    #+#             */
/*   Updated: 2019/06/22 12:27:47 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*j;

	i = 0;
	j = (char*)b;
	while (i < len)
	{
		j[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
