/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:38:49 by scoron            #+#    #+#             */
/*   Updated: 2018/11/14 12:40:45 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(int nbp)
{
	if (nbp > 9)
	{
		ft_print_nbr(nbp / 10);
		ft_putchar(nbp % 10 + '0');
	}
	else
	{
		ft_putchar(nbp + '0');
	}
}

void		ft_putnbr(int n)
{
	int check;

	check = 0;
	if (n == -2147483648)
	{
		n = -214748364;
		check = 1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_print_nbr(n);
	if (check == 1)
	{
		ft_putchar('8');
	}
}
