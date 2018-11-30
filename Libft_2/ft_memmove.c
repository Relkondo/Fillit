/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:35:34 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 16:59:05 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (((char *)dst - (char *)src) >= 0)
	{
		while (i-- > 0)
			*((char *)dst + i) = *((char *)src + i);
	}
	if (((char *)dst - (char *)src) < 0)
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	return ((void *)dst);
}
