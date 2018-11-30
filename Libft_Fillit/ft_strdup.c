/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:39:43 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 19:08:08 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	int		i;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	i = -1;
	while (src[++i])
		res[i] = src[i];
	res[i] = 0;
	return (res);
}
