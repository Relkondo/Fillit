/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:28:48 by scoron            #+#    #+#             */
/*   Updated: 2018/11/11 15:07:18 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dstlgth;
	size_t srclgth;

	i = 0;
	srclgth = 0;
	while (dst[i] != '\0')
		i++;
	dstlgth = i;
	while (src[srclgth] != '\0' && size != 0 && i < (size - 1))
	{
		dst[i] = src[srclgth];
		srclgth++;
		i++;
	}
	dst[i] = '\0';
	while (src[srclgth] != '\0')
		srclgth++;
	if (size <= dstlgth)
		return (srclgth + size);
	else
		return (srclgth + dstlgth);
}
