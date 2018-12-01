/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:40:31 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 14:44:28 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rest;
	int		i;

	if (!(s) || !(f))
		return (0);
	rest = ft_strnew(ft_strlen(s));
	if (rest == 0)
		return (0);
	rest = ft_strcpy(rest, s);
	i = -1;
	while (rest[++i])
		rest[i] = f(rest[i]);
	return (rest);
}
