/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:11:47 by scoron            #+#    #+#             */
/*   Updated: 2018/11/12 15:44:24 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*rest;

	if (!(rest = (void *)malloc(size * sizeof(size_t))))
		return (0);
	while (size-- != 0)
		*((char *)rest + size) = 0;
	return (rest);
}
