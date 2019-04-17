/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:52:00 by scoron            #+#    #+#             */
/*   Updated: 2018/11/15 18:48:07 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_error_str(char *str, char *base)
{
	int i;
	int j;
	int check;

	i = 0;
	if (str == 0 || base == 0)
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		check = 0;
		while (base[j] != '\0')
		{
			if (base[j] == str[i] || str[i] == '+'
					|| str[i] == '-')
				check = 1;
			j++;
		}
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_check_error_b(char *base)
{
	int i;
	int j;

	i = 0;
	if (base == 0)
		return (1);
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int		ft_find(char *str, char *base, int i, int j)
{
	int r;

	if (j == 0)
	{
		r = 0;
		while (base[r] != str[i])
			r++;
		return (r);
	}
	else
	{
		r = 1;
		if (i < 0)
		{
			i *= -1;
			r++;
		}
		while (i >= j)
		{
			i /= j;
			r++;
		}
		return (r);
	}
}

int				ft_atoi_base(char *str, char *base)
{
	int		bs;
	int		i;
	int		sign;
	int		nb;

	bs = 0;
	nb = 0;
	i = ft_check_error_b(base);
	sign = ft_check_error_str(str, base);
	if (i == 1 || sign == 0)
		return (0);
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (base[bs] != '\0')
		bs++;
	while (str[i] != '\0' && str[i] != '+' && str[i] != '-')
	{
		nb = (nb * bs) + ft_find(str, base, i, 0);
		i++;
	}
	return (nb * sign);
}
