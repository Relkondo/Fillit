/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:07:29 by scoron            #+#    #+#             */
/*   Updated: 2018/11/11 16:03:38 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (*((unsigned char *)s1 + i) != '\0'
			|| *((unsigned char *)s2 + i) != '\0')
	{
		if (*((unsigned char *)s1 + i) == '\0')
			return (-*((unsigned char *)s2 + i));
		if (*((unsigned char *)s2 + i) == '\0')
			return (*((unsigned char *)s1 + i));
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}
