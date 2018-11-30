/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:40:31 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 16:28:05 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rest;
	int		i;

	if (s == NULL)
		return (0);
	rest = ft_strnew(ft_strlen(s));
	if (rest == 0)
		return (0);
	rest = ft_strcpy(rest, s);
	i = -1;
	while (rest[++i])
		rest[i] = f(i, rest[i]);
	return (rest);
}
