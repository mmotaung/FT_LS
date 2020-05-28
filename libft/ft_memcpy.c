/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotaung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:37:20 by mmotaung          #+#    #+#             */
/*   Updated: 2019/06/22 12:33:07 by mmotaung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	if (dst == src)
		return ((char *)src);
	if (n == 0 && dst == src)
		return (dst);
	i = (unsigned char *)dst;
	j = (unsigned char *)src;
	while (n--)
		*i++ = *j++;
	return (dst);
}
