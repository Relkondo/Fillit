/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:04:36 by scoron            #+#    #+#             */
/*   Updated: 2018/11/21 19:34:43 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rest;

	if (!(rest = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	while (size > 0)
		*(rest + size--) = 0;
	*rest = 0;
	return (rest);
}
