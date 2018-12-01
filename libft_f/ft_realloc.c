/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:48:09 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/27 15:50:07 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;
	int		i;

	if (size == 0)
	{
		free(ptr);
		return ((void *)0);
	}
	if (!(ret = (void *)malloc(size)))
		return ((void *)0);
	if (!ptr)
	{
		ptr = ret;
		return (ptr);
	}
	i = 0;
	while (((char *)ptr)[i])
	{
		((char *)ret)[i] = ((char*)ptr)[i];
		i++;
	}
	ptr = ret;
	return (ret);
}
