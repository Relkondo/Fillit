/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:34:08 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/05 20:33:24 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char	const *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	i = ft_strlen(str);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return ((char *)0);
	i -= 1;
	j = 0;
	while (i >= 0)
	{
		ret[j] = str[i];
		i--;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
