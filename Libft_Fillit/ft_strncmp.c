/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:10:04 by scoron            #+#    #+#             */
/*   Updated: 2018/11/13 14:54:46 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char *)s1 + i) != '\0'
			&& *((unsigned char *)s2 + i) != '\0')
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	if (i == n)
		return (0);
	if (*((unsigned char *)s1 + i) == '\0')
		return (-*((unsigned char *)s2 + i));
	if (*((unsigned char *)s2 + i) == '\0')
		return (*((unsigned char *)s1 + i));
	return (0);
}
