/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutuntil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:47:19 by scoron            #+#    #+#             */
/*   Updated: 2018/11/25 13:35:43 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutuntil(char **src, int c)
{
	int		i;
	char	*newstr;

	i = 0;
	if (src == NULL || *src == NULL)
		return (NULL);
	while ((*src)[i] != '\0' && (*src)[i] != (unsigned char)c)
		i++;
	if (!(newstr = ft_strnew(i)))
		return (NULL);
	ft_strncat(newstr, *src, i);
	if ((*src)[i] == '\0' || (*src)[i + 1] == '\0')
		*src = ft_strshorten(src, 0, 0);
	else
		*src = ft_strshorten(src, i + 1, ft_strlen(*src) - i - 1);
	return (newstr);
}
