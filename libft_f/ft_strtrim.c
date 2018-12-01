/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:35:28 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 16:37:36 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			j;
	size_t			len;
	char			*res;

	if (!(s))
		return (0);
	i = 0;
	len = ft_strlen(s);
	j = 0;
	while (ft_iswhite(s[i]) && s[i])
		i++;
	if (i != len)
		while (ft_iswhite(s[len - 1]))
		{
			len--;
			j++;
		}
	res = ft_strsub(s, i, (ft_strlen(s) - i - j));
	return (res);
}
