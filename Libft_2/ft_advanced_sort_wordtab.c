/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:54:53 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 18:56:42 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_sort_char(char **tab, int i, int (*f)(char *, char *))
{
	if (f(tab[i - 1], tab[i]) > 0)
		return (0);
	else
		return (1);
}

void			ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	i = 0;
	if (tab == 0 || !(cmp))
		return ;
	while (tab[++i])
		if (!(ft_is_sort_char(tab, i, cmp)))
		{
			ft_swap(tab, i);
			i = 0;
		}
}
