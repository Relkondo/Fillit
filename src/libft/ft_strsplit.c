/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:23:54 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 16:38:08 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			k++;
		while (s[i] != c && s[i])
			i++;
	}
	return (k);
}

static char	*ft_spmall(char const *s, int i, char c)
{
	int		j;
	char	*res;

	j = 0;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	if (!(res = (char *)malloc((j + 1) * sizeof(char))))
		return (0);
	return (res);
}

static void	ft_spcpy(char **res, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		k++;
		if (s[i])
			if (!(res[k] = ft_spmall(s, i, c)))
				return ;
		j = 0;
		while (s[i] != c && s[i])
		{
			res[k][j] = s[i];
			i++;
			j++;
		}
		if (s[i])
			res[k][j] = 0;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	int		w;
	char	**res;

	if (s == 0)
		return (0);
	w = ft_countw(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (w + 1))))
		return (0);
	res[w] = 0;
	ft_spcpy(res, s, c);
	return (res);
}
