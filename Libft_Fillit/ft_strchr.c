/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:46:42 by scoron            #+#    #+#             */
/*   Updated: 2018/11/11 14:12:04 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (*(s + ++i))
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
	return (*((char *)s + i) == (unsigned char)c ? (char *)s + i : 0);
}
