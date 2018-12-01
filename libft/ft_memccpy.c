/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:35:34 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 16:06:11 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t p;

	p = 0;
	while (p < n && *((unsigned char*)src + p) != (unsigned char)c)
	{
		*((unsigned char*)dst + p) = *((unsigned char*)src + p);
		p++;
	}
	if (p != n)
		*((unsigned char*)dst + p) = *((unsigned char*)src + p);
	return (p == n ? 0 : dst + p + 1);
}
