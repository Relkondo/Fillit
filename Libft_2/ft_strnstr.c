/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:51:51 by scoron            #+#    #+#             */
/*   Updated: 2018/11/12 10:30:50 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int k;
	int milestone;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < (int)len)
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			milestone = i;
			while (haystack[i] == needle[k++]
					&& haystack[i] != '\0' && i < (int)len)
			{
				i++;
				if (needle[k] == '\0')
					return ((char *)haystack + i - k);
			}
			i = milestone;
		}
		i++;
	}
	return (0);
}
