/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:49:55 by mmotaung          #+#    #+#             */
/*   Updated: 2019/06/19 08:53:29 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	size_t			len;
	char			*s;
	unsigned int	nb;

	len = digit_counter(n);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = nb % 10 + '0';
	while (nb /= 10)
		s[--len] = nb % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
